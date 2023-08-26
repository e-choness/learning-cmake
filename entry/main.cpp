//
// Created by echo_ on 2023-07-25.
//


#include "LibCore.hpp"
#include <memory>

int main(){
    std::unique_ptr<LibCore> libCore = std::make_unique<LibCore>();
    libCore->RunOperatorOverrideExamples();
    libCore->RunUndefinedBehaviorExamples();
    libCore->RunBinarySearch();
    libCore->RunStaticMembersExamples();
    libCore->RunLambdaFunctionPointerExamples();
    libCore->RunSmartPointersExamples();
}
