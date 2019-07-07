cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)

add_executable(cut_stick.cpp cut_stick.cpp)
add_executable(matrix_mult matrix_multiplication.cpp)
add_executable(matrix_ordering matrix_ordering.cpp ../random/random_data.h ../random/random_data.cpp)
