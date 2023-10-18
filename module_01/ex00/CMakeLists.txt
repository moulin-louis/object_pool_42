cmake_minimum_required(VERSION 3.22)
project(ex00)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "-Wall -Werror -Wextra")

add_executable(ex00 ./src/main.cpp
        ./src/Hammer.cpp
        ./src/Shovel.cpp
        ./src/Tool.cpp
        ./src/Worker.cpp
        ./src/Workshop.cpp
        ./inc/Hammer.hpp
        ./inc/Position.hpp
        ./inc/Shovel.hpp
        ./inc/Statistic.hpp
        ./inc/Tool.hpp
        ./inc/Worker.hpp
        ./inc/Workshop.hpp)