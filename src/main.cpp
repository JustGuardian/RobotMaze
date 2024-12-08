#include "../include/Maze.h"
#include "../include/RandomRobot.h"
#include "../include/RightHandRuleRobot.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <locale>

using namespace std::chrono_literals;

void clearOutput(){
    for(int i=0;i<=NUM_LINES+2;i++){
        printf("\33[2K\033[A"); //elimina intera riga corrente e muove il cursone su di una riga
    }
    printf("\r");   //riporta il cursore all'inizio della riga
}

using namespace std;

int main(void) {
    setlocale(LC_CTYPE, "en_US.UTF-8");
    Maze firstMaze("../test.txt");

    cout << "Scegli un tipo di robot:" << endl;
    cout << "1. Right Hand Rule Robot" << endl;
    cout << "2. Random Robot" << endl;
    cout << "Scelta: ";
    
    int choice;
    cin >> choice;    
    
    if (choice == 1) {

        cout << "\nRight Hand Rule Robot\n" << endl;
        RightHandRuleRobot bot(firstMaze.get_startPositionX(), firstMaze.get_startPositionY());

        auto startTime = std::chrono::high_resolution_clock::now();

        cout << "Maze" << endl;

        bot.displayPosition(firstMaze, false);

        while (firstMaze.isSolved() == false) {
            bot.move(firstMaze);
            std::this_thread::sleep_for(std::chrono::milliseconds(150));
            clearOutput();
        }

        auto endTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsedTime = endTime - startTime;

        bot.displayPosition(firstMaze);

        std::cout << "Total moves: " << bot.getMoves() << std::endl;
        std::cout << "Total time: " << elapsedTime.count() << " seconds." << std::endl;

    } else {

        cout << "\nRandom Robot\n" << endl;
        RandomRobot bot(firstMaze.get_startPositionX(), firstMaze.get_startPositionY());
        
        auto startTime = std::chrono::high_resolution_clock::now();

        cout << "Maze" << endl;
        
        bot.displayPosition(firstMaze, false);

        while (firstMaze.isSolved() == false) {
            bot.move(firstMaze);
            std::this_thread::sleep_for(std::chrono::milliseconds(150));
            clearOutput();
        }

        auto endTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsedTime = endTime - startTime;

        bot.displayPosition(firstMaze);

        std::cout << "Total moves: " << bot.getMoves() << std::endl;
        std::cout << "Total time: " << elapsedTime.count() << " seconds." << std::endl;
    }
    return 0;
}
