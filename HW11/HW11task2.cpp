#include <iostream>

enum class SortingDirection
{
    ascending,
    descending
};

bool isSorted(const int* arr, int size, SortingDirection direction)
{
    if (size <= 1) {
        return true;
    }

    if (direction == SortingDirection::ascending) {
        for (int i = 0; i < size - 1; ++i) {
            if (arr[i] > arr[i + 1]) {
                return false;
            }
        }
    }
    else if (direction == SortingDirection::descending) {
        for (int i = 0; i < size - 1; ++i) {
            if (arr[i] < arr[i + 1]) {
                return false;
            }
        }
    }
    else {
        std::cerr << "Invalid sorting direction." << std::endl;
        return false;
    }

    return true;
}

int main2() 
{
    const int ascendingArr[] = { 1, 2, 3, 4, 5 };
    const int descendingArr[] = { 5, 4, 3, 2, 1 };
    int numOfArr = 0;

    std::cout << "Enter number of array (1 or 2): ";
    std::cin >> numOfArr;

    if (numOfArr == 1)
    {
        if (isSorted(ascendingArr, 5, SortingDirection::ascending))
        {
            std::cout << "The array is sorted in ascending order." << std::endl;
        }
    }
    else if (numOfArr == 2)
    {
        if (isSorted(descendingArr, 5, SortingDirection::descending))
        {
            std::cout << "The array is sorted in descending order." << std::endl;
        }
    }
    if (numOfArr != 1 && numOfArr != 2)
    {
        std::cout << "Invalid number of array.";
    }
    return 0;
}
