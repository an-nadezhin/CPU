cmake_minimum_required(VERSION 3.8)
project(CPU)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES CPU.cpp assembler.cpp)
add_executable(CPU ${SOURCE_FILES})