#include "sort.h"

void quickSortParallel(std::vector<int>& arr, int left, int right, int num_threads) 
{
    if (left < right) {
        int pivot = arr[left];
        int i = left;
        int j = right;

        while (i < j) {
            while (arr[i] <= pivot && i < right) i++;
            while (arr[j] > pivot) j--;
            if (i < j) std::swap(arr[i], arr[j]);
        }

        std::swap(arr[left], arr[j]);

        if (num_threads > 1) {
            std::thread left_thread(quickSortParallel, std::ref(arr), left, j - 1, num_threads / 2);
            quickSortParallel(arr, j + 1, right, num_threads - num_threads / 2);
            left_thread.join();
        }
        else {
            quickSortParallel(arr, left, j - 1, 1);
            quickSortParallel(arr, j + 1, right, 1);
        }
    }
}

void merge(std::vector<int>& arr, int left, int mid, int right) 
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}