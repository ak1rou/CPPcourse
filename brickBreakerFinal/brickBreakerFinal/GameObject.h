#pragma once
#include "Resources.h"

class GameObject
{
public:
    GameObject() = default;

    GameObject(const std::string& textureName, float x, float y, int collisionsReq);

    GameObject(const std::string& textureName, float x, float y);

    void draw(sf::RenderWindow& window) const;

    sf::Sprite& getSprite() { return sprite; }

    void setSpritePosition(float x, float y);

    int getCollisionsRequired() const { return collisionsRequired; }

    void setCollisionsRequired(int collisions) { collisionsRequired = collisions; }

    void decrementCollisionsRequired(int amount = 1);

    void updateText();

protected:
    sf::Sprite sprite;
    sf::Text m_text;
    int collisionsRequired;
};