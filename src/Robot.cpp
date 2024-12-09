#include "../include/Maze.h"
#include "../include/Robot.h"
#include <chrono>
#include <thread>

int Robot::getPositionX() const {return positionX;}
int Robot::getPositionY() const {return positionY;}
int Robot::getMoves() const {return moves;}

void clearOutput(){
    for(int i=0;i<=NUM_LINES+1;i++){
        std::cout << "\33[2K\033[A"; //elimina intera riga corrente e muove il cursone su di una riga
    }
    std::cout << "\r";   //riporta il cursore all'inizio della riga
}

void Robot::displayPosition(const Maze& maze, bool printMoves) const{
    for(int i=0; i<NUM_LINES; i++){
        for(int j=0; j<NUM_COLUMNS; j++){
            if(j == positionX && i == positionY){
                std::cout << ROBOT_CHAR;
            }else if(maze.getPosition(j,i) == WALL_CHAR){
                std::cout << "▒";
            }else{
                std::cout << maze.getPosition(j,i);
            }
        }
        std::cout << std::endl;
    }

    if(!printMoves) std::cout << "Start";
    std::cout << "Position: " << positionX << ", " << positionY << std::endl;

    if (printMoves) std::cout << "Moves: " << moves << std::endl;
}

void Robot::solveMaze(Maze& maze){
    auto startTime = std::chrono::high_resolution_clock::now();

    std::cout << "Maze" << std::endl;

    displayPosition(maze, false);

    std::cout << std::endl;

    while (maze.isSolved() == false) {
        move(maze);
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
        clearOutput();
    }

    auto endTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedTime = endTime - startTime;

    displayPosition(maze);

    std::cout << "Total moves: " << getMoves() << std::endl;
    std::cout << "Total time: " << elapsedTime.count() << " seconds." << std::endl;
}