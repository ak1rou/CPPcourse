#include "funcs.h"
#include <iostream>
#include <vector>

auto compareByLengthLambda = [](const std::string& str1, const std::string& str2) 
    {
    return str1.length() < str2.length();
    };

int main() 
{
    std::vector<std::string> stringContainer = {"apple", "banana", "orange", "grape", "kiwi"};

    std::sort(stringContainer.begin(), stringContainer.end(), compareByLength);
    std::cout << "Sorted by length using function: ";
    for (const auto& str : stringContainer) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    std::sort(stringContainer.begin(), stringContainer.end(), LengthComparator());
    std::cout << "Sorted by length using function object: ";
    for (const auto& str : stringContainer) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    std::sort(stringContainer.begin(), stringContainer.end(), compareByLengthLambda);
    std::cout << "Sorted by length using lambda: ";
    for (const auto& str : stringContainer) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    std::vector<int> numbers = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int divisor = 4;

    unsigned int count = countDivisibleBy(numbers, divisor);
    std::cout << "Count of numbers divisible by " << divisor << ": " << count << std::endl;

    return 0;
}
