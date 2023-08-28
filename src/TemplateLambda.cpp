//
// Created by echo_ on 2023-08-27.
//

#include "TemplateLambda.hpp"
#include <vector>
#include <iostream>
void TemplateLambda::DisplayTemplateLambdaResult() {
    std::cout << "========================== The Beginning of Template Lambda Examples ==========================\n";
    auto l = [](auto first, auto second){
        return first+second;
    };

    auto l1 = []<typename T>(T first, auto second){
        return first-second;
    };

    auto l2 = []<typename T>(T first, T second){
        return first*second;
    };

    std::cout << "Auto template for lambda is: " << l(2.4, 5) << "\n";
    std::cout << "T template for one lambda is: " << l1(3.4, 3) << "\n";
    // In this case it has to have the same type
    std::cout << "T template for both lambda is: " << l2(2.1, 4.0) << "\n";
    std::cout << "========================== The End of Template Lambda Examples ==========================\n";
}

void TemplateLambda::DisplayTemplateVectorResult() {
    std::cout << "========================== The Beginning of Template Vector Examples ==========================\n";
    auto l = []<typename T>(const std::vector<T> &v){
        return v.size();
    };

    std::cout << "The double vector size is: "<< l(std::vector<double>{2.1, 4.5, 7.8}) << "\n";
    std::cout << "========================== The End of Template Vector Examples ==========================\n";
}
