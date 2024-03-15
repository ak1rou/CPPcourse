#pragma once
#include <SFML/Graphics.hpp>

class InputManager
{
public:
    static void processInput(sf::RenderWindow& window, sf::Sprite& paddle);
};