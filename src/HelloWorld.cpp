#include "HelloWorld.h"
#include <iostream>

void HelloWorld::OutputOriginal() {
    std::cout << "The ultimate original Hello World/n";
}

void HelloWorld::OutputNewer() {
    std::puts("A newer Hello World/n");
}

void HelloWorld::OutputAfter23plus() {
    // This one is after C++23, no available on prior versions.
//    std::println("Hello World/n");
//    std::printf("A fancy Hello World can't be displayed right now only be replaced by printf./n");
}

//void HelloWorld::DisplayResults() {
//    OutputOriginal();
//    OutputNewer();
//    OutputAfter23plus();
//}
