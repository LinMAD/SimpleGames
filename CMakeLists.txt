cmake_minimum_required(VERSION 3.12)
project(PlainTetris)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

add_executable(PlainTetris main.cpp)
