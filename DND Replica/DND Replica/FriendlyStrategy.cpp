#include "Strategy.h"
#include "FriendlyStrategy.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


FriendlyStrategy::FriendlyStrategy(){

}

FriendlyStrategy::~FriendlyStrategy(){

}

void FriendlyStrategy::move(Character& character, int newRow, int newCol) {
    cout << "Friendly Strategy: Moving to position (" << newRow << ", " << newCol << ")!"<< endl;
    character.setPosition(newRow, newCol);
}


void FriendlyStrategy::attack(Character& current, Character& other){
    cout << "Friendly Strategy: I am friendly - I do not attack." << endl;
}

void FriendlyStrategy::freeActions(Character& character){    
    cout << "Friendly Strategy: Free Actions!" << endl;
    speak();
    
}

void FriendlyStrategy::nothing(){
    cout << "Nothing: No free actions executed." << endl;
}

void FriendlyStrategy::speak(){
    cout << "Speak: 'I am friendly :D'" << endl << endl;
}

void FriendlyStrategy::viewBackpack(Character& character){

}

void FriendlyStrategy::equip(Character& character){

}
