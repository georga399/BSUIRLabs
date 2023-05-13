cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 23)
project(HashTable)
add_executable(HashTable main.cpp HashTable.h 
    ../../Lab3/cvector/cvector.h 
    ../../Lab3/citerator/citerator.h)