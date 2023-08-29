//
// Created by echo_ on 2023-08-28.
//

#include "MultiThreading.hpp"
#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <string>

void MultiThreading::BrewCoffee() {
//    std::vector<const char*> brewingSteps {
//            "Unpack the ground coffee package.\n",
//            "Boiling water.\n",
//            "Put ground coffee into the water.\n",
//            "Pull water out of coffee pot.\n"
//    };
    for(int i=0; i<100; i++){
        std::cout << i << " ";
    }
//    auto print = [](const char* step) {std::cout << step;};*
//    std::for_each(brewingSteps.cbegin(), brewingSteps.cend(), print);
}

void MultiThreading::CookBreakfast() {
//    std::vector<const char*> cookingSteps {
//            "Take food out of the fridge.\n",
//            "Heat up the stove.\n",
//            "Put ingredients into the pan.\n",
//            "Done cooking.\n",
//            "Fill food in the plate.\n"
//    };
//    auto print = [](const char* step) {std::cout << step;};*
//
//    std::for_each(cookingSteps.cbegin(), cookingSteps.cend(), print);
    for(int i=101; i<200; i++){
        std::cout << i << " ";
    }
}

void MultiThreading::DisplayMultiThreadingResults() {
    std::cout << "========================== The Beginning of Multi-Threading Examples ==========================\n";
    std::thread brewing(&MultiThreading::BrewCoffee);
    std::thread cooking(&MultiThreading::CookBreakfast);
    // The main thread ends before child threads, it will lead to undefined behavior.

    // Join threads, so that there are no errors.
    brewing.join();
    cooking.join();
    std::cout << "\n";
    std::cout << "========================== The End of Multi-Threading Examples ==========================\n";
}
