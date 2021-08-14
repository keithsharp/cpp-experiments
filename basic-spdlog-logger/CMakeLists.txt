cmake_minimum_required(VERSION 3.21.1)

project(FetchGLFW
        VERSION 1.0.0
        DESCRIPTION "Basic logging with spdlog"
        LANGUAGES CXX
)

include(FetchContent)

FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG        v1.9.2
)

FetchContent_MakeAvailable(spdlog)

add_executable(logger main.cpp)
target_link_libraries(logger spdlog)
target_compile_features(logger PUBLIC cxx_std_17)
set_target_properties(logger PROPERTIES CXX_EXTENSIONS OFF)