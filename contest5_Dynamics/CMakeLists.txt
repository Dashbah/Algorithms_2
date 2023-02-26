cmake_minimum_required(VERSION 3.23)
project(contest5_Dynamics)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -fsanitize=address")

set(CMAKE_CXX_STANDARD 23)

add_executable(contest5_Dynamics main.cpp)
add_executable(A A_LengthOfSequence.cpp)
add_executable(B B_AboutRocks.cpp)
add_executable(D D_WeightedInterval.cpp)
add_executable(C C_Internet.cpp)