set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -fsanitize=address")

cmake_minimum_required(VERSION 3.23)
project(contest6_rbt_new)

set(CMAKE_CXX_STANDARD 14)

add_executable(contest6_rbt_new main.cpp AVL_tree.cpp)
