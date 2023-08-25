//
// Created by echo_ on 2023-08-24.
//

#pragma once
#include<functional>

class LambdaFunctionPointer {
public:
    static void RunLambdaExample();
    static void RunSTDFunctionExample();
    static void RunFunctionPointerExample();
private:
    static int call(int(*f)(int, int)){return f(2,3);}
    static int add(int x, int y){ return x+y;}
    std::function<int (const int, const int)> func{add};
    static int call(const std::function<int (int, int)> &f){return f(2,3);}
};
