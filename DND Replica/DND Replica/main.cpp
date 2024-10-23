//Main file

#include "CharacterP1.h"
#include "CharacterP1.cpp"
#include "Map.h"
#include "Map.cpp"
#include "MapBuilder.h"
#include "FileMapBuilder.h"
#include "FileMapBuilder.cpp"
#include "Container.h"
#include "Container.cpp"
#include "testSophia.h"
#include "testSophia.cpp"
#include "Strategy.h"
#include "HumanPlayerStrategy.h"
#include "HumanPlayerStrategy.cpp"
#include "FriendlyStrategy.h"
#include "FriendlyStrategy.cpp"
#include "AggressorStrategy.h"
#include "AggressorStrategy.cpp"
#include "CharacterDecorator.cpp"
#include "Dice.cpp"


#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void mainMenu();
void play(string chosenCampaign, Character* player);
item createRandomItem();

int main(){  
    srand(time(0));
    mainMenu();    
    return 0;
}

void mainMenu(){

    int menuSelection, campaignNum, numPlayers, charNum;
    CharacterDirector director;
    BullyBuilder bullyBuilder;
    NimbleBuilder nimbleBuilder;
    TankBuilder tankBuilder;

    Character* bully = director.createCharacter(&bullyBuilder);
    Character* nimble = director.createCharacter(&nimbleBuilder);
    Character* tank = director.createCharacter(&tankBuilder);

    vector<Character*> charArray = {};
    //loadCharacters("characters.txt");

    cout<<endl<<"┌───── •✧✧• ─────┐"<<endl;
    cout<<"|    WELCOME TO  |"<<endl;
    cout<<"|       DND!     |"<<endl;
    cout<<"└───── •✧✧• ─────┘"<<endl;

    cout << "[1] Create new character(s)." << endl;
    cout << "[2] Open map editor." << endl;
    cout << "[3] Start session." << endl;
    cout << "[4] Quit." << endl;
    cin >> menuSelection;

    switch(menuSelection){
        case 1: //Create new characters
            {
                while(createCharacter(director));
                loadCharacters("characters.txt");
                mainMenu();  
                break;
            }
        case 2: //Open map editor
            {
                mapEditor();
                mainMenu();
                break;
            }
        case 3: //Start session
            {
                //Select campaign  
                cout << "To begin, please select a campaign." <<endl;
                cout << "Available campaigns: " <<endl;

                cout << "[0] Random" << endl;
                ifstream allCampaigns; 
                allCampaigns.open("Campaigns.txt");
                vector<string> chosenCampaign;
                string line;
                int count = 1;
                while(getline(allCampaigns, line)){
                    chosenCampaign.push_back(line);
                    cout << "[" << count << "] " << line << endl;
                    count++;
                }
                allCampaigns.close();

                bool validChoice;

                while(!validChoice){
                    cout << "\nCampaign selection: ";
                    cin >> campaignNum;

                    if(campaignNum > count){
                        cout << "Invalid option." << endl;
                        cout << "Try again." << endl;
                    }
                    else{
                        validChoice = true;
                    }        
                }

                if(campaignNum == 0){
                    cout << "Selecting random campaign..."<< endl;
                    campaignNum = (rand() % (count - 1)) + 1;
                }
                
                string campaign;
                bool mapBool = true;

                cout << "Campaign " << campaignNum << " selected." << endl;
                campaign = chosenCampaign.at(campaignNum - 1);
                

                //Select Character
                vector<Character*> allCharacters = loadCharacters("characters.txt"); //will show all characters created in characters.txt
                charArray.insert(charArray.end(), allCharacters.begin(), allCharacters.end()); //combine pre-generated and created characters

                int neededPlayers = numPlayers - charArray.size();

                //If no character exists, prompt user to one
                if(charArray.size() < 1){
                    cout << "Must create a character before embarking." << endl;
                    createCharacter(director);

                    allCharacters = loadCharacters("characters.txt"); //will show all characters created in characters.txt
                    charArray.insert(charArray.end(), allCharacters.begin(), allCharacters.end()); //combine pre-generated and created characters
                }
                cout<<endl<<"size of characters in text file "<< allCharacters.size()<<endl;
                
                //Select character to play
                vector<Character*> gameCharacters;

                cout<<endl<<"Character Choices:"<<endl;
                for(int j =0; j<charArray.size(); j++)
                {
                    cout<<endl<<"»»————-Option " << j+1 <<"————-««"<<endl;
                    charArray[j]->displayInfo();
                }
                    
                cout<<endl<< "Please choose your character (1, 2, 3...):";
                cin>>charNum; 
                Character* playerChar = charArray[charNum-1];
                gameCharacters.push_back(playerChar); //chosen player character to set on map

                cout<<endl<<"You have chosen "<<endl;
                playerChar->displayInfo();
                
                //Start campaign
                cout << "Character has been selected. Time to begin your journey!!" << endl;
                play(campaign, playerChar);
                break;
                
            }       
        default: //Quit
            {
                cout << "See you next time!" << endl;
                exit(0);
                break;
            }      
    }

}

