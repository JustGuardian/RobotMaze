#include "Maze.h"
class Robot{
    public:
    int getPositionX() const;
    int getPositionY() const;

    virtual void move(Maze&) = 0;
    virtual void displayPosition(const Maze&);

    protected:
    int positionX;
    int positionY;
};