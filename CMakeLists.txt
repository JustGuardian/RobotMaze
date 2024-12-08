cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(MazeBot VERSION 1.0 LANGUAGES CXX)

add_library(Maze
	include/Maze.h
	src/Maze.cpp
)

add_library(Robot
	include/Robot.h
	src/Robot.cpp
)

add_library(RandomRobot
	include/RandomRobot.h
	src/RandomRobot.cpp
)

add_library(RightHandRuleRobot
	include/RightHandRuleRobot.h
	src/RightHandRuleRobot.cpp
)

add_executable(main
	src/main.cpp
)

target_link_libraries(main
	Maze
    Robot
	RandomRobot
    RightHandRuleRobot
)