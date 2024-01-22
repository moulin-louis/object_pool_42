cmake_minimum_required(VERSION 3.22)
project(ex01)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "-Wall -Werror -Wextra")

add_executable(ex01
        main.cpp
        Graph.cpp
        Graph.hpp
        Vector2.cpp
        Vector2.hpp
)