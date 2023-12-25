#include "hello/hello.hpp"
#include <iostream>

void Hello::SetGreetings(const std::string& greetings){
    this->greetings = greetings;
}

std::string Hello::GetGreetings() const{
    std::cout << "Library version: " << SAY_HELLO_VERSION << "\n";
    return greetings;
}