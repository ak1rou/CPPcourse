#include "BlockGenerator.h"
#include <random>
#include <SFML/Graphics.hpp>

std::vector<std::pair<sf::Vector2f, std::string>> BlockGenerator::generateBlocks(int maxBlocks, float minY, float maxY, float offsetX) 
{
    std::vector<std::pair<sf::Vector2f, std::string>> blockPositions;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> disY(minY, maxY);

    float prevX = 0.f;

    for (int i = 0; i < maxBlocks; ++i)
    {
        std::uniform_real_distribution<float> disX(prevX + 15.f, prevX + 45.f);
        float xPos;
        float yPos;
        bool validPosition = false;

        while (!validPosition)
        {
            xPos = disX(gen);
            yPos = disY(gen);
            validPosition = true;

            sf::FloatRect blockRect(xPos, yPos, 45.f, 45.f);
            for (const auto& block : blockPositions) {
                sf::FloatRect existingBlockRect(block.first.x, block.first.y, 45.f, 45.f);
                if (blockRect.intersects(existingBlockRect)) {
                    validPosition = false;
                    break;
                }
            }
            prevX = xPos;
        }

        std::uniform_int_distribution<int> disColor(0, 4);
        int colorIndex = disColor(gen);
        std::string color;
        int hits = 0;
        switch (colorIndex)
        {
        case 0:
            color = "blueBrick";
            hits = 1;
            break;
        case 1:
            color = "purpleBrick";
            hits = 2;
            break;
        case 2:
            color = "greenBrick";
            hits = 3;
            break;
        case 3:
            color = "yellowBrick";
            hits = 4;
            break;
        case 4:
            color = "redBrick";
            hits = 5;
            break;
        }

        blockPositions.emplace_back(sf::Vector2f(xPos, yPos), color);
    }

    return blockPositions;
}
