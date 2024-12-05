#include "Robot.h"

class RandomRobot : public Robot{

    public:
    void displayPosition(const Maze& maze);
    void move(Maze&);
    RandomRobot(int x, int y);
};