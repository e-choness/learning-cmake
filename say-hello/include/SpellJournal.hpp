#pragma once
#include<string>

class SpellJournal{
public:
    static std::string mJournal;
    static std::string read(){ return mJournal; }
};

std::string SpellJournal::mJournal = "";