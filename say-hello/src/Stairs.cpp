#include "Stairs.hpp"
#include <iostream>


long long Stairs::climb(int stairCount) {
    if(stairCount<1) return 0;

    if(stairCount<=2) return stairCount;

    std::vector<long long> stepList(stairCount+1);
    stepList[1] = 1;
    stepList[2] = 2;

    for(int i=3; i<=stairCount; ++i){
        stepList[i] = stepList[i-1] + stepList[i-2];
    }

    return stepList[stairCount];
}

void Stairs::show() {
    int stairCount;
    std::cin >> stairCount;
    std::cout << climb(stairCount) << "\n";
}
