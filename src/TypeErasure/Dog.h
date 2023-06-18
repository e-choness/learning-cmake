//
// Created by echo_ on 2023-06-17.
//
#pragma once
#include "Animal.h"
class Dog: public Animal{
public:
    [[nodiscard]] const char* see() const override{return "Dog";}
    [[nodiscard]] const char* say() const override{return "Wooof!";}
};
