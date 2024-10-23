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
#include "CharacterDecorator.cpp"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;


int main(){
    vector<shared_ptr<wornItems>> decoratorList;


    CharacterDirector director;
    BullyBuilder bullyBuilder;
    NimbleBuilder nimbleBuilder;
    TankBuilder tankBuilder;

    Character* bully = director.createCharacter(&bullyBuilder);
    Character* nimble = director.createCharacter(&nimbleBuilder);
    Character* tank = director.createCharacter(&tankBuilder);


    //Making the list of decorators
    addComponent(make_shared<helmetDecorator>(nimble, 2, "armor class", 5), decoratorList);
    addComponent(make_shared<shieldDecorator>(nimble, 4, "armor class", 2), decoratorList);
    addComponent(make_shared<weaponDecorator>(nimble, 2, 3, "attack bonus", 2), decoratorList);
    addComponent(make_shared<ringDecorator>(nimble, 0, "armor class", 7), decoratorList);

    
    nimble->addToBackpack(helmet("Iron helmet", 2, "None", 0));
    std::pair<string, int> enchantInfo = nimble->getBackpackItemEnchantment(0);
    cout << "Enchantment is: " << enchantInfo.first << endl << "Enchantment amount is: " << enchantInfo.second << endl;
    
    //Testing equipping and removing items from the player/equipment list
    Character* newNimble = getCharacter(decoratorList, nimble);
    newNimble->displayInfo();
    decoratorList = removeComponent("Helmet", decoratorList);
    newNimble = getCharacter(decoratorList, nimble);
    newNimble->displayInfo();

    


    

    return 0;
}