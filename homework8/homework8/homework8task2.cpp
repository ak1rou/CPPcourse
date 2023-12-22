#include <iostream>
#include "functions.h"

int main()
{
    int factorialNumber;
    std::cout << "Enter a number to calculate its factorial: ";
    std::cin >> factorialNumber;
    std::cout << "Factorial using loop: " << factorialWithLoop(factorialNumber) << std::endl;
    std::cout << "Factorial using recursion: " << factorialWithRecursion(factorialNumber) << std::endl;
    return 0;
}