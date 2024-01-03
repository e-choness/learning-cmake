#include "hello.hpp"
#include <iostream>

void Hello::SetGreetings(const std::string& greetings){
    this->greetings = greetings;
}

std::string Hello::GetGreetings() const{
    std::cout << "Library version from Hello: " << SAY_HELLO_VERSION << "\n";

    // C++ 20 features
    auto value = ((10 <=> 20) > 0);
    std::cout << "The value of ((10 <=> 20) > 0) is: " << value << "\n";

    return greetings;
}