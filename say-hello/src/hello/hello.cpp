#include "hello.hpp"

void Hello::SetGreetings(const std::string& greetings){
    this->greetings = greetings;
}

std::string Hello::GetGreetings() const{
    return greetings;
}