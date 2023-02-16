cmake_minimum_required(VERSION 3.23)
project(contest4_ScanLine)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -fsanitize=address")

set(CMAKE_CXX_STANDARD 17)

add_executable(contest4_ScanLine main.cpp)
add_executable(A A_DotsAndLines.cpp)
add_executable(B B_maxSquare.cpp)
add_executable(C C_MaxSum.cpp)
add_executable(E E_PrefixSumsMatrix.cpp)