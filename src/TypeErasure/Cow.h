//
// Created by echo_ on 2023-06-17.
//
#pragma once
#include "Animal.h"
class Cow: public Animal{
public:
    [[nodiscard]] const char* see() const override{return "Cow";}
    [[nodiscard]] const char* say() const override{return "Moooooo~~";}
};
