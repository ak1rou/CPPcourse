#include <iostream>
#include "funcs.h"

int main4()
{
    const int size = 5;
    double array[size];

    std::cout << "Enter " << size << " values: ";
    for (int i = 0; i < size; i++) 
    {
        std::cin >> array[i];
    }

    double sum;
    if (calculateSum(array, size, sum))
    {
        std::cout << "Sum of array elements: " << sum << std::endl;
    }
    else 
    {
        std::cout << "Array size is invalid (<= 0)." << std::endl;
    }

    return 0;
}
