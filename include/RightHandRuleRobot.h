#include "Robot.h"

class RightHandRuleRobot : public Robot{
    public:
    RightHandRuleRobot(int x, int y);
    void move(Maze&);
    int findInitialDirection(Maze& maze);
};