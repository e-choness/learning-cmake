//
// Created by echo_ on 2023-08-08.
//

#pragma once
#include"OperatorOverride.hpp"
#include "UndefinedBehavior.hpp"

class LibCore {
public:
    void RunOperatorOverrideExamples();
    static void RunUndefinedBehaviorExamples();

private:
    Object object = Object{4,5};
};
