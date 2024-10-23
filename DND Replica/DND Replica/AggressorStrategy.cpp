#include "Strategy.h"
#include "AggressorStrategy.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


AggressorStrategy::AggressorStrategy(){

}

AggressorStrategy::~AggressorStrategy(){

}

void AggressorStrategy::move(Character& character, int newRow, int newCol) {
    cout << "Aggressor Strategy: Moving to position (" << newRow << ", " << newCol << ")!"<< endl;
    character.setPosition(newRow, newCol);
}


void AggressorStrategy::attack(Character& current, Character& other){
    cout << "Aggressor Strategy: Attack!" << endl;
    current.attack(&other);
}

void AggressorStrategy::freeActions(Character& character){    
    cout << "Aggressor Strategy: Free Actions!" << endl;
    speak();
}

void AggressorStrategy::nothing(){
    cout << "Nothing: No free actions executed." << endl;
}

void AggressorStrategy::speak(){
    cout << "Speak: 'I will defeat you!'" << endl << endl;
}

void AggressorStrategy::viewBackpack(Character& character){
    
}

void AggressorStrategy::equip(Character& character){

}
