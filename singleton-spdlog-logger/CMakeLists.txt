cmake_minimum_required(VERSION 3.21.1)

project(LoggerExample
        VERSION 1.0.0
        DESCRIPTION "Basic logging with spdlog"
        LANGUAGES CXX
)

add_subdirectory(logger)
add_subdirectory(app)