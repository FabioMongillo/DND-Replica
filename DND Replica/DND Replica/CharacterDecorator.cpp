#include "CharacterDecorator.h"
#include <iostream>
using namespace std;
#include <vector>
#include <memory>


//All wornItems class functions
wornItems::wornItems(Character* c) : character(c) {
    type = "Worn item";
    
}

string wornItems::getType(){
    return "Worn items";
}

Character* wornItems::attachTo(Character* charToDec){

    charToDec = new wornItems(charToDec);
    return charToDec;
}

void wornItems::displayInfo(){
    cout << "Displaying wornItems info \n";
}




//All helmetDecorator class functions
helmetDecorator::helmetDecorator(Character* c, int ac, string enchantName, int enchantAmount) : wornItems(c){
    type = "Helmet";
    itemAC = ac;

    for (char& c : enchantName){
        c = std::tolower(c);
    }
    
    if ((enchantName == "intelligence") && ((enchantAmount <= 5) && enchantAmount >= 1)){
        enchantInc = enchantAmount;
        intelligenceInc = enchantAmount;
        enchantment = enchantName;
    }

    else if ((enchantName == "wisdom") && ((enchantAmount <= 5) && enchantAmount >= 1)){
        enchantInc = enchantAmount;
        wisdomInc = enchantAmount;
        enchantment = enchantName;
    }

    else if ((enchantName == "ac") && ((enchantAmount <= 5) && enchantAmount >= 1)){
        enchantInc = enchantAmount;
        ACInc += enchantAmount;
        enchantment = enchantName;
    }

    else{
        enchantInc = 0;
        enchantment = "None";
    }

};

void helmetDecorator::displayInfo(){
    cout << endl << "Class: " << character->getType() << ", Level: " << character->getLevel() << endl;
    cout << "Hp: " << character->getcurrentHp() << "/" << character->getmaxHp() << endl;
    cout << endl << "Strength score: " << getStrengthScore() << endl;
    cout << "Dexterity score: " << getDexterityScore() << endl;
    cout << "Constitution score: " << getConstitutionScore() << endl;
    cout << "Intelligence score: " << getIntelligenceScore() << endl;
    cout << "Wisdom score: " << getWisdomScore() << endl;
    cout << "Charisma score: " << getCharismaScore() << endl;
    cout << endl;
    cout << "Attacks per round: " << getAttacksPerRound() << endl;
    cout << "Attack Bonus: " << getAttackScore() << endl;
    cout << "Damage Bonus: " << getDamageScore() << endl;
    cout << "Armor Class : " << getArmorClassScore() << endl;
    cout << endl;
}

string helmetDecorator::getType(){
    return type;
}

Character* helmetDecorator::attachTo(Character* charToDec){
    charToDec = new helmetDecorator(charToDec, this->itemAC, this->enchantment, this->enchantInc);
    return charToDec;

}

int helmetDecorator::getStrengthScore(){
    return (character->getStrengthScore() + strengthInc);
}

int helmetDecorator::getDexterityScore(){
    return character->getDexterityScore() + dexterityInc;
}

int helmetDecorator::getConstitutionScore(){
    return character->getConstitutionScore() + constitutionInc;
}

int helmetDecorator::getIntelligenceScore(){
    return character->getIntelligenceScore() + intelligenceInc;
}

int helmetDecorator::getWisdomScore(){
    return character->getWisdomScore() + wisdomInc;
}

int helmetDecorator::getCharismaScore(){
    return character->getCharismaScore() + charismaInc;
}

int helmetDecorator::getArmorClassScore(){
    return character->getArmorClassScore() + ACInc + itemAC;
}

int helmetDecorator::getAttackScore(){
    return character->getAttackScore() + attackInc;
}

int helmetDecorator::getDamageScore(){
    return character->getDamageScore() + damageInc;
}



//All armorDecorator class functions
armorDecorator::armorDecorator(Character* c, int ac, string enchantName, int enchantAmount) : wornItems(c){
    type = "Armor";
    itemAC += ac;

    for (char& c : enchantName){
        c = std::tolower(c);
    }

    if ((enchantName == "ac") && ((enchantAmount <= 5) && enchantAmount >= 1)){
        enchantInc = enchantAmount;
        ACInc += enchantAmount;
        enchantment = enchantName;
    }

    else{
        enchantInc = 0;
        enchantment = "None";
    }

};

