#include <iostream>
#include <cstring>
#include "functions.h"

int main()
{
    const int maxSize = 100;  
    char inputString[maxSize];

    std::cout << "Enter a string: ";
    std::cin.getline(inputString, maxSize);

    toUppercase(inputString);

    std::cout << "Output: " << inputString << std::endl;

    return 0;
}
