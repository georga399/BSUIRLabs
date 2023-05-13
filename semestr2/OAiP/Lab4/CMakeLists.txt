cmake_minimum_required(VERSION 3.5)

project(Example VERSION 0.1 LANGUAGES CXX)

add_executable(Example main.cpp
         
                )
add_library(cstring SHARED task2/string.h task2/string.cpp task2/custcstring.h task2/custcstring.cpp)
target_link_libraries(Example cstring)
