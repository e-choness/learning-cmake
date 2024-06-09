#pragma once
#include <vector>

class ArrayHandler {
public:
    static void show();
private:
    static int getMaxSub(std::vector<int>& numbers);
};