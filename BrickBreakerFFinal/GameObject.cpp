#include <SFML/Graphics.hpp>
#include "Resources.h"
#include "GameObject.h"

GameObject::GameObject(const std::string& textureName, float x, float y, int collisionsReq) : collisionsRequired(collisionsReq)
{
    sprite.setTexture(Resources::getTexture(textureName));
    sprite.setPosition(x, y);
    updateText();
}

GameObject::GameObject(const std::string& textureName, float x, float y) : collisionsRequired(0)
{
    sprite.setTexture(Resources::getTexture(textureName));
    sprite.setPosition(x, y);
}

void GameObject::updateText()
{
    if (m_text.getString() != std::to_string(collisionsRequired)) {
        std::string textString = std::to_string(collisionsRequired);
        m_text.setString(textString);
        m_text.setFont(Resources::getFont("font"));
        m_text.setCharacterSize(24);
        m_text.setFillColor(sf::Color::White);

        sf::FloatRect textBounds = m_text.getLocalBounds();
        m_text.setOrigin(textBounds.left + textBounds.width / 2, textBounds.top + textBounds.height / 2);
        m_text.setPosition(sprite.getPosition().x + sprite.getGlobalBounds().width / 2,
            sprite.getPosition().y + sprite.getGlobalBounds().height / 2);
    }
}

void GameObject::decrementCollisionsRequired(int amount)
{
    collisionsRequired -= amount;
    updateText();
}

void GameObject::draw(sf::RenderWindow& window) const
{
    window.draw(sprite);
    window.draw(m_text);
}

void GameObject::setSpritePosition(float x, float y) 
{
    sprite.setPosition(x, y);
}
