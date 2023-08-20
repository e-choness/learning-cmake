//
// Created by echo_ on 2023-08-20.
//

#pragma once
#include <vector>

/* Notes:
 * 1. Binary Search technique works on sorted array.
 * 2. It works on divide and conquer( each iteration it divides array in half).
 *
 * Algorithm:
 * 1. Get middle element of array check if it is the one we are looking.
 * 2. If yes, then we have found the number.
 * 3. If no, then check if the middle element is bigger than our element.
 * 4. If yes, then we will choose left half of the array.
 * 5. Otherwise, we will choose right half of the array.
 * 6. Repeat this until we find the number or return null if the number is not found.
 *
 * COMPLEXITY:
 * Worse Case Time: O(log2(n))
 * Best Case Time: O(1)
 * Average Case Time: O(log2(n))
 * */

#include <iostream>

class BinarySearch {
public:
    explicit BinarySearch(std::vector<int> array, int target):
    m_ArrayInts(std::move(array)),
    m_Target(target){
        if(&m_ArrayInts == nullptr) return;
        std::cout << "========================== Beginning of Binary Search Examples ==========================\n";
        std::cout << m_ArrayInts[Searching()]<< "\n";
        std::cout << "========================== End of Binary Search Examples ==========================\n";
    };
private:
    int Searching();
private:
    std::vector<int> m_ArrayInts;
    int m_Target;
};
