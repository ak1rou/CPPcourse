#include "sort.h"

int main() 
{
    std::vector<int> vec100k(100000);
    std::vector<int> vec1m(1000000);
    std::vector<int> vec10m(10000000);
    std::vector<int> vec100m(100000000);
    std::vector<int> vec1b(1000000000); 

    std::generate(vec100k.begin(), vec100k.end(), rand);
    std::generate(vec1m.begin(), vec1m.end(), rand);
    std::generate(vec10m.begin(), vec10m.end(), rand);
    std::generate(vec100m.begin(), vec100m.end(), rand);

    std::vector<std::vector<int>> vectors = { vec100k, vec1m, vec10m, vec100m };

    int thread_counts[] = { 1, 2, std::thread::hardware_concurrency(), 2 * std::thread::hardware_concurrency() };

    std::string thread_count_names[] = { "1", "2", "hardware_concurrency()", "hardware_concurrency() * 2" };
    std::cout << "Number of Elements" << std::setw(20) << "Threads" << std::setw(20) << "Time (s)" << std::setw(30) << "Boost" << std::endl;

    double elapsed_single_threaded = 0.0;
    for (const auto& vec : vectors) 
    {
        auto start_single = std::chrono::high_resolution_clock::now();
        std::vector<int> temp_vec = vec;
        quickSortParallel(temp_vec, 0, temp_vec.size() - 1, 1);
        auto end_single = std::chrono::high_resolution_clock::now();
        elapsed_single_threaded = std::chrono::duration<double>(end_single - start_single).count();

        for (int i = 0; i < 4; ++i)
        {
            std::vector<int> temp_vec = vec;

            auto start = std::chrono::high_resolution_clock::now();
            if (thread_counts[i] != 0) 
            {
                std::vector<std::thread> threads;
                int chunk_size = temp_vec.size() / thread_counts[i];
                for (int j = 0; j < thread_counts[i]; ++j) 
                {
                    int start_index = j * chunk_size;
                    int end_index = (j == thread_counts[i] - 1) ? temp_vec.size() - 1 : (j + 1) * chunk_size - 1;
                    threads.emplace_back(quickSortParallel, std::ref(temp_vec), start_index, end_index, thread_counts[i]);
                }

                for (auto& t : threads)
                {
                    t.join();
                }

                for (int k = 1; k < thread_counts[i]; ++k) 
                {
                    int start_index = k * chunk_size;
                    int end_index = (k == thread_counts[i] - 1) ? temp_vec.size() - 1 : (k + 1) * chunk_size - 1;
                    merge(temp_vec, 0, start_index - 1, end_index);
                }
            }

            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = end - start;

            double boost = (thread_counts[i] == 1) ? 1.0 : (elapsed_single_threaded / elapsed.count());

            std::cout << vec.size() << std::setw(30) << thread_count_names[i] << std::setw(20) << elapsed.count() << std::setw(30) << boost << std::endl;
        }

        std::cout << std::endl;
    }

    return 0;
}