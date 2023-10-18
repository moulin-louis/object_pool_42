cmake_minimum_required(VERSION 3.22)
project(ex00)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "-Wall -Werror -Wextra")

add_executable(ex00 ./src/main.cpp
        src/Car.cpp
        inc/Car.hpp
        src/Engine.cpp
        inc/Engine.hpp
        src/Wheels.cpp
        inc/Wheels.hpp
        src/Gears.cpp
        inc/Gears.hpp
        src/SpeedControl.cpp
        inc/SpeedControl.hpp)