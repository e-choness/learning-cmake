#include "Wizard.hpp"
#include "Spells.hpp"
#include "SpellJournal.hpp"
#include <vector>
#include <algorithm>
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

Spell* Wizard::decide(const std::string &spellWord, int power) {
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
    long long spellSize = spellName.length();
    int journalSize = SpellJournal::mJournal.size();

    std::vector<std::vector<int>> countTable(spellSize+1, std::vector<int>(journalSize+1, 0));
    for(int i=1; i<=spellSize; ++i){
        for(int j=1; j<=journalSize; ++j){
            if(spellName[i-1] == SpellJournal::mJournal[j-1]){
                countTable[i][j] = countTable[i-1][j-1] + 1;
            }else{
                countTable[i][j] = std::max(countTable[i-1][j], countTable[i][j-1]);
            }
        }
    }

    std::cout<< countTable[spellSize][journalSize]  << "\n";
}
