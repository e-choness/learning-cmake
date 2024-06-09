#include "Spells.hpp"
#include <iostream>

std::string Spell::revealName() const{
    return mName;
}

void Fireball::revealFirePower() {
    std::cout << mName << ": " << mPower << "\n";
}

void Frostbite::revealFrostPower() {
    std::cout << mName << ": " << mPower << "\n";
}

void ThunderStorm::revealThunderPower() {
    std::cout << mName << ": " << mPower << "\n";
}

void Waterbolt::revealWaterPower() {
    std::cout << mName << ": " << mPower << "\n";
}
