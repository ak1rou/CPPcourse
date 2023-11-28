#include <iostream>
#include "functions.h"

int main()
{
    const int size = 10;
    int numbers[size];

    std::cout << "Enter 10 elements of the array:\n";
    for (int i = 0; i < size; ++i)
    {
        std::cin >> numbers[i];
    }

    translateArray(numbers, size);

    std::cout << "Modified array:\n";
    for (int i = 0; i < size; ++i)
    {
        std::cout << numbers[i] << " ";
    }

    return 0;
}
