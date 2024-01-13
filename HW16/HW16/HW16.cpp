#include <iostream>
#include <vector>
#include <limits>
#include "Player.h"
#include "Team.h"
#include "Rectangle.h"

void displayMainMenu();
void displayPlayerInfo(const Player& player);
PlayerClass choosePlayerClass();
Weapon* createWeapon();
void handleAddPlayer(std::vector<Player>& players, Team& direTeam, Team& radiantTeam);
void handleRemovePlayer(std::vector<Player>& players, Team& direTeam, Team& radiantTeam);

int main() 
{
    Rectangle rectangle1;
    Rectangle rectangle2(3.0, 4.0);
    Rectangle rectangle3(5.0, 2.5);

    std::cout << "Rectangle 1: Area = " << rectangle1.getArea() << ", Perimeter = " << rectangle1.getPerimeter() << std::endl;
    std::cout << "Rectangle 2: Area = " << rectangle2.getArea() << ", Perimeter = " << rectangle2.getPerimeter() << std::endl;
    std::cout << "Rectangle 3: Area = " << rectangle3.getArea() << ", Perimeter = " << rectangle3.getPerimeter() << std::endl;

    std::vector<Player> players;
    Team direTeam("Dire");
    Team radiantTeam("Radiant");

    int choice;
    do {
        displayMainMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            handleAddPlayer(players, direTeam, radiantTeam);
            break;
        case 2:
            handleRemovePlayer(players, direTeam, radiantTeam);
            break;
        case 3:
            direTeam.printTeamInfo();
            radiantTeam.printTeamInfo();
            break;
        case 0:
            std::cout << "Exiting the program...\n";
            break;
        default:
            std::cout << "Invalid choice. Please enter a valid option.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    } while (choice != 0);

    return 0;
}
