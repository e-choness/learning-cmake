#include "QueryBuilder.hpp"

std::tuple<std::string, std::stringstream> QueryBuilder::getTag(std::string& line) {
    // Opening tag or standalone tag
    std::stringstream ss(line); // Convert the html line to stringstream for searching tags, attributes and values
    std::string tag; // tag stores the tag after '< '
    char ch; // ch stores the first character after '<', normally a whitespace
    ss >> ch >> tag; // Reads tag and a whitespace before it.

    // Find closing '>' and remove it
    if(tag.back() == '>') tag.pop_back();

    return std::make_tuple(tag, std::move(ss));
}

std::string QueryBuilder::getValue(std::string &query) {
    if(mTagMap.find(query) != mTagMap.end()){
        return mTagMap[query];
    }else{
        return "Not Found!";
    }
}

void QueryBuilder::build(std::string &line) {
    if(line.substr(0, 2) == "</"){
        mTagStack.pop_back();
    }else{
        auto [tag, ss] = getTag(line);
        auto key = createKey(tag);

        // Store tag to stack
        mTagStack.push_back(tag);

        readAttributes(ss, key);
    }
}

std::string QueryBuilder::createKey(std::string &tag) {
    // Create query key for mapping values
    std::string key;
    for(std::string t : mTagStack) key += t + ".";
    key += tag;

    return key;
}

void QueryBuilder::readAttributes(std::stringstream &ss, std::string& key) {
    std::string attribute, value;
    char ch;

    while(ss >> attribute){
        if(attribute == "=") continue;
        ss >> ch >> value;
        value = trim(value);
        key.append("~");
        key.append(attribute);
        mTagMap[key] = value;
    }
}

std::string QueryBuilder::trim(std::string &value) {
    size_t pos;
    while((pos = value.find_first_of("\"<>")) != std::string::npos){
        value.replace(pos, 1, "");
    }
    return value;
}
