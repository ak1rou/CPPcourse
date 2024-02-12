#include "funcs.h"

unsigned int uniqueWordsCount(const std::string& line)
{
    std::istringstream iss(line);
    std::unordered_set<std::string> uniqueWords;
    std::string word;

    while (iss >> word)
    {
        uniqueWords.insert(word);
    }

    return uniqueWords.size();
}

std::vector<std::string> mostOccurredWord(const std::string& line) {
    std::istringstream iss(line);
    std::unordered_map<std::string, int> wordCount;
    std::vector<std::string> mostOccurredWords;
    std::string word;

    while (iss >> word) {
        wordCount[word]++;
    }

    int maxCount = 0;
    for (const auto& entry : wordCount) {
        if (entry.second > maxCount) {
            maxCount = entry.second;
            mostOccurredWords = { entry.first };
        }
        else if (entry.second == maxCount) {
            mostOccurredWords.push_back(entry.first);
        }
    }

    return mostOccurredWords;
}
bool isBalanced(const std::string& expression)
{
    std::stack<char> brackets;
    std::unordered_set<char> openingBrackets = { '{', '(', '[' };
    std::unordered_map<char, char> bracketPairs = { {'}', '{'}, {')', '('}, {']', '['} };

    for (char ch : expression)
    {
        if (openingBrackets.find(ch) != openingBrackets.end()) 
        {
            brackets.push(ch);
        }
        else if (bracketPairs.find(ch) != bracketPairs.end())
        {
            if (brackets.empty() || brackets.top() != bracketPairs[ch]) 
            {
                return false;
            }
            brackets.pop();
        }
    }

    return brackets.empty();
}

bool hasCycle(Node* head)
{
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) 
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return true; 
        }
    }

    return false;
}
