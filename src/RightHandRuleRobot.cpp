#include <iostream>
#include "../include/RightHandRuleRobot.h"
#include <string>
#include <cstdlib>
#include <ctime>


RightHandRuleRobot::RightHandRuleRobot(int x, int y){
    positionX = x;
    positionY = y;
    moves = 0;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

void RightHandRuleRobot::move(Maze& maze) {
    //direzioni
    int directions[8][2] = {
        {1, 0},   // ➡
        {1, -1},  // ↘
        {0, -1},  // ⬇
        {-1, -1}, // ↙
        {-1, 0},  // ⬅
        {-1, 1},  // ↖
        {0, 1},   // ⬆
        {1, 1}    // ↗
    };

    int currentDirection = findInitialDirection(maze);

    bool moved = false;
    while (!moved) {
        
        for (int i = 0; i < 8; ++i) {
            int nextDirection = (currentDirection + i) % 8;//ruoto
            int newX = positionX + directions[nextDirection][0];
            int newY = positionY + directions[nextDirection][1];

            if (maze.getPosition(newX, newY) != WALL_CHAR) {                
                positionX = newX;
                positionY = newY;
                currentDirection = nextDirection;
                moved = true;
                break;
            }
        }
    }

    moves++;
    if (maze.getPosition(positionX, positionY) == EXIT_CHAR) {
        maze.setSolved();
    }
    displayPosition(maze);
}

int RightHandRuleRobot::findInitialDirection(Maze& maze) {    
    int directions[8][2] = {
        {1, 0},   // ➡
        {1, -1},  // ↘
        {0, -1},  // ⬇
        {-1, -1}, // ↙
        {-1, 0},  // ⬅
        {-1, 1},  // ↖
        {0, 1},   // ⬆
        {1, 1}    // ↗
    };

    
    for (int i = 0; i < 8; ++i) {
        int newX = positionX + directions[i][0];
        int newY = positionY + directions[i][1];

        if (maze.getPosition(newX, newY) == WALL_CHAR) {
            return i; 
        }
    }
    
    return std::rand() % 8; //se non trovo niente faccio a caso
}
