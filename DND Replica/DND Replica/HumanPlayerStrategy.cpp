#include "Strategy.h"
#include "HumanPlayerStrategy.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


HumanPlayerStrategy::HumanPlayerStrategy(){

}

HumanPlayerStrategy::~HumanPlayerStrategy(){

}

void HumanPlayerStrategy::move(Character& character, int newRow, int newCol) {
    cout << "Human Player Strategy: Moving to position (" << newRow << ", " << newCol << ")!"<< endl;
    character.setPosition(newRow, newCol);
}


void HumanPlayerStrategy::attack(Character& current, Character& other){
    cout << "Human Player Strategy: Attack!" << endl;
    current.attack(&other);
}

void HumanPlayerStrategy::freeActions(Character& character){
    cout << "Human Player Strategy: Free Actions! What would you like to do?" << endl;
    cout << "[1] Nothing" << endl;
    cout << "[2] Speak" << endl;
    cout << "[3] View Inventory/Backpack" << endl;
    cout << "Enter your choice: " << endl;
    
    string choice;
    cin >> choice;

    if (choice == "1") {
        nothing();

    } else if (choice == "2") {
        speak();

    } else if (choice == "3"){
        viewBackpack(character);

    } else {
        cout << "Invalid option." << endl;
    }

}

void HumanPlayerStrategy::nothing(){
    cout << "Nothing: No free actions executed." << endl << endl;
}

void HumanPlayerStrategy::speak(){
    cout << "Speak: 'I am ready!'" << endl << endl;
}

void HumanPlayerStrategy::viewBackpack(Character& character){
    character.backpackInfo();
}

void HumanPlayerStrategy::equip(Character& character){
    
    /*
    int itemType;
    string itemName;
    cout << "[1] Armor" << endl;
    cout << "[2] Shield" << endl;
    cout << "[3] Weapon" << endl;
    cout << "[4] Boots" << endl;
    cout << "[5] Ring" << endl;
    cout << "[6] Helmet" << endl;

    // Commented out so demo is quicker

    
    cout << "Enter the item type:" << endl;
    
    //cin >> itemType;
    //cin.ignore();
    cout << "Enter the item name:" << endl;
    //getline(cin, itemName);
    */
    
    /*
       switch (itemType) {
        case 1:
            character.equipArmor(itemName);
            break;

        case 2:
            character.equipShield(itemName);
            break;

        case 3:
            character.equipShield(itemName);
            break;

        case 4:
            character.equipBoots(itemName);
            break;

        case 5:
            character.equipRing(itemName);
            break;

        case 6:
            character.equipHelmet(itemName);
            break;

        default:
            cout << "Invalid selection." <<endl;
            break;
    }
    
    */


}