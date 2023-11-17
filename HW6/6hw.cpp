#include <iostream>

int main() {
    
    double a1, d;
    int n;

    std::cout << "Enter the first element of the arithmetic progression: ";
    std::cin >> a1;

    std::cout << "Enter the common difference of the arithmetic progression: ";
    std::cin >> d;

    std::cout << "Enter the number of the last element of the arithmetic progression: ";
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        double currentElement = a1 + i * d;
        std::cout << currentElement << " ";
    }

    return 0;
}
