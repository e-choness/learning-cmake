#include <iostream>
#include "hello/hello.hpp"

int main(int argc, char **argv){

    auto hello = Hello();
    
    hello.SetGreetings("Hello, CMake from library in subdirectory!\n");
    std::cout << hello.GetGreetings();
    std::cout << "The say-hello library is version: " << SAY_HELLO_VERSION << "\n";

    // Get command line arguments from main entry args.
    if(argc > 1){
        const double inputValue = std::stod(argv[1]);
        std::cout << "The first command line argument: " << inputValue << "\n";
    }
}