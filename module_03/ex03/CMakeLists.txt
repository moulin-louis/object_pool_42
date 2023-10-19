cmake_minimum_required(VERSION 3.13)  # CMake version check
project(ex03)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 98)            # Enable c++14 standard

# Add main.cpp file of the project root directory as a source file
set(SOURCE_FILES src/main.cpp
        inc/hourlyEmployee.hpp
        inc/salariedEmployee.hpp)
include_directories(./inc)

add_compile_options(-g -Wall -Werror -Wextra)
# Add executable target with source files listed in SOURCE_FILES variable
add_executable(ex03 ${SOURCE_FILES})