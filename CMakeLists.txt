cmake_minimum_required(VERSION 3.27)
project(untitled4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(untitled4 main.cpp
        src/Philosopher.cpp
        src/Philosopher.h
        src/Fork.cpp
        src/Fork.h)
