#include "Logger.hpp"

#include <iostream>

void Logger::log(std::string message) {
    std::cout << message << std::endl;
}

void Logger::warn(std::string message) {
    std::cout << message << std::endl;
}

void Logger::error(std::string message) {
    std::cerr << message << std::endl;
}
