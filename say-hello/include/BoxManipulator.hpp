#pragma once
#include "Box.hpp"

class BoxManipulator {
public:
    void show();
private:
    void selectOperation(int choice);
    Box box1;
};
