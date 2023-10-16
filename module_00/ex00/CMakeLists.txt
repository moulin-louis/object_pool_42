cmake_minimum_required(VERSION 3.26)
project(module_00)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "-Wall -Werror -Wextra")

add_executable(module_00 main.cpp
        Account.cpp
        Account.hpp
        Bank.cpp
        Bank.hpp)
