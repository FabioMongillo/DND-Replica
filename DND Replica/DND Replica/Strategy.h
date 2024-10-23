#ifndef STRATEGY_H
#define STRATEGY_H

#include "CharacterP1.h" // Include the header file that defines the Character class

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Character; // Forward declaration of Character class

/**
 * @brief Abstract class to declare the interface for creating the Strategy
 * 
 */
class Strategy{
public:
    
    /**
     * @brief Move the character to the new cell and update the character's position.
     * 
     * @param character character object
     * @param newRow value of the new row
     * @param newCol value of the new column
     */
    virtual void move(Character& character, int newRow, int newCol) = 0;

    /**
     * @brief Attack during a turn
     * 
     * @param damage damage dealt by the attack - calculated by the sum of the character's level, strength mod and dex mod.
     */
    virtual void attack(Character& current, Character& other) = 0;

    /**
     * @brief Free Action during a turn - can do nothing, speak or equip item.
     * 
     * @param character character object
     */
    virtual void freeActions(Character& character) = 0;

    /**
     * @brief Do nothing for free action
     * 
     */
    virtual void nothing() = 0;

    /**
     * @brief Speak - Voiceline 
     * 
     */
    virtual void speak() = 0;

    /**
     * @brief View backpack/inventory
     * 
     * @param character executing the turn
     */
    virtual void viewBackpack(Character& character) = 0;

    /**
     * @brief Equip an item to a character
     * 
     * @param character character object
     */
    virtual void equip(Character& character) = 0;

    /**
     * @brief Destroy the Strategy object
     * 
     */
    virtual ~Strategy() {}

private:

};

#endif