#include <iostream>

int main() {
    int n;

    
    std::cout << "Enter the number of the Fibonacci sequence element: ";
    std::cin >> n;

    
    int fib1 = 1, fib2 = 1, fibN = 0;

    if (n == 1 || n == 2) 
    {
        fibN = 1;
    }
    else
    {
        for (int i = 3; i <= n; ++i) {
            fibN = fib1 + fib2;
            fib1 = fib2;
            fib2 = fibN;
        }
    }
    std::cout << "The Fibonacci sequence element at position " << n << " is: " << fibN << std::endl;
    
   

    return 0;
}
