cmake_minimum_required(VERSION 3.20)
project(TP_project)

set(CMAKE_CXX_STANDARD 14)

include_directories(Units)

add_executable(TP_project
        Units/Archer.cpp
        Units/Swordsman.cpp
        Units/Unit.cpp
        Units/Warrior.cpp)