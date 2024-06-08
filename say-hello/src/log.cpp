#include "log.hpp"

void Log::log_data(const std::string& message, LogType log_type)
{
    switch (log_type)
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
        std::cout << "Unknown Log Type: " << log_type << "\n";
        break;
    }
}


