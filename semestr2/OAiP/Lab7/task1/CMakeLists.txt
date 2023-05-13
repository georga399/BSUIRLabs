cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 23)
project(heap)
add_executable(heap main.cpp array_heap.h cshared_ptr.h)