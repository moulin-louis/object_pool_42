cmake_minimum_required(VERSION 3.22)
project(ex00)

set(CMAKE_CXX_STANDARD 11)

add_compile_options(-g -Wall -Werror -Wextra)
include_directories(./inc)
add_executable(ex00
        src/main.cpp)