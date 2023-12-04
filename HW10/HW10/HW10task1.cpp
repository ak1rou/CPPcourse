#include <iostream>
#include "funcs.h"

int main3()
{
    int x, y;

    std::cout << "Enter the first integer: ";
    std::cin >> x;

    std::cout << "Enter the second integer: ";
    std::cin >> y;

 
        swap(x, y);

        std::cout << "Swap using references: x = " << x << ", y = " << y << std::endl;
    
     
        swap(x, y);

        std::cout << "Swap using pointers: x = " << x << ", y = " << y << std::endl;
    
    return 0;
}