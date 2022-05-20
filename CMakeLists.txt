cmake_minimum_required(VERSION 3.16)
project(TP_Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(dev)

add_executable(main
        dev/Factories.cpp
        dev/Factories.h
        dev/Player.cpp
        dev/Player.h
        dev/Units.h
        dev/run.h
        dev/run.cpp
        main.cpp)
