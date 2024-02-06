#include <iostream>
#include "DynamicIntArray.h"

int main()
{
    DynamicIntArray arr(3);

    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;

    std::cout << "Initial Array: ";
    for (std::size_t i = 0; i < arr.getSize(); ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    arr.setSize(5);

    arr.push_back(4);
    arr.push_back(5);

    std::cout << "Array after resizing and pushing: ";
    for (std::size_t i = 0; i < arr.getSize(); ++i) 
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    arr.clear();

    std::cout << "Size after clear: " << arr.getSize() << std::endl;

    return 0;
}
