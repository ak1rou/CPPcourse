#include "Player.h"
#include "Weapon.h"
#include "PlayerClass.h"
#include <iostream>

Player::~Player()
{
    delete m_class;
    delete m_weapon;
}

void Player::setWeapon(Weapon* weapon)
{
    delete m_weapon;
    m_weapon = weapon;
}

void Player::setPlayerClass(PlayerClass* playerClass)
{
    delete m_class;
    m_class = playerClass;
}

void Player::attack(const Player& other, int distance)
{
    if (&other == this)
    {
        std::cout << "\n-------FRIENDLY FIRE!-------\n";
    }

    if (other.isEliminated())
    {
        std::cout << "Player " << other.getName() << " has been already eliminated!\n";
        return;
    }

    float baseDamage = static_cast<float>(m_weapon->getDamageRate(distance));
    float damageReduction = m_weapon->getDistanceDamageReduction(distance);
    float damage = baseDamage * damageReduction * m_class->getDamageMultiplier() / other.m_class->getArmorMultiplier();

    m_health = static_cast<int>(m_health - damage);

    std::cout << "Player " << getName() << " attacked Player " << other.getName() <<
        " at distance " << distance << " using " << typeid(*m_weapon).name();

    std::cout << "\nBase Damage: " << baseDamage << ", Damage after Reduction: " << damage << "\n";
    std::cout << "Health left: " << m_health << std::endl;

    if (m_health <= 0)
    {
        m_health = 0;
        std::cout << "Player " << other.getName() << " was eliminated!\n";
    }
}