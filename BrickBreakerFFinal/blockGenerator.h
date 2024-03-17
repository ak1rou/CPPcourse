#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class BlockGenerator 
{
public:
    static std::vector<std::pair<sf::Vector2f, std::string>> generateBlocks(int maxBlocks, float minY, float maxY, float offsetX);
};
