//
// Created by echo_ on 2023-08-08.
//

#include "LibCore.hpp"
#include "BinarySearch.hpp"
#include "StaticMembers.hpp"
#include "LambdaFunctionPointer.hpp"
#include "SmartPointers.hpp"
#include "BitFieldMember.hpp"
#include "DesignatedInitializers.hpp"
#include "TemplateLambda.hpp"
#include "MultiThreading.hpp"
#include "DiamondInheritance.hpp"
#include "Iterators.hpp"
#include "HelloWorld.h"
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

void LibCore::RunStaticMembersExamples() {
    StaticMembers::DisplayResult();
}

void LibCore::RunLambdaFunctionPointerExamples() {
    LambdaFunctionPointer::RunLambdaExample();
    LambdaFunctionPointer::RunSTDFunctionExample();
    LambdaFunctionPointer::RunFunctionPointerExample();
}

void LibCore::RunSmartPointersExamples() {
    SmartPointers::DisplayUniquePointerResult();
    SmartPointers::DisplaySharedPointerResult();
    SmartPointers::DisplayWeakPointerResult();
}

void LibCore::RunBitFieldMemberExamples() {
    BitFieldMember::DisplayStructPadding();
}

void LibCore::RunDesignatedInitializerExamples() {
    DesignatedInitializers::DisplayInitializerResults();
}

void LibCore::RunTemplateLambdaExamples() {
    TemplateLambda::DisplayTemplateLambdaResult();
    TemplateLambda::DisplayTemplateVectorResult();
}

void LibCore::RunMultiThreadingExamples() {
    MultiThreading::DisplayMultiThreadingResults();
}

void LibCore::RunDiamondInheritanceExamples() {
    DiamondInheritance::DisplayDiamondInheritanceResult();
}

void LibCore::RunIteratorsExamples() {
    Iterators::DisplayIteratorsResults();
}

void LibCore::RunHelloWorldExamples() {
    HelloWorld::OutputOriginal();
    HelloWorld::OutputNewer();
    HelloWorld::OutputAfter23plus();
}




