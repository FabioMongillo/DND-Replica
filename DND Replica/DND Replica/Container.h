// Container header

#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>
using namespace std;
#include <vector>


/**
 * @brief Item and container creation
 * 
 * This file allows the creation of multiple equipment items, as well as the creation of containers to store said items in.
 * Vectors were used to simplify adding and removing items so that there is no empty space.
 * 
 */


// Parent class of all items
/**
 * @class item
 * @brief Represents all equipment items and is the parent class of all items
 * 
 */
class item{
    public:
        std::pair<string, int> getEnchantment(); 
        void setEnchantment(string enchantName, int enchantAmount);
        /**
         * @brief Prints all the information of the called item
         * 
         */
        void itemInfo();
        int getAC();
        int getAttackBonus();
        int getDmgBonus();   
        string getName();  
        string getType(){return type;};

    protected:
        string name;
        string type;
        std::pair<string, int> enchantment;
        int armorClass;
        int attackBonus;
        int dmgBonus;
};

item createRandomItem();



/**
 * @brief Allows the creation of helmets (child of item)
 * 
 */
class helmet : public item{
    public:
    /**
     * @brief Construct a new helmet object
     * 
     * @param wName Name of the helmet
     * @param armorAmount Amount of AC the helmet provides
     * @param enchantName The enchantment type of the helmet
     * @param enchantAmount The strength of the enchantment 
     */
        helmet(string wName, int armorAmount, string enchantName, int enchantAmount);
    
};

/**
 * @brief Allows the creation of armor pieces (child of item)
 * 
 */
class armor : public item{
    public:
    /**
     * @brief Construct a new armor object
     * 
     * @param wName Name of the armor piece
     * @param armorAmount Amount of AC the armor piece gives
     * @param enchantName The enchantment type of the armor piece
     * @param enchantAmount The strength of the enchantment
     */
        armor(string wName, int armorAmount, string enchantName, int enchantAmount);

};

/**
 * @brief Allows the creation of shields (child of item)
 * 
 */
class shield : public item{
    public:
    /**
     * @brief Construct a new shield object
     * 
     * @param wName Name of the shield
     * @param armorAmount Amount of AC the shield gives
     * @param enchantName The enchantment type of the shield
     * @param enchantAmount The strength of the enchantment
     */
        shield(string wName, int armorAmount, string enchantName, int enchantAmount);

};

/**
 * @brief Allows the creation of rings (child of item)
 * 
 */
class ring : public item{
    public:
    /**
     * @brief Construct a new ring object
     * 
     * @param wName Name of the ring
     * @param armorAmount Amount of AC the ring gives
     * @param enchantName The enchantment type of the ring
     * @param enchantAmount The strength of the enchantment
     */
        ring(string wName, int armorAmount, string enchantName, int enchantAmount);

};

/**
 * @brief Allows the creation of belts (child of item)
 * 
 */
class belt : public item{
    public:
    /**
     * @brief Construct a new belt object
     * 
     * @param wName The name of the belt
     * @param armorAmount The amount of AC the belt gives
     * @param enchantName The enchantment type of the belt
     * @param enchantAmount The strength of the enchantment
     */
        belt(string wName, int armorAmount, string enchantName, int enchantAmount);

};

/**
 * @brief Allows the creation of boots (child of item)
 * 
 */
class boots : public item{
    public:
    /**
     * @brief Construct a new boots object
     * 
     * @param wName The name of the boots
     * @param armorAmount The amount of AC the boots give
     * @param enchantName The enchantment type of the boots
     * @param enchantAmount The strength of the enchantment
     */
        boots(string wName, int armorAmount, string enchantName, int enchantAmount);

};

/**
 * @brief Allows the creation of weapons
 * 
 */
class weapon : public item{
    public:
    /**
     * @brief Construct a new weapon object
     * 
     * @param wName The name of the weapon
     * @param attack The chance it has to land a hit
     * @param dmg The amount of damage it does if it lands a hit
     * @param enchantName The enchantment type of the weapon
     * @param enchantAmount The strength of the enchantment
     */
        weapon(string wName, int attack, int dmg, string enchantName, int enchantAmount);

};



/**
 * @class container
 * @brief Allows for the creation of containers which can store and display items
 * 
 */
class container{
    public:
    /**
     * @brief Construct a new container object
     * 
     * @param cName The name of the container
     */
    container(string cName);
    container();
    void addItem(item addedItem);
    /**
     * @brief Removes items from the container
     * 
     * @param index The index of the item to be removed
     */
    void removeItem(int index);
    /**
     * @brief Prints out the name and index of every item in the container
     * 
     */
    void containerInfo();
    /**
     * @brief Prints out the item info of a specific item
     * 
     * @param index The index of the desired item
     */
    void containerItemInfo(int index);

    std::vector<item> getContainerVector(){return itemArray;};

    std::pair<string, int> getContainerItemEnchantment(int index);

    
    private:
    string containerName;
    std::vector<item> itemArray;

};

#endif
