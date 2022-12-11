cmake_minimum_required(VERSION 3.12)
project(SimpleTetris)

set(CMAKE_CXX_STANDARD 17)

include_directories("src")
if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
else()
    message(WARNING "The file conanbuildinfo.cmake doesn't exist, you have to run conan install first")
endif()

set(SOURCE_FILES main.cpp)
add_executable(SimpleTetris ${SOURCE_FILES})

target_link_libraries(SimpleTetris ${CONAN_LIBS})
