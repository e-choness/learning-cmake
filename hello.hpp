#include <string>

class Hello{
    public:
        void SetGreetings(const std::string& greetings);
        std::string GetGreetings() const;
    private:
        std::string greetings;
};