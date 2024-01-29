#include "Weapon.h"

float calculateDistanceDamageReduction(int distance, int effectiveRange, float reductionRate)
{
    if (distance <= effectiveRange)
    {
        return 1.0f;
    }
    else
    {
        float reductionFactor = std::pow(reductionRate, (distance - effectiveRange) / 100.0f);
        return std::fmax(0.0f, 1.0f - reductionFactor);
    }
}

int SniperRifle::getDamageRate(int distance) const
{
    int effectiveRange = getEffectiveRange();
    float baseDamage = 48.0f;

    return static_cast<int>(calculateDistanceDamageReduction(distance, effectiveRange, 0.75f) * baseDamage);
}

int SniperRifle::getEffectiveRange() const
{
    return 2000;
}

float SniperRifle::getDistanceDamageReduction(int distance) const
{
    int effectiveRange = getEffectiveRange();

    if (distance > effectiveRange)
    {
        return 0.0f;
    }
    else
    {
        return 1.0f;
    }
}

int Pistol::getDamageRate(int distance) const
{
    int effectiveRange = getEffectiveRange();
    float baseDamage = 24.0f;

    return static_cast<int>(calculateDistanceDamageReduction(distance, effectiveRange, 0.75f) * baseDamage);
}

int Pistol::getEffectiveRange() const
{
    return 400;
}

float Pistol::getDistanceDamageReduction(int distance) const
{
    int effectiveRange = getEffectiveRange();

    if (distance > effectiveRange)
    {
        return 0.0f;
    }
    else
    {
        return 1.0f;
    }
}

int AssaultRifle::getDamageRate(int distance) const
{
    int effectiveRange = getEffectiveRange();
    float baseDamage = 35.0f;

    return static_cast<int>(calculateDistanceDamageReduction(distance, effectiveRange, 0.65f) * baseDamage);
}

int AssaultRifle::getEffectiveRange() const
{
    return 1000;
}

float AssaultRifle::getDistanceDamageReduction(int distance) const
{
    int effectiveRange = getEffectiveRange();

    if (distance > effectiveRange)
    {
        return 0.0f;
    }
    else
    {
        return 1.0f;
    }
}

int Crossbow::getDamageRate(int distance) const
{
    int effectiveRange = getEffectiveRange();
    float baseDamage = 18.0f;

    return static_cast<int>(calculateDistanceDamageReduction(distance, effectiveRange, 0.75f) * baseDamage);
}

int Crossbow::getEffectiveRange() const
{
    return 800;
}

float Crossbow::getDistanceDamageReduction(int distance) const
{
    int effectiveRange = getEffectiveRange();

    if (distance > effectiveRange)
    {
        return 0.0f;
    }
    else
    {
        return 1.0f;
    }
}

int Shotgun::getDamageRate(int distance) const
{
    int effectiveRange = getEffectiveRange();
    float baseDamage = 35.0f;

    return static_cast<int>(calculateDistanceDamageReduction(distance, effectiveRange, 0.5f) * baseDamage);
}

int Shotgun::getEffectiveRange() const
{
    return 500;
}

float Shotgun::getDistanceDamageReduction(int distance) const
{
    int effectiveRange = getEffectiveRange();

    if (distance > effectiveRange)
    {
        return 0.0f;
    }
    else
    {
        return 1.0f;
    }
}

int BareHand::getDamageRate(int distance) const
{
    return 10;
}

int BareHand::getEffectiveRange() const
{
    return 1;
}

float BareHand::getDistanceDamageReduction(int distance) const
{
    return 1.0f;
}

int Axe::getDamageRate(int distance) const
{
    int effectiveRange = getEffectiveRange();
    float baseDamage = 15.0f;

    return static_cast<int>(calculateDistanceDamageReduction(distance, effectiveRange, 0.6f) * baseDamage);
}

int Axe::getEffectiveRange() const
{
    return 2;
}

float Axe::getDistanceDamageReduction(int distance) const
{
    int effectiveRange = getEffectiveRange();

    if (distance > effectiveRange)
    {
        return 0.0f;
    }
    else
    {
        return 1.0f;
    }
}

int Sword::getDamageRate(int distance) const
{
    int effectiveRange = getEffectiveRange();
    float baseDamage = 20.0f;

    return static_cast<int>(calculateDistanceDamageReduction(distance, effectiveRange, 0.7f) * baseDamage);
}

int Sword::getEffectiveRange() const
{
    return 2;
}

float Sword::getDistanceDamageReduction(int distance) const
{
    int effectiveRange = getEffectiveRange();

    if (distance > effectiveRange)
    {
        return 0.0f;
    }
    else
    {
        return 1.0f;
    }
}

int Dagger::getDamageRate(int distance) const
{
    int effectiveRange = getEffectiveRange();
    float baseDamage = 10.0f;

    return static_cast<int>(calculateDistanceDamageReduction(distance, effectiveRange, 0.8f) * baseDamage);
}

int Dagger::getEffectiveRange() const
{
    return 2;
}

float Dagger::getDistanceDamageReduction(int distance) const
{
    int effectiveRange = getEffectiveRange();

    if (distance > effectiveRange)
    {
        return 0.0f;
    }
    else
    {
        return 1.0f;
    }
}

int MeleeWeapon::getDamageRate(int distance) const
{
    int effectiveRange = getEffectiveRange();

    if (distance > effectiveRange)
    {
        return 0;
    }
    else
    {
        float baseDamage = 10.0f; 
        return static_cast<int>(calculateDistanceDamageReduction(distance, effectiveRange, 0.8f) * baseDamage);
    }
}

int MeleeWeapon::getEffectiveRange() const
{
    return 2;
}

float MeleeWeapon::getDistanceDamageReduction(int distance) const
{
    int effectiveRange = getEffectiveRange();

    if (distance > effectiveRange)
    {
        return 0.0f;
    }
    else
    {
        return 1.0f;
    }
}