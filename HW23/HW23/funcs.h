#pragma once
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <stack>
#include <unordered_set>
#include <unordered_map>

struct Node
{
    int data;
    Node* next;
};

unsigned int uniqueWordsCount(const std::string& line);
std::vector<std::string> mostOccurredWord(const std::string& line);
bool isBalanced(const std::string& expression);
bool hasCycle(Node* head);


