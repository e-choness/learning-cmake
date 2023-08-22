//
// Created by echo_ on 2023-08-21.
//

#include "StaticMembers.hpp"
#include <iostream>

void StaticMembers::DisplayResult() {
    Square square1(5);
    Square square2(10);
    Square squares[3] = {Square(2),Square(4),Square(8)};
    std::cout << "square 1 area: " << square1.Area() << "\n";
    std::cout << "square 2 area: " << square2.Area() << "\n";
    for(auto&& square : squares ){
        std::cout << "This square area: " << square.Area() << "\n";
    }
    std::cout << "Total square counts: " << Square::GetTotalCount() << "\n";
}
