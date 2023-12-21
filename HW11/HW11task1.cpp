#include <iostream>

const int ROWS = 3; 
const int COLUMNS = 3; 

bool find(int arr_2d[ROWS][COLUMNS], int toFind)
{
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            if (arr_2d[i][j] == toFind) {
                return true; 
            }
        }
    }
    return false; 
}

int mains()
{
    int arr_2d[ROWS][COLUMNS] {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int toFind = 0;

    std::cout << "Enter element to find in the array: ";
    std::cin >> toFind;

    if (find(arr_2d, toFind)) {
        std::cout << "Element " << toFind << " was found in the array.\n";
    }
    else {
        std::cout << "Element " << toFind << " was not found in the array.\n";
    }

    return 0;
}

