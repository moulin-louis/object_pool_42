cmake_minimum_required(VERSION 3.22)
project(ex00)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "-Wall -Werror -Wextra")

add_executable(ex00
        main.cpp
        Bank.cpp
        Bank.hpp
)
