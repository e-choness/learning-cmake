#include "Wizard.hpp"
#include "Spells.hpp"
#include "SpellJournal.hpp"
#include <iostream>
#include <tuple>

Spell *Wizard::cast() {
    auto [word, power] = read();
    return decide(word, power);
}

std::tuple<std::string, int> Wizard::read() {
    std::string word;
    int power;
    std::cin>> word;
    std::cin>> power;

    return std::make_tuple(word, power);
}

Spell* Wizard::decide(const std::string &spellWord, const int power) {
    Spell *spell;
    if(spellWord == "fire") spell = new Fireball(power);
    else if(spellWord == "frost") spell = new Frostbite(power);
    else if(spellWord == "thunder") spell = new ThunderStorm(power);
    else if(spellWord == "water") spell = new Waterbolt(power);
    else{
        spell = new Spell(spellWord);
        std::cin >> SpellJournal::mJournal;
    }
    return spell;
}

void Wizard::counter(Spell *spell) {
    if(dynamic_cast<Fireball*>(spell)){ dynamic_cast<Fireball*>(spell)->revealFirePower(); }
    else if(dynamic_cast<Frostbite*>(spell)) { dynamic_cast<Frostbite*>(spell)->revealFrostPower(); }
    else if(dynamic_cast<ThunderStorm*>(spell)) { dynamic_cast<ThunderStorm*>(spell)->revealThunderPower(); }
    else if(dynamic_cast<Waterbolt*>(spell)) { dynamic_cast<Waterbolt*>(spell)->revealWaterPower(); }
    else{
        compare(spell->revealName());
    }
}

void Wizard::compare(const std::string &spellName) {
    int count = 0;
    size_t pos;
    for(char c: spellName){
        while((pos = SpellJournal::mJournal.find_first_of(c))!= std::string::npos){
            SpellJournal::mJournal.replace(pos, 1, "");
            count++;
        }
    }
    std::cout << count << "\n";
}
