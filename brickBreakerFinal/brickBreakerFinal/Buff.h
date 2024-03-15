#pragma once
#include <SFML/System.hpp>
#include "GameObject.h"

class Buff
{
public:
    Buff();

    void applyBuff();

    void update();

    bool isActive() const;

    void setBall(GameObject* ball);

    void buffReset();

private: 
    bool m_active;
    sf::Clock m_durationTimer; 
    GameObject* m_ball; 

};

