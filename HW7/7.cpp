#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::cout << "Welcome to the Random Number Generator Game!" << std::endl;

    std::srand((std::time(nullptr)));  

    int highscore = INT_MAX;
    bool playAgain = 1;

    while (playAgain != -1) {
        const int GeneratingRange = 50;
        const int targetNumber = std::rand() % (GeneratingRange + 1);
        int attempts = 0;

        

        std::cout << "I've selected a number between 0 and 50. Try to guess it!" << std::endl;

        while (1) {
            int userGuess;
            std::cout << "Your guess: ";
            std::cin >> userGuess;
            attempts++;

            if (userGuess == -1) {
                std::cout << "Thanks for playing! Goodbye." << std::endl;
                return 0;
            }
            else if (userGuess > 50) {
                std::cout << "Your number is too high. Please enter a number between 0 and 50." << std::endl;
            }
            else if (userGuess < -1) {
                std::cout << "Your number is too less. Please enter a number between 0 and 50." << std::endl;
            }
            if (userGuess == targetNumber) {
                std::cout << "Congratulations! You guessed the correct number in " << attempts << " attempts." << std::endl;

                if (attempts < highscore) {
                    highscore = attempts;
                    std::cout << "New highscore! Best attempts: " << highscore << std::endl;
                }
                else {
                    std::cout << "Attempts in this game: " << attempts << std::endl;
                    std::cout << "Highscore: " << highscore << std::endl;
                }

                break;
            }
            else if (userGuess < targetNumber - 10) {
                std::cout << "Too way less. Try higher." << std::endl;
            }
            else if (userGuess >= targetNumber - 10 && userGuess <= targetNumber - 1) {
                std::cout << "Too less! Try a little higher." << std::endl;
            }
            else if (userGuess > targetNumber + 10) {
                std::cout << "Too way much. Try less." << std::endl;
            }
            else if (userGuess >= targetNumber + 1 && userGuess <= targetNumber + 10) {
                std::cout << "Too much! Try a little less." << std::endl;
            }
        }
      
      
       
    }

    std::cout << "Thanks for playing! Goodbye." << std::endl;

    return 0;
}

