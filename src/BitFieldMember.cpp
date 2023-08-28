//
// Created by echo_ on 2023-08-27.
//

#include "BitFieldMember.hpp"
#include <iostream>
void BitFieldMember::DisplayStructPadding() {
    std::cout << "========================== Beginning of Bit Field Examples ==========================\n";
    std::cout << "The size of struct S is: " << sizeof(S) << "\n";
    std::cout << "The size of struct S1 is: " << sizeof (S1) << "\n";
    std::cout << "========================== End of Bit Field Examples ==========================\n";
}
