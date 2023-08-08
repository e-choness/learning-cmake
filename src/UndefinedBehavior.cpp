//
// Created by echo_ on 2023-08-08.
//

#include "UndefinedBehavior.hpp"
#include <iostream>
#include <vector>

void UndefinedBehavior::RunPointerAndAddress() {
    std::cout << "========================== Beginning of Undefined Behavior - Pointer and Address Examples ==========================\n";
    int *VarA = nullptr;
//    *VarA = 17; // This will lead to run time error, since it's accessing non-accessible memory
//
//    int VarB;
//    VarA = &VarB;
//
//    std::cout << *VarA << "\n";
//    std::cout << VarB << "\n";
    std::cout << "========================== End of Undefined Behavior - Pointer and Address Examples ==========================\n";
}

void UndefinedBehavior::RunTemplateLessThan() {
    std::cout << "========================== Beginning of Undefined Behavior - Template Less Than ==========================\n";
    int t1 = 250;
    int t2 = 75;
    doLessThanLessThan(t1, t2); // bit shift, undefined behavior
    std::cout << t1 << " " << t2 << "\n";
    doLessThanLessThan(std::cout, "cat\n"); // write to standard out
    std::cout << "========================== End of Undefined Behavior - Template Less Than ==========================\n";
}

void UndefinedBehavior::RunVSignedIntegerOverflow() {
    std::cout << "========================== Beginning of Undefined Behavior - Signed Integer Overflow ==========================\n";
    std::cout << volume(65000) << "\n";
    // The integer overflow to a negative result
    // Untestable when type overflow happens
    std::cout << "========================== End of Undefined Behavior - Signed Integer Overflow ==========================\n";
}

int UndefinedBehavior::volume(int length) {
    return pow(length, 3);
}

void UndefinedBehavior::RunContainerInvalidateIterators() {
    std::cout << "========================== Beginning of Undefined Behavior - Container Invalidate Iterators ==========================\n";
    // std::vector::insert() has two loops
    // It might crash, it might not
    std::vector<int> myContainer = {42, 14, 5, 31, 9};

    for(auto &item: myContainer){
        if(item == 5){
            myContainer.insert(myContainer.begin(), -5);
        }
    }

    for(auto &item: myContainer){
        std::cout << item << " ";
    }
    std::cout << "\n";
    std::cout << "========================== End of Undefined Behavior - Container Invalidate Iterators ==========================\n";
}

void UndefinedBehavior::RunConstCast() {
    std::cout << "========================== Beginning of Undefined Behavior - Const Cast ==========================\n";
    const std::string value = "tiger";
    DoThing8(value);
    std::cout << "========================== End of Undefined Behavior - Const Cast ==========================\n";
}

void UndefinedBehavior::DoThing8(const std::string &input){
    std::string &temp = const_cast<std::string &>(input);
    temp = "bear";
    std::cout<< temp << "\n"; // the const variable is modified despite it's "constness"
}

template<typename T1, typename T2>
void UndefinedBehavior::doLessThanLessThan(T1 &t1, T2 &t2) {
    t1 << t2;
}


