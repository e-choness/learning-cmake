#include "HtmlParser.hpp"
#include <iostream>

void HtmlParser::readNumbers() {
    std::cin >> mLineCount >> mQueryCount;
    std::cin.ignore();
}

void HtmlParser::readLines() {
    for(int i = 0; i < mLineCount; i++){
        std::string line;
        std::getline(std::cin, line);
        queryBuilder.build(line);
    }
}

void HtmlParser::readQueries() {
    for(int i=0; i < mQueryCount; i++){
        std::string query;
        std::getline(std::cin, query);
        std::cout << queryBuilder.getValue(query) << "\n";
    }
}