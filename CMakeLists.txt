cmake_minimum_required(VERSION 3.23)
project(Breakout)

set(CMAKE_CXX_STANDARD 23)

find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(${CMAKE_SOURCE_DIR}/lib)

add_executable(Breakout main.cpp src/Physics.cpp headers/Physics.h src/Window.cpp headers/Window.h src/Game.cpp headers/Game.h src/Object.cpp headers/Object.h src/Time.cpp headers/Time.h)
target_link_libraries(Breakout PRIVATE box2d-lite sfml-system sfml-window sfml-graphics)

