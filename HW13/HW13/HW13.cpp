#include "funcs.h"

int main()
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    std::string storedDate;
    wordDatabase = loadWordDatabase();
    bool wordOfTheDayGuessed;
    wordDatabase = loadWordDatabase();
    bool loadedStatus = loadWordOfTheDayStatus(wordOfTheDayGuessed, storedDate);

    while (true)
    {
        std::cout << "1 - Wordle of the day\n";
        std::cout << "2 - Random Wordle\n";
        std::cout << "0 - Exit\n";
        std::cout << "Enter: ";

        int choice;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            std::string wordOfTheDay = getRandomWord(wordDatabase);
            if (!wordOfTheDay.empty())
            {
                playWordleGame(wordOfTheDay, wordOfTheDayGuessed, storedDate);
            }
            else
            {
                std::cout << "Already found. Come back tomorrow!" << std::endl;
            }
        }
        break;
        case 2:
        {
            std::string randomWord = getRandomWord(wordDatabase);
            if (!randomWord.empty())
            {
                playWordleGame(randomWord, wordOfTheDayGuessed = false, storedDate);
            }
            else
            {
                std::cout << "No more words in the database. Come back tomorrow!" << std::endl;
            }
        }
        break;
        case 0:
            std::cout << "Thank you for playing! Goodbye)" << std::endl;
            return 0;
        default:
            std::cout << "Invalid choice. Try again." << std::endl;
        }
    }

    return 0;
}