#ifndef CHARACTER_H
#define CHARACTER_H

#include "Map.h"
#include "Container.h"
#include "Strategy.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;
/**
 * @brief Game & Design of the code.
 * 
 * User can create a Character of type Bully, Nimble, or Tank, each with 6 abilities. 
 * They can also equip different items.
 * 
 * The scores of the abilities are randomly generated and assigned depending on the type of character.
 * This was implemented using cmath, ctime, and cstdlib.
 * 
 * The Builder pattern is used to construct complex objects (Characters) step by step.
 * - CharacterBuilder: Abstract base class defining the steps for building a Character.
 * - Concrete Builders (BullyBuilder, NimbleBuilder, TankBuilder): Implement the steps for building specific types of Characters.
 * - CharacterDirector: Constructs a Character using a specified builder.
 * - Character: Represents the final product with methods for setting abilities, equipping items, and displaying information.
 */

/**
 * 
 * @brief Libraries used in the code.
 * 
 * The libraries used:
 * - vector: Used tocreate vector for the generated ability socres, used for sorting and assignment.
 * - algorthm: Used for sorting the order of the ability scores in vector format from least to greastest. 
 * - ctime: Used for time-related functions and for seeding the random number generator.
 * - cstdlib: Used for general utility functions, including rand function for generating random numbers.
 * 
 * The rationale for the selection of the library:
 * - ctime is used for generating random numbers by seeding the random number generator with the current time.
 * - cstdlib is used for the rand function to generate random numbers for the ability scores and damageAttack calculations.
 */


/**
 * @class Character    
 * @brief Represents a generic character in a d20 system. This class is the Product component of the Builder pattern.
 */
class Character {
public:
    /**
     * @brief Constructor for Character class.
     * @param level The level of the character.
     */
    Character(int level);
    /**
     * @brief Default constructor for Character class.
     */
    Character();

    void setStrength(int strength);
    int getStrength();
    void setDexterity(int dexterity);
    int getDexterity();
    void setConstitution(int constitution);
    int getConstitution();
    void setIntelligence(int intelligence);
    void setWisdom(int wisdom);
    void setCharisma(int charisma);

    void setLevel(int level);
    int getLevel();

    void setcurrentHp(int currentHp);
    int getcurrentHp();

    void setmaxHp(int maxHp);
    int getmaxHp();

    void setType(std::string type);
    string getType();

    int getAttackBonus();
    void setAttackBonus(int attackBonus);

    int getDamageBonus();
    void setDamageBonus(int damageBonus);

    int getArmorClass();
    void setArmorClass(int armorClass);

    void setAttacksPerRound(int attacksPerRound);
    int getAttacksPerRound();

    /**
     * @brief Used after character creation to level up characters update current HP and max HP, attack bonus, and attacks per round 
     * every 5 levels.
     */
    void levelUpCharacter();

    void takeDamage(int damage);

    void attack(Character *other);

     /**
     * @brief Displays information about the character.
     */
    virtual void displayInfo();


    // NEW 

    /**
     * @brief Get the Position Row object
     * 
     * @return int value current position row
     */
    virtual int getPositionRow();

    /**
     * @brief Get the Position Column object
     * 
     * @return int value current position row
     */
    virtual int getPositionColumn();

    /**
     * @brief Set the Position Row object
     * 
     * @param row value of new position row
     */
    virtual void setPositionRow(int row);

    /**
     * @brief Set the Position Column object
     * 
     * @param col value of new position column
     */
    virtual void setPositionColumn(int col);

    /**
     * @brief Set the Position object (updates both position row and column)
     * 
     * @param row value of the new position row
     * @param col value of the new position column
     */
    virtual void setPosition(int row, int col);

    /**
     * @brief Move a character along a map
     * 
     * @param map map associated with the character
     * @return string output of the result
     */
    virtual string moveCharacter(Map& map);


    // Strategy related functions
    virtual bool getIsAggressive();
    virtual void setIsAggressive(bool newBool);
    
    virtual Strategy* getStrategy();
    virtual void setStrategy(Strategy* newStrategy);

    virtual void performTurn();


    //Backpack related functions
    void addToBackpack(item itemToAdd);
    void removeFromBackpack(int itemIndex);
    void backpackInfo();
    void backpackItemInfo(int itemIndex);
    std::pair<string, int> getBackpackItemEnchantment(int index);
    container getBackpack(){return backpack;};


