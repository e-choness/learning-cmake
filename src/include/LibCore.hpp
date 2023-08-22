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
private:
    Object object{Object{4,5}};
    Concepts conceptsFloat{Concepts{3.4}};
    Concepts conceptsPointer{Concepts{&object}};
};
