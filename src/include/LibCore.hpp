//
// Created by echo_ on 2023-08-08.
//

#pragma once
#include"OperatorOverride.hpp"
#include "UndefinedBehavior.hpp"
#include "Concepts.hpp"

class LibCore {
public:
    void RunOperatorOverrideExamples();
    static void RunUndefinedBehaviorExamples();
    static void RunBinarySearch();
    static void RunStaticMembersExamples();
    static void RunLambdaFunctionPointerExamples();
    static void RunSmartPointersExamples();
    static void RunBitFieldMemberExamples();
    static void RunDesignatedInitializerExamples();
    static void RunTemplateLambdaExamples();
    static void RunMultiThreadingExamples();
    static void RunDiamondInheritanceExamples();
    static void RunIteratorsExamples();
private:
    Object object{Object{4,5}};
    [[maybe_unused]] Concepts conceptsFloat{Concepts{3.4}};
    [[maybe_unused]] Concepts conceptsPointer{Concepts{&object}};
};
