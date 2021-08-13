cmake_minimum_required(VERSION 3.21.1)

project(MultipleSource
        VERSION 1.0.0
        DESCRIPTION "Multiple source files/directories example"
        LANGUAGES CXX
)

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "subdir/*.cpp")

add_executable(hello main.cpp ${SOURCES})
target_compile_features(hello PUBLIC cxx_std_17)
set_target_properties(hello PROPERTIES CXX_EXTENSIONS OFF)