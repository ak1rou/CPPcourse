#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

int main() {
    int n;

    
    std::cout << "Enter a positive integer: ";
    std::cin >> n;

    
    if (n < 0) {
        std::cout << "Please enter a positive integer." << std::endl;
        return 1;  
    }

    
    boost::multiprecision::cpp_int factorial = 1;
    for (int i = 1; i <= n; ++i) {
        factorial *= i;
    }

   
    std::cout << "The factorial of " << n << " is: " << factorial << std::endl;

    return 0;
}

