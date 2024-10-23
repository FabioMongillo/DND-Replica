//Container implementation file

#include <iostream>
using namespace std;
#include "Container.h"


// Definitions for item class
std::pair<string, int> item::getEnchantment(){
    return enchantment;
}

void item::setEnchantment(string enchantName, int enchantAmount){
    for (char& c : enchantName){
        c = std::tolower(c);
    }

    if (type == "Helmet" && (enchantName == "intelligence" || enchantName == "wisdom" || enchantName == "ac")){
        if (enchantAmount >=1 && enchantAmount <= 5){
            enchantment.first = enchantName;
            enchantment.second = enchantAmount;
            cout << "Enchantment successfully set" << std::endl;
        }

            else {
        enchantment.first = "None";
        enchantment.second = 0;
        cout << "Enchantment invalid" << std::endl;
        }
    }

    else if (type == "Armor" && (enchantName == "ac")){
        if (enchantAmount >=1 && enchantAmount <= 5){
            enchantment.first = enchantName;
            enchantment.second = enchantAmount;
            cout << "Enchantment successfully set" << std::endl;
        }

            else {
        enchantment.first = "None";
        enchantment.second = 0;
        cout << "Enchantment invalid" << std::endl;
        }
    }

    else if (type == "Shield" && (enchantName == "ac")){
        if (enchantAmount >=1 && enchantAmount <= 5){
            enchantment.first = enchantName;
            enchantment.second = enchantAmount;
            cout << "Enchantment successfully set" << std::endl;
        }

            else {
        enchantment.first = "None";
        enchantment.second = 0;
        cout << "Enchantment invalid" << std::endl;
        }
    }

    else if (type == "Ring" && (enchantName == "ac" || enchantName == "strength" || enchantName == "constitution" || enchantName == "wisdom" || enchantName == "charisma")){
        if (enchantAmount >=1 && enchantAmount <= 5){
            enchantment.first = enchantName;
            enchantment.second = enchantAmount;
            cout << "Enchantment successfully set" << std::endl;
        }

            else {
        enchantment.first = "None";
        enchantment.second = 0;
        cout << "Enchantment invalid" << std::endl;
        }
    }

    else if (type == "Belt" && (enchantName == "constitution" || enchantName == "strength")){
        if (enchantAmount >=1 && enchantAmount <= 5){
            enchantment.first = enchantName;
            enchantment.second = enchantAmount;
            cout << "Enchantment successfully set" << std::endl;
        }

            else {
        enchantment.first = "None";
        enchantment.second = 0;
        cout << "Enchantment invalid" << std::endl;
        }
    }

    else if (type == "Boots" && (enchantName == "ac" || enchantName == "dexterity")){
        if (enchantAmount >=1 && enchantAmount <= 5){
            enchantment.first = enchantName;
            enchantment.second = enchantAmount;
            cout << "Enchantment successfully set" << std::endl;
        }

            else {
        enchantment.first = "None";
        enchantment.second = 0;
        cout << "Enchantment invalid" << std::endl;
        }
    }

    else if (type == "Weapon" && (enchantName == "ab" || enchantName == "db")){
        if (enchantAmount >=1 && enchantAmount <= 5){
            enchantment.first = enchantName;
            enchantment.second = enchantAmount;
            cout << "Enchantment successfully set" << std::endl;
        }

            else {
        enchantment.first = "None";
        enchantment.second = 0;
        cout << "Enchantment invalid" << std::endl;
        }
    }

    else {
        enchantment.first = "None";
        enchantment.second = 0;
        cout << "Enchantment invalid" << std::endl;
    }


} // End of item::setEnchantment()

void item::itemInfo(){
    if (attackBonus == 0 && dmgBonus == 0){
        cout << name << std::endl;
        cout << "Type: " << type << std::endl;
        cout << "Armor class: " << armorClass << std::endl;
        cout << "Enchantment: " << enchantment.first << " +" << enchantment.second << "\n\n";
    }

    else if (armorClass == 0){
        cout << name << std::endl;
        cout << "Type: " << type << std::endl;
        cout << "Attack bonus: " << attackBonus << std::endl;
        cout << "Damage bonus: " << dmgBonus << std::endl;
        cout << "Enchantment: " << enchantment.first << " +" << enchantment.second << "\n\n";
    }
}

