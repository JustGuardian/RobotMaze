#include "../include/Maze.h"
#include "../include/RandomRobot.h"
#include <iostream>

#include <chrono>
#include <thread>

using namespace std::chrono_literals;

void clearScreen(){
    for(int i=0;i<=NUM_LINES;i++){
        printf("\33[2K\033[A"); //elimina intera riga corrente e muove il cursone su di una riga
    }
    printf("\r");   //riporta il cursore all'inizio della riga
}

using namespace std;
int main(void){

    Maze firstMaze("../test.txt");

    cout << "START POSITION: " << firstMaze.get_startPositionX() << ", " << firstMaze.get_startPositionY() << endl;

    RandomRobot bot1(firstMaze.get_startPositionX(), firstMaze.get_startPositionY());

    bot1.displayPosition(firstMaze);
    while(firstMaze.isSolved() == false){
        bot1.move(firstMaze);
        std::this_thread::sleep_for(125ms);
        clearScreen();        
    }
    bot1.displayPosition(firstMaze);
    return 0;
}