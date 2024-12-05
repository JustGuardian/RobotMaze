#include <iostream>
#include "../include/RandomRobot.h"
#include <string>
#include <cstdlib>
#include <ctime>

RandomRobot::RandomRobot(int x, int y){
    positionX = x;
    positionY = y;
}

void RandomRobot::displayPosition(const Maze& maze){
    for(int i=0; i<NUM_LINES; i++){
        for(int j=0; j<NUM_COLUMNS; j++){
            if(j == positionX && i == positionY){
                std::cout << "R";
            }else{ 
                std::cout << maze.getPosition(j,i); 
            }            
        }
        std::cout << std::endl;
    }

    /*
    for(int i=NUM_LINES-1; i>=0; i--){
        for(int j=NUM_COLUMNS-1; j>=0; j--){
            if(j == positionX && i == positionY){
                std::cout << "R";
            }else{ 
                std::cout << maze.getPosition(i,j); 
            }            
        }
        std::cout << std::endl;
    }
    */
    std::cout << "Position: " << positionX << ", " << positionY << std::endl;
}

void RandomRobot::move(Maze& maze){
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

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

