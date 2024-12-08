#include "../include/Maze.h"
#include "../include/Robot.h"

int Robot::getPositionX() const {return positionX;};
int Robot::getPositionY() const {return positionY;};
int Robot::getMoves() const {return moves;}

void Robot::displayPosition(const Maze& maze) const{
    for(int i=0; i<NUM_LINES; i++){
        for(int j=0; j<NUM_COLUMNS; j++){
            if(j == positionX && i == positionY){
                std::cout << ROBOT_CHAR;
            }else{
                std::cout << maze.getPosition(j,i);
            }
        }
        std::cout << std::endl;
    }
    std::cout << "Position: " << positionX << ", " << positionY << std::endl;
    std::cout << "Moves: " << moves << std::endl;
}