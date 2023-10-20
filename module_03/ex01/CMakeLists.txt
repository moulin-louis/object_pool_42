cmake_minimum_required(VERSION 3.22)
project(ex01)

set(CMAKE_CXX_STANDARD 98)

add_compile_options(-g -Wall -Werror -Wextra)

add_executable(ex01 main.cpp
        command.hpp
        thuesdayDiscount.hpp
        packageReductionDiscount.hpp)
