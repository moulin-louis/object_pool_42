cmake_minimum_required(VERSION 3.22)
project(ex03)

set(CMAKE_CXX_STANDARD 98)

include_directories(./inc)

add_compile_options(-g -Wall -Werror -Wextra)

add_executable(ex03 src/main.cpp)