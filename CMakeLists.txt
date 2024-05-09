cmake_minimum_required(VERSION 3.28)
project(untitled)

set(CMAKE_CXX_STANDARD 23)

add_executable(untitled
        ProyectoUni.cpp)
set(-Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion)
set(-pedantic-errors)
set(CMAKE_EXE_LINKER_FLAGS "-static")