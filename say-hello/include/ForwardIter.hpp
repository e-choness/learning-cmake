#pragma once
#include <iostream>

class ForwardIter {
private:
    template <typename ForwardIterator>
    void PrePrint(ForwardIterator i)
    {
        const auto i0 = i;
        const auto i1 = ++i;
        const auto i2 = ++i;
        std::cout << *i0 << ", " << *i1 << ", "<< *i2 << "\n";
    }

    template <typename ForwardIterator>
    void PostPrint(ForwardIterator i)
    {
        const auto i0 = i;
        const auto i1 = i++;
        const auto i2 = i++;
        std::cout << *i0 << ", " << *i1 << ", "<< *i2 << "\n";
    }

    void PrintFibonacciSum(const int n)
    {
        int fi = 0; // Fibonacci number F(i)
        int f1 = 1; // Fibonacci number F(i + 1)
        int f2 = 1; // Fibonacci number F(i + 2)
         int sum = 0; // Running sum of Fibonacci numbers
         for (int i = 0; i <= n; ++i)
         {   std::cout << fi;
             sum += fi;
             fi = f1;
             f1 = f2;
             f2 = fi + f1;
             std::cout << ((i < n) ? " + " : " = "); }
             std::cout << sum << '\n';
         }
public:
    void show(){
        PrintFibonacciSum(10);
    }
};

class Operation {
public: virtual ~Operation() = default; // Return identity by default.
 virtual int Perform(const int x) const  { return x; }
};

 class Square : public Operation
 {
    int Perform(const int x) const override { return x * x; }
 };

 void PrintOp(const Operation& op, const int x)
 { std::cout << op.Perform(x) << '\n'; }

 void PrintSquareOf(const int x)
 {
//     const Square squre;
     const Operation* const op = new Square;
//    const Operation op;
     PrintOp(*op, x);
     delete op;
 }
