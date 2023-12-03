cmake_minimum_required(VERSION 3.26)
project(Lab3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(stack)

add_executable(Lab3
        stack/TStack.h
        postfix.cpp
        postfix.h
        main.cpp)