void armorDecorator::displayInfo(){
    cout << endl << "Class: " << character->getType() << ", Level: " << character->getLevel() << endl;
    cout << "Hp: " << character->getcurrentHp() << "/" << character->getmaxHp() << endl;
    cout << endl << "Strength score: " << getStrengthScore() << endl;
    cout << "Dexterity score: " << getDexterityScore() << endl;
    cout << "Constitution score: " << getConstitutionScore() << endl;
    cout << "Intelligence score: " << getIntelligenceScore() << endl;
    cout << "Wisdom score: " << getWisdomScore() << endl;
    cout << "Charisma score: " << getCharismaScore() << endl;
    cout << endl;
    cout << "Attacks per round: " << getAttacksPerRound() << endl;
    cout << "Attack Bonus: " << getAttackScore() << endl;
    cout << "Damage Bonus: " << getDamageScore() << endl;
    cout << "Armor Class : " << getArmorClassScore() << endl;
    cout << endl;
}

string armorDecorator::getType(){
    return type;
}

Character* armorDecorator::attachTo(Character* charToDec){
    charToDec = new armorDecorator(charToDec, this->itemAC, this->enchantment, this->enchantInc);
    return charToDec;

}

int armorDecorator::getStrengthScore(){
    return (character->getStrengthScore() + strengthInc);
}

int armorDecorator::getDexterityScore(){
    return character->getDexterityScore() + dexterityInc;
}

int armorDecorator::getConstitutionScore(){
    return character->getConstitutionScore() + constitutionInc;
}

int armorDecorator::getIntelligenceScore(){
    return character->getIntelligenceScore() + intelligenceInc;
}

int armorDecorator::getWisdomScore(){
    return character->getWisdomScore() + wisdomInc;
}

int armorDecorator::getCharismaScore(){
    return character->getCharismaScore() + charismaInc;
}

int armorDecorator::getArmorClassScore(){
    return character->getArmorClassScore() + ACInc + itemAC;
}

int armorDecorator::getAttackScore(){
    return character->getAttackScore() + attackInc;
}

int armorDecorator::getDamageScore(){
    return character->getDamageScore() + damageInc;
}



//All shieldDecorator class functions
shieldDecorator::shieldDecorator(Character* c, int ac, string enchantName, int enchantAmount) : wornItems(c){
    type = "Shield";
    itemAC += ac;

    for (char& c : enchantName){
        c = std::tolower(c);
    }

    if ((enchantName == "ac") && ((enchantAmount <= 5) && enchantAmount >= 1)){
        enchantInc = enchantAmount;
        ACInc += enchantAmount;
        enchantment = enchantName;
    }

    else{
        enchantInc = 0;
        enchantment = "None";
    }

};

void shieldDecorator::displayInfo(){
    cout << endl << "Class: " << character->getType() << ", Level: " << character->getLevel() << endl;
    cout << "Hp: " << character->getcurrentHp() << "/" << character->getmaxHp() << endl;
    cout << endl << "Strength score: " << getStrengthScore() << endl;
    cout << "Dexterity score: " << getDexterityScore() << endl;
    cout << "Constitution score: " << getConstitutionScore() << endl;
    cout << "Intelligence score: " << getIntelligenceScore() << endl;
    cout << "Wisdom score: " << getWisdomScore() << endl;
    cout << "Charisma score: " << getCharismaScore() << endl;
    cout << endl;
    cout << "Attacks per round: " << getAttacksPerRound() << endl;
    cout << "Attack Bonus: " << getAttackScore() << endl;
    cout << "Damage Bonus: " << getDamageScore() << endl;
    cout << "Armor Class : " << getArmorClassScore() << endl;
    cout << endl;
}

string shieldDecorator::getType(){
    return type;
}

Character* shieldDecorator::attachTo(Character* charToDec){
    charToDec = new shieldDecorator(charToDec, this->itemAC, this->enchantment, this->enchantInc);
    return charToDec;

}

int shieldDecorator::getStrengthScore(){
    return (character->getStrengthScore() + strengthInc);
}

int shieldDecorator::getDexterityScore(){
    return character->getDexterityScore() + dexterityInc;
}

int shieldDecorator::getConstitutionScore(){
    return character->getConstitutionScore() + constitutionInc;
}

int shieldDecorator::getIntelligenceScore(){
    return character->getIntelligenceScore() + intelligenceInc;
}

int shieldDecorator::getWisdomScore(){
    return character->getWisdomScore() + wisdomInc;
}

int shieldDecorator::getCharismaScore(){
    return character->getCharismaScore() + charismaInc;
}

int shieldDecorator::getArmorClassScore(){
    return character->getArmorClassScore() + ACInc + itemAC;
}

int shieldDecorator::getAttackScore(){
    return character->getAttackScore() + attackInc;
}

int shieldDecorator::getDamageScore(){
    return character->getDamageScore() + damageInc;
}



