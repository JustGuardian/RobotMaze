#include "Maze.h"
class Robot{
    public:
    int getPositionX() const;
    int getPositionY() const;
    void displayPosition(const Maze&);

    virtual void move(Maze&) = 0;

    protected:
    int positionX;
    int positionY;
};