cmake_minimum_required(VERSION 3.23)
project(contest11_graphs)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -fsanitize=address")

set(CMAKE_CXX_STANDARD 11)

add_executable(contest11_graphs main.cpp)
add_executable(A A_Kon.cpp)
add_executable(B B_KonAndFamily1.cpp)
add_executable(C C_KonAndFamily2.cpp)