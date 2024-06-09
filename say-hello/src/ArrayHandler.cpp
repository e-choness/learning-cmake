#include "ArrayHandler.hpp"
#include <algorithm>
#include <iostream>

int ArrayHandler::getMaxSub(std::vector<int> &numbers) {
    int maxCurrent = numbers[0];
    int maxGlobal = numbers[0];
    for(int i=1; i<numbers.size(); ++i){
        maxCurrent = std::max(numbers[i], maxCurrent + numbers[i]);
        if(maxCurrent > maxGlobal){
            maxGlobal = maxCurrent;
        }
    }
    return maxGlobal;
}

void ArrayHandler::show() {
    std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4, 6, 2, -10};
    std::cout << getMaxSub(nums) << "\n";
}
