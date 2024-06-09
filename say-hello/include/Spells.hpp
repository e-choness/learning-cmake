#pragma once
#include<string>
#include <utility>

class Spell {
public:
    Spell()= default;
    explicit Spell(std::string  name): mName(std::move(name)){}
    virtual ~Spell()= default;
    [[nodiscard]] std::string revealName() const;

protected:
    std::string mName;
};

class Fireball : public Spell{
public:
    Fireball(int power) : mPower(power){ mName = "Fireball"; }
    void revealFirePower();
private:
    int mPower;
};

class Frostbite : public Spell{
public:
    Frostbite(int power) : mPower(power){ mName = "Frostbite"; }
    void revealFrostPower();
private:
    int mPower;
};

class ThunderStorm : public Spell{
public:
    ThunderStorm(int power) : mPower(power) { mName = "ThunderStorm"; }
    void revealThunderPower();
private:
    int mPower;
};

class Waterbolt : public Spell{
public:
    Waterbolt(int power) : mPower(power) { mName = "Waterbolt"; }
    void revealWaterPower();
private:
    int mPower;
};