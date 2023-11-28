#include <iostream>
#include "functions.h"

int main()
{
    const int maxSize = 100;
    char inputString1[maxSize], inputString2[maxSize];

    std::cout << "Enter the first string: ";
    std::cin.getline(inputString1, maxSize);

    std::cout << "Enter the second string: ";
    std::cin.getline(inputString2, maxSize);

    if (isEqual(inputString1, inputString2))
    {
        std::cout << "The strings are equal.\n";
    }
    else
    {
        std::cout << "The strings are not equal.\n";
    }

    return 0;
}