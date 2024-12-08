#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <vector>

const char EXIT_CHAR = 'E';
const char START_CHAR = 'S';
const char WALL_CHAR = '*';
const char PATH_CHAR = ' ';

const int NUM_LINES = 9;
const int NUM_COLUMNS = 9;

class Maze{
    public:
    Maze();
    Maze(std::string fileName);

    char getPosition(int x, int y) const;
    int get_startPositionX() const {return startPositionX;};
    int get_startPositionY() const {return startPositionY;};
    /*
    int get_endPositionX() const {return endPositionX;};
    int get_endPositionY() const {return endPositionY;};
    */
    void setSolved() {solved = true;};
    bool isSolved() const {return solved;};
    std::vector<std::string> getMaze() const {return matrix;};
    
    private:
    bool solved = false;
    void readFromFile(std::string fileName);
    bool checkLine(std::string stringToCheck) const;

    int startPositionX;
    int startPositionY;
    /*
    int endPositionX;
    int endPositionY;
    */
    std::vector<std::string> matrix;
};

#endif