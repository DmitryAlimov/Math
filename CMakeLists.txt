cmake_minimum_required(VERSION 3.21)
project(Math)
set(CMAKE_CXX_STANDARD 14)

set(EIGEN_DIR "C:/Program Files/JetBrains/CLion 2021.3.4/eigen-3.4.0")
include_directories(${EIGEN_DIR})

add_executable(Math main.cpp)


