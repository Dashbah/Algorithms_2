cmake_minimum_required(VERSION 3.23)
project(contest10_LZW)

set(CMAKE_CXX_STANDARD 17)

add_executable(contest10_LZW main.cpp)
add_executable(A A_encoding.cpp)
add_executable(B B_decoding.cpp)