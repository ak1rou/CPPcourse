#pragma once
#include <vector>
#include "Player.h"

#define MAX_PLAYERS 10

class Team
{
private:
    std::string teamName;
    std::vector<Player*> players;

public:
    Team(const std::string& name);
    void removePlayerFromAllTeams(Player* player);
    bool addPlayer(Player* player);
    bool removePlayer(Player* player);
    void printPlayersInfo() const;
    void printTeamInfo() const;
};
