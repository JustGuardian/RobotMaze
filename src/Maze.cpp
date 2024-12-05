#include <iostream>
#include <fstream>
#include <string>

#include "../include/Maze.h"

bool Maze::checkLine(std::string stringToCheck){\
    if(stringToCheck.length() != NUM_COLUMNS) return false;
    for(char c : stringToCheck){
        if(c != EXIT_CHAR && c != START_CHAR && c != WALL_CHAR && c != PATH_CHAR){
            return false;
        }
    }
    return true;
}

void Maze::readFromFile(std::string fileName){
    std::ifstream inputFile(fileName);
    std::string currentLine;

    if(inputFile.is_open()){
        while(std::getline(inputFile, currentLine)){            
            if(checkLine(currentLine)){
                std::cout<<currentLine<<std::endl;
                matrix.push_back(currentLine);
            }else{
                std::cerr << "ERRORE carattere non valido: " << currentLine << std::endl;
            }            
        }
        if(matrix.size() != NUM_LINES) std::cerr << "ERRORE numero di linee non valido: " << currentLine << std::endl;
    }
    inputFile.close();
}

Maze::Maze(){}

Maze::Maze(std::string fileName){
    readFromFile(fileName);
}