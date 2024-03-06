#include "sort.h"

void quickSortParallel(std::vector<int>& arr, int left, int right, int num_threads)
{
    if (left < right) 
    {
        int pivot = arr[left];
        int i = left;
        int j = right;

        while (i < j) 
        {
            while (arr[i] <= pivot && i < right) i++;
            while (arr[j] > pivot) j--;
            if (i < j) std::swap(arr[i], arr[j]);
        }

        std::swap(arr[left], arr[j]);

        if (num_threads > 1)
        {
            std::thread left_thread(quickSortParallel, std::ref(arr), left, j - 1, num_threads / 2);
            std::thread right_thread(quickSortParallel, std::ref(arr), j + 1, right, num_threads - num_threads / 2);

            left_thread.join();
            right_thread.join();
        }
        else
        {
            quickSortParallel(arr, left, j - 1, 1);
            quickSortParallel(arr, j + 1, right, 1);
        }
    
    }
}
