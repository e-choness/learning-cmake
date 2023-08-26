//
// Created by echo_ on 2023-08-26.
//

#pragma once
#include<memory>


class SmartPointers {
public:
    // Three smart pointers: unique pointer, shared pointer, weak pointer
    static void DisplaySmartPointerResult();


};

class UniqueClass{
public:
    UniqueClass();
    ~UniqueClass();
    std::unique_ptr<int> GetPointer();
private:
    std::unique_ptr<int> m_UniquePtr;
};
