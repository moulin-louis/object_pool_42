cmake_minimum_required(VERSION 3.22)
project(ex02)

set(CMAKE_CXX_STANDARD 11)

add_compile_options(-g -Wall -Werror)
include_directories(./inc)
add_executable(ex02
        src/main.cpp
        src/Course.cpp
        src/Person.cpp
        src/Room.cpp
        src/Form.cpp
        src/Staff.cpp)