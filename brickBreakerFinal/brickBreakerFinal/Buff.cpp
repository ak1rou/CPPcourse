#include "Buff.h"
#include "Resources.h"
#include <iostream>

Buff::Buff() : m_active(false), m_ball(new GameObject()) {}

void Buff::setBall(GameObject* ball) {
    m_ball = ball;
}

void Buff::buffReset()
{
    m_active = false;
    m_durationTimer.restart();

    if (m_ball != nullptr)
    {
        m_ball->getSprite().setTexture(Resources::getTexture("whiteBall"));
    }
}

void Buff::applyBuff()
{
    m_active = true;
    m_durationTimer.restart();

    sf::Texture& blackBallTexture = Resources::getTexture("blackBall");
    if (blackBallTexture.getSize().x == 0 || blackBallTexture.getSize().y == 0) {
        std::cout << "Failed to load blackBall texture" << std::endl;
    }

    m_ball->getSprite().setTexture(blackBallTexture);
    std::cout << "bb was loaded" << std::endl;
}

void Buff::update()
{
    if (m_active)
    {
        float elapsedTime = m_durationTimer.getElapsedTime().asSeconds();

        const float buffDuration = 10.0f;

        if (elapsedTime >= buffDuration)
        {
            m_active = false;

            if (m_ball != nullptr)
            {
                m_ball->getSprite().setTexture(Resources::getTexture("whiteBall"));
            }
        }
    }
}

bool Buff::isActive() const
{
    return m_active;
}