//All ringDecorator class functions
ringDecorator::ringDecorator(Character* c, int ac, string enchantName, int enchantAmount) : wornItems(c){
    type = "Ring";
    itemAC += ac;

    for (char& c : enchantName){
        c = std::tolower(c);
    }
    
    if ((enchantName == "ac") && ((enchantAmount <= 5) && enchantAmount >= 1)){
        enchantInc = enchantAmount;
        ACInc += enchantAmount;
        enchantment = enchantName;
    }

    else if ((enchantName == "strength") && ((enchantAmount <= 5) && enchantAmount >= 1)){
        enchantInc = enchantAmount;
        strengthInc = enchantAmount;
        enchantment = enchantName;
    }

    else if ((enchantName == "constitution") && ((enchantAmount <= 5) && enchantAmount >= 1)){
        enchantInc = enchantAmount;
        constitutionInc = enchantAmount;
        enchantment = enchantName;
    }

    else if ((enchantName == "wisdom") && ((enchantAmount <= 5) && enchantAmount >= 1)){
        enchantInc = enchantAmount;
        wisdomInc = enchantAmount;
        enchantment = enchantName;
    }

    else if ((enchantName == "charisma") && ((enchantAmount <= 5) && enchantAmount >= 1)){
        enchantInc = enchantAmount;
        charismaInc = enchantAmount;
        enchantment = enchantName;
    }

    else{
        enchantInc = 0;
        enchantment = "None";
    }

};

void ringDecorator::displayInfo(){
    cout << endl << "Class: " << character->getType() << ", Level: " << character->getLevel() << endl;
    cout << "Hp: " << character->getcurrentHp() << "/" << character->getmaxHp() << endl;
    cout << endl << "Strength score: " << getStrengthScore() << endl;
    cout << "Dexterity score: " << getDexterityScore() << endl;
    cout << "Constitution score: " << getConstitutionScore() << endl;
    cout << "Intelligence score: " << getIntelligenceScore() << endl;
    cout << "Wisdom score: " << getWisdomScore() << endl;
    cout << "Charisma score: " << getCharismaScore() << endl;
    cout << endl;
    cout << "Attacks per round: " << getAttacksPerRound() << endl;
    cout << "Attack Bonus: " << getAttackScore() << endl;
    cout << "Damage Bonus: " << getDamageScore() << endl;
    cout << "Armor Class : " << getArmorClassScore() << endl;
    cout << endl;
}

string ringDecorator::getType(){
    return type;
}

Character* ringDecorator::attachTo(Character* charToDec){
    charToDec = new ringDecorator(charToDec, this->itemAC, this->enchantment, this->enchantInc);
    return charToDec;

}

int ringDecorator::getStrengthScore(){
    return (character->getStrengthScore() + strengthInc);
}

int ringDecorator::getDexterityScore(){
    return character->getDexterityScore() + dexterityInc;
}

int ringDecorator::getConstitutionScore(){
    return character->getConstitutionScore() + constitutionInc;
}

int ringDecorator::getIntelligenceScore(){
    return character->getIntelligenceScore() + intelligenceInc;
}

int ringDecorator::getWisdomScore(){
    return character->getWisdomScore() + wisdomInc;
}

int ringDecorator::getCharismaScore(){
    return character->getCharismaScore() + charismaInc;
}

int ringDecorator::getArmorClassScore(){
    return character->getArmorClassScore() + ACInc + itemAC;
}

int ringDecorator::getAttackScore(){
    return character->getAttackScore() + attackInc;
}

int ringDecorator::getDamageScore(){
    return character->getDamageScore() + damageInc;
}



//All beltDecorator class functions
beltDecorator::beltDecorator(Character* c, int ac, string enchantName, int enchantAmount) : wornItems(c){
    type = "Belt";
    itemAC += ac;

    for (char& c : enchantName){
        c = std::tolower(c);
    }
    
    if ((enchantName == "constitution") && ((enchantAmount <= 5) && enchantAmount >= 1)){
        enchantInc = enchantAmount;
        constitutionInc = enchantAmount;
        enchantment = enchantName;
    }

    else if ((enchantName == "strength") && ((enchantAmount <= 5) && enchantAmount >= 1)){
        enchantInc = enchantAmount;
        strengthInc = enchantAmount;
        enchantment = enchantName;
    }

    else{
        enchantInc = 0;
        enchantment = "None";
    }

};

