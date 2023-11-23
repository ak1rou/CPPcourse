#include <iostream>
#include "functions.h"

int main()
{
    int naturalNumber;
    std::cout << "Enter the value of N for printing natural numbers: ";
    std::cin >> naturalNumber;

    std::cout << "Descending order (loop): ";
    printNaturalNumbersDescendingLoop(naturalNumber);

    std::cout << "Ascending order (loop): ";
    printNaturalNumbersAscendingLoop(naturalNumber);

    std::cout << "Descending order (recursion): ";
    printNaturalNumbersDescendingRecursion(naturalNumber);
    std::cout << std::endl;

    std::cout << "Ascending order (recursion): ";
    printNaturalNumbersAscendingRecursion(naturalNumber, 1);
    std::cout << std::endl;

    return 0;
}