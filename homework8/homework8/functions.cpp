#include <iostream>
#include "functions.h"

void countNumbers(int n) {
    int positive = 0, negative = 0, zeroes = 0;

    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;

        if (num > 0) {
            positive++;
        }
        else if (num < 0) {
            negative++;
        }
        else {
            zeroes++;
        }
    }

    std::cout << "Positive: " << positive << ", negative: " << negative << ", zeroes: " << zeroes << std::endl;
}

int factorialWithLoop(int count) {
    int result = 1;
    for (int i = 2; i <= count; ++i) {
        result *= i;
    }
    return result;
}

int factorialWithRecursion(int count) {
    if (count <= 1) {
        return 1;
    }
    else {
        return count * factorialWithRecursion(count - 1);
    }
}

void printNaturalNumbersDescendingLoop(int count) {
    for (int i = count; i >= 1; --i) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void printNaturalNumbersAscendingLoop(int count) {
    for (int i = 1; i <= count; ++i) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void printNaturalNumbersDescendingRecursion(int count) {
    if (count >= 1) {
        std::cout << count << " ";
        printNaturalNumbersDescendingRecursion(count - 1);
    }
}

void printNaturalNumbersAscendingRecursion(int count) {
    if (count >= 1) {
        std::cout << count << " ";
        printNaturalNumbersAscendingRecursion(count + 1);
    }
}
