#include <iostream>
#include "funcs.h"

int main()
{
    int arr[ROWS][COLUMNS]
    {
       {5, 12, 1, 4},
       {2, 10, 9, 6},
       {7, 8, 3, 11}
    };

    std::cout << "Original array:" << std::endl;
    printArray(arr);

    sort(arr, SortingDirection::ByRows);

    std::cout << "Array sorted by rows:" << std::endl;
    printArray(arr);

    sort(arr, SortingDirection::ByColumns);

    std::cout << "Array sorted by columns:" << std::endl;
    printArray(arr);

    return 0;
}
