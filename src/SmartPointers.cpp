//
// Created by echo_ on 2023-08-26.
//

#include "SmartPointers.hpp"
#include <iostream>

void SmartPointers::DisplaySmartPointerResult() {
    std::unique_ptr<int> uniquePtr = std::make_unique<int>(25);
    // unique pointer's ownership cannot be assigned using =
    // but using std::move() can reassign a unique pointer's ownership to an address.
    std::unique_ptr<int> uniquePtr2 = std::move(uniquePtr);
    //If right now I'm trying to access uniquePtr, the code can still compile but returns the address 0x00000000
    std::cout<< "Unique pointer address is moved to: " << uniquePtr << "\n";
    // Initializing a unique pointer class like this will not invoke constructor and deconstructor.
    std::unique_ptr<UniqueClass> uniqueClass{};
    // Initializing by using make_unique will invoke constructor and deconstructor.
    std::unique_ptr<UniqueClass> uniqueClass1 = std::make_unique<UniqueClass>();

}

void SmartPointers::DisplaySharedPointerResult() {
    std::shared_ptr<SharedClass> sharedPtr = std::make_shared<SharedClass>();
    std::shared_ptr<SharedClass> sharedClass = std::make_shared<SharedClass>();
    std::cout << "Share pointer counts to the ownership of an address: " << sharedPtr.use_count() << "\n";
    {// The lifetime of shared pointer created in within this scope ends with at the end of the bracket.
        // Copy or move semantics are both worked here.
        std::shared_ptr<SharedClass> sharedPtr1{sharedPtr};
        std::shared_ptr<SharedClass> sharedPtr2 = sharedPtr;
        std::cout << "Share pointer counts to the ownership of an address: " << sharedPtr.use_count() << "\n";

        // Interestingly, std::move() will call desconstructor once it is moved;
        std::shared_ptr<SharedClass> sharedPtr3 = std::move(sharedPtr);
        std::cout << "Share pointer counts to the ownership of an address: " << sharedPtr.use_count() << "\n";

        // Using {} assignment will on std::move() will also call deconstructor;
        std::shared_ptr<SharedClass> sharedPtr4{std::move(sharedClass)};
        std::cout << "Share pointer counts to the ownership of an address: " << sharedClass.use_count() << "\n";
    }
    std::cout << "Share pointer counts to the ownership of an address: " << sharedPtr.use_count() << "\n";
}

UniqueClass::UniqueClass() {
    std::cout << "I'm a constructor on this unique pointer." << "\n";
}

UniqueClass::~UniqueClass() {
    std::cout << "The unique pointer to the instance of this class is deconstructed." << "\n";
}

SharedClass::SharedClass() {
    std::cout << "I'm a constructor on this share pointer." << "\n";
}

SharedClass::~SharedClass() {
    std::cout << "The shared pointer to the instance of this class is deconstructed." << "\n";
}
