#include "PlayerClass.h"

float DefaultClass::getDamageMultiplier() const
{
    return 1.0f;
}

float DefaultClass::getArmorMultiplier() const
{
    return 1.0f;
}

float DefaultClass::getMissChance() const
{
    return 0.0f;
}

float DefenderClass::getArmorMultiplier() const
{
    return 1.2f;
}

float DefenderClass::getMissChance() const
{
    return 0.1f;
}

float AttackerClass::getDamageMultiplier() const
{
    return 1.2f;
}

float LuckyManClass::getMissChance() const
{
    return 0.2f;
}

float BerserkClass::getMissChance() const
{
    return 0.3f;
}
