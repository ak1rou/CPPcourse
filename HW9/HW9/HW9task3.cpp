#include <iostream>
#include <cstring>
#include <cctype>
#include "functions.h"

int main()
{
    const int maxSize = 100;  
    char inputString[maxSize];

    std::cout << "Enter a string: ";
    std::cin.getline(inputString, maxSize);

    if (isPalindrome(inputString)) {
        std::cout << "Output: true\n";
    }
    else {
        std::cout << "Output: false\n";
    }

    return 0;
}