cmake_minimum_required(VERSION 3.23)
project(Breakout)

set(CMAKE_CXX_STANDARD 23)

find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(${CMAKE_SOURCE_DIR}/lib)

add_executable(Breakout main.cpp Engine/src/Physics.cpp Engine/headers/Physics.h Engine/src/Window.cpp Engine/headers/Window.h Engine/src/Game.cpp Engine/headers/Game.h Engine/src/Object.cpp Engine/headers/Object.h Engine/src/Time.cpp Engine/headers/Time.h Game/src/Paddle.cpp Game/headers/Paddle.h Game/headers/Constants.h Engine/src/Body.cpp Engine/headers/Body.h)
target_link_libraries(Breakout PRIVATE box2d sfml-system sfml-window sfml-graphics)

