cmake_minimum_required(VERSION 3.21.1)

project(FindBoostExample
        VERSION 1.0.0
        DESCRIPTION "Download and build Boost"
        LANGUAGES CXX
)

include(ProcessorCount)
ProcessorCount(CORES)

set( Boost_Bootstrap_Command )
if( UNIX )
        set( Boost_Bootstrap_Command ./bootstrap.sh )
        set( Boost_b2_Command ./b2 )
else()
        if( WIN32 )
                set( Boost_Bootstrap_Command bootstrap.bat )
                set( Boost_b2_Command b2.exe )
        endif()
endif()

include(ExternalProject)
ExternalProject_Add(Boost
        GIT_REPOSITORY https://github.com/boostorg/boost.git
        GIT_TAG boost-1.77.0
        BUILD_IN_SOURCE 1
        CONFIGURE_COMMAND ${Boost_Bootstrap_Command}
        BUILD_COMMAND  ${Boost_b2_Command} install
                --with-program_options
                --disable-icu
                --prefix=${CMAKE_BINARY_DIR}/INSTALL
                --threading=multi
                --variant=release
                -j${CORES}
        INSTALL_COMMAND ""
        INSTALL_DIR ${CMAKE_BINARY_DIR}/INSTALL
)

if( NOT WIN32 )
        set(Boost_LIBRARY_DIR ${CMAKE_BINARY_DIR}/INSTALL/lib/ )
        set(Boost_INCLUDE_DIR ${CMAKE_BINARY_DIR}/INSTALL/include/ )
else()
        set(Boost_LIBRARY_DIR ${CMAKE_BINARY_DIR}/INSTALL/lib/ )
        # I don't think this is right, but I'm not on Win32 so I can't test
        set(Boost_INCLUDE_DIR ${CMAKE_BINARY_DIR}/INSTALL/include/boost-1_49/ )
endif()

add_executable(example main.cpp)
add_dependencies(example Boost)
target_include_directories(example PRIVATE ${Boost_INCLUDE_DIR})
target_link_directories(example PRIVATE ${Boost_LIBRARY_DIR})
target_link_libraries(example boost_program_options)
target_compile_features(example PUBLIC cxx_std_17)
set_target_properties(example PROPERTIES CXX_EXTENSIONS OFF)