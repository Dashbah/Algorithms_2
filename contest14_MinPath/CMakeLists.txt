cmake_minimum_required(VERSION 3.23)
project(contest14_MinPath)

set(CMAKE_CXX_STANDARD 11)

add_executable(contest14_MinPath main.cpp)
add_executable(A A_Dijkstra.cpp)
add_executable(B B_BelmanFord.cpp)
