// Character decorator header

#ifndef CHARACTERDECORATOR_H
#define CHARACTERRECORATOR_H
#include "CharacterP1.h"
#include "Strategy.h"
#include <iostream>
using namespace std;




/**
 * @brief This file contains a decorator class wornItems and all of its children which are used to equip equipment
 * on to the characters.
 * 
 */



/**
 * 
 * @class wornItems
 * @brief wornItems class is a decorator class for Character and is the parent of all the actual children
 * 
 */
class wornItems : public Character{
    public:

    /**
     * @brief Construct a new worn Items object
     * 
     * @param c Character to decorate
     */
        wornItems(Character* c);

        /**
         * @brief Prints all the info about the character updated with the stats of the equipped decorators
         * 
         */
        void displayInfo() override;

        virtual string getType();
        
        /**
         * @brief Allows the decorator to attach itself to a character object
         * 
         * @param charToDec The Character to equip the decorator to
         * @return Character* The given character equipped with the decorator
         */
        virtual Character* attachTo(Character* charToDec);     

        //All functions need to not break main
        int getPositionRow() override{character->getPositionRow();};
        int getPositionColumn() override{character->getPositionColumn();};
        void setPositionRow(int row) override{character->setPositionRow(row);};
        void setPositionColumn(int column) override{character->setPositionColumn(column);};
        void setPosition(int row, int column) override{character->setPosition(row, column);};
        string moveCharacter(Map& map) override{character->moveCharacter(map);};

        //Strategy functions to not break main
        bool getIsAggressive() override{character->getIsAggressive();};
        void setIsAggressive(bool newBool) override{character->setIsAggressive(newBool);};
        Strategy* getStrategy() override{character->getStrategy();};
        void setStrategy(Strategy* newStrat) override{character->setStrategy(newStrat);};
        void performTurn() override{character->performTurn();};

        //Backpack function to not break main
        




    protected:
        Character* character;
        //Protected constructor so it can not be called
        wornItems();
        string type;
        int itemAC = 0;
        int itemAD = 0;
        int itemDB = 0;

};


/**
 * class helmetDecorator
 * @brief Decorator class for helmetDecorators, child of wornItems
 * 
 */
class helmetDecorator : public wornItems{
    public:

    /**
     * @brief Construct a new helmetDecorator object
     * 
     * @param c Character to decorate
     * @param enchantType Name of the enchantment
     * @param enchantNum Amounnt of the enchantment
     */
        helmetDecorator(Character* c, int ac, string enchantType, int enchantNum);

        /**
         * @brief Prints all the info about the character updated with the stats of the equipped decorators
         * 
         */
        void displayInfo() override;

        string getType() override;

        /**
         * @brief Allows the decorator to attach itself to a character object
         * 
         * @param charToDec The Character to equip the decorator to
         * @return Character* The given character equipped with the decorator
         */
        Character* attachTo(Character* charToDec) override;

        
        int getStrengthScore() override;
        int getDexterityScore() override;
        int getConstitutionScore() override;
        int getIntelligenceScore() override;
        int getWisdomScore() override;
        int getCharismaScore() override;
        int getArmorClassScore() override;
        int getAttackScore() override;
        int getDamageScore() override;
        

    protected:    

    private:
        helmetDecorator();
        int strengthInc = 0;
        int dexterityInc = 0;
        int constitutionInc = 0;
        int intelligenceInc = 0;
        int wisdomInc = 0;
        int charismaInc = 0;
        int attackInc = 0;
        int damageInc = 0;
        int ACInc = 0;
        string enchantment;
        int enchantInc = 0;

};



//armorDecorator is a subclass of wornItems 
class armorDecorator : public wornItems{
    public:

    /**
     * @brief Construct a new armorDecorator object
     * 
     * @param c Character to decorate
     * @param enchantType Name of the enchantment
     * @param enchantNum Amount of the enchantment
     */
        armorDecorator(Character* c, int ac, string enchantType, int enchantNum);

        /**
         * @brief Prints all the info about the character updated with the stats of the equipped decorators
         * 
         */
        void displayInfo() override;

