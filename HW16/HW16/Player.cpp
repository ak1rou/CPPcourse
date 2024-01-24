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

void Weapon::printInfo() const
{
    std::cout << ", Weapon: " << getName() << ", Damage: " << getDamage() << ", Range: " << getRange();
}

void Player::printPlayerInfo() const
{
    std::cout << "Name: " << name << ", Health: " << health << ", Class: " << playerClassToString(playerClass);
    if (weapon != nullptr) {
        weapon->printInfo();
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

bool Player::operator==(const Player& other) const
{
    return false;
}
