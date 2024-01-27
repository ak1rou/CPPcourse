#pragma once
#include <string>

enum PlayerClass
{
    ASSAULT,
    SUPPORT,
    SNIPER,
    MEDIC
};

class Weapon
{
private:
    std::string name;
    int damage;
    int range;

public:
    Weapon(const std::string& n, int d, int r);
    ~Weapon();
    std::string getName() const;
    int getDamage() const;
    int getRange() const;
    void printInfo() const;
};

class Player
{
private:
    std::string name;
    int health;
    PlayerClass playerClass;
    Weapon* weapon;

public:
    Player(const std::string& n, int h, PlayerClass pc);
    ~Player();
    void setWeapon(Weapon* w);
    Weapon* getWeapon() const;
    void printPlayerInfo() const;
    static std::string playerClassToString(PlayerClass pc);
    bool operator==(const Player& other) const;
};