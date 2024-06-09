#include "BoxManipulator.hpp"
#include<iostream>

void BoxManipulator::show() {
    int n;
    std::cin >> n;
    for(int i=0; i<n; i++){
        int choice;
        std::cin >> choice;
        selectOperation(choice);
    }
}

void BoxManipulator::selectOperation(int choice) {
    switch(choice){
        case 1:{
            std::cout << box1 << "\n";
            break;
        }
        case 2:{
            int l,b,h;
            std::cin >> l >> b >> h;
            Box b2(l, b, h);
            box1 = b2;
            std::cout << box1 << "\n";
            break;
        }
        case 3:{
            int l, b, h;
            std::cin >> l >> b >> h;
            Box b2(l, b, h);
            if(b2 < box1){ std::cout << "Lesser\n"; }
            else{ std::cout << "Greater\n"; }
            break;
        }
        case 4:{
            std::cout << box1.CalculateVolume() << "\n";
            break;
        }
        case 5:{
            Box b2(box1);
            std::cout << b2 << "\n";
        }
        default:
            break;
    }
}
