#include <iostream>

const int ROWS = 4;
const int COLUMNS = 4;

void traverseArray1(int arr[ROWS][COLUMNS])
{
    for (int col = 0; col < COLUMNS; ++col)
    {
        for (int row = 0; row < ROWS; ++row)
        {
            std::cout << arr[row][col] << "  ";
        }
    }
}

void traverseArray2(int arr[ROWS][COLUMNS])
{
    for (int row = ROWS - 1; row >= 0; --row)
    {
        if (row % 2 == 0)
        {
            for (int col = COLUMNS - 1; col >= 0; --col)
            {
                std::cout << arr[row][col] << "  ";
            }
        }
        else
        {
            for (int col = 0; col < COLUMNS; ++col)
            {
                std::cout << arr[row][col] << "  ";
            }
        }
    }
}

int main() 
{
    int arr[ROWS][COLUMNS]
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int numOfArr = 0;

    std::cout << "Enter number of way to traverse an array (1 or 2): ";
    std::cin >> numOfArr;

    if (numOfArr == 1)
    {
            traverseArray1(arr);       
    }

    else if (numOfArr == 2)
    {
         traverseArray2(arr);      
    }

    if (numOfArr != 1 && numOfArr != 2)
    {
        std::cout << "Invalid number of way to traverse an array.";
    }

    return 0;
}

