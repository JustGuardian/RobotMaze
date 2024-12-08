#include "Maze.h"

const char ROBOT_CHAR = 'R';

class Robot{
    public:
    int getPositionX() const;
    int getPositionY() const;
    int getMoves() const;
    void displayPosition(const Maze&) const;

    virtual void move(Maze&) = 0;

    protected:
    int positionX;
    int positionY;
    int moves;
};