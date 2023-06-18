//
// Created by echo_ on 2023-06-17.
//
#pragma once
#include <iostream>
#include <format>
class Animal{
public:
    [[nodiscard]] virtual const char* see() const = 0;
    [[nodiscard]] virtual const char* say() const = 0;
};

template<typename T>
void SeeAndSay(T *animal){
    std::cout << std::format("The {} says {}\n", animal->see(), animal->say());
}