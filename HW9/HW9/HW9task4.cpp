#include <iostream>
#include <cctype>
#include "functions.h"

int main() 
{
    const int maxSize = 100;
    char inputString[maxSize];

    std::cout << "Enter a string: ";
    std::cin.getline(inputString, maxSize);

    int vowelsCount, consonantsCount;

    parseStringLetters(inputString, vowelsCount, consonantsCount);

    std::cout << "Vowels: " << vowelsCount << "\n";
    std::cout << "Consonants: " << consonantsCount << "\n";

    return 0;
}