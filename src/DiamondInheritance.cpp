//
// Created by echo_ on 2023-08-29.
//

#include "DiamondInheritance.hpp"
#include <iostream>
void DiamondInheritance::DisplayDiamondInheritanceResult() {
    std::cout << "========================== Beginning of Diamond Inheritance Examples ==========================\n";
    Pet pet{};
    pet.BeingAlive();
    Cat cat{};
    cat.BeingAlive();
    Dog dog{};
    dog.BeingAlive();
    Fox fox{};
    fox.BeingAlive();
    std::cout << "========================== End of Diamond Inheritance Examples ==========================\n";
}

void Pet::BeingAlive() const {
    if(m_IsAlive)
        std::cout << "I'm alive!\n";
    else
        std::cout << "Dead through and through.\n";
}

void Cat::BeingAlive() const {
    if(m_IsAlive)
        std::cout << m_Name << " is alive!\n";
    else
        std::cout << m_Name << " will be missed.\n";
}

void Dog::BeingAlive() const {
    if(m_IsAlive)
        std::cout << "Our little baby "<< m_Breed << " is alive!\n";
    else
        std::cout << m_Breed << " will be missed.\n";
}

void Fox::BeingAlive() const {
    if(m_IsAlive)
        std::cout << "Fox is " << m_Status << " inheritance from Cat and Dog, but hey. Fox is cute.\n";
    else
        std::cout << m_Status << " also doesn't quite exist.\n";
}
