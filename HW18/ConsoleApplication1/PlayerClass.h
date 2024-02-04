#pragma once

class PlayerClass
{
public:
    virtual float getDamageMultiplier() const = 0;
    virtual float getArmorMultiplier() const = 0;
    virtual float getMissChance() const = 0;
    virtual ~PlayerClass() {}
};

class DefaultClass : public PlayerClass
{
public:
    float getDamageMultiplier() const override;
    float getArmorMultiplier() const override;
    float getMissChance() const override;
};

class DefenderClass : public DefaultClass
{
public:
    float getArmorMultiplier() const override;
    float getMissChance() const override;
};

class AttackerClass : public DefaultClass
{
public:
    float getDamageMultiplier() const override;
};

class LuckyManClass : public DefaultClass
{
public:
    float getMissChance() const override;
};

class BerserkClass : public AttackerClass, public LuckyManClass
{
public:
    float getMissChance() const override;
};
