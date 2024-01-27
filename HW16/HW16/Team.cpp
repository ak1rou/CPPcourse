#include "Team.h"
#include <iostream>

Team::Team(const std::string& name) : teamName(name) {}

bool Team::addPlayer(Player* p)
{
    for (Player* player : players)
    {
        if (player == p)
        {
            std::cout << "Player is already in the team." << std::endl;
            return false;
        }
    }

    if (players.size() >= MAX_PLAYERS)
    {
        std::cout << "Team is full. Cannot add more players." << std::endl;
        return false;
    }

    players.push_back(p);
    std::cout << "Player added to the team." << std::endl;
    return true;
}

bool Team::removePlayer(Player* p)
{
    auto it = std::find(players.begin(), players.end(), p);

    if (it != players.end())
    {
        players.erase(it);
        std::cout << "Player removed from the team." << std::endl;
        return true;
    }
    else
    {
        std::cerr << "Error: Player is not in the team." << std::endl;
        return false;
    }
}

void Team::printTeamInfo() const
{
    std::cout << "Team: " << teamName << ", Number of Players: " << players.size() << std::endl;

    for (const Player* player : players)
    {
        if (player)
        {
            player->printPlayerInfo();
        }
    }
}
