cmake_minimum_required(VERSION 3.21.1)

project(FindGLFW
        VERSION 1.0.0
        DESCRIPTION "Find a library (GLFW) on the system"
        LANGUAGES CXX
)

find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)

add_executable(window main.cpp)
target_include_directories(window PRIVATE ${GLFW_INCLUDE_DIRS})
target_link_directories(window PRIVATE ${GLFW_LIBRARY_DIRS})
target_link_libraries(window ${GLFW_LIBRARIES})
target_compile_features(window PUBLIC cxx_std_17)
set_target_properties(window PROPERTIES CXX_EXTENSIONS OFF)