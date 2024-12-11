#include <iostream>
#include "../include/RightHandRuleRobot.h"
#include <string>
#include <cstdlib>
#include <ctime>

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

RightHandRuleRobot::RightHandRuleRobot(int x, int y) {
    positionX = x;
    positionY = y;
    moves = 0;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

void RightHandRuleRobot::move(Maze& maze) {
    int currentDirection = findInitialDirection(maze);
    bool moved = false;
    int lastPossibleDirection = -1; // Direzione opposta come ultima risorsa

    while (!moved) {
        for (int i = 0; i < 8; ++i) {
            int nextDirection = (currentDirection + i) % 8;

            int newX = positionX + directions[nextDirection][0];
            int newY = positionY + directions[nextDirection][1];

            if (maze.getPosition(newX, newY) != WALL_CHAR) {
                //salvo la ultima posizione possibile
                if (nextDirection == (previousDirection + 4) % 8) {
                    lastPossibleDirection = nextDirection;
                    continue;
                }

                //vado nella prima direzione valida
                positionX = newX;
                positionY = newY;
                previousDirection = nextDirection;
                currentDirection = nextDirection;
                moved = true;
                break;
            }
        }

        //provo direzione opposta
        if (!moved && lastPossibleDirection != -1) {
            int newX = positionX + directions[lastPossibleDirection][0];
            int newY = positionY + directions[lastPossibleDirection][1];

            positionX = newX;
            positionY = newY;
            previousDirection = lastPossibleDirection;
            currentDirection = lastPossibleDirection;
            moved = true;
        }
    }

    moves++;
    if (maze.getPosition(positionX, positionY) == EXIT_CHAR) {
        maze.setSolved();
    }
    displayPosition(maze);
}

int RightHandRuleRobot::findInitialDirection(Maze& maze) {
    for (int i = 0; i < 8; ++i) {
        int newX = positionX + directions[i][0];
        int newY = positionY + directions[i][1];

        if (maze.getPosition(newX, newY) == WALL_CHAR) {
            return i;
        }
    }

    return std::rand() % 8; // Se non trovo niente, scelgo una direzione casuale
}
