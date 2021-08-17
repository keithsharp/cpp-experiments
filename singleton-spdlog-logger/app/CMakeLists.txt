add_executable(app main.cpp)

target_include_directories (app PRIVATE ${CMAKE_SOURCE_DIR})
target_link_libraries (app PRIVATE logger)

target_compile_features(app PUBLIC cxx_std_17)