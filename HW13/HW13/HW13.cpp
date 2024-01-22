#include "funcs.h"

int main()
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    std::string storedDate;
    wordDatabase = loadWordDatabase();
    bool wordOfTheDayGuessed;
    bool wordOfTheDayGuessedInSession = false;
    wordDatabase = loadWordDatabase();
    bool loadedStatus = loadWordOfTheDayStatus(wordOfTheDayGuessed, storedDate, wordOfTheDayGuessedInSession);

    while (true)
    {
        std::cout << "1 - Wordle of the day\n";
        std::cout << "2 - Random Wordle\n";
        std::cout << "0 - Exit\n";
        std::cout << "Enter: ";

        int choice;
        std::cin >> choice;

        UserChoice userChoice = convertIntToChoice(choice);

        switch (userChoice)
        {
        case UserChoice::WordOfDay:
        {
            if (wordOfTheDayGuessedInSession)
            {
                std::cout << "Word of the day has already been guessed. Come back tomorrow!" << std::endl;
            }
            else
            {
                std::string wordOfTheDay = getRandomWord(wordDatabase);
                playWordleGame(wordOfTheDay, wordOfTheDayGuessed, storedDate);
                wordOfTheDayGuessedInSession = true;
            }
        }
        break;
        case UserChoice::RandomWord:
        {
            std::string randomWord = getRandomWord(wordDatabase);
            playWordleGame(randomWord, wordOfTheDayGuessed = false, storedDate);
        }
        break;
        case UserChoice::Exit:
            std::cout << "Thank you for playing! Goodbye)" << std::endl;
            return 0;
        default:
            std::cout << "Invalid choice. Try again." << std::endl;
        }
    }

    return 0;
}