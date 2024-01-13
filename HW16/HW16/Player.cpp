#include "Player.h"
#include <iostream>

Weapon::Weapon(const std::string& n, int d, int r) : name(n), damage(d), range(r) {}

Weapon::~Weapon()
{

}

std::string Weapon::getName() const
{
    return name;
}

int Weapon::getDamage() const
{
    return damage;
}

int Weapon::getRange() const
{
    return range;
}

Player::Player(const std::string& n, int h, PlayerClass pc) : name(n), health(h), playerClass(pc), weapon(nullptr) {}

Player::~Player()
{

}

void Player::setWeapon(Weapon* w)
{
    weapon = w;
}

Weapon* Player::getWeapon() const
{
    return weapon;
}

void Player::printPlayerInfo() const
{
    std::cout << "Name: " << name << ", Health: " << health << ", Class: " << playerClassToString(playerClass);
    if (weapon != nullptr) {
        std::cout << ", Weapon: " << weapon->getName() << ", Damage: " << weapon->getDamage() << ", Range: " << weapon->getRange();
    }
    std::cout << std::endl;
}

std::string Player::playerClassToString(PlayerClass pc)
{
    switch (pc) {
    case ASSAULT:
        return "Assault";
    case SUPPORT:
        return "Support";
    case SNIPER:
        return "Sniper";
    case MEDIC:
        return "Medic";
    default:
        return "Unknown";
    }
}