#include <iostream>

void swapByReferences(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swapByPointers(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool calculateSum(const double* arr, int arrSize, double& sum) 
{
    if (arrSize > 0)
    {
        sum = 0;
        for (int i = 0; i < arrSize; i++) 
        {
            sum += arr[i];
        }
        return true;
    }
    else
    {
        return false;
    }
}

bool find(const int* arr, int size, int elem) 
{

    if (size <= 0)
    {
        return false;
    }

    const int* ptr = arr;

    while (ptr < arr + size)
    {
        if (*ptr == elem)
        {
            return true;
        }
        ptr++;
    }

    return false;
}
