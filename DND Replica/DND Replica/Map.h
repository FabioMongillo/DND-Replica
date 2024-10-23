// Map header

#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>
#include <fstream>

using namespace std;

/**
 * @brief Game & Design of the code.
 * 
 * The Game contains a Map composed of a grid, in which each cell is either empty (character can move), contains a wall or contains a 
 * chest/character/object.
 * 
 * The design of the code represents the Map of the d20 system, created as a grid. This was implemented using a 2D vector to be able to 
 * access and and modify cell content through rows and columns.
 *
 */


/**
 * 
 * @brief Libraries used in the code.
 * 
 * The libraries used:
 * - Vector: Used for creating dynamic arrays.
 * 
 * The rationale for the selection of the library:
 * - The vector class allows the use of flexible arrays, allowing the grid to be declared as an attribute and intialized in the constructor. In 
 * C++, declaring arrays requires stating the number of rows and columns. Since this is unknown until the constructor is called, the use
 * of vectors is advantageous as it allows the grid to be resized to the desired size. 
 */

/**
 * @class Map
 * @brief Represents a Map in the d20 system - intially contains blank cells which can be modified.
 * 
 */
class Map {

private:
    int numRows;
    int numColumns;
    int beginRow = 0;                      // Beginning Cell set to the top-leftmost cell of coordinates (0,0)
    int beginColumn = 0;                   // Beginning Cell set to coordinates (0,0)
    int endRow;
    int endColumn;
    
    string fileName;
    bool startConnection = false;
    bool endConnection = false;

public:
    ::vector<::vector<string>> grid;       // 2D representation of the map made of rows and column (vector of int, inside of another vector) ////////////////////////////
    vector<string> mapConnections;      // List of map relationships in a campaign

    /**
    * @brief Construct a new Map object
    * 
    * @param numOfRows      number of rows of the grid to create
    * @param numOfColumns   number of columns of the grid to create
    */
    Map(int numOfRows, int numOfColumns);
    
    /**
    * @brief Get the Rows object.
    * 
    * @return int value of the total number of rows in the map/grid.
    */
    int getNumRows();


    /**
    * @brief Get the Columns object.
    * 
    * @return int value of the total number of columns in the map/grid.
    */
    int getNumColumns();


    /**
     * @brief Get the Begin Row object
     * 
     * @return int value of the row coordinate of the begin cell.
     */
    int getBeginRow();


    /**
     * @brief Get the Begin Column object
     * 
     * @return int value of the column coordinate of the begin cell.
     */
    int getBeginColumn();


    /**
     * @brief Get the End Row object
     * 
     * @return int value of the row coordinate of the end cell.
     */
    int getEndRow();


    /**
     * @brief Get the End Column object
     * 
     * @return int value of the column coordinate of the end cell.
     */
    int getEndColumn();


    /**
     * @brief Set the Begin Row object
     * 
     * @param row value of the begin cell's row
     */
    void setBeginRow(int row);


    /**
     * @brief Set the Begin Column object
     * 
     * @param column value of the begin cell's column
     */
    void setBeginColumn(int column);


    /**
     * @brief Set the End Row object
     * 
     * @param row value of the end cell's row
     */
    void setEndRow(int row);


    /**
     * @brief Set the End Column object
     * 
     * @param column value of the end cell's column
     */
    void setEndColumn(int column);


    /**
    * @brief Get the Cell Content object
    * 
    * @param row       row number of the targeted cell 
    * @param column    column number of the targeted cell
    * @return int      int of the targeted cell content - returns -1 if targeted cell is out of bounds
    */
    string getCellContent(int row, int column);


    /**
    * @brief Set the Cell Content object
    * 
    * @param row           row number of the targeted cell
    * @param column        column number of the targeted cell
    * @param cellContent   new value of the targeted cell's content - returns "" if targeted cell is out of bounds
    */
    void setCellContent(int row, int column, string cellContent);


    /**
    * @brief Displays the map along with each's cells content and a legend.
    * 
    */
    void displayMap();

    /**
     * @brief Returns number of enemies on map
     * 
     * @return vector<string> 
     */
    vector<string> enemiesList();

    /**
     * @brief Checks the validity of the Map by using a depth-first search algorithm to evaluate if there is a path of empty cells (0) from the 
     * beginning cell (top-leftmost cell by default) to the end cell (bottom-rightmost cell set in constructor) and utilizes recursion. 
     * 
     * @param startRow  row coordinate value of the start cell
     * @param startCol  column coordinate value of the start cell
     * @param endRow    row coordinate value of the end cell
     * @param endCol    column coordinate value of the end cell
     * @return true if the map contains a valid path
     * @return false if the map does not contain a valid path
     */
    bool hasValidPath(int startRow, int startCol, int endRow, int endCol);
    
    /**
     * @brief Helper method to hasValidPath which marks up a virtual map
     * 
     * @param startRow row coordinate value of the start cell
     * @param startCol column coordinate value of the start cell
     * @param endRow row coordinate value of the end cell
     * @param endCol column coordinate value of the end cell
     * @param visited marks if a cell has been visited
     * @return true if the map contains a valid path
     * @return false if the map does not contain a valid path
     */
    bool hasValidPathHelper(int startRow, int startCol, int endRow, int endCol, vector<vector<bool>>& visited);

    /**
     * @brief Set the Start Connection object
     * 
     * @param startConnection boolean to represent whether or not a map is connected at its start point in a campaign
     */
    void setStartConnection(bool startConnection);

    /**
     * @brief Set the End Connection object
     * 
     * @param endConnection boolean to represent whether or not a map is connected at its start point in a campaign
     */
    void setEndConnection(bool endConnection);

    /**
     * @brief Get the Start Connection object
     * 
     * @return true if the map is connected at its start point to another map
     * @return false if the map is not connected at its start point
     */
    bool getStartConnection();

    /**
     * @brief Get the End Connection object
     * 
     * @return true if the map is connected at its end point to another map
     * @return false if the map is not connected at its end point
     */
    bool getEndConnection();

    /**
     * @brief Saves the configuration details of the map to a file.
     * 
     * @param fileName text file to contain the map
     */
    void saveMapConfiguration(string fileName);

    bool enemiesInRange();

};

/**
 * @brief Reads the contents of a file containing the specifications of a map object and loads that object
 * 
 * @param fileName name of the map file
 * @return Map a map object constructed from the file specifications
 */
Map loadMap(string fileName);

/**
 * @brief Connects two maps to form a campaign.
 * 
 * @param map1 the first map, to be connected at its end point
 * @param map2 the second map, to be connected at its start point
 */
void connectMaps(Map map1, Map map2);

/**
 * @brief Disconnects two maps in a campaign
 * 
 * @param map1 the first map, to be disconnected at its end point
 * @param map2 the second map, to be disconnected at its start point
 */
void disconnectMaps(Map map1, Map map2);

/**
 * @brief Saves the configuration details of the campaign
 * 
 * @param fileName file that stores the campaign
 * @param mapConnections map adjacency relationships stored in the file
 */
void saveCampaignConfiguration(string fileName, vector<string> mapConnections);

/**
 * @brief Map Editor: Used to create new maps, edit previously saved maps, create new campaigns and edit previously saved campaigns
 * 
 */
void mapEditor();

string changeTurn(string mapFileName);


#endif
