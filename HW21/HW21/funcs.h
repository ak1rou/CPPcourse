#pragma once
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

bool compareByLength(const std::string& str1, const std::string& str2);

class LengthComparator
{
public:
    bool operator()(const std::string& str1, const std::string& str2) const;
};

unsigned int countDivisibleBy(const std::vector<int>& vec, int number);

