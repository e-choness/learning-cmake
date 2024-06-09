#pragma once
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <tuple>


class QueryBuilder{
public:
    void build(std::string& line);
    std::string getValue(std::string& query);
private:
    static std::tuple<std::string, std::stringstream> getTag(std::string& line);
    std::string createKey(std::string& tag);
    void readAttributes(std::stringstream& ss, std::string& key);
    static std::string trim(std::string& value);
private:
    std::unordered_map<std::string, std::string> mTagMap;
    std::vector<std::string> mTagStack;
};
