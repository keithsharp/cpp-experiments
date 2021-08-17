#include "logger.hpp"

#include <spdlog/spdlog.h>

void Logger::info() {
    get().infoImpl();
}

void Logger::infoImpl() {
    spdlog::info("Hello from the logger!");
}