cmake_minimum_required(VERSION 3.21.1)

project(HelloWorld
        VERSION 1.0.0
        DESCRIPTION "A basic CMake example"
        LANGUAGES CXX
)

add_executable(hello main.cpp)
target_compile_features(hello PUBLIC cxx_std_17)
set_target_properties(hello PROPERTIES CXX_EXTENSIONS OFF)