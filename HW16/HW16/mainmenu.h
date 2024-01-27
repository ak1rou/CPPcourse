#pragma once

#include "Player.h"
#include "Team.h"
#include "Rectangle.h"
#include <memory>

void displayMainMenu();
void displayPlayerInfo(const Player& player);
PlayerClass choosePlayerClass();
std::unique_ptr<Weapon> createWeapon();
std::unique_ptr<Player> createPlayer(const std::string& playerName, int playerHealth, PlayerClass playerClass, Weapon* playerWeapon);
bool askForWeapon();
Team* chooseTeam(Team& direTeam, Team& radiantTeam);
void handleAddPlayer(std::vector<Player>& players, Team& direTeam, Team& radiantTeam);
void handleRemovePlayer(std::vector<Player>& players, Team& direTeam, Team& radiantTeam);