        string getType() override;

        /**
         * @brief Allows the decorator to attach itself to a character object
         * 
         * @param charToDec The Character to equip the decorator to
         * @return Character* The given character equipped with the decorator
         */
        Character* attachTo(Character* charToDec) override;

        
        int getStrengthScore() override;
        int getDexterityScore() override;
        int getConstitutionScore() override;
        int getIntelligenceScore() override;
        int getWisdomScore() override;
        int getCharismaScore() override;
        int getArmorClassScore() override;
        int getAttackScore() override;
        int getDamageScore() override;


    protected:    

    private:
        armorDecorator();
        int strengthInc = 0;
        int dexterityInc = 0;
        int constitutionInc = 0;
        int intelligenceInc = 0;
        int wisdomInc = 0;
        int charismaInc = 0;
        int attackInc = 0;
        int damageInc = 0;
        int ACInc = 0;
        string enchantment;
        int enchantInc = 0;

};



//shieldDecorator is a subclass of wornItems 
class shieldDecorator : public wornItems{
    public:

    /**
     * @brief Construct a new shieldDecorator object
     * 
     * @param c Character to decorate
     * @param enchantType Name of the enchantment
     * @param enchantNum Amount of the enchantment
     */
        shieldDecorator(Character* c, int ac, string enchantType, int enchantNum);

        /**
         * @brief Prints all the info about the character updated with the stats of the equipped decorators
         * 
         */
        void displayInfo() override;

        string getType() override;

        /**
         * @brief Allows the decorator to attach itself to a character object
         * 
         * @param charToDec The Character to equip the decorator to
         * @return Character* The given character equipped with the decorator
         */
        Character* attachTo(Character* charToDec) override;

        
        int getStrengthScore() override;
        int getDexterityScore() override;
        int getConstitutionScore() override;
        int getIntelligenceScore() override;
        int getWisdomScore() override;
        int getCharismaScore() override;
        int getArmorClassScore() override;
        int getAttackScore() override;
        int getDamageScore() override;


    protected:    

    private:
        shieldDecorator();
        int strengthInc = 0;
        int dexterityInc = 0;
        int constitutionInc = 0;
        int intelligenceInc = 0;
        int wisdomInc = 0;
        int charismaInc = 0;
        int attackInc = 0;
        int damageInc = 0;
        int ACInc = 0;
        string enchantment;
        int enchantInc = 0;

};



//ringDecorator is a subclass of wornItems 
class ringDecorator : public wornItems{
    public:

    /**
     * @brief Construct a new ringDecorator object
     * 
     * @param c Character to decorate
     * @param enchantType Name of the enchantment 
     * @param enchantNum Amount of the enchantment
     */
        ringDecorator(Character* c, int ac, string enchantType, int enchantNum);

        /**
         * @brief Prints all the info about the character updated with the stats of the equipped decorators
         * 
         */
        void displayInfo() override;

        string getType() override;

        /**
         * @brief Allows the decorator to attach itself to a character object
         * 
         * @param charToDec The Character to equip the decorator to
         * @return Character* The given character equipped with the decorator
         */
        Character* attachTo(Character* charToDec) override;

        
        int getStrengthScore() override;
        int getDexterityScore() override;
        int getConstitutionScore() override;
        int getIntelligenceScore() override;
        int getWisdomScore() override;
        int getCharismaScore() override;
        int getArmorClassScore() override;
        int getAttackScore() override;
        int getDamageScore() override;


    protected:    

    private:
        ringDecorator();
        int strengthInc = 0;
        int dexterityInc = 0;
        int constitutionInc = 0;
        int intelligenceInc = 0;
        int wisdomInc = 0;
        int charismaInc = 0;
        int attackInc = 0;
        int damageInc = 0;
        int ACInc = 0;
        string enchantment;
        int enchantInc = 0;

};



//beltDecorator is a subclass of wornItems 
class beltDecorator : public wornItems{
    public:

    /**
     * @brief Construct a new beltDecorator object
     * 
     * @param c Character to decorate
     * @param enchantType Name of the enchantment
     * @param enchantNum Amount of the enchantment
     */
        beltDecorator(Character* c, int ac, string enchantType, int enchantNum);

