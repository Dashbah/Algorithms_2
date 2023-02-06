cmake_minimum_required(VERSION 3.23)
project(contest3_binaryHeap)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -fsanitize=address")

set(CMAKE_CXX_STANDARD 14)

add_executable(contest3_binaryHeap main.cpp A0_HeapLastIndex.cpp A_LastHeapElement.cpp B_HeapSort.cpp C_Heap.cpp)
add_executable(A A0_HeapLastIndex.cpp)
add_executable(A0 A_LastHeapElement.cpp)
add_executable(B B_HeapSort.cpp)
add_executable(C C_Heap.cpp)