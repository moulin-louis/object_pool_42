cmake_minimum_required(VERSION 3.22)
project(ex00)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "-Wall -Werror -Wextra")

add_executable(ex01
        ./src/main.cpp
        ./src/Hammer.cpp
        ./inc/Hammer.hpp
        ./src/Shovel.cpp
        ./inc/Shovel.hpp
        ./src/Tool.cpp
        ./inc/Tool.hpp
        ./src/Worker.cpp
        ./inc/Worker.hpp
        ./src/Workshop.cpp
        ./inc/Workshop.hpp
        ./inc/Position.hpp
)
