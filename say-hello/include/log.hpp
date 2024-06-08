#pragma once
#include <iostream>
#include <string>

struct Entry;

enum LogType{
    MESSAGE,
    WARNING,
    FATAL_ERROR
};

class Log{
    public:
        static void log_data(const std::string& message, LogType log_type);

};