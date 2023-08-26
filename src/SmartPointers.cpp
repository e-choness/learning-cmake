//
// Created by echo_ on 2023-08-26.
//

#include "SmartPointers.hpp"
#include <iostream>

void SmartPointers::DisplaySmartPointerResult() {
    std::unique_ptr<int> uniquePtr = std::make_unique<int>(25);
    // unique pointer's ownership cannot be assigned using =
    // but using std::move() can reassign a unique pointer's ownership to an address.
    std::unique_ptr<int> uniquePtr2 = std::move(uniquePtr);
    //If right now I'm trying to access uniquePtr, the code can still compile but returns the address 0x00000000
    std::cout << uniquePtr << "\n";
    UniqueClass uniqueClass{};
    std::cout << uniqueClass.GetPointer() << "\n";
}

UniqueClass::UniqueClass() {
    m_UniquePtr = std::make_unique<int>(1);
    std::cout << m_UniquePtr << "\n";
}

UniqueClass::~UniqueClass() {
    std::cout << m_UniquePtr << "\n";// At this time unique pointer still holds the memory address assigned to it
}

std::unique_ptr<int> UniqueClass::GetPointer() {
    // if return m_UniquePtr directly will result in compiler error
    return std::move(m_UniquePtr);
}
