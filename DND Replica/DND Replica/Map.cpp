//Map implementation file

#include "Map.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <experimental/filesystem>
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <sstream>
using namespace std;

Map::Map(int numOfRows, int numOfColumns) 
    : numRows(numOfRows), numColumns(numOfColumns) {
    grid.resize(numOfRows, vector<string>(numOfColumns, "0"));          // Adjusting grid size, and set default contents to 0 ///////////////////
    setEndRow(numOfRows - 1);                   // Setting the End Cell's row to the bottom-rightmost coordinate
    setEndColumn(numOfColumns - 1);       // Setting the End Cell's column to the bottom-rightmost coordinate
}
        
int Map::getNumRows() {
    return numRows;
}

int Map::getNumColumns(){
    return numColumns;
}

int Map::getBeginRow(){
    return beginRow;
}

int Map::getBeginColumn(){
    return beginColumn;
}

int Map::getEndRow(){
    return endRow;
}

int Map::getEndColumn(){
    return endColumn;
}

void Map::setBeginRow(int row){
    beginRow = row;
}

void Map::setBeginColumn(int column){
    beginColumn = column;
}

void Map::setEndRow(int row){
    endRow = row;
}

void Map::setEndColumn(int column){
    endColumn = column;
}

string Map::getCellContent(int row, int column){
    if (row >= getNumRows() || row < 0 || column >= getNumColumns() || column < 0){       // Verifiying if cell to obtain is in bound
        cout << "Cell out of bounds - unable to view cell value." << endl;
        return ""; 
    } else {
        return grid[row][column];
    }
}


void Map::setCellContent(int row, int column, string cellContent){
    if (row >= getNumRows() || row < 0 || column >= getNumColumns() || column < 0){       // Verifiying if cell to modify is in bound
        cout << "Cell out of bounds - unable to change cell value." << endl;
    } else {
        grid[row][column] = cellContent;
    }
}

void Map::displayMap(){
    ::string horizontalLine;

    int charRow, charCol;

    for(int i = 0;i < getNumRows();i++){
        for(int j = 0;j < getNumColumns();j++){
            if(grid[i][j] == "C"){
                charRow = i;
                charCol = j;
            }
        }
    }

    for (int i = 0; i < getNumColumns(); i++){
        horizontalLine = horizontalLine + "----";
    }
            
    cout << horizontalLine << endl;
    for (int i = 0; i < getNumRows(); i++){
        cout << "| ";
        for (int j = 0; j < getNumColumns(); j++){
            if(i == getBeginRow() && j == getBeginColumn()){
                cout << "\033[1;32m" << grid[i][j] << "\033[0m"<< " | "; //Colors starting point green
            }  
            if(i == getEndRow() && j == getEndColumn()){
                cout << "\033[1;31m" << grid[i][j] << "\033[0m"<< " | "; //Colors ending point red
            }

            if(!(i == getEndRow() && j == getEndColumn()) && !(i == getBeginRow() && j == getBeginColumn())){
                
                //Highlights character movement spaces
                if((i == (charRow + 1) && j == charCol)){
                    if((grid[i][j] == "0" || grid[i][j] == "T")){
                        cout << "\033[1;33m" << grid[i][j] << "\033[0m"<< " | "; //Colors possible movement points yellow
                    }
                    else if(grid[i][j] == "E"){
                        cout << "\033[1;36m" << grid[i][j] << "\033[0m"<< " | "; //Colors enemy in range blue
                    }
                    else{
                        cout << grid[i][j] << " | ";
                    }
                }
                else if((i == (charRow - 1) && j == charCol)){
                    if((grid[i][j] == "0" || grid[i][j] == "T")){
                        cout << "\033[1;33m" << grid[i][j] << "\033[0m"<< " | "; //Colors possible movement points yellow
                    }
                    else if(grid[i][j] == "E"){
                        cout << "\033[1;36m" << grid[i][j] << "\033[0m"<< " | "; //Colors enemy in range blue
                    }
                    else{
                        cout << grid[i][j] << " | ";
                    }
                }
                else if((i == charRow && j == (charCol + 1))){
                    if((grid[i][j] == "0" || grid[i][j] == "T")){
                        cout << "\033[1;33m" << grid[i][j] << "\033[0m"<< " | "; //Colors possible movement points yellow
                    }
                    else if(grid[i][j] == "E"){
                        cout << "\033[1;36m" << grid[i][j] << "\033[0m"<< " | "; //Colors enemy in range blue
                    }
                    else{
                        cout << grid[i][j] << " | ";
                    }
                }
                else if((i == charRow && j == (charCol - 1))){
                    if((grid[i][j] == "0" || grid[i][j] == "T")){
                        cout << "\033[1;33m" << grid[i][j] << "\033[0m"<< " | "; //Colors possible movement points yellow
                    }
                    else if(grid[i][j] == "E"){
                        cout << "\033[1;36m" << grid[i][j] << "\033[0m"<< " | "; //Colors enemy in range blue
                    }
                    else{
                        cout << grid[i][j] << " | ";
                    }
                }
                else{
                    cout << grid[i][j] << " | ";  
                }
            }       
        }
        cout << endl << horizontalLine << endl;
    }
    cout << "Legend:" << endl << "0 = Empty Cell\tW = Wall\tT = Treasure\tE = Enemy\tC = Character" << endl;
}

