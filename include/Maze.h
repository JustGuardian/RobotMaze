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

    private:
    void readFromFile(std::string);
    bool checkLine(std::string);

    std::vector<std::string> matrix;
};

#endif