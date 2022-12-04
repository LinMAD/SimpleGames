cmake_minimum_required(VERSION 3.2)
project(rogesci-console-game)
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

set(ROGESCI_INSTALL_BIN_DIR ${PROJECT_SOURCE_DIR}/bin)

set(ROGESCI_HEADERS_DIR ${PROJECT_SOURCE_DIR}/src/Game)

include_directories(${ROGESCI_HEADERS_DIR})

add_subdirectory(src)
