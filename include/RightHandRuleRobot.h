#include "Robot.h"

class RightHandRuleRobot : public Robot{
    public:
    RightHandRuleRobot(int, int);
    void move(Maze&);
    int findInitialDirection(Maze&);
};