//
// Created by echo_ on 2023-08-30.
//

#include "Iterators.hpp"
#include <vector>
#include <iterator>
#include <iostream>

void Iterators::DisplayIteratorsResults() {
    std::vector<int> nums {1,2,3,4};
    std::istream_iterator<int> input(std::cin);
    std::copy(input, std::istream_iterator<int>(), std::back_inserter(nums));
}
