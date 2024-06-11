#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>

void sortWords(std::vector<std::string>& words) {
    std::map<int, std::vector<std::string>> priorityMap;

    // Construct priority map for the words
    // Words starting with f get 0 for priority key
    // Words starting with l get 2 for priority key
    // Words starting with neither f nor l get 1 for priority key
    for (const std::string& s : words) {
        char first = s[0];
        int priority = (first == 'f') ? 0 : (first == 'l') ? 2 : 1;
        priorityMap[priority].push_back(s);
    }

    // Sort strings inside the values of priority map
    for (auto& pair : priorityMap) {  // Note: Remove `const` here
        std::sort(
                pair.second.begin(),
                pair.second.end(),
                [](const std::string& first, const std::string& second) {
                    return first < second;
                });
    }

    // Reconstruct words into sorted order
    words.clear();
    for (const auto& pair : priorityMap) {
        for (const std::string& s : pair.second) {
            words.push_back(s);
        }
    }
}

void printWords(const std::vector<std::string>& words){
    for(const auto& word : words){
        std::cout << word << " ";
    }
    std::cout << "\n";
}

bool validate(const std::vector<std::string>& actual, const std::vector<std::string>& expected){
    for(int i=0; i< actual.size(); i++){
        if(!std::equal(actual[i].begin(), actual[i].end(),expected[i].begin(), expected[i].end())){
            return false;
        }
    }
    return true;
}

void runTests(){
    std::vector<std::string> actual = {"my", "last", "car", "was", "on", "fire"};
    std::vector<std::string> expected = { "fire", "car", "my", "on", "was", "last"};
    sortWords(actual);
    if(validate(actual, expected)) std::cout << "Pass!\n";
    else std::cout << "Fail!\n";
}
