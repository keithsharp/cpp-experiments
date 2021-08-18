cmake_minimum_required(VERSION 3.21.1)

project(FindPackageTest
        VERSION 1.0.0
        DESCRIPTION "CMake find_package test"
        LANGUAGES CXX
)

find_package(spdlog REQUIRED)
if (${spdlog_FOUND}) 
    message(STATUS "Found spdlog")
else (${spdlog_FOUND}) 
    message(FATAL_ERROR "Could not find spdlog")
endif (${spdlog_FOUND}) 

find_package(glm REQUIRED)
if (${glm_FOUND}) 
    message(STATUS "Found glm")
else (${glm_FOUND}) 
    message(FATAL_ERROR "Could not find glm")
endif (${glm_FOUND})

find_package(PkgConfig REQUIRED)
pkg_search_module(glfw REQUIRED glfw3)
if (${glfw_FOUND}) 
    message(STATUS "Found glfw")
else (${glfw_FOUND}) 
    message(FATAL_ERROR "Could not find glfw")
endif (${glfw_FOUND})

find_package(Vulkan REQUIRED)
if (${Vulkan_FOUND}) 
    message(STATUS "Found vulkan")
else (${Vulkan_FOUND}) 
    message(FATAL_ERROR "Could not find vulkan")
endif (${Vulkan_FOUND})

add_executable(test main.cpp)
target_compile_features(test PUBLIC cxx_std_17)

target_link_libraries(test PRIVATE spdlog::spdlog)
target_include_directories(test PRIVATE ${glfw_INCLUDE_DIRS})
target_link_directories(test PRIVATE ${glfw_LIBRARY_DIRS})
target_link_libraries(test PRIVATE ${glfw_LIBRARIES})
target_include_directories(test PRIVATE ${Vulkan_INCLUDE_DIRS})
target_link_directories(test PRIVATE ${Vulkan_LIBRARY_DIRS})
target_link_libraries(test PRIVATE ${Vulkan_LIBRARIES})