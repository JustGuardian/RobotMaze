#include "../include/Maze.h"
#include "../include/RandomRobot.h"
#include <iostream>

#include <chrono>
#include <thread>

using namespace std::chrono_literals;

void clearOutput(){
    for(int i=0;i<=NUM_LINES+1;i++){
        printf("\33[2K\033[A"); //elimina intera riga corrente e muove il cursone su di una riga
    }
    printf("\r");   //riporta il cursore all'inizio della riga
}

using namespace std;
int main(void){

    Maze firstMaze("../test.txt");

    cout << "START POSITION: " << firstMaze.get_startPositionX() << ", " << firstMaze.get_startPositionY() << endl;

    RandomRobot bot1(firstMaze.get_startPositionX(), firstMaze.get_startPositionY());
    
    auto startTime = std::chrono::high_resolution_clock::now();
    bot1.displayPosition(firstMaze);
    
    while(firstMaze.isSolved() == false){
        bot1.move(firstMaze);
        std::this_thread::sleep_for(std::chrono::milliseconds(125));
        clearOutput();
    }

    auto endTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedTime = endTime - startTime;

    bot1.displayPosition(firstMaze);

    std::cout << "Total moves: " << bot1.getMoves() << std::endl;
    std::cout << "Total time: " << elapsedTime.count() << " seconds" << std::endl;
    return 0;
}