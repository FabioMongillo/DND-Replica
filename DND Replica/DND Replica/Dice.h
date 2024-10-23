// Dice header

#ifndef DICE_H
#define DICE_H

#include <iostream>
#include <time.h>
#include <stdlib.h> 
#include <string>
using namespace std;

// Forward declaration of the Observer class since it appears in Dice class
class DiceObserver;

/**
 * @class Dice
 * @brief Represents a dice object in a d20 system
 * 
 */
class Dice{
    public:
        /**
         * @brief Calculates the result of a dice roll as defined by an input string
         * 
         * @return int 
         */
        int rollDice();

        int rollGivenDice(string diceExpression);

};

#endif
