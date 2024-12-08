#include <iostream>
#include "../include/RandomRobot.h"
#include <string>
#include <cstdlib>
#include <ctime>


RandomRobot::RandomRobot(int x, int y){
    positionX = x;
    positionY = y;
    moves = 0;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

void RandomRobot::move(Maze& maze){
    bool moved = false;
    while (!moved) {
        int randomMovementNumber = std::rand() % 8 + 1;
        switch (randomMovementNumber){
            case 1: //⬆
                if(maze.getPosition(positionX, positionY+1) != WALL_CHAR){
                    positionY++; //move robot up
                    moved = true;
                    break;
                }                
            case 2: //↗
                if(maze.getPosition(positionX+1, positionY+1) != WALL_CHAR){
                    positionX++;    //move robot right
                    positionY++;    //move robot up
                    moved = true;
                    break;
                }
            case 3: //➡
                if(maze.getPosition(positionX+1, positionY) != WALL_CHAR){
                    positionX++;    //move robot right
                    moved = true;
                    break;
                }
            case 4: //↘
                if(maze.getPosition(positionX+1, positionY-1) != WALL_CHAR){
                    positionX++;    //move robot right
                    positionY--;    //move robot down
                    moved = true;
                    break;
                }
            case 5: //⬇
                if(maze.getPosition(positionX, positionY-1) != WALL_CHAR){
                    positionY--; //move robot down
                    moved = true;
                    break;
                }
            case 6: //↙
                if(maze.getPosition(positionX-1, positionY-1) != WALL_CHAR){
                    positionX--;    //move robot left
                    positionY--;    //move robot down
                    moved = true;
                    break;
                }
            case 7: //⬅
                if(maze.getPosition(positionX-1, positionY) != WALL_CHAR){
                    positionX--; //move robot up left
                    moved = true;
                    break;
                }
            case 8: //↖
                if(maze.getPosition(positionX-1, positionY+1) != WALL_CHAR){
                    positionX--;    //move robot left
                    positionY++;    //move robot up
                    moved = true;
                    break;
                }
        }
    }
    moves++;
    if(maze.getPosition(positionX,positionY) == EXIT_CHAR){
            maze.setSolved();
    }
    displayPosition(maze);
}