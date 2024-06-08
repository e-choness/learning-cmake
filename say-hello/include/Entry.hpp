#pragma once
#include <iostream>

using std::string;

struct Entry{
    string mFullName;
    int mPhoneNumber;
    friend std::ostream& operator<<(std::ostream& os, const Entry& entry) {
            return os << "Full Name: " << entry.mFullName << "Phone Number" << entry.mPhoneNumber << "\n";
    }
};