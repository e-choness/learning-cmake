//
// Created by echo_ on 2023-08-27.
//

#include "DesignatedInitializers.hpp"

void DesignatedInitializers::DisplayInitializerResults() {
    std::cout << "========================== Beginning of Designated Initializers Examples ==========================\n";
    S2 s{.i= 1, .f = 1.0, .d = 2.0};
    useParameters({.i=2, .f=2.0, .d= 3.0});
    std::cout << "========================== End of Designated Initializers Examples ==========================\n";
}