        /**
         * @brief Prints all the info about the character updated with the stats of the equipped decorators
         * 
         */
        void displayInfo() override;

        string getType() override;

        /**
         * @brief Allows the decorator to attach itself to a character object
         * 
         * @param charToDec The Character to equip the decorator to
         * @return Character* The given character equipped with the decorator
         */
        Character* attachTo(Character* charToDec) override;

        
        int getStrengthScore() override;
        int getDexterityScore() override;
        int getConstitutionScore() override;
        int getIntelligenceScore() override;
        int getWisdomScore() override;
        int getCharismaScore() override;
        int getArmorClassScore() override;
        int getAttackScore() override;
        int getDamageScore() override;


    protected:    

    private:
        beltDecorator();
        int strengthInc = 0;
        int dexterityInc = 0;
        int constitutionInc = 0;
        int intelligenceInc = 0;
        int wisdomInc = 0;
        int charismaInc = 0;
        int attackInc = 0;
        int damageInc = 0;
        int ACInc = 0;
        string enchantment;
        int enchantInc = 0;

};



//bootsDecorator is a subclass of wornItems 
class bootsDecorator : public wornItems{
    public:

    /**
     * @brief Construct a new bootsDecorator object
     * 
     * @param c Character to decorate
     * @param enchantType Name of the enchantment
     * @param enchantNum Amount of the enchantment
     */
        bootsDecorator(Character* c, int ac, string enchantType, int enchantNum);

        /**
         * @brief Prints all the info about the character updated with the stats of the equipped decorators
         * 
         */
        void displayInfo() override;

        string getType() override;

        /**
         * @brief Allows the decorator to attach itself to a character object
         * 
         * @param charToDec The Character to equip the decorator to
         * @return Character* The given character equipped with the decorator
         */
        Character* attachTo(Character* charToDec) override;

        
        int getStrengthScore() override;
        int getDexterityScore() override;
        int getConstitutionScore() override;
        int getIntelligenceScore() override;
        int getWisdomScore() override;
        int getCharismaScore() override;
        int getArmorClassScore() override;
        int getAttackScore() override;
        int getDamageScore() override;


    protected:    

    private:
        bootsDecorator();
        int strengthInc = 0;
        int dexterityInc = 0;
        int constitutionInc = 0;
        int intelligenceInc = 0;
        int wisdomInc = 0;
        int charismaInc = 0;
        int attackInc = 0;
        int damageInc = 0;
        int ACInc = 0;
        string enchantment;
        int enchantInc = 0;

};



//weaponDecorator is a subclass of wornItems 
class weaponDecorator : public wornItems{
    public:

    /**
     * @brief Construct a new weaponDecorator object
     * 
     * @param c Character to decorate
     * @param enchantType Name of the enchantment
     * @param enchantNum Amount of the enchantment
     */
        weaponDecorator(Character* c, int ad, int db, string enchantType, int enchantNum);

        /**
         * @brief Prints all the info about the character updated with the stats of the equipped decorators
         * 
         */
        void displayInfo() override;

        string getType() override;

        /**
         * @brief Allows the decorator to attach itself to a character object
         * 
         * @param charToDec The Character to equip the decorator to
         * @return Character* The given character equipped with the decorator
         */
        Character* attachTo(Character* charToDec) override;


        int getStrengthScore() override;
        int getDexterityScore() override;
        int getConstitutionScore() override;
        int getIntelligenceScore() override;
        int getWisdomScore() override;
        int getCharismaScore() override;
        int getArmorClassScore() override;
        int getAttackScore() override;
        int getDamageScore() override;
        

    protected:    

    private:
        weaponDecorator();
        int strengthInc = 0;
        int dexterityInc = 0;
        int constitutionInc = 0;
        int intelligenceInc = 0;
        int wisdomInc = 0;
        int charismaInc = 0;
        int attackInc = 0;
        int damageInc = 0;
        int ACInc = 0;
        string enchantment;
        int enchantInc = 0;

};









#endif