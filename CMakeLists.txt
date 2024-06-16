cmake_minimum_required(VERSION 3.10)
project(TetrisV2)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
set(BUILD_SHARED_LIBS OFF)
FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.1
)
FetchContent_MakeAvailable(SFML)

include_directories(src)

add_executable(TetrisV2
        src/main.cpp
        src/Game.cpp
        src/Game.h
        src/Board.cpp
        src/Board.h
        src/Piece.cpp
        src/Piece.h
        src/Tetromino.cpp
        src/Tetromino.h
        C:/Users/Samue/CLionProjects/TetrisV2/src/ds_digital/DS-DIGI.TTF
)

target_link_libraries(TetrisV2 PRIVATE sfml-graphics sfml-window sfml-system)

