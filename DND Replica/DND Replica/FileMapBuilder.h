#ifndef FILEMAPBUILDER_H
#define FILEMAPBUILDER_H

#include "MapBuilder.h"
#include "Map.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
 * @brief The concrete class FileMapBuilder implements the MapBuilder interface to define the construction steps for a Map from a file.
 * 
 */
class FileMapBuilder : public MapBuilder {
public: 

    /**
     * @brief Construct a new File Map Builder object
     * 
     * @param filename name of the file to extract the Map from
     */
    FileMapBuilder(string filename);

    /**
     * @brief Destroy the File Map Builder object
     * 
     */
    virtual ~FileMapBuilder();
    
    /**
     * @brief Get the Map object
     * 
     * @return Map* Pointer to the map created
     */
    virtual Map* getMap();

    /**
     * @brief Builds the Begin Cell of the Map
     * 
     * @param row value of the row of the begin cell
     * @param col value of the column of the begin cell
     */
    virtual void buildBeginCell(int row, int col) override;

    /**
     * @brief Builds the End Cell of the Map
     * 
     * @param row value of the row of the begin cell
     * @param col value of the column of the begin cell
     */
    virtual void buildEndCell(int row, int col) override;

    /**
     * @brief Builds a Cell Content on the map.
     * 
     * @param row value of the row of the begin cell
     * @param col value of the column of the begin cell
     * @param value value of the cell content (0, 1, 2)
     */
    virtual void buildCellContent(int row, int col, string value) override;

    /**
     * @brief Builds the Level of the Map
     * 
     * @param num value of the Map Level
     */
    virtual void buildLevel(int num);

    /**
     * @brief Get the Level object
     * 
     * @return int value of the Map Level
     */
    virtual int getLevel();


protected:
    Map* createdMap;               // Reference to Map created
    int level;                                  // Map Level
};

#endif