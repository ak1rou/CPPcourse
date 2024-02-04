#pragma once
#include <cmath>
#include <algorithm>

class Weapon
{
public:
    virtual int getDamageRate(int distance) const = 0;
    virtual int getEffectiveRange() const = 0;
    virtual float getDistanceDamageReduction(int distance) const = 0;
    virtual ~Weapon() = default;
};

class RangedWeapon : public Weapon
{
public:
    int getDamageRate(int distance) const override = 0;
    int getEffectiveRange() const override = 0;
    float getDistanceDamageReduction(int distance) const override = 0;
};

class SniperRifle : public RangedWeapon
{
public:
    int getDamageRate(int distance) const override;
    int getEffectiveRange() const override;
    float getDistanceDamageReduction(int distance) const override;
};

class Pistol : public RangedWeapon
{
public:
    int getDamageRate(int distance) const override;
    int getEffectiveRange() const override;
    float getDistanceDamageReduction(int distance) const override;
};

class AssaultRifle : public RangedWeapon
{
public:
    int getDamageRate(int distance) const override;
    int getEffectiveRange() const override;
    float getDistanceDamageReduction(int distance) const override;
};

class Crossbow : public RangedWeapon
{
public:
    int getDamageRate(int distance) const override;
    int getEffectiveRange() const override;
    float getDistanceDamageReduction(int distance) const override;
};

class Shotgun : public RangedWeapon
{
public:
    int getDamageRate(int distance) const override;
    int getEffectiveRange() const override;
    float getDistanceDamageReduction(int distance) const override;
};

class MeleeWeapon : public Weapon
{
public:
    int getDamageRate(int distance) const override = 0;
    int getEffectiveRange() const override;
    float getDistanceDamageReduction(int distance) const override;
};

class BareHand : public MeleeWeapon
{
public:
    int getDamageRate(int distance) const override;
    int getEffectiveRange() const override;
    float getDistanceDamageReduction(int distance) const override;
};

class Axe : public MeleeWeapon
{
public:
    int getDamageRate(int distance) const override;
    int getEffectiveRange() const override;
    float getDistanceDamageReduction(int distance) const override;
};

class Sword : public MeleeWeapon
{
public:
    int getDamageRate(int distance) const override;
    int getEffectiveRange() const override;
    float getDistanceDamageReduction(int distance) const override;
};

class Dagger : public MeleeWeapon
{
public:
    int getDamageRate(int distance) const override;
    int getEffectiveRange() const override;
    float getDistanceDamageReduction(int distance) const override;
};
