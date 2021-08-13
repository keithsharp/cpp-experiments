cmake_minimum_required(VERSION 3.21.1)

project(HelloLibrary
        VERSION 1.0.0
        DESCRIPTION "CMake small library example"
        LANGUAGES CXX
)

add_subdirectory(subdir)

add_executable(hello main.cpp)
target_link_libraries(hello mylibrary)
target_compile_features(hello PUBLIC cxx_std_17)
set_target_properties(hello PROPERTIES CXX_EXTENSIONS OFF)