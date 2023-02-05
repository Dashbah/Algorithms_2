set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -fsanitize=address")

cmake_minimum_required(VERSION 3.23)
project(contest2_linearAndIterativeSortings)

set(CMAKE_CXX_STANDARD 14)

add_executable(contest2_linearAndIterativeSortings E_Keyboard.cpp)
