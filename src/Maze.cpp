#include <iostream>
#include <fstream>
#include <string>

#include "../include/Maze.h"

bool Maze::checkLine(std::string stringToCheck){
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
        bool startNotFound = true;
        while(std::getline(inputFile, currentLine)){            
            if(checkLine(currentLine)){
                matrix.push_back(currentLine);
                if(startNotFound){
                    for(int i=0; i<currentLine.length(); i++){ //trova carattere di START
                        if(currentLine[i] == START_CHAR){
                            startPositionX = i;
                            startPositionY = matrix.size()-1;
                            startNotFound = false;
                            break;
                        }
                    }
                }
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

Maze::Maze(){}  //da implementare generazione random del labirinto

Maze::Maze(std::string fileName){
    readFromFile(fileName);
}