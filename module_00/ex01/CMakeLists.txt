cmake_minimum_required(VERSION 3.26)
project(ex01)

set(CMAKE_CXX_STANDARD 17)

add_executable(ex01 main.cpp
        Vector2.cpp
        Vector2.hpp
        Graph.cpp
        Graph.hpp)
