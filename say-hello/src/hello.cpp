#include "hello.hpp"
#include "log.hpp"
#include "Entry.hpp"
#include <vector>
#include <iostream>
#include <glfw3.h>

void Hello::setGreetings(const std::string& message){
    this->greetings = message;
}

std::string Hello::getGreetings() const{
    std::cout << "Library version from Hello: " << SAY_HELLO_VERSION << "\n";

    // C++ 20 features
    auto value = ((10 <=> 20) > 0);
    std::cout << "The value of ((10 <=> 20) > 0) is: " << value << "\n";

    GLFWwindow *window;

    if(!glfwInit()){
        std::cerr << "Failed to initialize GLFW\n";
        exit(EXIT_FAILURE);
    }

    window = glfwCreateWindow(300, 300, "Gears", NULL, NULL);

    if(!window){
        std::cerr << "Failed to open GLFW window\n";
        glfwTerminate(); // terminate
        exit(EXIT_FAILURE);
    }

    while(!glfwWindowShouldClose(window)){
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

    return greetings;
}

void Hello::showEntries() const {
    std::vector<Entry> entries;
    entries.push_back({"James Bond", 54543413});
    entries.push_back({"Harry Potter", 188492053});

    for(const auto& entry : entries){
        Log::logData(entry, MESSAGE);
    }

}
