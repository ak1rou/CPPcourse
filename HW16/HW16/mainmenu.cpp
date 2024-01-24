#include "mainmenu.h"
#include <iostream>
#include <vector>
#include <limits>

void displayMainMenu() {
    std::cout << "Main Menu\n";
    std::cout << "1. Add Player\n";
    std::cout << "2. Remove Player\n";
    std::cout << "3. Display Team Info\n";
    std::cout << "0. Exit\n";
}

void displayPlayerInfo(const Player& player) {
    std::cout << "\nPlayer Information:\n";
    player.printPlayerInfo();
}

PlayerClass choosePlayerClass() {
    int choice;
    do {
        std::cout << "Choose player class:\n";
        std::cout << "1. Assault\n";
        std::cout << "2. Support\n";
        std::cout << "3. Sniper\n";
        std::cout << "4. Medic\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice >= 1 && choice <= 4) {
            return static_cast<PlayerClass>(choice - 1);
        }
        else {
            std::cout << "Invalid choice. Please enter a valid option.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (true);
}

std::unique_ptr<Weapon> createWeapon() {
    std::string name;
    int damage, range;

    do {
        std::cout << "Enter weapon name: ";
        std::cin >> name;

        std::cout << "Enter weapon damage: ";
        std::cin >> damage;

        std::cout << "Enter weapon range: ";
        std::cin >> range;

        if (damage >= 1 && range >= 2) {
            return std::make_unique<Weapon>(name, damage, range);
        }
        else {
            std::cout << "Invalid choice. Please enter valid values for damage and range.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (true);
}

std::unique_ptr<Player> createPlayer(const std::string& playerName, int playerHealth, PlayerClass playerClass, Weapon* playerWeapon) {
    std::unique_ptr<Player> newPlayer = std::make_unique<Player>(playerName, playerHealth, playerClass);

    if (playerWeapon) {
        newPlayer->setWeapon(playerWeapon);
    }

    return newPlayer;
}

bool askForWeapon() {
    int weaponChoice;
    do {
        std::cout << "Do you want to give a weapon to the player? (1. Yes, 2. No): ";
        std::cin >> weaponChoice;

        if (std::cin.fail() || (weaponChoice != 1 && weaponChoice != 2)) {
            std::cout << "Invalid choice. Please enter a valid option (1 or 2).\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            return weaponChoice == 1;
        }
    } while (true);
}

Team* chooseTeam(Team& direTeam, Team& radiantTeam) {
    int teamChoice;
    do {
        std::cout << "Choose team for the player (1. Dire, 2. Radiant): ";
        std::cin >> teamChoice;

        if (std::cin.fail() || (teamChoice != 1 && teamChoice != 2)) {
            std::cout << "Invalid choice. Please enter a valid option (1 or 2).\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            break;
        }
    } while (true);

    return (teamChoice == 1) ? &direTeam : &radiantTeam;
}

void handleAddPlayer(std::vector<Player>& players, Team& direTeam, Team& radiantTeam) {
    std::string playerNameInput;
    int playerHealthInput;
    PlayerClass playerClassInput;
    std::unique_ptr<Weapon> playerWeapon;

    Team* selectedTeam = chooseTeam(direTeam, radiantTeam);

    if (askForWeapon()) {
        playerWeapon = createWeapon();
    }

    std::cout << "Enter player name: ";
    std::cin >> playerNameInput;

    std::cout << "Enter player health: ";
    std::cin >> playerHealthInput;

    playerClassInput = choosePlayerClass();

    std::unique_ptr<Player> newPlayer = createPlayer(playerNameInput, playerHealthInput, playerClassInput, playerWeapon.get());

    selectedTeam->addPlayer(newPlayer.get());
    players.push_back(*newPlayer.release());
}

void handleRemovePlayer(std::vector<Player>& players, Team& direTeam, Team& radiantTeam)
{
    if (players.empty()) {
        std::cout << "No players to remove.\n";
        return;
    }

    std::cout << "Choose player to remove:\n";
    for (size_t i = 0; i < players.size(); ++i) {
        std::cout << i + 1 << ". ";
        displayPlayerInfo(players[i]);
    }

    int choice;
    std::cout << "Enter the number of the player to remove: ";
    std::cin >> choice;

    if (choice >= 1 && static_cast<size_t>(choice) <= players.size()) {
        Player* playerToRemove = &players[choice - 1];
        direTeam.removePlayer(playerToRemove);
        radiantTeam.removePlayer(playerToRemove);

        players.erase(players.begin() + choice - 1);
        delete playerToRemove;
        std::cout << "Player removed.\n";
    }
    else {
        std::cout << "Invalid choice. No player removed.\n";
    }
}