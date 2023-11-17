#include <iostream>
#include <cctype>

int main() {
    char input;
    int sumOfDigits = 0;

    do 
    {
        std::cout << "Enter a character: ";
        std::cin >> input;

        if (std::islower(input)) 
        {
            char upperCase = std::toupper(input);
            std::cout << "Converted to upper case: " << upperCase << std::endl;
        }
  
        else if (std::isdigit(input)) 
        {         
            int digit = input - '0';
            sumOfDigits += digit;
            std::cout << "Current sum of digits: " << sumOfDigits << std::endl;
        }
     
        else if (input != '.') 
        {
            std::cout << "This character is not processed by the program." << std::endl;
        }

    }

    while (input != '.');

    std::cout << "Program terminated." << std::endl;

    return 0;
}







