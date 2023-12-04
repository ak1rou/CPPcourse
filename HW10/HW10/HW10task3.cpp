#include <iostream>
#include "funcs.h"

int main() {
    const int arrSize = 5;
    int arr[arrSize]{};

    std::cout << "Enter " << arrSize << " integer values:\n";
    for (int i = 0; i < arrSize; ++i)
    {
        std::cin >> arr[i];
    }

    int elem;

    std::cout << "Enter the element to find: ";
    std::cin >> elem;

    if (find(arr, arrSize, elem))
    {
        std::cout << "Element found in the array.\n";
    }
    else
    {
        std::cout << "Element not found in the array.\n";
    }

    return 0;
}