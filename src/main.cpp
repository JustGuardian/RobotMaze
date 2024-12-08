#include "../include/Maze.h"
#include "../include/RandomRobot.h"
#include "../include/RightHandRuleRobot.h"
#include <iostream>

#include <locale>

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
        bot.solveMaze(firstMaze);

    } else {

        cout << "\nRandom Robot\n" << endl;
        RandomRobot bot(firstMaze.get_startPositionX(), firstMaze.get_startPositionY());
        bot.solveMaze(firstMaze);
    }
    return 0;
}
