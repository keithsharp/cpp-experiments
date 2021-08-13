add_library(mylibrary mylibrary.cpp mylibrary.hpp)
target_include_directories(mylibrary PUBLIC .)
target_compile_features(mylibrary PUBLIC cxx_std_17)