vector<string> Map::enemiesList(){
    vector<string> enemies;
    for (int i = 0; i < getNumRows(); i++){
        for (int j = 0; j < getNumColumns(); j++){
            if(getCellContent(i,j) == "E"){
                enemies.push_back("E");
            }       
        }
    }
    return enemies;
}

bool Map::enemiesInRange(){

    for(int i = 0;i < getNumRows();i++){
        for(int j = 0;j < getNumColumns();j++){
            if(grid[i][j] == "C"){

                if(i < getNumRows() && getCellContent(i + 1,j) == "E"){
                    return true;
                }
                if(i > 0 && getCellContent(i - 1,j) == "E"){
                    return true;
                }
                if(j < getNumColumns() && getCellContent(i,j + 1) == "E"){
                    return true;
                }
                if(j > 0 && getCellContent(i,j - 1) == "E"){
                    return true;
                }
            }
        }
    }
    return false;
}

bool Map::hasValidPath(int startRow, int startCol, int endRow, int endCol) {
    // Create a temporary grid to keep track of visited cells without overwriting values
    vector<vector<bool>> visited(numRows, vector<bool>(numColumns, false));

    // Call the helper function with the temporary grid
    return hasValidPathHelper(startRow, startCol, endRow, endCol, visited);
}

bool Map::hasValidPathHelper(int startRow, int startCol, int endRow, int endCol, vector<vector<bool>>& visited) {
    // Check if the current cell is the end cell
    if (startRow == endRow && startCol == endCol) {
        return true;
    }

    // Mark the current cell as visited to prevent infinite loop
    visited[startRow][startCol] = true;

    // Check if cell above contains an empty cell (0) and is in grid bounds - recursive call
    if (startRow > 0 && grid[startRow - 1][startCol] == "0" && !visited[startRow - 1][startCol]) {
        if (hasValidPathHelper(startRow - 1, startCol, endRow, endCol, visited)) {
            return true;
        }
    }
    // Check if cell below contains an empty cell (0) and is in grid bounds - recursive call
    if (startRow < numRows - 1 && grid[startRow + 1][startCol] == "0" && !visited[startRow + 1][startCol]) {
        if (hasValidPathHelper(startRow + 1, startCol, endRow, endCol, visited)) {
            return true;
        }
    }
    // Check if cell to the left contains an empty cell (0) and is in grid bounds - recursive call
    if (startCol > 0 && grid[startRow][startCol - 1] == "0" && !visited[startRow][startCol - 1]) {
        if (hasValidPathHelper(startRow, startCol - 1, endRow, endCol, visited)) {
            return true;
        }
    }
    // Check if cell to the right contains an empty cell (0) and is in grid bounds - recursive call
    if (startCol < numColumns - 1 && grid[startRow][startCol + 1] == "0" && !visited[startRow][startCol + 1]) {
        if (hasValidPathHelper(startRow, startCol + 1, endRow, endCol, visited)) {
            return true;
        }
    }

    return false;
}

//Set map start point connection
void Map::setStartConnection(bool start){
    startConnection = start;
};

//Set map end point connection
void Map::setEndConnection(bool end){
    endConnection = end;
};

//Get map start point connection
bool Map::getStartConnection(){
    return startConnection;
};

//Get map end point connection
bool Map::getEndConnection(){
    return endConnection;
};

