cmake_minimum_required(VERSION 3.2)
project(Game C CXX)

set(SOURCE_FILES
    BombWeapon.h
    Character.h
    CollisionHandler.cpp
    CollisionHandler.h
    GameManager.cpp
    GameManager.h
    GameStructure.cpp
    GameStructure.h
    InputController.cpp
    InputController.h
    ScreenRender.cpp
    ScreenRender.h
)

add_library(Game SHARED STATIC ${SOURCE_FILES})
