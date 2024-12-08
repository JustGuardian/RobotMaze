#include <iostream>
#include "../include/RandomRobot.h"
#include <string>
#include <cstdlib>
#include <ctime>


RandomRobot::RandomRobot(int x, int y){
    positionX = x;
    positionY = y;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

void RandomRobot::move(Maze& maze){
    bool moved = false;
    while (!moved) {
        int randomMovement = std::rand() % 8 + 1;
        switch (randomMovement){
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
        if(maze.getPosition(positionX,positionY) == 'E'){
            maze.setSolved();
        }
    }
    displayPosition(maze);
}