int item::getAC(){
    return armorClass;
}

int item::getAttackBonus(){
    return attackBonus;
}

int item::getDmgBonus(){
    return dmgBonus;
}

string item::getName(){
    return name;
}


// Definitions for helmet class
helmet::helmet(string wName, int armorAmount, string enchantName, int enchantAmount){
    name = wName;
    type = "Helmet";
    armorClass = armorAmount;
    dmgBonus = 0;
    attackBonus = 0;


    for (char& c : enchantName){
        c = std::tolower(c);
    }

    if (enchantName == "intelligence" || enchantName == "wisdom" || enchantName == "ac"){
        if (enchantAmount >=1 && enchantAmount <= 5){
            enchantment.first = enchantName;
            enchantment.second = enchantAmount;
        }

            else {
        enchantment.first = "None";
        enchantment.second = 0;
        }
    }

    else {
        enchantment.first = "None";
        enchantment.second = 0;
    }
}


// Definitions for armor class
armor::armor(string wName, int armorAmount, string enchantName, int enchantAmount){
    name = wName;
    type = "Armor";
    armorClass = armorAmount;
    attackBonus = 0;
    dmgBonus = 0;


    for (char& c : enchantName){
        c = std::tolower(c);
    }

    if (enchantName == "ac"){
        if (enchantAmount >=1 && enchantAmount <= 5){
            enchantment.first = enchantName;
            enchantment.second = enchantAmount;
        }

            else {
        enchantment.first = "None";
        enchantment.second = 0;
        }
    }

    else {
        enchantment.first = "None";
        enchantment.second = 0;
    }
}


// Definitions for shield class
shield::shield(string wName, int armorAmount, string enchantName, int enchantAmount){
    name = wName;
    type = "Shield";
    armorClass = armorAmount;
    attackBonus = 0;
    dmgBonus = 0;


    for (char& c : enchantName){
        c = std::tolower(c);
    }

    if (enchantName == "ac"){
        if (enchantAmount >=1 && enchantAmount <= 5){
            enchantment.first = enchantName;
            enchantment.second = enchantAmount;
        }

            else {
        enchantment.first = "None";
        enchantment.second = 0;
        }
    }

    else {
        enchantment.first = "None";
        enchantment.second = 0;
    }
}


// Definitions for ring class
ring::ring(string wName, int armorAmount, string enchantName, int enchantAmount){
    name = wName;
    type = "Ring";
    armorClass = armorAmount;
    attackBonus = 0;
    dmgBonus = 0;


    for (char& c : enchantName){
        c = std::tolower(c);
    }

    if (enchantName == "strength" || enchantName == "wisdom" || enchantName == "ac" || enchantName == "charisma" || enchantName == "constitution"){
        if (enchantAmount >=1 && enchantAmount <= 5){
            enchantment.first = enchantName;
            enchantment.second = enchantAmount;
        }

            else {
        enchantment.first = "None";
        enchantment.second = 0;
        }
    }

    else {
        enchantment.first = "None";
        enchantment.second = 0;
    }
}


// Definitions for belt class
belt::belt(string wName, int armorAmount, string enchantName, int enchantAmount){
    name = wName;
    type = "Belt";
    armorClass = armorAmount;
    attackBonus = 0;
    dmgBonus = 0;


    for (char& c : enchantName){
        c = std::tolower(c);
    }

    if (enchantName == "strength" || enchantName == "constitution"){
        if (enchantAmount >=1 && enchantAmount <= 5){
            enchantment.first = enchantName;
            enchantment.second = enchantAmount;
        }

            else {
        enchantment.first = "None";
        enchantment.second = 0;
        }
    }

    else {
        enchantment.first = "None";
        enchantment.second = 0;
    }
}


