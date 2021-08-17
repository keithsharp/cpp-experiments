include(FetchContent)

FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG        v1.9.2
)

FetchContent_MakeAvailable(spdlog)

add_library(logger logger.cpp logger.hpp)

target_include_directories (logger PRIVATE ${spdlog_SOURCE_DIR}/include)

target_compile_features(logger PUBLIC cxx_std_17)
