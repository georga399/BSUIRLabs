# cmake_minimum_required(VERSION 3.5)
message("-- Linking string")

# project(string VERSION 0.1 LANGUAGES CXX)

add_library(string SHARED custcstring.h custcstring.cpp string.h string.cpp)
set_target_properties(string PROPERTIES LINKER_LANGUAGE C)
