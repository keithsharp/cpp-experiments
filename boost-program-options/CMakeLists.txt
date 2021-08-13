cmake_minimum_required(VERSION 3.21.1)

project(BoostProgramOptions
        VERSION 1.0.0
        DESCRIPTION "A basic Boost Program Options example"
        LANGUAGES CXX
)

find_package(Boost 1.76.0 REQUIRED COMPONENTS program_options)

add_executable(example main.cpp)
target_link_libraries(example Boost::program_options)
target_compile_features(example PUBLIC cxx_std_17)
set_target_properties(example PROPERTIES CXX_EXTENSIONS OFF)