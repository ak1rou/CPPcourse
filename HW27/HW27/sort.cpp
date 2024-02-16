#include "sort.h"

void quickSort(std::vector<int>& arr, int left, int right) 
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

        quickSort(arr, left, j - 1);
        quickSort(arr, j + 1, right);
    }
}