cmake_minimum_required(VERSION 3.12)
project(SovietTetris)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)

include_directories(
        ${SDL2_INCLUDE_DIRS}
        "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

add_executable(SovietTetris main.cpp)

target_link_libraries(SovietTetris ${SDL2_LIBRARIES})
