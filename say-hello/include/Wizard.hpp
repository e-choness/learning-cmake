#pragma once
#include<string>
class Spell;

class Wizard {
public:
    static Spell *cast();
    void counter(Spell *spell);
private:
    static std::tuple<std::string, int> read();
    static Spell* decide(const std::string& spellWord, const int power);
    static void compare(const std::string& spellName);
};
