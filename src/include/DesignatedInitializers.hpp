//
// Created by echo_ on 2023-08-27.
//

#pragma once
#include <iostream>

class DesignatedInitializers {
public:
    static void DisplayInitializerResults();
};

struct S2{
    int i;
    float f;
    double d;
};

// Using designated initializer for passing parameters is a clean way to do it
static void useParameters(S2 p){
    std::cout << "The parameters are: " << p.i << " " << p.f << " " << p.d << "\n";
}



