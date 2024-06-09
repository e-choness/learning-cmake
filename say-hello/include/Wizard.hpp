#pragma once
#include<string>
class Spell;

class Wizard {
public:
    static Spell *cast();
    static void counter(Spell *spell);
private:
    static std::tuple<std::string, int> read();
    static Spell* decide(const std::string& spellWord, int power);
    static void compare(const std::string& spellName);
};
