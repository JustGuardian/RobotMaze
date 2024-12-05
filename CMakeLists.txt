cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(MazeBot VERSION 1.0 LANGUAGES CXX)

add_library(Maze
	include/Maze.h
	src/Maze.cpp
)

add_executable(main
	src/main.cpp
)

target_link_libraries(main
	Maze
)