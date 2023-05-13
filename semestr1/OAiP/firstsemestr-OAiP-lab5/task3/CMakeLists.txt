cmake_minimum_required(VERSION 3.1)
project(test)
add_library(sum SHARED sum.cpp)
add_executable(test main.cpp)