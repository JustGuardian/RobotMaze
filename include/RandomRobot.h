#include "Robot.h"

class RandomRobot : public Robot{
    public:
    RandomRobot(int, int);
    void move(Maze&);
};