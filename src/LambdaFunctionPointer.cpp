//
// Created by echo_ on 2023-08-24.
//

#include "LambdaFunctionPointer.hpp"
#include <iostream>

// C++ lambda is not std::function
void LambdaFunctionPointer::RunLambdaExample() {
    auto add = [](const int x, const int y){
        return x+y;
    };
    std::cout << "Lambda result: " << add(4,5) << "\n";
}

// std::function: a type-erased wrapper around a "callable"
void LambdaFunctionPointer::RunSTDFunctionExample() {
    auto minus = [](const int x, const int y){
        return x-y;
    };
    std::function<int (const int, const int)> func{minus};
    std::cout << "std::function result:" << func(4,5) << "\n";
}

void LambdaFunctionPointer::RunFunctionPointerExample() {
    std::cout << "function pointer result:" << call(add) << "\n";

    std::vector<std::function<int (int, int)>> operations;

    operations.emplace_back([](int x, int y){return x+y;});
    operations.emplace_back([](int x, int y){return x-y;});
    operations.emplace_back([](int x, int y){return x*y;});

    // This is also allowed
    std::vector<int (*)(int, int)> operationPointers;
    operationPointers.emplace_back(add);
}
