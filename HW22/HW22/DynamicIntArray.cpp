#include "DynamicIntArray.h"

template class DynamicIntArray<int>;

template <typename Type>
DynamicIntArray<Type>::DynamicIntArray() : array(nullptr), size(0) {}

template <typename Type>
DynamicIntArray<Type>::DynamicIntArray(std::size_t size) : size(size)
{
    array = new Type[size]();
}

template <typename Type>
DynamicIntArray<Type>::DynamicIntArray(const DynamicIntArray<Type>& other)
    : array(new Type[other.size]), size(other.size)
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
        array = new Type[other.size];
        size = other.size;
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
    Type* newArray = new Type[newSize]();
    std::size_t minSize = std::min(size, newSize);
    std::copy(array, array + minSize, newArray);
    delete[] array;
    array = newArray;
    size = newSize;
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
    array = nullptr;
    size = 0;
}

template <typename Type>
void DynamicIntArray<Type>::push_back(Type element)
{
    setSize(size + 1);
    array[size - 1] = element;
}

template <typename Type>
void DynamicIntArray<Type>::pop_back()
{
    if (size > 0)
    {
        setSize(size - 1);
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
    if (reservedSpace > size)
    {
        Type* newArray = new Type[reservedSpace]();
        std::copy(array, array + size, newArray);
        delete[] array;
        array = newArray;
    }
}

template <typename Type>
std::size_t DynamicIntArray<Type>::getCapacity() const
{
    return size;
}

template <typename Type>
void DynamicIntArray<Type>::shrinkToFit()
{
    if (size > 0)
    {
        Type* newArray = new Type[size]();
        std::copy(array, array + size, newArray);
        delete[] array;
        array = newArray;
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

