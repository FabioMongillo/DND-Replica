#ifndef MAPBUILDER_H
#define MAPBUILDER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief Abstract Class to declare the interface for creating the FileMapBuilder
 * 
 */
class MapBuilder {
public:

    /**
     * @brief Builds the Begin Cell of the Map
     * 
     * @param row value of the row of the begin cell
     * @param col value of the column of the begin cell
     */
    virtual void buildBeginCell(int row, int col) = 0;

    /**
     * @brief Builds the End Cell of the Map
     * 
     * @param row value of the row of the begin cell
     * @param col value of the column of the begin cell
     */
    virtual void buildEndCell(int row, int col) = 0;

    /**
     * @brief Builds a Cell Content on the map.
     * 
     * @param row value of the row of the begin cell
     * @param col value of the column of the begin cell
     * @param value value of the cell content (0, 1, 2)
     */
    virtual void buildCellContent(int row, int col, string value) = 0;

    /**
     * @brief Builds the Level of the Map
     * 
     * @param num value of the Map Level
     */
    virtual void buildLevel(int num) = 0;

};


#endif