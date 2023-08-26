//
// Created by echo_ on 2023-08-26.
//

#pragma once
#include<memory>


class SmartPointers {
public:
    // Three smart pointers: unique pointer, shared pointer, weak pointer
    static void DisplaySmartPointerResult();
    static void DisplaySharedPointerResult();

};

class UniqueClass{
public:
    UniqueClass();
    ~UniqueClass();
};

class SharedClass{
public:
    SharedClass();
    ~SharedClass();
};
