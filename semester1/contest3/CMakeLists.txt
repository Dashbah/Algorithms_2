set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -fsanitize=address")

cmake_minimum_required(VERSION 3.23)
project(contest3)

set(CMAKE_CXX_STANDARD 14)

add_executable(contest3 .clang-tidy myList.cpp Merge.cpp bracketSequence.cpp)
