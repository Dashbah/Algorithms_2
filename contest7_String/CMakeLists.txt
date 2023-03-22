cmake_minimum_required(VERSION 3.23)
project(contest7_String)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -fsanitize=address")

set(CMAKE_CXX_STANDARD 23)

add_executable(contest7_String main.cpp)
add_executable(A A_KMP.cpp)
add_executable(B B_VagnerFisher.cpp)
add_executable(C С_Levenshtein.cpp)