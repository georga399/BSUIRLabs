cmake_minimum_required(VERSION 3.0.0)
project(task2)


add_executable(task2 main.cpp)

add_library(algo SHARED algo.cpp)
#add_library(inputs SHARED inputs.cpp)
#target_link_libraries(task2 algo )
