cmake_minimum_required(VERSION 3.16)
project(nquat)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

set(CURSES_NEED_NCURSES TRUE)
find_package(Curses REQUIRED)

add_executable(nquat
    ./src/main.cpp
    ./src/quaternion/quaternion.cpp
    ./src/vectors/vector3.cpp
    ./src/vectors/vector2.cpp
    ./src/window/window.cpp
    ./src/rasterizer/rasterizer.cpp
)

target_link_libraries(nquat
    ${CURSES_LIBRARIES}
)
