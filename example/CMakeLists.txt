cmake_minimum_required(VERSION 3.0)
project(example)

set(CMAKE_CXX_STANDARD 11)

set(ED_INCLUDE ../include)

include_directories(${ED_INCLUDE})

set(SOURCE_FILES main.cpp)
add_executable(example ${SOURCE_FILES})