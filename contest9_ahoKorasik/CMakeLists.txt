cmake_minimum_required(VERSION 3.23)
project(contest9_ahoKorasik)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -fsanitize=address")

set(CMAKE_CXX_STANDARD 23)

add_executable(contest9_ahoKorasik main.cpp)
add_executable(C C_Duet.cpp)
add_executable(D D_threeLines.cpp)
add_executable(E E_virus.cpp)
add_executable(F F_biology.cpp)
