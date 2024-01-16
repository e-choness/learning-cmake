#pragma once

#include <string>
#include <glfw3.h>

class Hello{
    public:
        void SetGreetings(const std::string& greetings);
        std::string GetGreetings() const;
    private:
        std::string greetings;
};