//
// Created by echo_ on 2023-06-17.
//
#pragma once
#include <string>
#include <utility>
#include <vector>

struct Journal{
    std::string Title;
    std::vector<std::string> Entries;

    explicit Journal(std::string  title): Title(std::move(title)){}
    void Add(const std::string& entry);
};


