#pragma once
#include<iostream>
#include<ostream>

class Box{
public:
    Box():mL(0), mB(0), mH(0){}
    Box(int l, int b, int h) : mL(l), mB(b), mH(h){}
    Box(const Box& box) : mL(box.mL), mB(box.mB), mH(box.mH){}

public:
    int getLength(){ return mL; }
    int getBreadth(){ return mB; }
    int getHeight(){ return mH; }
    long long CalculateVolume() {return mL*mB*mH;}

public:
    friend bool operator<(const Box& thisBox, const Box& otherBox);
    friend std::ostream& operator<<(std::ostream& os, const Box& box);

private:
    int mL;
    int mB;
    int mH;
};