//
// Created by echo_ on 2023-08-30.
//

#include "Iterators.hpp"
#include <vector>
#include <iterator>
#include <iostream>
#include <list>
#include <deque>
#include <algorithm>

void Iterators::DisplayIteratorsResults() {
    std::cout << "========================== Begin of Iterator Examples ==========================\n";
    AdvanceIterator();
    BackInsertIterator();
    IteratorBegin();
    Distance();
    FrontInsertIterator();
    MakeMoveIterator();
    Next();
    Previous();
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

void Iterators::Distance() {
    std::list<int> aList;
    for(int i=0; i<10; i++)
        aList.push_back(i*10);

    auto first = aList.begin();
    auto last = aList.end();

    std::cout << "The distance is: " << std::distance(first, last) << "\n";
}

void Iterators::FrontInsertIterator() {
    std::deque<int> foo, bar;
    for(int i=0; i<=5; i++){
        foo.push_back(i);
        bar.push_back(i*10);
    }

    std::copy(bar.begin(), bar.end(), std::front_inserter(foo));

    std::cout << "foo contains:";
    for(auto it = foo.begin(); it!=foo.end(); ++it)
        std::cout << " " << *it;
    std::cout << "\n";
}

void Iterators::MakeMoveIterator() {
    std::vector<std::string> foo(3);
    std::vector<std::string> bar {"one", "two", "three"};

    // move_iterator adapts an iterator so that dereferencing it produces rvalue references
    // As if std::move was applied, while all other operations behave the same.
    std::copy (std::make_move_iterator(bar.begin()),
               std::make_move_iterator(bar.end()),
               foo.begin());

    bar.clear();

    std::cout << "foo:";
    for(auto& x: foo)
        std::cout << " " << x;
    std::cout << "\n";
}

void Iterators::Next() {
    std::list<int> myList;
    for(int i=0; i<10; i++){
        myList.push_back(i*10);
    }

    std::cout << "my list:";
    std::for_each(myList.begin(), std::next(myList.begin(),5),
                  [](int x){std::cout << " " << x;});

    std::cout << "\n";
}

void Iterators::Previous() {
    std::list<int> myList;
    for(int i=0; i<10; i++){
        myList.push_back(i*10);
    }
    std::cout << "The last element is " << *std::prev(myList.end()) << "\n";
}






