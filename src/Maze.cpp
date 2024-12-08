#include <iostream>
#include <fstream>
#include <string>

#include "../include/Maze.h"

void Maze::analyzeMaze(){
    for(int i=0; i<NUM_LINES; i++){
        for(int j=0; j<NUM_COLUMNS; j++){
            if(matrix[i][j] == 'S'){
                startPositionX = j;
                startPositionY = i;
            }
        }
    } 
}

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
                //std::cout<<currentLine<<std::endl;
                matrix.push_back(currentLine);
            }else{
                std::cerr << "ERRORE carattere non valido: " << currentLine << std::endl;
            }            
        }
        if(matrix.size() != NUM_LINES) std::cerr << "ERRORE numero di linee non valido: " << currentLine << std::endl;
    }
    inputFile.close();
}

char Maze::getPosition (int x, int y) const{
    return matrix[y][x];
}

Maze::Maze(){}

Maze::Maze(std::string fileName){
    readFromFile(fileName);
    analyzeMaze();
}