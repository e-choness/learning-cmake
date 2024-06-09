#include "HtmlProvider.hpp"
#include "HtmlParser.hpp"

void HtmlProvider::showResults() {
    HtmlParser parser;
    parser.readNumbers();
    parser.readLines();
    parser.readQueries();
}


