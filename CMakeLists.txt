cmake_minimum_required(VERSION 3.23)
project(ForTesting)

set(CMAKE_CXX_STANDARD 17)

add_executable(A5_0 test.cpp)
add_executable(A0_0 main.cpp)
add_executable(A4 Implementation.cpp)
add_executable(A3_0 Recursion.cpp)
add_executable(A1_0 CP_problem.cpp)
add_executable(A2_0 Soring.cpp)
include_directories(include/My_Header_Files)
