#include "DynamicIntArray.h"

template class DynamicIntArray<int>;

template <typename Type>
DynamicIntArray<Type>::DynamicIntArray() : array(nullptr), size(0), capacity(0) {}

template <typename Type>
DynamicIntArray<Type>::DynamicIntArray(std::size_t size) : size(size), capacity(size)
{
    array = new Type[size]();
}

template <typename Type>
DynamicIntArray<Type>::DynamicIntArray(const DynamicIntArray<Type>& other)
    : array(new Type[other.capacity]), size(other.size), capacity(other.capacity)
{
    std::copy(other.array, other.array + size, array);
}

template <typename Type>
DynamicIntArray<Type>::~DynamicIntArray()
{
    delete[] array;
}

template <typename Type>
DynamicIntArray<Type>& DynamicIntArray<Type>::operator=(const DynamicIntArray<Type>& other)
{
    if (this != &other)
    {
        delete[] array;
        array = new Type[other.capacity];
        size = other.size;
        capacity = other.capacity;
        std::copy(other.array, other.array + size, array);
    }
    return *this;
}

template <typename Type>
Type& DynamicIntArray<Type>::operator[](std::size_t index)
{
    if (index >= size)
    {
        throw std::out_of_range("Index out of bounds");
    }
    return array[index];
}

template <typename Type>
void DynamicIntArray<Type>::setSize(std::size_t newSize)
{
    if (newSize <= capacity)
    {
        size = newSize;
    }
    else
    {
        reserve(newSize);
        size = newSize;
    }
}

template <typename Type>
std::size_t DynamicIntArray<Type>::getSize() const
{
    return size;
}

template <typename Type>
void DynamicIntArray<Type>::clear()
{
    delete[] array;
    size = 0;
}

template <typename Type>
void DynamicIntArray<Type>::push_back(Type element)
{
    if (size >= capacity)
    {
        reserve(capacity == 0 ? 1 : capacity * 2);
    }
    array[size++] = element;
}

template <typename Type>
void DynamicIntArray<Type>::pop_back()
{
    if (size > 0)
    {
        --size;
    }
}

template <typename Type>
Type DynamicIntArray<Type>::back() const
{
    if (size > 0)
    {
        return array[size - 1];
    }
    throw std::out_of_range("Empty array");
}

template <typename Type>
void DynamicIntArray<Type>::reserve(std::size_t reservedSpace)
{
    if (reservedSpace > capacity)
    {
        Type* newArray = new Type[reservedSpace]();
        std::copy(array, array + size, newArray);
        delete[] array;
        array = newArray;
        capacity = reservedSpace;
    }
}

template <typename Type>
std::size_t DynamicIntArray<Type>::getCapacity() const
{
    return capacity;
}

template <typename Type>
void DynamicIntArray<Type>::shrinkToFit()
{
    if (capacity > size)
    {
        Type* newArray = new Type[size]();
        std::copy(array, array + size, newArray);
        delete[] array;
        array = newArray;
        capacity = size;
    }
}

template <typename Type>
bool DynamicIntArray<Type>::operator==(const DynamicIntArray<Type>& other) const
{
    if (size != other.size)
    {
        return false;
    }
    return std::equal(array, array + size, other.array);
}