void beltDecorator::displayInfo(){
    cout << endl << "Class: " << character->getType() << ", Level: " << character->getLevel() << endl;
    cout << "Hp: " << character->getcurrentHp() << "/" << character->getmaxHp() << endl;
    cout << endl << "Strength score: " << getStrengthScore() << endl;
    cout << "Dexterity score: " << getDexterityScore() << endl;
    cout << "Constitution score: " << getConstitutionScore() << endl;
    cout << "Intelligence score: " << getIntelligenceScore() << endl;
    cout << "Wisdom score: " << getWisdomScore() << endl;
    cout << "Charisma score: " << getCharismaScore() << endl;
    cout << endl;
    cout << "Attacks per round: " << getAttacksPerRound() << endl;
    cout << "Attack Bonus: " << getAttackScore() << endl;
    cout << "Damage Bonus: " << getDamageScore() << endl;
    cout << "Armor Class : " << getArmorClassScore() << endl;
    cout << endl;
}

string beltDecorator::getType(){
    return type;
}

Character* beltDecorator::attachTo(Character* charToDec){
    charToDec = new beltDecorator(charToDec, this->itemAC, this->enchantment, this->enchantInc);
    return charToDec;

}

int beltDecorator::getStrengthScore(){
    return (character->getStrengthScore() + strengthInc);
}

int beltDecorator::getDexterityScore(){
    return character->getDexterityScore() + dexterityInc;
}

int beltDecorator::getConstitutionScore(){
    return character->getConstitutionScore() + constitutionInc;
}

int beltDecorator::getIntelligenceScore(){
    return character->getIntelligenceScore() + intelligenceInc;
}

int beltDecorator::getWisdomScore(){
    return character->getWisdomScore() + wisdomInc;
}

int beltDecorator::getCharismaScore(){
    return character->getCharismaScore() + charismaInc;
}

int beltDecorator::getArmorClassScore(){
    return character->getArmorClassScore() + ACInc + itemAC;
}

int beltDecorator::getAttackScore(){
    return character->getAttackScore() + attackInc;
}

int beltDecorator::getDamageScore(){
    return character->getDamageScore() + damageInc;
}



//All bootsDecorator class functions
bootsDecorator::bootsDecorator(Character* c, int ac, string enchantName, int enchantAmount) : wornItems(c){
    type = "Boots";
    itemAC = ac;

    for (char& c : enchantName){
        c = std::tolower(c);
    }
    
    if ((enchantName == "ac") && ((enchantAmount <= 5) && enchantAmount >= 1)){
        enchantInc = enchantAmount;
        ACInc += enchantAmount;
        enchantment = enchantName;
    }

    else if ((enchantName == "dexterity") && ((enchantAmount <= 5) && enchantAmount >= 1)){
        enchantInc = enchantAmount;
        dexterityInc = enchantAmount;
        enchantment = enchantName;
    }

    else{
        enchantInc = 0;
        enchantment = "None";
    }

};

void bootsDecorator::displayInfo(){
    cout << endl << "Class: " << character->getType() << ", Level: " << character->getLevel() << endl;
    cout << "Hp: " << character->getcurrentHp() << "/" << character->getmaxHp() << endl;
    cout << endl << "Strength score: " << getStrengthScore() << endl;
    cout << "Dexterity score: " << getDexterityScore() << endl;
    cout << "Constitution score: " << getConstitutionScore() << endl;
    cout << "Intelligence score: " << getIntelligenceScore() << endl;
    cout << "Wisdom score: " << getWisdomScore() << endl;
    cout << "Charisma score: " << getCharismaScore() << endl;
    cout << endl;
    cout << "Attacks per round: " << getAttacksPerRound() << endl;
    cout << "Attack Bonus: " << getAttackScore() << endl;
    cout << "Damage Bonus: " << getDamageScore() << endl;
    cout << "Armor Class : " << getArmorClassScore() << endl;
    cout << endl;
}

string bootsDecorator::getType(){
    return type;
}

Character* bootsDecorator::attachTo(Character* charToDec){
    charToDec = new bootsDecorator(charToDec, this->itemAC, this->enchantment, this->enchantInc);
    return charToDec;

}

int bootsDecorator::getStrengthScore(){
    return (character->getStrengthScore() + strengthInc);
}

int bootsDecorator::getDexterityScore(){
    return character->getDexterityScore() + dexterityInc;
}

int bootsDecorator::getConstitutionScore(){
    return character->getConstitutionScore() + constitutionInc;
}

int bootsDecorator::getIntelligenceScore(){
    return character->getIntelligenceScore() + intelligenceInc;
}

int bootsDecorator::getWisdomScore(){
    return character->getWisdomScore() + wisdomInc;
}

int bootsDecorator::getCharismaScore(){
    return character->getCharismaScore() + charismaInc;
}

int bootsDecorator::getArmorClassScore(){
    return character->getArmorClassScore() + ACInc + itemAC;
}

