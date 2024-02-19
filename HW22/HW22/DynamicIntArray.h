#pragma once
#include <cstdlib>
#include <algorithm> 
#include <stdexcept>

template <typename Type>
class DynamicIntArray
{
public:
    DynamicIntArray();

    DynamicIntArray(std::size_t size);

    DynamicIntArray(const DynamicIntArray& other); 

    ~DynamicIntArray();

    DynamicIntArray& operator=(const DynamicIntArray& other); 

    Type& operator[](std::size_t index);

    void setSize(std::size_t newSize);
    std::size_t getSize() const;

    void clear();

    void push_back(Type element);

    void pop_back();    
    Type back() const;   

    void reserve(std::size_t reservedSpace);
    std::size_t getCapacity() const;    

    void shrinkToFit();

    bool operator==(const DynamicIntArray& other) const;    

private:
    Type* array;
    std::size_t size;
    std::size_t capacity;
};


