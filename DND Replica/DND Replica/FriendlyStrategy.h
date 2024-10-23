#ifndef FRIENDLYSTRATEGY_H
#define FRIENDLYSTRATEGY_H

#include "Strategy.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
 * @brief The concrete class FriendlyStrategy implements the Strategy interface to define a Friendly Strategy - will convert to Aggresor Strategy if attacked.
 * 
 */
class FriendlyStrategy : public Strategy{

public:

    /**
     * @brief Construct a new Friendly Strategy object
     * 
     */
    FriendlyStrategy();

    /**
     * @brief Destroy the Friendly Strategy object
     * 
     */
    virtual ~FriendlyStrategy();

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