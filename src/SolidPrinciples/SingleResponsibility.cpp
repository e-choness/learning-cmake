//
// Created by Echo Yin on 2023-06-17.
//
#include "SingleResponsibility.h"

void Journal::Add(const std::string &entry) {
    static int count = 1;
    std::vector<std::string> entries;
    entries.push_back(std::to_string(count++) + ": " + entry);
}