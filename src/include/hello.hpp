//
// Created by echo_ on 2023-07-26.
//

#pragma once
#include <ostream>
class Object{
public:
    Object(int a, int b);
    friend std::ostream& operator<<(std::ostream& os, const Object& obj){
        os << obj.m_A << " and "<< obj.m_B;
        return os;
    }
private:
    int m_A;
    int m_B;
};