// Definitions for boots class
boots::boots(string wName, int armorAmount, string enchantName, int enchantAmount){
    name = wName;
    type = "Boots";
    armorClass = armorAmount;
    attackBonus = 0;
    dmgBonus = 0;


    for (char& c : enchantName){
        c = std::tolower(c);
    }

    if (enchantName == "dexterity" || enchantName == "ac"){
        if (enchantAmount >=1 && enchantAmount <= 5){
            enchantment.first = enchantName;
            enchantment.second = enchantAmount;
        }

            else {
        enchantment.first = "None";
        enchantment.second = 0;
        }
    }

    else {
        enchantment.first = "None";
        enchantment.second = 0;
    }
}


// Definitions for weapon class
weapon::weapon(string wName, int attack, int dmg, string enchantName, int enchantAmount){
    name = wName;
    type = "Weapon";
    attackBonus = attack;
    dmgBonus = dmg;
    armorClass = 0;

    for (char& c : enchantName){
        c = std::tolower(c);
    }

    if (enchantName == "ab" || enchantName == "db"){
        if (enchantAmount >=1 && enchantAmount <= 5){
            enchantment.first = enchantName;
            enchantment.second = enchantAmount;
        }

            else {
        enchantment.first = "None";
        enchantment.second = 0;
        }
    }

    else {
        enchantment.first = "None";
        enchantment.second = 0;
    }

}


// Definitions for container class
container::container(string cName){
    containerName = cName;
}

container::container(){
    containerName = "Unnamed container";
}

void container::addItem(item addedItem){
    itemArray.push_back(addedItem);

}

void container::removeItem(int index){
    itemArray.erase(itemArray.begin() + index);
}

void container::containerInfo(){
    if(itemArray.empty()){
        cout << containerName << " is empty \n\n";
    }

    else{
        cout << containerName << " contains: \n\n";
        for (int i = 0; i < itemArray.size(); i++){
        cout << "Item index: " << i << std::endl;
        cout << "Item: " << itemArray[i].getName() << "\n\n";
    }
    }
}

void container::containerItemInfo(int index){
    itemArray[index].itemInfo();
}


std::pair<string, int> container::getContainerItemEnchantment(int index){
    return (itemArray[index].getEnchantment());
}

//Function to create a random item
item createRandomItem(){
    int itemToCreate = (rand() % 7) + 1;
    item output;

    if(itemToCreate == 1){
        vector<string> enchantList = {"None", "Intelligence", "AC", "Wisdom"};

        output = helmet("Iron helmet", (rand() % 4), enchantList[rand() % 4], (rand() % 6));
    }

    else if(itemToCreate == 2){
        vector<string> enchantList = {"None", "AC"};

        output = armor("Iron armor", (rand() % 6), enchantList[rand() % 4], (rand() % 6));
    }

    else if(itemToCreate == 3){
        vector<string> enchantList = {"None", "AC"};

        output = shield("Iron shield", (rand() % 5), enchantList[rand() % 4], (rand() % 6));
    }

    else if(itemToCreate == 4){
        vector<string> enchantList = {"None", "AC", "Strength", "Constitution", "Wisdom", "Charisma"};

        output = ring("Iron ring", (rand() % 3), enchantList[rand() % 4], (rand() % 6));
    }

    else if(itemToCreate == 5){
        vector<string> enchantList = {"None", "Constitution", "Strength"};

        output = belt("Leather belt", (rand() % 2), enchantList[rand() % 4], (rand() % 6));
    }

    else if(itemToCreate == 6){
        vector<string> enchantList = {"None", "AC", "Dexterity"};

        output = boots("Iron armor", (rand() % 4), enchantList[rand() % 4], (rand() % 6));
    }

    else if(itemToCreate == 7){
        vector<string> enchantList = {"None", "AD", "DB"};

        output = weapon("Iron armor", (rand() % 7), (rand() % 13), enchantList[rand() % 4], (rand() % 6));
    }

    return output;

}
