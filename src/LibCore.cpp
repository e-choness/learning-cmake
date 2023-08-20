//
// Created by echo_ on 2023-08-08.
//

#include "LibCore.hpp"
#include "BinarySearch.hpp"
#include <iostream>

void LibCore::RunOperatorOverrideExamples() {

    std::cout << "========================== Beginning of Operator Override Examples ==========================\n";
    std::cout << "The object override output is: " << object << "\n";
    std::cout << "========================== End of Operator Override Examples ==========================\n";
}

void LibCore::RunUndefinedBehaviorExamples() {
    UndefinedBehavior::RunPointerAndAddress();
    UndefinedBehavior::RunTemplateLessThan();
    UndefinedBehavior::RunVSignedIntegerOverflow();
    UndefinedBehavior::RunContainerInvalidateIterators();
    UndefinedBehavior::RunConstCast();
}

void LibCore::RunBinarySearch() {
    BinarySearch({1,2,3,4,5,6,7,8}, 3);
}
