cmake_minimum_required(VERSION 3.2)
project(Game C CXX)

set(SOURCE_FILES
    Collision.cpp
    Collision.h
    CollisionHandler.cpp
    CollisionHandler.h
    Configuration.cpp
    Configuration.h
    Header.h
    Input.cpp
    Input.h
    Map.cpp
    Map.h
    Player.cpp
    Player.h
    Prefab.cpp
    Prefab.h
    Render.cpp
    Render.h
)

add_library(Game SHARED STATIC ${SOURCE_FILES})
