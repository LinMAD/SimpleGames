cmake_minimum_required(VERSION 3.2)
project(Rogesci)

add_subdirectory(Game)
set(SOURCE_FILES main.cpp)

add_executable(Rogesci ${SOURCE_FILES})
target_link_libraries(Rogesci Game)
install(TARGETS Rogesci DESTINATION ${ROGESCI_INSTALL_BIN_DIR})
