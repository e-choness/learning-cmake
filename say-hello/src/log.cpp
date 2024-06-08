#include "log.hpp"
#include "Entry.hpp"

void Log::logData(const std::string& message, LogType logType)
{
    switch (logType)
    {
    case LogType::MESSAGE:
        std::cout << "Message: " << message << "\n";
        break;
    case LogType::WARNING:
        std::cout << "Warning: " << message << "\n";
        break;
    case LogType::FATAL_ERROR:
        std::cout << "Fatal Error: " << message << "\n";
        break;
    default:
        std::cout << "Unknown Log Type: " << logType << "\n";
        break;
    }
}

void Log::logData(const Entry& entry, LogType logType) {
    switch (logType)
    {
        case LogType::MESSAGE:
            std::cout << "Message: " << entry << "\n";
            break;
        case LogType::WARNING:
            std::cout << "Warning: " << entry << "\n";
            break;
        case LogType::FATAL_ERROR:
            std::cout << "Fatal Error: " << entry << "\n";
            break;
        default:
            std::cout << "Unknown Log Type: " << entry << "\n";
            break;
    }
}


