#ifndef AGGRESSORSTRATEGY_H
#define AGGRESSORSTRATEGY_H

#include "Strategy.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
 * @brief The concrete class AggressorStrategy implements the Strategy interface to define an Aggressor Strategy.
 * 
 */
class AggressorStrategy : public Strategy{

public:

    /**
     * @brief Construct a new Aggressor Strategy object
     * 
     */
    AggressorStrategy();

    /**
     * @brief Destroy the Aggressor Strategy object
     * 
     */
    virtual ~AggressorStrategy();

    /**
     * @brief Move the character to the new cell and update the character's position.
     * 
     * @param character character object
     * @param newRow value of the new row
     * @param newCol value of the new column
     */
    virtual void move(Character& character, int newRow, int newCol) override;

    /**
     * @brief Attack during a turn
     * 
     * @param damage damage dealt by the attack - calculated by the sum of the character's level, strength mod and dex mod.
     */
    virtual void attack(Character& current, Character& other) override;

    /**
     * @brief Free Action during a turn - can do nothing, speak or equip item.
     * 
     * @param character character object
     */
    virtual void freeActions(Character& character) override;

    /**
     * @brief Do nothing for free action
     * 
     */
    virtual void nothing() override;

    /**
     * @brief Speak - Voiceline 
     * 
     */
    virtual void speak() override;

    /**
     * @brief View backpack/inventory
     * 
     * @param character executing the turn
     */
    virtual void viewBackpack(Character& character) override;

    /**
     * @brief Equip an item to a character
     * 
     * @param character character object
     */
    virtual void equip(Character& character) override;

};

#endif