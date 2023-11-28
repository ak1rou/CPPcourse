#include <iostream>

int main()
{
    int size;

    std::cout << "Enter the size: ";
    std::cin >> size;

    std::cout << "a." << std::endl;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size - i; ++j) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    std::cout << "b." << std::endl;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < i; ++j) {
            std::cout << " ";
        }
        for (int k = 0; k < size - i; ++k) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    std::cout << "c." << std::endl;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    std::cout << "d." << std::endl;
    for (int i = 0; i < size; ++i) {

        for (int j = 0; j < i; ++j) {
            std::cout << " ";
        }

        for (int k = 0; k < size; ++k) {
            std::cout << "*";
        }

        std::cout << std::endl;
    }

    std::cout << "e." << std::endl;
    for (int i = 1; i <= size; ++i) {
        int startValue = (i % 2 == 0) ? 1 : 0;
        for (int k = 1; k <= i; ++k) {
            std::cout << (startValue + (k % 2)) % 2;
        }
        std::cout << std::endl;
    }

    return 0;
}