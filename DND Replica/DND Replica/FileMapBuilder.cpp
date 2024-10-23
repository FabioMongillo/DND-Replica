#include "MapBuilder.h"
#include "FileMapBuilder.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


Map* FileMapBuilder::getMap() {
    return createdMap;
}

FileMapBuilder::FileMapBuilder(string filename) : createdMap(nullptr), level(1) {
    ifstream file(filename);                                // open/read file
    if (!file.is_open()) {                                       // validating file
        std::cerr << "Unable to open file.\n";
        return;
    }

    //cout << endl << "Reading the file...." << endl << endl;
    int rows, cols; 
    file >> rows >> cols;                               // reading the lines 1-2 of the file to determine num of rows and num of columns

    createdMap = new Map(rows, cols);       // create map with coordinates

    // Converting the grid in the file to the createdMap
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            string value;
            file >> value;
            createdMap->setCellContent(i, j, value); 
        }
    }

    file.close();                                                   // Closing file when done
}


FileMapBuilder::~FileMapBuilder() {
    delete createdMap;
}


void FileMapBuilder::buildBeginCell(int row, int col){
    createdMap->setBeginRow(row);
    createdMap->setBeginColumn(col);
}

void FileMapBuilder::buildEndCell(int row, int col){
    createdMap->setEndRow(row);
    createdMap->setEndColumn(col);
}

void FileMapBuilder::buildCellContent(int row, int col, string value){
    createdMap->setCellContent(row, col, value);
}


void FileMapBuilder::buildLevel(int num){
    level = num;     
}

int FileMapBuilder::getLevel(){
    return level;
}
