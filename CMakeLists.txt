cmake_minimum_required(VERSION 3.16)
project(nquat)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

add_executable(nquat
    ./src/main.cpp
    ./src/quaternion/quaternion.cpp
)
