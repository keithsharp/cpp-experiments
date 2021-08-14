cmake_minimum_required(VERSION 3.21.1)

project(PseudoRandomNumbers
        VERSION 1.0.0
        DESCRIPTION "Generate pseudo random numbers based on user supplied seed"
        LANGUAGES CXX
)

find_package(Boost 1.76.0 REQUIRED COMPONENTS program_options)

add_executable(random main.cpp)
target_link_libraries(random Boost::program_options)
target_compile_features(random PUBLIC cxx_std_17)
set_target_properties(random PROPERTIES CXX_EXTENSIONS OFF)