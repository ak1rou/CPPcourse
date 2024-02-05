#include "funcs.h"

bool compareByLength(const std::string& str1, const std::string& str2) 
{
    return str1.length() < str2.length();
}

bool LengthComparator::operator()(const std::string& str1, const std::string& str2) const 
{
    return str1.length() < str2.length();
}

unsigned int countDivisibleBy(const std::vector<int>& vec, int number)
{
    return std::count_if(vec.begin(), vec.end(), [number](int num) 
        {
        return num % number == 0;
        });
}
