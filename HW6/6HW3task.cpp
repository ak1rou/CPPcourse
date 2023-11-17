#include <iostream>

int main() {
    int n;
  
    std::cout << "Enter a positive integer: ";
    std::cin >> n;
 
    if (n < 0) {
        std::cout << "Please enter a positive integer." << std::endl;
        return 1;  
    }
 
    unsigned long long factorial = 1;
    for (int i = 1; i <= n; ++i) {
        factorial *= i;
    }

    std::cout << "The factorial of " << n << " is: " << factorial << std::endl;

    return 0;
}
// при введенні значення >65 видає 0 в результаті (наскільки я зрозумів через переповенення лонг лонг) і я не знайшов як це пофіксити(( 