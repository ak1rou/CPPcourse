#include "funcs.h"

const std::string WORD_DATABASE_FILE = "word_database.txt";
const std::string WORD_OF_THE_DAY_FILE = "word_of_the_day_status.txt";
std::vector<std::string> wordDatabase;

std::vector<std::string> loadWordDatabase()
{
    std::vector<std::string> loadedWords;

    std::ifstream file(WORD_DATABASE_FILE);
    if (!file.is_open())
    {
        std::cerr << "Error: Unable to open file for reading." << std::endl;
        return loadedWords;
    }

    std::string word;
    while (std::getline(file, word, ','))
    {
        loadedWords.push_back(word);
    }

    return loadedWords;
}

void saveWordDatabase(const std::vector<std::string>& words)
{
    std::ofstream file(WORD_DATABASE_FILE);
    if (!file.is_open())
    {
        std::cerr << "Error: Unable to open file for writing." << std::endl;
        return;
    }

    for (const auto& word : words)
    {
        file << word << ",";
    }
    file.close();
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

void saveWordOfTheDayStatus(bool wordOfTheDayGuessed, const std::string& todayDate)
{
    std::ofstream file(WORD_OF_THE_DAY_FILE);
    if (file.is_open())
    {
        file << std::boolalpha << wordOfTheDayGuessed << " " << todayDate;
        file.close();
    }
}

bool loadWordOfTheDayStatus(bool& wordOfTheDayGuessed, std::string& storedDate, bool& wordOfTheDayGuessedInSession)
{
    std::ifstream file(WORD_OF_THE_DAY_FILE);
    if (file.is_open())
    {
        file >> std::boolalpha >> wordOfTheDayGuessed >> storedDate;
        file.close();

        wordOfTheDayGuessedInSession = false;

        return true;
    }

    wordOfTheDayGuessedInSession = false;
    return false;
}


std::string getTodayDate()
{
    std::time_t now = std::time(nullptr);
    char buffer[11];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", std::localtime(&now));
    return buffer;
}

bool checkGuess(const std::string& secretWord, const std::string& guessedWord, bool& wordOfTheDayGuessed, std::string& todayDate, int& attempts)
{
    std::string upperSecretWord = secretWord;
    std::transform(upperSecretWord.begin(), upperSecretWord.end(), upperSecretWord.begin(), ::toupper);

    std::string displayResult(secretWord.length(), '*');

    bool fullyGuessed = true;

    std::vector<std::size_t> matchedPositions(secretWord.length(), std::string::npos);

    for (std::size_t i = 0; i < guessedWord.length(); ++i)
    {
        char guessedChar = std::toupper(guessedWord[i]);

        auto secretIt = std::find(upperSecretWord.begin(), upperSecretWord.end(), guessedChar);

        while (secretIt != upperSecretWord.end())
        {
            std::size_t position = std::distance(upperSecretWord.begin(), secretIt);

            if (matchedPositions[position] == std::string::npos)
            {
                if (i == position)
                {
                    displayResult[position] = guessedChar;
                }
                else
                {
                    fullyGuessed = false;
                    displayResult[i] = std::tolower(guessedChar);
                }

                matchedPositions[position] = i;
                break;
            }
            else
            {
                secretIt = std::find(secretIt + 1, upperSecretWord.end(), guessedChar);
            }
        }

        if (secretIt == upperSecretWord.end())
        {
            fullyGuessed = false;
        }
    }

    std::cout << "RESULT: " << displayResult << std::endl;

    return fullyGuessed;

    if (fullyGuessed)
    {
        std::cout << "That's right!" << std::endl;
        std::cout << "You made " << attempts << " tries!" << std::endl;
    }
}

bool isSameDay(const std::string& storedDate, const std::string& currentDate)
{
    return storedDate == currentDate;
}

void playWordleGame(const std::string& secretWord, bool& wordOfTheDayGuessed, std::string& storedDate)
{
    int attempts = 1;
    std::string todayDate = getTodayDate();

    if (isSameDay(storedDate, todayDate))
    {
        if (wordOfTheDayGuessed)
        {
            std::cout << "Word of the day has already been guessed. Come back tomorrow!" << std::endl;
            return;
        }
    }

    std::string guessedWord(secretWord.length(), '*');
    std::cout << "RESULT: " << guessedWord << std::endl;

    while (true)
    {
        std::string userGuess;
        std::cout << "ENTER: ";
        std::cin >> userGuess;

        if (userGuess == "0")
        {
            std::cout << "Exiting the game...\n";
            break;
        }

        if (userGuess.length() != secretWord.length())
        {
            std::cout << "Please enter a word with " << secretWord.length() << " characters." << std::endl;
            continue;
        }

        std::transform(userGuess.begin(), userGuess.end(), userGuess.begin(), ::toupper);

        if (checkGuess(secretWord, userGuess, wordOfTheDayGuessed, todayDate, attempts))
        {
            wordOfTheDayGuessed = true;
            saveWordOfTheDayStatus(wordOfTheDayGuessed, todayDate);

            std::cout << "That's right!" << std::endl;
            std::cout << "You made " << attempts << " tries!" << std::endl;
            break;
        }
        else
        {
            attempts++;
        }
    }
}

UserChoice convertIntToChoice(int rawInput)
{
    switch (rawInput)
    {
    case 1:
        return UserChoice::WordOfDay;
    case 2:
        return UserChoice::RandomWord;
    case 0:
        return UserChoice::Exit;
    default:
        return UserChoice::Exit;
    }
}
