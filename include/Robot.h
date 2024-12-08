#ifndef ROBOT_H
#define ROBOT_H

#include "Maze.h"

const char ROBOT_CHAR = 'R';

class Robot{
    public:
    int getPositionX() const;
    int getPositionY() const;
    int getMoves() const;
    void displayPosition(const Maze&, bool printMoves=true) const;
    void solveMaze(Maze&);

    virtual void move(Maze&) = 0;

    protected:
    int positionX;
    int positionY;
    int moves;
};
#endif