#include "logger.hpp"

#include <spdlog/spdlog.h>

void Logger::info() {
    spdlog::info("Hello from the logger!");
}