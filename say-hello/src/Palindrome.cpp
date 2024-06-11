#include "Palindrome.hpp"
#include <iostream>
#include <vector>

void Palindrome::show() {

}

std::string Palindrome::findLongest(std::string &s) {
    int size = s.size();
    // If the string is empty, nothing to compare, return empty string.
    if (size == 0) return "";

    // Build check table
    std::vector<std::vector<bool>> checkTable(size, std::vector<bool>(size, false));

    // Initialize start and max index
    int start = 0;
    int max = 1;

    // Single character is a palindrome
    for(int i=0; i<size; ++i){
        checkTable[i][i] = true;
    }

    return std::string();
}
