cmake_minimum_required(VERSION 3.23)
project(contest3_binaryHeap)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -fsanitize=address")

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS_ASAN "-g -fsanitize=address"
        CACHE STRING "Compiler flags in asan build"
        FORCE)

set(CMAKE_CXX_FLAGS_UBSAN "-g -fsanitize=undefined"
        CACHE STRING "Compiler flags in ubsan build"
        FORCE)

add_executable(contest3_binaryHeap main.cpp A0_HeapLastIndex.cpp A_LastHeapElement.cpp B_HeapSort.cpp C_Heap.cpp D_GrazdanskayaOborona.cpp E_LifeAfterZAVOD.cpp)
add_executable(A A0_HeapLastIndex.cpp)
add_executable(A0 A_LastHeapElement.cpp)
add_executable(B B_HeapSort.cpp)
add_executable(C C_Heap.cpp)
add_executable(D D_GrazdanskayaOborona.cpp)
add_executable(E E_LifeAfterZAVOD.cpp)