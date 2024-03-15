#include "InputManager.h"

void InputManager::processInput(sf::RenderWindow& window, sf::Sprite& paddle) 
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    float mouseX = static_cast<float>(mousePosition.x);

    if (mouseX < 0)
    {
        mouseX = 0;
    }
    else if (mouseX > window.getSize().x - paddle.getGlobalBounds().width) 
    {
        mouseX = window.getSize().x - paddle.getGlobalBounds().width;
    }

    paddle.setPosition(mouseX, paddle.getPosition().y);
}
