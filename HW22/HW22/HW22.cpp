#include <iostream>
#include "DynamicIntArray.h"

int main()
{
    DynamicIntArray<int> m_container;
    m_container.reserve(4);
    m_container.push_back(25);
    m_container.push_back(30);
    m_container.push_back(10);
    m_container.push_back(39);

    std::cout << "Current Size: " << m_container.getSize() << std::endl;
    std::cout << "Current Capacity: " << m_container.getCapacity() << std::endl;

    m_container.push_back(55);

    std::cout << "After adding 55:" << std::endl;
    std::cout << "Current Size: " << m_container.getSize() << std::endl;
    std::cout << "Current Capacity: " << m_container.getCapacity() << std::endl;

    m_container.pop_back();
    
    std::cout << "After popping back:" << std::endl;
    std::cout << "Current Size: " << m_container.getSize() << std::endl;
    std::cout << "Current Capacity: " << m_container.getCapacity() << std::endl;

    return 0;
}

