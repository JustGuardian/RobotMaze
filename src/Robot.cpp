#include "../include/Maze.h"
#include "../include/Robot.h"

int Robot::getPositionX() const {return positionX;};
int Robot::getPositionY() const {return positionY;};

void Robot::displayPosition(const Maze& maze){
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
    std::cout << "Position: " << positionX << ", " << positionY << std::endl;
}