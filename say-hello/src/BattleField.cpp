#include "BattleField.hpp"
#include "Wizard.hpp"
#include "Spells.hpp"
#include <iostream>


void BattleField::fight() {
    int turns;
    std::cin >> turns;

    Wizard Arawn;
    Wizard Player;

    while(turns--){
        Spell *spell = Arawn.cast();
        Player.counter(spell);
    }
}
