cmake_minimum_required(VERSION 3.13)
project(Labo5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wconversion -Wextra -pedantic")

set(CMAKE_CXX_STANDARD 11)

add_executable(Labo5 main.cpp StackList.h)