void Map::saveMapConfiguration(string fileName){
    ofstream mapFile; //create file to save map to
    mapFile.open(fileName); //open file
    
    //Save number of rows
    int rows = getNumRows();
    mapFile << "Rows: " << rows << endl;

    //Save number of columns
    int columns = getNumColumns();
    mapFile << "Columns: " << columns << endl;

    //Save start point
    int beginRow = getBeginRow();
    int beginCol = getBeginColumn();
    mapFile << "Start point row: " << beginRow << endl;
    mapFile << "Start point column: " << beginCol <<endl;

    //Save end point
    int endRow = getEndRow();
    int endCol = getEndColumn();
    mapFile << "End point row: " << endRow << endl;
    mapFile << "End point column: " <<  endCol <<endl;

    //Save walls and occupied cells
    for (int i = 0; i < getNumRows(); i++){
        for (int j = 0; j < getNumColumns(); j++){
            if(grid[i][j] == "W"){
                mapFile << "Wall: (" << i << "," << j << ")" << endl;
            }
            if(grid[i][j] == "T"){
                mapFile << "Treasure: (" << i << "," << j << ")" << endl; 
            }
            if(grid[i][j] == "E"){
                mapFile << "Enemy: (" << i << "," << j << ")" << endl; 
            }
            if(grid[i][j] == "C"){
                mapFile << "Character: (" << i << "," << j << ")" << endl; 
            }
        }
    }

    //Save display
    mapFile << "\nDisplay:" << endl;
    ::string horizontalLine;
    for (int i = 0; i < getNumColumns(); i++){
        horizontalLine = horizontalLine + "----";
    }
            
    mapFile << horizontalLine << endl;
    for (int i = 0; i < getNumRows(); i++){
        mapFile << "| ";
        for (int j = 0; j < getNumColumns(); j++){
            if(i == getBeginRow() && j == getBeginColumn()){
                mapFile << "S: " << grid[i][j] << " | "; //Mark start point
            }  
            if(i == getEndRow() && j == getEndColumn()){
                mapFile << "E: " << grid[i][j] << " | "; //Mark end point
            }
            if(!(i == getEndRow() && j == getEndColumn()) && !(i == getBeginRow() && j == getBeginColumn())){
                mapFile << grid[i][j] << " | ";    
            } 
        }
        mapFile << endl << horizontalLine << endl;
    }
    mapFile << "Legend:" << endl << "0 = Empty Cell\tW = Wall\tT = Treasure\tE= Enemy\tC = Character" << endl;

    mapFile.close(); //close file

};

