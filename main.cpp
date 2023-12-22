#include <iostream>
#include "hello.hpp"

int main(int argc, char **argv){
    auto hello = Hello();
    hello.SetGreetings("Hello, CMake from library!\n");
    std::cout << hello.GetGreetings();
}