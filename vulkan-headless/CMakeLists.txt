cmake_minimum_required(VERSION 3.21.1)

project(VulkanHeadless
        VERSION 1.0.0
        DESCRIPTION "Testing Vulkan C API without drawing anything"
        LANGUAGES CXX
)

find_package(Vulkan REQUIRED)
if (${Vulkan_FOUND}) 
    message(STATUS "Found vulkan")
else (${Vulkan_FOUND}) 
    message(FATAL_ERROR "Could not find vulkan")
endif (${Vulkan_FOUND})

add_executable(vulkan main.cpp)
target_compile_features(vulkan PUBLIC cxx_std_17)

target_include_directories(vulkan PRIVATE ${Vulkan_INCLUDE_DIRS})
target_link_directories(vulkan PRIVATE ${Vulkan_LIBRARY_DIRS})
target_link_libraries(vulkan PRIVATE ${Vulkan_LIBRARIES})