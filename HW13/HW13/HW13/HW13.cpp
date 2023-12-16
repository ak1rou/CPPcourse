#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

const std::string WORD_DATABASE_FILE = "word_database.txt";
std::vector<std::string> wordDatabase = { "biker", "loser", "crown", "party", "disco", "mommy", "daddy", "grand", "sharp", "prism", "month", "hello", "cocon", "speak" };
const std::string WORD_OF_THE_DAY_FILE = "word_of_the_day_status.txt";

std::vector<std::string> loadWordDatabase()
{
    std::vector<std::string> wordDatabase;

    std::ifstream file(WORD_DATABASE_FILE);
    if (!file.is_open())
    {
        std::ofstream createFile(WORD_DATABASE_FILE);
        createFile.close();
        file.open(WORD_DATABASE_FILE);
    }

    std::string word;
    while (std::getline(file, word, ','))
    {
        word.erase(std::remove_if(word.begin(), word.end(), ::isspace), word.end());
        if (!word.empty())
        {
            wordDatabase.push_back(word);
        }
    }

    file.close();
    return wordDatabase;
}

void saveWordDatabase(const std::vector<std::string>& wordDatabase)
{
    std::ofstream file(WORD_DATABASE_FILE);
    if (file.is_open())
    {
        for (const auto& word : wordDatabase)
        {
            file << word << ",";
        }
        file.close();
    }
}

std::string generateWordOfTheDay(const std::vector<std::string>& wordDatabase)
{
    if (wordDatabase.empty())
    {
        return "";
    }

    std::size_t randomIndex = std::rand() % wordDatabase.size();

    std::string word = wordDatabase[randomIndex];

    return word;
}

std::string getRandomWord(const std::vector<std::string>& wordDatabase)
{
    if (wordDatabase.empty())
    {
        return "";
    }

    std::size_t randomIndex = std::rand() % wordDatabase.size();

    std::string word = wordDatabase[randomIndex];

    return word;
}

bool checkGuess(const std::string& secretWord, const std::string& guessedWord)
{
    return secretWord == guessedWord;
}

void saveWordOfTheDayStatus(bool wordOfTheDayGuessed, const std::string& todayDate)
{
    std::ofstream file(WORD_OF_THE_DAY_FILE);
    if (file.is_open())
    {
        file << std::boolalpha << wordOfTheDayGuessed << "\n" << todayDate;
        file.close();
    }
}

bool loadWordOfTheDayStatus(std::string& storedDate)
{
    std::ifstream file(WORD_OF_THE_DAY_FILE);
    if (file.is_open())
    {
        bool wordOfTheDayGuessed;
        file >> std::boolalpha >> wordOfTheDayGuessed >> storedDate;
        file.close();
        return wordOfTheDayGuessed;
    }
    return false;
}

bool isSameDay(const std::string& storedDate, const std::string& currentDate)
{
    return storedDate == currentDate;
}

std::string getTodayDate()
{
    std::time_t now = std::time(nullptr);
    char buffer[11];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", std::localtime(&now));
    return buffer;
}

void playWordleGame(const std::string& secretWord, bool& wordOfTheDayGuessed, std::string& storedDate)
{
    std::string todayDate = getTodayDate();

    if (wordOfTheDayGuessed && isSameDay(storedDate, todayDate))
    {
        std::cout << "Word of the day has already been guessed. Come back tomorrow!" << std::endl;
        return;
    }

    std::map<std::string, bool> guessedWords;
    int attempts = 1;
    std::string guessedWord(secretWord.length(), '*');

    while (true)
    {
        std::cout << "RESULT: " << guessedWord << std::endl;

        std::string userGuess;
        std::cout << "ENTER: ";
        std::cin >> userGuess;

        if (userGuess.length() < 5)
        {
            std::cout << "Please enter a word with at least 5 characters." << std::endl;
            continue;
        }

        if (checkGuess(secretWord, userGuess))
        {
            std::cout << "That's right!" << std::endl;
            std::cout << "You made " << attempts << " tries!" << std::endl;
            guessedWords[secretWord] = true;
            wordOfTheDayGuessed = true;
            saveWordOfTheDayStatus(wordOfTheDayGuessed, todayDate);
            break;
        }
        else
        {
            for (std::size_t i = 0; i < secretWord.length(); ++i)
            {
                if (secretWord[i] == userGuess[i])
                {
                    guessedWord[i] = std::toupper(userGuess[i]);
                }
                else if (secretWord.find(userGuess[i]) != std::string::npos)
                {
                    guessedWord[i] = std::tolower(userGuess[i]);
                }
                else
                {
                    guessedWord[i] = '*';
                }
            }
            attempts++;
        }
    }
}

int main()
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    std::string storedDate;
    std::vector<std::string> wordDatabase = loadWordDatabase();
    bool wordOfTheDayGuessed = loadWordOfTheDayStatus(storedDate);

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
            std::string wordOfTheDay = generateWordOfTheDay(wordDatabase);
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
            std::cout << "Thank you for playing! Goodbye)";
            return 0;
        default:
            std::cout << "Invalid choice. Try again." << std::endl;
        }
    }

    return 0;
}
