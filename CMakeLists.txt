cmake_minimum_required(VERSION 3.10)
project(clrs)

set(CMAKE_CXX_STANDARD 11)

add_executable(clrs_1 Chapter_2/insertion_sort.cpp Chapter_2/my_functions.h)
add_executable(clrs_2 Chapter_2/merge_sort.cpp)
add_executable(clrs_3 Chapter_2/2.3-7.cpp)

