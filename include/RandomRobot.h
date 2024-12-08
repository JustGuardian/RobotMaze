#include "Robot.h"

class RandomRobot : public Robot{
    public:
    RandomRobot(int x, int y);
    void move(Maze&);    
};