//Function for parsing string input by delimeter
std::vector<std::string> split(std::string s, std::string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

void mapEditor(){
    int selection; //variable to hold menu selection input
    string fileName; //variable to file name input
    bool fileExists; //variable to check if a file exists
    bool closeEditor = false;

    do{
    //Selection menu
    cout << "Welcome to the map editor. What would you like to do?" << endl;
    cout << "[1] Create new map." << endl;
    cout << "[2] Edit a map." << endl;
    cout << "[3] Create new campaign." << endl;
    cout << "[4] Edit a campaign." << endl;
    cout << "[5] Quit." << endl;
    cin >> selection;

    switch(selection){
        case 1: //Create a new map
            {
                //Variables to create & save a new map
                int rows, columns;
                string save; //checks for saving the map
                string anotherMap; //checks whether user wants to keep creating maps

                do{
                    cout << "Please enter dimensions for the map." << endl;
                    cout << "Number of rows: ";
                    cin >> rows; //user input for number of rows in map
                    cout << "Number of columns: ";
                    cin >> columns; //user input for number of columns in map
                    Map newMap(rows, columns); //generates map
                    cout << "\n Displaying map..." << endl;
                    newMap.displayMap(); //display newly created map

                    //Prompt user to save map
                    cout << "Would you like to save this map? Y/N:" << endl;
                    cin >> save;
                    if(save == "Y" || save == "y"){
                        cout << "Save as (example.txt): ";
                        cin >> fileName; //get file name from user to save map
                        fileName = "Map_" + fileName; //append Map_ to the beginning of the file name for identification
                        newMap.saveMapConfiguration(fileName); //save map configuration to file Map_fileName
                        cout << "Map has successfully been saved to: " << fileName << endl; //inform user that map has been saved
                    }
                    else{
                        cout << "Map has not been saved."; //inform user that map has not been saved
                    }

                    //Prompt user to create another map
                    cout << "\nWould you like to create another map? Y/N" << endl;
                    cin >> anotherMap;
                } while(anotherMap == "Y" || anotherMap == "y");
            }
            break;
        case 2: //Edit a map
            {
                //Prompt user to enter the file name of the map they would like to edit
                cout << "Please enter the file name of the map you would like to edit (Note: Can only edit previously saved maps.): ";
                cin >> fileName;
                
                Map map = loadMap(fileName); //try to load the map that the user wishes to edit
                map.displayMap(); //display chosen map

                //Variables for editing & saving map 
                string anotherEdit, save;
                int editSelection, row, column;

                do{
                    //Prompt user for edit choice
                    cout << "What would you like to edit?" << endl;
                    cout << "[1] Change map start point." << endl;
                    cout << "[2] Change map end point." << endl;
                    cout << "[3] Change a cell's contents." << endl;
                    cout << "[4] Cancel." << endl;
                    cin >> editSelection;

                    //Depending on the user's choice, prompt them for the appropraite values to edit
                    switch(editSelection){
                        case 1: //Change map start point
                            {
                                cout << "Please enter the coordinates for the new start point: " << endl;
                                cout << "Row: ";
                                cin >> row;
                                row -= 1; //get new row value
                                cout << "Column: ";
                                cin >> column; 
                                column -= 1; //get new column value

                                //Set new start point
                                map.setBeginRow(row);
                                map.setBeginColumn(column);

                                //Prompt user to save changes
                                cout << "Save changes? Y/N";
                                cin >> save;
                                
                                if(save =="Y" || save == "y"){
                                    map.saveMapConfiguration(fileName); //save changes
                                    cout << "Changes have been saved!" << endl;
                                }

                                break; //End of change map start point
                            }
                        case 2: //Change map end point
                            {
                                cout << "Please enter the coordinates for the new end point: " << endl;
                                cout << "Row: ";
                                cin >> row; 
                                row -= 1; //get new row value
                                cout << "Column: ";
                                cin >> column; //get new column value
                                column -= 1;

                                //Set new end point
                                map.setEndRow(row);
                                map.setEndColumn(column);

                                //Prompt user to save changes
                                cout << "Save changes? Y/N";
                                cin >> save;

                                if(save =="Y" || save == "y"){
                                    map.saveMapConfiguration(fileName); //save changes
                                    cout << "Changes have been saved!" << endl;
                                }

                                break; //End of change map end point
                            }
                        case 3: //Change a cell's contents
                            {
                                cout << "Please enter the coordinates for the cell you like to change: " << endl;
                                cout << "Row: ";
                                cin >> row;
                                row -= 1; //get row of cell user would like to change
                                cout << "Column: ";
                                cin >> column;
                                column -= 1; //get column of cell user would like to change

                                string content; //variable to hold user input for cell content

                                //Prompt user to specify what content they would like in the specified cell
                                cout << "What would you like to change the cell's content to? " << endl;
                                cout << "[0] Empty" << endl;
                                cout << "[W] Wall" << endl;
                                cout << "[T] Treasure" << endl;
                                cout << "[E] Enemy" << endl;
                                cout << "[C] Character" << endl;
                                cin >> content;

                                //Set content of cell as specified by user
                                map.setCellContent(row, column, content);

                                //Prompt user to save changes
                                cout << "Save changes? Y/N" << endl;
                                cin >> save;

                                if(save =="Y" || save == "y"){
                                    map.saveMapConfiguration(fileName); //save changes
                                    cout << "Changes have been saved!" << endl;
                                }

                                break; //End of change cell's contents
                            }
                        default:
                            cout << "Canceling map edits..." << endl;
                            break;
                        }

                        //Prompt user to keep editing map
                        cout << "Would you like to keep editing this map? Y/N" << endl;
                        cin >> anotherEdit;
                    } while(anotherEdit == "Y" || anotherEdit == "y");
            }
            break;
        case 3: //Create a campaign
            {
                //Variables 
                string mapsList; //holds user input of all maps to be used in campaign
                vector<string> mapsListParsed; //holds parsed input of all maps to be used in campaign
                string save; //checks for saving the campaign

                //Prompt user to list maps to be added to campaign
                cout << "Please enter the file names of all the maps you would like to use in your campaign (e.g.: Map_1.txt,Map_2.txt,Map_3.txt):" << endl;
                cout << "Note: The order in which the maps have been entered is the order in which they will be connected as a campaign (end point -> start point)." << endl;
                cout << "Maps: ";
                cin >> mapsList;

                mapsListParsed = split(mapsList, ","); //parse all maps into a vector

                //Checks if only one map has been added to the campaign
                if(mapsListParsed.size() == 1){
                    cout << "Cannot create a campaign with only one map." << endl;
                    break;
                }
                else{
                    //Check if maps are valid
                    bool allValid = true;
                    for(int i = 0; i < mapsListParsed.size(); i++){

                        fileExists = std::filesystem::exists(mapsListParsed.at(i));

                        if(!fileExists || mapsListParsed.at(i).find("Map_") == std::string::npos){
                            allValid = false; //flags if a map is invalid
                            break;
                        }
                    }

                    //If even one map is invalid, exit campaign creator
                    if(!allValid){
                        cout << "One or more maps entered do(es) not exist." << endl;
                        cout << "Cancelling campaign creation..." << endl;
                        break;
                    }

                    //Connects maps to form a campaign
                    vector<string> mapConnections;
                    for(int i = 0; i < mapsListParsed.size() - 1;i++){
                        Map map1 = loadMap(mapsListParsed.at(i));
                        Map map2 = loadMap(mapsListParsed.at(i+1));
                        connectMaps(map1, map2);
                        mapConnections.push_back(mapsListParsed.at(i) + "===" + mapsListParsed.at(i+1)); //adds map relationship to a string vector
                    }

                    cout<< "Campaign has successfully been created!\n" << endl; //notify user that campaign has successfully been created

                    
                    //Prompt user to save campaign
                    cout << "Would you like to save this campaign? Y/N" << endl;
                    cin >> save;

                    if(save == "Y" || save == "y"){
                        cout << "Save as (example.txt): ";
                        cin >> fileName; //get file name from user to save map
                        fileName = "Campaign_" + fileName; //append Campaign_ to the beginning of the file name for identification
                        saveCampaignConfiguration(fileName, mapConnections); //save campaign configuration to file Campaign_fileName
                        cout << "Campaign has successfully been saved to: " << fileName << endl; //inform user that map has been saved
                    }
                    else{
                        cout << "Campaign has not been saved."; //inform user that map has not been saved
                    }
                    
                }
            }
            break; 
        case 4: //Edit a campaign
            {
                //Prompt user to enter the file name of the campaign they want to edit
                cout << "Please enter the file name of the campaign you would like to edit (Note: Only previously saved campaigns can be edited): " << endl;
                cin >> fileName;
                fileExists = std::filesystem::exists(fileName); //check if the campaign exists

                if(fileExists && (fileName.find("Campaign_") != std::string::npos)){
                    ifstream campaignFile; 
                    campaignFile.open(fileName); //open campaign in input mode

                    int editSelection; //holds user's edit choice

                    //Prompt user with edit choices
                    cout << "\nHow would you like to edit this campaign?" << endl;
                    cout << "[1] Re-order maps in campaign." << endl;
                    cout << "[2] Remove a map." << endl;
                    cout << "[3] Add a map to the start of the campaign." << endl;
                    cout << "[4] Add a map to the end of the campaign." << endl;
                    cout << "[5] Cancel." << endl;
                    cin >> editSelection;

                    switch(editSelection){
                        case 1: //Re-order maps
                            {
                                //Variables 
                                string newMapOrder; //holds user input of new map order
                                vector<string> newMapsListParsed; //holds parsed input of new map order
                                string save; //checks for saving the campaign

                                //Prompt user for the new map connection order
                                cout << "\nPlease type the new map connection order (e.g.: Map_2.txt,Map_5.txt,Map_1.txt): ";
                                cin >> newMapOrder;

                                newMapsListParsed = split(newMapOrder, ","); //parse all maps into a vector

                                //Variable to check if entered list matches previous list of maps
                                string line; //hold line in file
                                string oldMapOrder; //hold all lines in file
                                vector<string> oldMapsListParsed; //holds all maps in file in current order

                                //Check if entered list matches previous list of maps
                                while(getline(campaignFile, line)){
                                    oldMapOrder += (line + "===");
                                }
                                oldMapsListParsed = split(oldMapOrder, "==="); //parse all maps in file in current order

                                //Remove duplicate maps
                                oldMapsListParsed.erase(std::unique(oldMapsListParsed.begin(), oldMapsListParsed.end()), oldMapsListParsed.end());
                                oldMapsListParsed.pop_back(); //remove end blank

                                //Check that old and new map vectors are the same size
                                int countNew = newMapsListParsed.size();
                                int countOld = oldMapsListParsed.size();

                                if(countNew == countOld){
                                    //Check if all the maps entered by the user are the same as what's already in the campaign
                                    for(string map: newMapsListParsed){
                                        if(std::find(oldMapsListParsed.begin(), oldMapsListParsed.end(), map) != oldMapsListParsed.end()){
                                            countNew--;
                                        }
                                    }

                                    //If maps are the same, disconnect them all, then reconnect them in the new order
                                    if(countNew == 0){
                                        
                                        //Disconnect all maps
                                        for(int i = 0; i < oldMapsListParsed.size() - 1;i++){
                                            Map map1 = loadMap(oldMapsListParsed.at(i));
                                            Map map2 = loadMap(oldMapsListParsed.at(i+1));
                                            disconnectMaps(map1, map2);
                                        }

                                        //Reconnect maps in the new order
                                        vector<string> mapConnections;
                                        for(int i = 0; i < newMapsListParsed.size() - 1;i++){
                                            Map map1 = loadMap(newMapsListParsed.at(i));
                                            Map map2 = loadMap(newMapsListParsed.at(i+1));
                                            connectMaps(map1, map2);
                                            mapConnections.push_back(newMapsListParsed.at(i) + "===" + newMapsListParsed.at(i+1));
                                        }

                                        //Prompt user to save campaign changes    
                                        cout << "Would you like to save changes to this campaign? Y/N" << endl;
                                        cin >> save;

                                        if(save == "Y" || save == "y"){
                                            saveCampaignConfiguration(fileName, mapConnections); //save changes
                                            cout << "Campaign has successfully been saved to: " << fileName << endl;
                                        }
                                        else{
                                            cout << "Campaign edits have not been saved."; //inform user if edits have not been saved
                                        }

                                    }
                                }
                                else{
                                    cout << "The entered map list is not the same as the map list in this campaign." << endl;
                                    cout << "Closing campaign edits..." << endl;
                                }
                                
                                break;
                            }
                        case 2: //Remove a map
                            {
                                //Variables
                                string mapToRemove; //map to be removed
                                string save; //checks for saving the campaign

                                //Prompt user for map to remove
                                cout << "Which map would you like to remove? (e.g.: Map_2.txt): ";
                                cin >> mapToRemove;

                                fileExists = std::filesystem::exists(mapToRemove); //check if map exists
                                
                                bool mapInCampaign; //checks if map is in the campaign
                                string line; //holds line of campaign file
                                vector<string> mapConnections; //vector of map relationships
                                vector<string> connectedMaps; //vector of map relationships related to map to be removed
                                vector<string> individualMaps; //parse of individual maps connected to the map to be removed

                                //Check if map to remove actually exists in campaign
                                while(getline(campaignFile, line)){
                                    if(line.find(mapToRemove) != std::string::npos){
                                        mapInCampaign = true;
                                        connectedMaps.push_back(line); //stores relationships related to map removal
                                    }
                                    else{
                                        mapConnections.push_back(line); //stores all relationships not related to map removal
                                    }
                                }
       
                                if(fileExists && mapInCampaign){ //checkls if map exists and is in the current campaign
                                    
                                    for(int i=0; i < connectedMaps.size(); i++){
                                        line += (connectedMaps.at(i) + "==="); //creates a string of all maps connected to map to remove
                                    }

                                    individualMaps = split(line, "==="); //parses string of all maps & removes delimeter 

                                    //Remove duplicated from individual maps
                                    individualMaps.erase(std::unique(individualMaps.begin(), individualMaps.end()), individualMaps.end());
                                    individualMaps.pop_back();

                                    //Disconnect map to remove & related maps
                                    for(int i = 0; i < individualMaps.size() - 1; i++){
                                        Map map1 = loadMap(individualMaps.at(i));
                                        Map map2 = loadMap(individualMaps.at(i + 1));
                                        disconnectMaps(map1, map2);
                                    }

                                    //If two maps remain, connect them to each other
                                    individualMaps.erase(std::remove(individualMaps.begin(), individualMaps.end(), mapToRemove), individualMaps.end()); //removes specified map

                                    if(individualMaps.size() > 1){
                                        Map map1 = loadMap(individualMaps.at(0));
                                        Map map2 = loadMap(individualMaps.at(1));
                                        connectMaps(map1, map2);
                                        mapConnections.push_back(individualMaps.at(0) + "===" + individualMaps.at(1)); //stores new relationship between final maps
                                    }
                                    
                                    //Prompt user to save campaign changes    
                                    cout << "Would you like to save changes to this campaign? Y/N" << endl;
                                    cin >> save;

                                    if(save == "Y" || save == "y"){
                                        saveCampaignConfiguration(fileName, mapConnections); //save changes
                                        cout << "Campaign has successfully been saved to: " << fileName << endl;
                                    }
                                    else{
                                        cout << "Campaign edits have not been saved."; //inform user if edits have not been saved
                                    }

                                }
                                else{
                                    cout << "This map does not exist in this campaign." << endl;
                                    break;
                                }

                                break;
                            }
                        case 3: //Add a map to the start of the campaign
                            {
                                //Variables
                                string mapToAdd; //map to add to campaign
                                string save; //checks for saving the campaign

                                //Prompt user for map to add
                                cout << "Which map would you like to add? (e.g.: Map_2.txt): ";
                                cin >> mapToAdd;

                                fileExists = std::filesystem::exists(mapToAdd); //check if map exists

                                string line; //holds line of campaign file
                                vector<string> lineContents; //hold all lines of file
                                string mapToConnectTo; //holds file name of map to connect to

                                while(getline(campaignFile, line)){
                                    lineContents.push_back(line);
                                }
                                mapToConnectTo = lineContents.at(0).substr(0, lineContents.at(0).find("=")); //get map to connect to

                                Map map1 = loadMap(mapToAdd);
                                Map map2 = loadMap(mapToConnectTo);

                                connectMaps(map1, map2); //connect new start map to campaign

                                //Adding campaign connections to file
                                vector<string> mapConnections;
                                mapConnections.push_back(mapToAdd + "===" + mapToConnectTo);
                                for(int i = 0; i < lineContents.size(); i++){
                                    mapConnections.push_back(lineContents.at(i));
                                }
                                
                                //Prompt user to save campaign changes    
                                cout << "Would you like to save changes to this campaign? Y/N" << endl;
                                cin >> save;

                                if(save == "Y" || save == "y"){
                                    saveCampaignConfiguration(fileName, mapConnections); //save changes
                                    cout << "Campaign has successfully been saved to: " << fileName << endl;
                                }
                                else{
                                    cout << "Campaign edits have not been saved."; //inform user if edits have not been saved
                                }
                                
                                break;
                            }
                        case 4: //Add a map to the end of the campaign
                            {
                                //Variables
                                string mapToAdd; //map to add to campaign
                                string save; //checks for saving the campaign

                                //Prompt user for map to remove
                                cout << "Which map would you like to add? (e.g.: Map_2.txt): ";
                                cin >> mapToAdd;

                                fileExists = std::filesystem::exists(mapToAdd);

                                string line; //holds line of campaign file
                                vector<string> lineContents; //hold all lines of file
                                string lastTwoMaps; //holds last line of campaign file
                                vector<string> lastMaps; //contains parse of last line of campaign file
                                string mapToConnectTo; //holds file name of map to connect to

                                while(getline(campaignFile, line)){
                                    lineContents.push_back(line);
                                }
                                lastTwoMaps = lineContents.at(lineContents.size() - 1);
                                lastMaps = split(lastTwoMaps, "===");
                                mapToConnectTo = lastMaps.at(lastMaps.size() - 1);
                                
                                Map map1 = loadMap(mapToConnectTo);
                                Map map2 = loadMap(mapToAdd);

                                connectMaps(map1, map2); //connect new end map to campaign

                                //Adding campaign connections to file
                                vector<string> mapConnections;
                                for(int i = 0; i < lineContents.size(); i++){
                                    mapConnections.push_back(lineContents.at(i));
                                }
                                mapConnections.push_back(mapToConnectTo + "===" + mapToAdd);
                                
                                //Prompt user to save campaign changes    
                                cout << "Would you like to save changes to this campaign? Y/N" << endl;
                                cin >> save;

                                if(save == "Y" || save == "y"){
                                    saveCampaignConfiguration(fileName, mapConnections); //save changes
                                    cout << "Campaign has successfully been saved to: " << fileName << endl;
                                }
                                else{
                                    cout << "Campaign edits have not been saved."; //inform user if edits have not been saved
                                }

                                break;
                            }
                        default:
                            cout << "Canceling campaign edits...\n" << endl;
                            break;
                    }

                }
                else{
                    cout << "This campaign does not exist." << endl;
                    cout << "Canceling campaign edits...\n" << endl;
                }
            } 
            break;
        default: 
            cout << "Closing Map Editor. See you next time!" << endl;
            closeEditor = true;
            break;
    }

    }while(!closeEditor);

};

void saveCampaignConfiguration(string fileName, vector<string> mapConnections){
    ofstream campaignFile; 
    campaignFile.open(fileName); //open campaign (output) file

    for(int i=0; i < mapConnections.size();i++){
        campaignFile << mapConnections.at(i) << endl; //add all map relationships to campaign file
    }

    campaignFile.close(); //close campaign file
};

void connectMaps(Map map1, Map map2){

    //Map connection points
    bool map1EndConnection = map1.getEndConnection();
    bool map2StartConnection = map2.getStartConnection();

    //Check if maps have valid paths
    bool map1Valid = map1.hasValidPath(map1.getBeginRow(), map1.getBeginColumn(), map1.getEndRow(), map1.getEndColumn());
    bool map2Valid = map2.hasValidPath(map2.getBeginRow(), map2.getBeginColumn(), map2.getEndRow(), map2.getEndColumn());

    //If both maps contain valid paths, continue
    if(map1Valid && map2Valid){

        //If both map ends are free, connect them
        if(!map1EndConnection && !map2StartConnection){
            map1.setEndConnection(true);
            map2.setStartConnection(true);
        }
        else{
            cout<<"Cannot connect maps to form a campaign." << endl;
            exit(0);
        }
    }
    else{
        cout << "Cannot create campaign as one or more maps contains an ivalid path." << endl;
        exit(0);
    }
};

void disconnectMaps(Map map1, Map map2){
    //Free map connection points
    map1.setEndConnection(false);
    map2.setStartConnection(false);
};

Map loadMap(string fileName){
    //Check if file exists
    bool fileExists;
    fileExists = std::filesystem::exists(fileName);

    if(fileExists && (fileName.find("Map_") != std::string::npos)){ //checks if file exists and is a map
        ifstream mapFile; 
        mapFile.open(fileName); //open map file in input mode
        
        string line; //to hold a line in the file
        vector<string> lineContents; //list to hold all lines in a file
        vector<string> walls; //list to hold all file lines with wall information
        vector<string> treasure; //list to hold all file lines with occupied cell information
        vector<string> enemies;
        vector<string> characters;

        char num; //for processing line contents
        int rows, columns, beginRow, beginCol, endRow, endCol;

        //Iterate through all lines in the file
        while (getline(mapFile, line)) {
            lineContents.push_back(line); //get all file contents

            if(line.find("Wall") != std::string::npos){
                    walls.push_back(line); //add wall information to wall list
            }

            if(line.find("Treasure") != std::string::npos){
                treasure.push_back(line); //add treasure cell information to treasure list
            }

            if(line.find("Enemy") != std::string::npos){
                enemies.push_back(line); //add enemy cell information to enemies list
            }

            if(line.find("Character") != std::string::npos){
                characters.push_back(line); //add character cell information to character list
            }
        }

        //Get number of rows
        line = lineContents.at(0);
        num = line.back();
        rows = num - '0';

        //Get number of columns
        line = lineContents.at(1);
        num = line.back();
        columns = num - '0';

        //Create map
        Map map(rows,columns);

        //Set start point
        line = lineContents.at(2);
        num = line.back();
        beginRow = num - '0';
        map.setBeginRow(beginRow); //row

        line = lineContents.at(3);
        num = line.back();
        beginCol = num - '0';
        map.setBeginColumn(beginCol); //column

        //Set end point
        line = lineContents.at(4);
        num = line.back();
        endRow = num - '0';
        map.setEndRow(endRow); //row

        line = lineContents.at(5);
        num = line.back();
        endCol = num - '0';
        map.setEndColumn(endCol); //column

        //Variables for getting wall & occupied cell coordinates
        int row;
        int column;

        //Walls
        for(int i=0;i<walls.size()-1;i++){
            //Row
            line = walls.at(i).substr(line.find("(")+1, line.find(","));
            string val = line.substr(line.find("(")+1, line.find(",") - 1);
            val = val.substr(0, val.find(","));
            row = stoi(val); //convert string to int
            
            //Column
            line = walls.at(i).substr(line.find(",")+1, line.find(")") - 1);
            line.pop_back();
            column = stoi(line); //convert string to int
            
            map.setCellContent(row,column,"W");
        }

        //Treasure cells
        for(int i=0;i<treasure.size()-1;i++){
            //Row
            line = treasure.at(i).substr(line.find("(")+1, line.find(","));
            string val = line.substr(line.find("(")+1, line.find(",") - 1);
            val = val.substr(0, val.find(","));
            row = stoi(val); //convert string to int

            //Column
            line = treasure.at(i).substr(line.find(",")+1, line.find(")") - 1);
            line.pop_back();
            column = stoi(line); //convert string to int
            
            map.setCellContent(row,column,"T");
        }

        //Enemy cells
        for(int i=0;i<enemies.size()-1;i++){
            //Row
            line = enemies.at(i).substr(line.find("(")+1, line.find(","));
            string val = line.substr(line.find("(")+1, line.find(",") - 1);
            val = val.substr(0, val.find(","));
            row = stoi(val); //convert string to int

            //Column
            line = enemies.at(i).substr(line.find(",")+1, line.find(")") - 1);
            line.pop_back();
            column = stoi(line); //convert string to int
            
            map.setCellContent(row,column,"E");
        }

        //Character cells
        for(int i=0;i<characters.size()-1;i++){
            //Row
            line = characters.at(i).substr(line.find("(")+1, line.find(","));
            string val = line.substr(line.find("(")+1, line.find(",") - 1);
            val = val.substr(0, val.find(","));
            row = stoi(val); //convert string to int

            //Column
            line = characters.at(i).substr(line.find(",")+1, line.find(")") - 1);
            line.pop_back();
            column = stoi(line); //convert string to int
            
            map.setCellContent(row,column,"C"); 
        }

        mapFile.close();
        return map;
    }
    else{
        cout << "Error: The map " << fileName << " does not exist." << endl;
        exit(0);
    }    
};

int currentTurn = -1;

string changeTurn(string mapFileName){
    //Check if file exists
    bool fileExists;
    fileExists = std::filesystem::exists(mapFileName);

    if(fileExists && (mapFileName.find("Map_") != std::string::npos)){ //checks if file exists and is a map
        ifstream mapFile; 
        mapFile.open(mapFileName); //open map file in input mode

        string line; //to hold a line in the file
        int countEnemy = 1;
        int countPlayers = 1;
        vector<string> lineContents; //list to hold all lines in a file
        vector<string> enemies; //list to hold all file lines with enemy information
        vector<string> players; //list to hold all file lines with player information
        vector <string> characters;

        //Iterate through all lines in the file
        while (getline(mapFile, line)) {
            if(line.find("Enemy") != std::string::npos){
                enemies.push_back("Enemy " + to_string(countEnemy)); //add enemy cell information to enemies list
                countEnemy++;
            }
            if(line.find("Character") != std::string::npos){
                players.push_back("Player " + to_string(countPlayers)); //add player cell information to players list
                countPlayers++;
            }
        }

        for(int i = 0; i < players.size() - 1; i++){
            characters.push_back(players.at(i));
        }

        for(int i = 0; i < enemies.size() - 1; i++){
            characters.push_back(enemies.at(i));
        }

        int numTurns = characters.size() - 1;
        if(currentTurn < numTurns){
            currentTurn = currentTurn + 1;
        }
        else{
            currentTurn = 0;
        }

        string nextTurn = characters.at(currentTurn) + "'s turn.";
        
        return nextTurn;

    }

    return "End of turns.";

};
