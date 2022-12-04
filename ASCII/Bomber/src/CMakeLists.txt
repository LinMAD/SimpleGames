cmake_minimum_required(VERSION 3.2)
project(BomberConsole)

add_subdirectory(Game)
set(SOURCE_FILES main.cpp)

add_executable(BomberConsole ${SOURCE_FILES})
target_link_libraries(BomberConsole Game)
install(TARGETS BomberConsole DESTINATION ${BOMBER_CONSOLE_INSTALL_BIN_DIR})
