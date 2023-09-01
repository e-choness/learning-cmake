//
// Created by echo_ on 2023-08-30.
//

#include "Iterators.hpp"
#include <vector>
#include <iterator>
#include <iostream>
#include <list>

void Iterators::DisplayIteratorsResults() {
    std::cout << "========================== Begin of Iterator Examples ==========================\n";
    AdvanceIterator();
    BackInsertIterator();
    IteratorBegin();
    std::cout << "========================== End of Iterator Examples ==========================\n";
}

void Iterators::AdvanceIterator() {
    std::list<int> myList;
    for(int i=0; i<10; i++)
        myList.push_back(i*10);
    auto  it = myList.begin();
    std::advance(it,5);
    std::cout << "The sixth element in my list is: " << *it <<".\n";
}

void Iterators::BackInsertIterator() {
    std::vector<int> foo, bar;
    for(int i=1; i<=5; i++){
        foo.push_back(i);
        bar.push_back(i*10);
    }

    std::copy (bar.begin(), bar.end(), std::back_inserter(foo));

    std::cout << "foo contains:";
    for(auto  it = foo.begin(); it!=foo.end(); ++it)
        std::cout << " " << *it;
    std::cout << "\n";
}

void Iterators::IteratorBegin() {
    int foo[] {10, 20, 30, 40, 50};
    std::vector<int> bar;

    for(auto it=std::begin(foo); it!=std::end(foo); ++it)
        bar.push_back(*it);

    std::cout << "bar contains";
    for(auto it=std::begin(bar);it!=std::end(bar); ++it)
        std::cout << " " << *it;
    std::cout << "\n";
}




