#pragma once
#include "QueryBuilder.hpp"

class HtmlParser{
public:
    void readNumbers();
    void readLines();
    void readQueries();
private:
    QueryBuilder queryBuilder;
    int mLineCount{0};
    int mQueryCount{0};
};