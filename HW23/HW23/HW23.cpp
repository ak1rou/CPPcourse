#include "funcs.h"
#include <iostream>

int main()
{
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    std::cout << "1. Unique Words Count: " << uniqueWordsCount(input) << std::endl;
    std::cout << "2. Most Occurred Word(s): ";
    std::vector<std::string> mostOccurred = mostOccurredWord(input);
    for (const auto& word : mostOccurred) 
    {
        std::cout << word << " ";
    }
    std::cout << std::endl;
    std::cout << "3. Balanced Brackets: " << (isBalanced(input) ? "OK" : "NOT OK") << std::endl;

    Node* head = new Node{ 1, nullptr };
    head->next = new Node{ 2, nullptr };
   //for cycle head->next->next = new Node{ 3, head };

    std::cout << "4. Has Cycle in Linked List: " << (hasCycle(head) ? "YES" : "NO") << std::endl;

    delete head->next->next;
    delete head->next;
    delete head;

    return 0;
}