    //Equipment related functions
        virtual int getStrengthScore();
        virtual int getDexterityScore();
        virtual int getConstitutionScore();
        virtual int getIntelligenceScore();
        virtual int getWisdomScore();
        virtual int getCharismaScore();
        virtual int getArmorClassScore();
        virtual int getAttackScore();
        virtual int getDamageScore();


private:
    int strength;
    int dexterity;
    int constitution;
    int intelligence;
    int wisdom;
    int charisma;
    int level;
    int currentHp;
    int maxHp;

    std::string type;

    std::string armor="Not Equiped";
    std::string shield="Not Equiped";
    std::string weapon="Not Equiped";
    std::string boots="Not Equiped";
    std::string ring="Not Equiped";
    std::string helmet="Not Equiped";

    int damageBonus;
    int armorClass;
    int attackBonus;
    int attacksPerRound;

    // NEW
    int positionRow;
    int positionColumn;

    Strategy* strategy;
    bool isAggressive = false;

    container backpack;

};

/**
 * @class CharacterBuilder
 * @brief Abstract base class for concrete character builder classes. Implements the Builder pattern.
 */
class CharacterBuilder {
public:
    /**
     * @brief Sets the ability scores of the character.
     */
    virtual void setAbilityScores() = 0;
    /**
     * @brief Sets the HP of the character.
     */
    virtual void setHP() = 0;
    /**
     * @brief Sets level-dependent characteristics of the character.
     */
    virtual void setLevelDependentCharacteristics() = 0;
    /**
     * @brief Sets the damage bonus of the character.
     */
    virtual void setDamageBonus() = 0;
    /**
     * @brief Sets the attack bonus of the character.
     */
    virtual void setAttackBonus() = 0;
    /**
     * @brief Sets the armor class of the character.
     */
    virtual void setArmorClass() = 0;
    /**
     * @brief Gets the constructed character.
     * @return A pointer to the constructed character.
     */
    virtual Character* getCharacter() = 0;
};

/**
 * @class BullyBuilder
 * @brief Concrete builder class for creating a bully-type character. Implements the Builder pattern.
 */
class BullyBuilder : public CharacterBuilder {
public:
    /**
     * @brief Constructor for BullyBuilder class.
     * @param level The level of the character to be built.
     */
    BullyBuilder(int level);
    /**
     * @brief Default constructor for BullyBuilder class.
     * */
    BullyBuilder();

    //Implementations of the virtual methods
    void setHP() override;
    void setAbilityScores() override;
    void setLevelDependentCharacteristics() override;
    void setDamageBonus() override;
    void setAttackBonus() override;
    void setArmorClass() override;

    Character* getCharacter() override;

private:
    Character* character;
    int rollAbilityScore();
    int rolld10();
};

/**
 * @class NimbleBuilder
 * @brief Concrete builder class for creating a nimble-type character. Implements the Builder pattern.
 */
class NimbleBuilder : public CharacterBuilder {
public:
    /**
     * @brief Constructor for NimbleBuilder class.
     * @param level The level of the character to be built.
     */
    NimbleBuilder(int level);
    /**
     * @brief Default constructor for NimbleBuilder class.
     */
    NimbleBuilder();

    // Implementations of the virtual methods
    void setHP() override;
    void setAbilityScores() override;
    void setLevelDependentCharacteristics() override;
    void setDamageBonus() override;
    void setAttackBonus() override;
    void setArmorClass() override;

    Character* getCharacter() override;

private:
    Character* character;
    int rollAbilityScore();
    int rolld10();
};

/**
 * @class TankBuilder
 * @brief Concrete builder class for creating a tank-type character. Implements the Builder pattern.
 */
class TankBuilder : public CharacterBuilder {
public:
    /**
     * @brief Constructor for TankBuilder class.
     * @param level The level of the character to be built.
     */
    TankBuilder(int level);
    /**
     * @brief Default constructor for TankBuilder class.
     */
    TankBuilder();

    // Implementations of the virtual methods
    void setHP() override;
    void setAbilityScores() override;
    void setLevelDependentCharacteristics() override;
    void setDamageBonus() override;
    void setAttackBonus() override;
    void setArmorClass() override;

    Character* getCharacter() override;

private:
    Character* character;
    int rollAbilityScore();
    int rolld10();
};

/**
 * @class CharacterDirector
 * @brief Director class for constructing characters using a builder.
 */
class CharacterDirector {
public:
    /**
     * @brief Creates a character using the specified builder.
     * @param builder The builder to use for constructing the character.
     * @return A pointer to the constructed character.
     */
    Character* createCharacter(CharacterBuilder* builder);
};

#endif 
