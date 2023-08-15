//
// Created by echo_ on 2023-08-08.
//

#pragma once
#include <concepts>
#include <iostream>

template<typename T>
concept Pointer = std::is_pointer_v<T>;

class Concepts {
public:
    Concepts(std::floating_point auto aFloat){
        std::cout << "This is from a constructor that passed a float " << aFloat << "\n";
    }

    Concepts(Pointer auto aPointer){std::cout << "This is from a constructor that passed a pointer " << *aPointer << "\n";};
};
