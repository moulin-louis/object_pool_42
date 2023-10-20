cmake_minimum_required(VERSION 3.22)
project(ex04)

set(CMAKE_CXX_STANDARD 98)

add_compile_options(-g -Wall -Werror -Wextra)
include_directories(./inc)
add_executable(ex04
        src/main.cpp
        src/FileLogger.cpp)