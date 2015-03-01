cmake_minimum_required(VERSION 2.8.4)
project(2lab20)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    2lab20/array.cpp
    2lab20/array.h
    2lab20/main.cpp
    2lab20/strings.cpp
    2lab20/strings.h)

add_executable(2lab20 ${SOURCE_FILES})