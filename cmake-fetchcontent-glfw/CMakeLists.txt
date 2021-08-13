cmake_minimum_required(VERSION 3.21.1)

project(FindGLFW
        VERSION 1.0.0
        DESCRIPTION "Find a library (GLFW) on the system"
        LANGUAGES CXX
)

include(FetchContent)

FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG        3.3.4
)

FetchContent_MakeAvailable(glfw)

add_executable(window main.cpp)
target_link_libraries(window glfw)
target_compile_features(window PUBLIC cxx_std_17)
set_target_properties(window PROPERTIES CXX_EXTENSIONS OFF)