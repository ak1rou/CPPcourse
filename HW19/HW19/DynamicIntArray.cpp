#include "DynamicIntArray.h"
#include <iostream>

DynamicIntArray::DynamicIntArray() : size(0), array(nullptr) {}

DynamicIntArray::DynamicIntArray(std::size_t size) : size(size), array(new int[size]) {}

DynamicIntArray::DynamicIntArray(const DynamicIntArray& other) : size(other.size), array(new int[other.size])
{
    std::copy(other.array, other.array + size, array);
}

DynamicIntArray::~DynamicIntArray() 
{
    delete[] array;
}

DynamicIntArray& DynamicIntArray::operator=(const DynamicIntArray& other)
{
    if (this != &other)
    {
        delete[] array;
        size = other.size;
        array = new int[size];
        std::copy(other.array, other.array + size, array);
    }
    return *this;
}

int& DynamicIntArray::operator[](std::size_t index)
{
    if (index >= size)
    {
        std::cerr << "Index out of bounds!" << std::endl;
        throw std::out_of_range("Index out of bounds");
    }
    return array[index];
}

void DynamicIntArray::setSize(std::size_t newSize) 
{
    delete[] array;
    size = newSize;
    array = new int[size];
}

std::size_t DynamicIntArray::getSize() const 
{
    return size;
}

void DynamicIntArray::clear()
{
    delete[] array;
    size = 0;
    array = nullptr;
}

void DynamicIntArray::push_back(int element)
{
    int* newArray = new int[size + 1];
    std::copy(array, array + size, newArray);
    newArray[size] = std::move(element);  

    delete[] array;
    array = newArray;
    size++;
}



