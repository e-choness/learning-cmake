#pragma once
#include <string>

class Hello{
    public:
        void setGreetings(const std::string& message);
        [[nodiscard]] std::string getGreetings() const;
        void showEntries() const;
    private:
        std::string greetings;
};