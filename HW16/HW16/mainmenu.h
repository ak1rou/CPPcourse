#pragma once

#include "Player.h"
#include "Team.h"
#include "Rectangle.h"

void displayMainMenu();
void displayPlayerInfo(const Player& player);
PlayerClass choosePlayerClass();
Weapon* createWeapon();
void handleAddPlayer(std::vector<Player>& players, Team& direTeam, Team& radiantTeam);
void handleRemovePlayer(std::vector<Player>& players, Team& direTeam, Team& radiantTeam);
