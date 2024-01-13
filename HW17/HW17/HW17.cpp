#include "Vector2d.h"

int main() 
{
    Vector2d testVec(1.2f, 5.6f);

    std::cout << "Initial count: " << Vector2d::getCount() << std::endl;

    std::cout << "Vector: " << testVec << std::endl;

    Vector2d newVec;
    std::cout << "Enter new vector (format: x y): ";
    std::cin >> newVec;

    std::cout << "Sum of vectors: " << (testVec.operator+(newVec)) << std::endl;
    std::cout << "Difference of vectors: " << (testVec.operator-(newVec)) << std::endl;

    std::cout << "Vector length: " << testVec() << std::endl;

    std::cout << "Final count: " << Vector2d::getCount() << std::endl;

    return 0;
}