int bootsDecorator::getAttackScore(){
    return character->getAttackScore() + attackInc;
}

int bootsDecorator::getDamageScore(){
    return character->getDamageScore() + damageInc;
}




//All weaponDecorator class functions
weaponDecorator::weaponDecorator(Character* c, int ad, int db, string enchantName, int enchantAmount) : wornItems(c){
    type = "Weapon";
    itemAD = ad;
    itemDB = db;

    for (char& c : enchantName){
        c = std::tolower(c);
    }
    
    if ((enchantName == "ab") && ((enchantAmount <= 5) && enchantAmount >= 1)){
        enchantInc = enchantAmount;
        attackInc = enchantAmount;
        enchantment = enchantName;
    }

    else if ((enchantName == "db") && ((enchantAmount <= 5) && enchantAmount >= 1)){
        enchantInc = enchantAmount;
        damageInc = enchantAmount;
        enchantment = enchantName;
    }

    else{
        enchantInc = 0;
        enchantment = "None";
    }

};

void weaponDecorator::displayInfo(){
    cout << endl << "Class: " << character->getType() << ", Level: " << character->getLevel() << endl;
    cout << "Hp: " << character->getcurrentHp() << "/" << character->getmaxHp() << endl;
    cout << endl << "Strength score: " << getStrengthScore() << endl;
    cout << "Dexterity score: " << getDexterityScore() << endl;
    cout << "Constitution score: " << getConstitutionScore() << endl;
    cout << "Intelligence score: " << getIntelligenceScore() << endl;
    cout << "Wisdom score: " << getWisdomScore() << endl;
    cout << "Charisma score: " << getCharismaScore() << endl;
    cout << endl;
    cout << "Attacks per round: " << getAttacksPerRound() << endl;
    cout << "Attack Bonus: " << getAttackScore() << endl;
    cout << "Damage Bonus: " << getDamageScore() << endl;
    cout << "Armor Class : " << getArmorClassScore() << endl;
    cout << endl;
}

string weaponDecorator::getType(){
    return type;
}

Character* weaponDecorator::attachTo(Character* charToDec){
    charToDec = new weaponDecorator(charToDec, this->itemAD, this->itemDB, this->enchantment, this->enchantInc);
    return charToDec;

}

int weaponDecorator::getStrengthScore(){
    return (character->getStrengthScore() + strengthInc);
}

int weaponDecorator::getDexterityScore(){
    return character->getDexterityScore() + dexterityInc;
}

int weaponDecorator::getConstitutionScore(){
    return character->getConstitutionScore() + constitutionInc;
}

int weaponDecorator::getIntelligenceScore(){
    return character->getIntelligenceScore() + intelligenceInc;
}

int weaponDecorator::getWisdomScore(){
    return character->getWisdomScore() + wisdomInc;
}

int weaponDecorator::getCharismaScore(){
    return character->getCharismaScore() + charismaInc;
}

int weaponDecorator::getArmorClassScore(){
    return character->getArmorClassScore() + ACInc;
}

int weaponDecorator::getAttackScore(){
    return character->getAttackScore() + attackInc + itemAD;
}

int weaponDecorator::getDamageScore(){
    return character->getDamageScore() + damageInc + itemDB;
}









//Functions for removal and addition of decorators to a list
//Adds a decorator to the list
void addComponent(std::shared_ptr<wornItems> decorator, vector<shared_ptr<wornItems>>& decList){
    bool inList = false;

    for (int i = 0; i < decList.size(); i++){
        if (decList[i]->getType() == decorator->getType()){
            inList = true;
            break;
        }
    }

    if (inList){
        cout << "Item was not equipped as there is already an item of the given type equipped" << endl;
    }

    else{
        decList.push_back(decorator);
        cout << "Item was equipped successfully" << endl;
    }

}


//Removes a decorator from the list
vector<shared_ptr<wornItems>> removeComponent(string typeToRemove, vector<shared_ptr<wornItems>>& decList){
    bool wasRemoved = false;
    for (int i = 0; i < decList.size(); i++){
        if (decList[i]->getType() == typeToRemove){
            decList.erase(decList.begin() + i);
            wasRemoved = true;
            cout << "Item was successfully removed" << endl;
            break;
        }

    }

    if (!wasRemoved){
        cout << "The item type was not equipped, nothing removed" << endl;
    }

    return decList;
}


//Creates the Character class with the given decorators
Character* getCharacter(const vector<shared_ptr<wornItems>>& decList, Character* character){
    for (const auto& decorator : decList){
        character = decorator->attachTo(character);
    }

    return character;
}

