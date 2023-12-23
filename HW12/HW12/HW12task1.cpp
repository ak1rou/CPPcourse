#include <iostream>
#include "funcs.h"

int main()
{
    const int size = 5;
    int arr[size];

    std::cout << "Enter " << size << " integers:" << std::endl;
    for (int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }

    bubbleSort(arr, size);

    std::cout << "Sorted array:" << std::endl;
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }

    return 0;
}
