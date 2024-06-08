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
        static void logData(const std::string &message, LogType logType);
        static void logData(const Entry& entry, LogType logType);
};