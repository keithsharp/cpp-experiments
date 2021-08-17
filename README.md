# C++ Experiments
Small experiments with C++ and associated tools, mainly CMake at the moment.

+ [`cmake-basic`](https://github.com/keithsharp/cpp-experiments/tree/main/cmake-basic) - simple, single C++ file CMake example.
+ [`cmake-subdir`](https://github.com/keithsharp/cpp-experiments/tree/main/cmake-subdir) - include source files from a subdirectory.
+ [`cmake-library`](https://github.com/keithsharp/cpp-experiments/tree/main/cmake-library) - make a library using files in a subdirectory and link to executable.
+ [`cmake-find-glfw`](https://github.com/keithsharp/cpp-experiments/tree/main/cmake-find-glfw) - use CMake `find_package` and `pkg-config` to link to GLFW.
+ [`cmake-fetchcontent-glfw`](https://github.com/keithsharp/cpp-experiments/tree/main/cmake-fetchcontent-glfw) - use CMake `FetchContent` module to download, build, and link to GLFW.
+ [`boost-program-options`](https://github.com/keithsharp/cpp-experiments/tree/main/boost-program-options) - use Boost `program_options` library to parse command line arguments.
+ [`pseudo-random-numbers`](https://github.com/keithsharp/cpp-experiments/tree/main/pseudo-random-numbers) - generate pseudo random integers and floats based on a user supplied seed.
+ [`basic-spdlog-logger`](https://github.com/keithsharp/cpp-experiments/tree/main/basic-spdlog-logger) - simple test of building and using spdlog.
+ [`boost-download-build`](https://github.com/keithsharp/cpp-experiments/tree/main/boost-download-build) - download and build Boost rather than using the system version.
+ [`singleton-spdlog-logger`](https://github.com/keithsharp/cpp-experiments/tree/main/singleton-spdlog-logger) - abstract spdlog behind a singleton logger class.

## Pre-requisites
Stuff you need to make this work, mainly for macOS.  I'm assuming you've got [HomeBrew](https://brew.sh) installed which has caused the `xcode-tools` to be installed, and hence `clang++`, `git`, and `make` to be installed.

1. Install CMake using HomeBrew: `brew install cmake`.
2. For the `cmake-find-glfw` example you'll need to install GLFW with HomeBrew: `brew install glfw`.
3. For experiments using Boost you'll need to install Boost with HomeBrew: `brew install boost`.  You'll also need to make sure the installed Boost version matches that specified in the `CMakeLists.txt` file.

VS Code Extensions:
1. [C/C++ for Visual Studio Code](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools).
2. [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools)

## Copyright and Licence
Copyright 2021, Keith Sharp kms@passback.co.uk.

This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>.