void play(string chosenCampaign, Character* player){

    //Equipping all the character's items
    vector<shared_ptr<wornItems>> characterDecoratorList;
    Character* playerWithEquips;

    container tempBackpack = player->getBackpack();
    std::vector<item> tempArray = tempBackpack.getContainerVector();
    for(int i = 0; i < tempArray.size(); i++)
    {
        if(tempArray[i].getType() == "Helmet"){
            addComponent(make_shared<helmetDecorator>(player, tempArray[i].getAC(), tempArray[i].getEnchantment().first, tempArray[i].getEnchantment().second), characterDecoratorList);
        }

        else if(tempArray[i].getType() == "Armor"){
            addComponent(make_shared<armorDecorator>(player, tempArray[i].getAC(), tempArray[i].getEnchantment().first, tempArray[i].getEnchantment().second), characterDecoratorList);
        }

        else if(tempArray[i].getType() == "Shield"){
            addComponent(make_shared<shieldDecorator>(player, tempArray[i].getAC(), tempArray[i].getEnchantment().first, tempArray[i].getEnchantment().second), characterDecoratorList);
        }

        else if(tempArray[i].getType() == "Ring"){
            addComponent(make_shared<ringDecorator>(player, tempArray[i].getAC(), tempArray[i].getEnchantment().first, tempArray[i].getEnchantment().second), characterDecoratorList);
            }

        else if(tempArray[i].getType() == "Belt"){
            addComponent(make_shared<beltDecorator>(player, tempArray[i].getAC(), tempArray[i].getEnchantment().first, tempArray[i].getEnchantment().second), characterDecoratorList);
        }

        else if(tempArray[i].getType() == "Boots"){
            addComponent(make_shared<bootsDecorator>(player, tempArray[i].getAC(), tempArray[i].getEnchantment().first, tempArray[i].getEnchantment().second), characterDecoratorList);
        }

        else if(tempArray[i].getType() == "Weapon"){
            addComponent(make_shared<weaponDecorator>(player, tempArray[i].getAttackBonus(), tempArray[i].getDmgBonus(), tempArray[i].getEnchantment().first, tempArray[i].getEnchantment().second), characterDecoratorList);
        }

    }//End of for loop to equip all items
    playerWithEquips = getCharacter(characterDecoratorList, player);

    //Log play activity
    ofstream writeLogFile; //for writing to log file
    ifstream readLogFile; //for reading from log file
    string fileName = "log.txt"; //log file

    writeLogFile.clear(); //clear log before the start of the session
    writeLogFile.open(fileName, std::ios_base::app); //open & append to file

    //Open campaign file
    ifstream readCampaignFile;
    readCampaignFile.open(chosenCampaign);
    vector<string> mapsListParsed;
    string line, allLines;
    int numMaps;

    while(getline(readCampaignFile, line)){
        allLines += (line + "===");
    }
    mapsListParsed = split(allLines, "==="); //parse all maps into a vector
    mapsListParsed.erase(std::unique(mapsListParsed.begin(), mapsListParsed.end()), mapsListParsed.end());
    mapsListParsed.pop_back(); //remove end blank
    numMaps = mapsListParsed.size();

    //Variables for handling turns and inputs
    int mapNum = 0;
    Map currentMap = loadMap(mapsListParsed.at(mapNum));
    Map* chosenMap = &currentMap;
    bool playing = true;
    bool inCombat = false;
    int turn = 0;
    string moveInput, quitPlaying;
    int playerMenuSelection;

    //Set characters on map
    chosenMap->setCellContent(chosenMap->getBeginRow(),chosenMap->getBeginColumn(), "C");
    player->setPosition(chosenMap->getBeginRow(),chosenMap->getBeginColumn());

    vector<string>enemies;
    bool playerMoved = false;

    vector<int> enemyHP;
    int currentEnemy = 0;

    //Goal
    cout<< "Goal: Get to map endpoint" << endl;
    writeLogFile << "Goal: Get to map endpoint" << endl;

    //Display initial setup
    chosenMap->displayMap();

    while(playing){

        //Get enemies of current map
        enemies = chosenMap->enemiesList();
        for(int i = 0; i < enemies.size();i++){
            enemyHP.push_back((rand() % 20) + 5);
        }

        //Player turn movement
        if(turn == 0){
            cout << "Player turn." << endl;
            writeLogFile << "Player turn.\n";
            
            cout << "Current position: (" << player->getPositionRow() << ", " << player->getPositionColumn() << ")" << endl;
            writeLogFile << "Current position: (" << player->getPositionRow() << ", " << player->getPositionColumn() << ")\n";  

            if(currentMap.enemiesInRange() == true){
                inCombat = true;
            }    

            //Player options for actions during gameplay
            cout << "[0] Quit game" << endl;
            cout << "[1] Move character" << endl;
            cout << "[2] View inventory" << endl;
            cout << "[3] Equip/unequip item" << endl;
            if(inCombat == true){
                cout << "[4] Engage with enemy" << endl;
            }
            cin >> playerMenuSelection;

            //Deals with player movement option
            if(playerMenuSelection == 0){
                cout << "Thanks for playing! See you next time!\n" << endl;
                mainMenu();
            }
            if (playerMenuSelection == 1){
                playerMoved = true;

                string moveOutput = player->moveCharacter(*chosenMap);
                cout << moveOutput;
                writeLogFile << moveOutput;
                
                cout << " New position: (" << player->getPositionRow() << ", " << player->getPositionColumn() << ")\n" << endl; 
                writeLogFile << " New position: (" << player->getPositionRow() << ", " << player->getPositionColumn() << ")\n";
                chosenMap->displayMap();

                //If player has reached end square, go to next map
                if(player->getPositionColumn() == chosenMap->getEndColumn() && (player->getPositionRow() == chosenMap->getEndRow())){
                    if(mapNum < (numMaps -1)){
                        cout << "\nYou carry on your journey and arrive at a new destination..." << endl;
                        writeLogFile << "\nYou carry on your journey and arrive at a new destination..." << endl;
                        currentMap = loadMap(mapsListParsed.at(mapNum + 1));
                        chosenMap->setCellContent(chosenMap->getBeginRow(),chosenMap->getBeginColumn(), "C");
                        player->setPosition(chosenMap->getBeginRow(),chosenMap->getBeginColumn());
                        cout<< "Goal: Get to map endpoint" << endl;
                        writeLogFile << "Goal: Get to map endpoint" << endl;
                        chosenMap->displayMap();
                        currentEnemy = 0;
                        mapNum++;
                    }
                    else{
                        cout << "\nYour journey has come to an end. Thanks for playing!" << endl;
                        writeLogFile << "\nYour journey has come to an end. Thanks for playing!" << endl;
                        mainMenu();
                    }
                }
            }
            
            //Deals with player inventory viewing option
            else if (playerMenuSelection == 2){
                cout << "Player Inventory: " << endl;
                player->getBackpack().containerInfo();
            } 

            //Deals with player equpping/unequipping 
            else if (playerMenuSelection == 3){
                int equipmentChoice;
                cout << "[1] Equip item" << endl;
                cout << "[2] Unequip item" << endl;

                cin >> equipmentChoice;
                cout << endl;

                //Equipping item
                if (equipmentChoice == 1){
                    int indexChoice;
                    tempBackpack = player->getBackpack();
                    tempArray = tempBackpack.getContainerVector();

                    cout << "Give the backpack index of the item you would like to equip: " << endl;
                    cin >> indexChoice;
                    if (indexChoice >= tempArray.size()){
                        cout << "There is no item with that index in the backpack" << endl;
                    }
                    else{
                        for(int i = 0; i < tempArray.size(); i++){
                            if(i == indexChoice){
                                if(tempArray[i].getType() == "Helmet"){
                                    addComponent(make_shared<helmetDecorator>(player, tempArray[i].getAC(), tempArray[i].getEnchantment().first, tempArray[i].getEnchantment().second), characterDecoratorList);
                                }

                                else if(tempArray[i].getType() == "Armor"){
                                    addComponent(make_shared<armorDecorator>(player, tempArray[i].getAC(), tempArray[i].getEnchantment().first, tempArray[i].getEnchantment().second), characterDecoratorList);
                                }

                                else if(tempArray[i].getType() == "Shield"){
                                    addComponent(make_shared<shieldDecorator>(player, tempArray[i].getAC(), tempArray[i].getEnchantment().first, tempArray[i].getEnchantment().second), characterDecoratorList);
                                }

                                else if(tempArray[i].getType() == "Ring"){
                                    addComponent(make_shared<ringDecorator>(player, tempArray[i].getAC(), tempArray[i].getEnchantment().first, tempArray[i].getEnchantment().second), characterDecoratorList);
                                    }

                                else if(tempArray[i].getType() == "Belt"){
                                    addComponent(make_shared<beltDecorator>(player, tempArray[i].getAC(), tempArray[i].getEnchantment().first, tempArray[i].getEnchantment().second), characterDecoratorList);
                                }

                                else if(tempArray[i].getType() == "Boots"){
                                    addComponent(make_shared<bootsDecorator>(player, tempArray[i].getAC(), tempArray[i].getEnchantment().first, tempArray[i].getEnchantment().second), characterDecoratorList);
                                }

                                else if(tempArray[i].getType() == "Weapon"){
                                    addComponent(make_shared<weaponDecorator>(player, tempArray[i].getAttackBonus(), tempArray[i].getDmgBonus(), tempArray[i].getEnchantment().first, tempArray[i].getEnchantment().second), characterDecoratorList);
                                }
                            }

                        }
                        
                        playerWithEquips = getCharacter(characterDecoratorList, player);
                        cout << "Item successfully equipped" << endl << endl;
                        
                    }//End of else statement
                }//End of item equipping

                else if (equipmentChoice == 2){
                    string itemToRemove;

                    cout << "Input the type of the item you want to remove: " << endl;
                    cin >> itemToRemove;

                    for (char& c : itemToRemove){
                        c = std::tolower(c);
                    }
                    itemToRemove[0] = std::toupper(itemToRemove[0]);

                    characterDecoratorList = removeComponent(itemToRemove, characterDecoratorList);
                    playerWithEquips = getCharacter(characterDecoratorList, player);

                }//End of unequipping
            }//End of selection option 3: equipping/unequipping items

            else if (playerMenuSelection == 4 && inCombat){
                Dice dice;
                int roll;
                roll = dice.rollDice();
                cout << "You rolled: " << roll << "!" << endl;
                writeLogFile << "You rolled: " << roll << "!" << endl;
                
                if(roll > enemyHP.at(currentEnemy)){
                    cout << "Attack successful!" << endl;
                    writeLogFile << "Attack successful!" << endl;
                    cout << "Roll for damage: " << endl;
                    roll = dice.rollDice();
                    writeLogFile << "Roll for damage: " << roll << endl; 
                    enemyHP.at(currentEnemy) -= roll;
                    cout << "Enemy HP:" << enemyHP.at(currentEnemy) << endl;
                    writeLogFile << "Enemy HP:" << enemyHP.at(currentEnemy) << endl;

                    if(enemyHP.at(currentEnemy) <= 0){
                        cout << "Enemy defeated!" << endl;
                        writeLogFile << "Enemy defeated!" << endl;

                        if((player->getPositionRow() < chosenMap->getNumRows()) && (chosenMap->getCellContent(player->getPositionRow() + 1, player->getPositionColumn()) == "E")){
                            chosenMap->setCellContent(player->getPositionRow() + 1,player->getPositionColumn(), "0");
                        }
                        if((player->getPositionRow() > 0) &&(chosenMap->getCellContent(player->getPositionRow() - 1, player->getPositionColumn()) == "E")){
                            chosenMap->setCellContent(player->getPositionRow() - 1,player->getPositionColumn(), "0");
                        }
                        if((player->getPositionColumn() < chosenMap->getNumColumns()) &&(chosenMap->getCellContent(player->getPositionRow(), player->getPositionColumn()+ 1) == "E")){
                            chosenMap->setCellContent(player->getPositionRow(),player->getPositionColumn()+ 1, "0");
                        }
                        if((player->getPositionColumn() > 0) &&(chosenMap->getCellContent(player->getPositionRow(), player->getPositionColumn()- 1) == "E")){
                            chosenMap->setCellContent(player->getPositionRow(),player->getPositionColumn()- 1, "0");
                        }

                        currentEnemy++;

                        if(currentEnemy > (enemies.size() - 1)){
                            cout << "All enemies defeated!" << endl;
                            writeLogFile << "All enemies defeated!" << endl;
                        }

                        chosenMap->displayMap();
                        inCombat = false;
                        turn = 0;
                    }
                    else{
                        chosenMap->displayMap();
                        turn++;
                    }
                }
                else{
                    cout << "Attack missed!" << endl;
                    writeLogFile << "Attack missed!" << endl;
                    turn++;
                }
                
            }
            
            else{
                cout << "No option selected.\n" << endl;
                writeLogFile << "No option selected.";
            }
        }
        //Enemy turn movement
        else{
            cout << "Enemy turn." << endl;
            writeLogFile << "Enemy turn.\n";

            Dice dice;
            int roll;
            roll = dice.rollGivenDice("2d10[+3]");
            cout << "Enemy attacks!" << endl;
            writeLogFile << "Enemy attacks!" << endl;
            cout << "Enemy rolled: " << roll << "!" << endl;
            writeLogFile << "Enemy rolled: " << roll << "!" << endl;
                
            if(roll > player->getArmorClass()){
                int currentPlayerHP = player->getcurrentHp();
                cout << "Attack successful!" << endl;
                writeLogFile << "Attack successful!" << endl;
                cout << "Enemy roll for damage: " << endl;
                roll = dice.rollGivenDice("1d6[+3]");
                writeLogFile << "Enemy roll for damage: " << roll << endl; 
                player->setcurrentHp(currentPlayerHP - roll);
                cout << "Player:" << player->getcurrentHp() << endl;
                writeLogFile << "Player HP:" << player->getcurrentHp() << endl;

                if(player->getcurrentHp() <= 0){
                    cout << "Player defeated!" << endl;
                    writeLogFile << "Player defeated!" << endl;
                    cout << "Game over!" << endl;
                    writeLogFile << "Game over!" << endl;
                    writeLogFile.close();
                    mainMenu();
                }
            }
            else{
                cout << "Enemy missed!" << endl;
                writeLogFile << "Enemy missed!" << endl;
            }

            chosenMap->displayMap();
            turn = 0;
        }
        writeLogFile.close();
    }
}
