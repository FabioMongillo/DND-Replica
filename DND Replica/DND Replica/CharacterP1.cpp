#include "CharacterP1.h"

#include "AggressorStrategy.h"

using namespace std;

    //Constructors
    Character::Character(int level){this->level=level;type = "Character"; this->attacksPerRound=1; this->backpack = container("Backpack");}
    Character::Character(){this->level=1;type = "Character";this->attacksPerRound=1; this->backpack = container("Backpack");}

    //Ability Getters/setters
    void Character::setStrength(int strength) { this->strength = strength; }
    int Character::getStrength() { return this->strength; }
    void Character::setDexterity(int dexterity) { this->dexterity = dexterity; }
    int Character::getDexterity() { return this->dexterity; }
    void Character::setConstitution(int constitution) { this->constitution = constitution; }
    int Character::getConstitution() { return constitution; }
    void Character::setIntelligence(int intelligence) { this->intelligence = intelligence; }
    void Character::setWisdom(int wisdom) { this->wisdom = wisdom; }
    void Character::setCharisma(int charisma) { this->charisma = charisma; }

    //Level getter/setter
    void Character::setLevel(int level) { this->level = level; }
    int Character::getLevel() { return level; }

    //HP getter/setter
    void Character::setcurrentHp(int currentHp) { this->currentHp = currentHp; }
    int Character::getcurrentHp() { return currentHp; }

    void Character::setmaxHp(int maxHp) { this->maxHp = maxHp; }
    int Character::getmaxHp() { return maxHp; }

    void Character::setType(std::string type) { this->type = type; }
    string Character::getType() { return type; }


    //Bonus getter/setters
    int Character::getAttackBonus() {return attackBonus;}
    void Character::setAttackBonus(int attackBonus) {this->attackBonus = attackBonus;}

    int Character::getDamageBonus() {return damageBonus;}
    void Character::setDamageBonus(int damageBonus) {this->damageBonus = damageBonus;}

    int Character::getArmorClass() {return armorClass;}
    void Character::setArmorClass(int armorClass) {this->armorClass = armorClass;}
    
    void Character::setAttacksPerRound(int attacksPerRound) {this->attacksPerRound=attacksPerRound;}
    int Character::getAttacksPerRound() {return attacksPerRound;}

    //level up function
    void Character::levelUpCharacter() 
    {
        int currentLevel = this->getLevel();
        this->setLevel(currentLevel + 1);

        this->setAttackBonus(this->getAttackBonus()+1);

        if(level%5==0){this->setAttacksPerRound(this->getAttacksPerRound()+1);}

        int hpInc = rand() % 10 + 1 +this->getConstitution();
        currentHp += hpInc;
        maxHp += hpInc;
    }

    //Take damage and attack methods
    void Character::takeDamage(int damage){
        setcurrentHp(getcurrentHp()-damage);
    }

    void Character::attack(Character *other){
        other->takeDamage(getAttackBonus());//?????? what is passed here? attack bonus, damage bonus?
    }


    //display character info
    void Character::displayInfo() {
        std::cout << endl <<type<< endl;
        std::cout << "Level: " << level << endl;
        std::cout << "Current HP: " << currentHp << " Max HP: " << maxHp << endl;
        std::cout << endl << "Strength: " << strength << endl;
        std::cout << "Dexterity: " << dexterity << endl;
        std::cout << "Constitution: " << constitution << endl;
        std::cout << "Intelligence: " << intelligence << endl;
        std::cout << "Wisdom: " << wisdom << endl;
        std::cout << "Charisma: " << charisma << endl;
        std::cout << endl << "Attacks per Round: " << attacksPerRound << endl;
        std::cout << "Attack Bonus: " << attackBonus << endl;
        std::cout << "Damage Bonus: " << damageBonus << endl;
        std::cout << "Armor Class: " << armorClass << endl;
        cout<<endl;
        backpack.containerInfo();
    }

    // NEW

    int Character::getPositionRow(){
        return positionRow;
    }

    int Character::getPositionColumn(){
        return positionColumn;
    }

    void Character::setPositionRow(int row){
        positionRow = row;
    }

    void Character::setPositionColumn(int col){
        positionColumn = col;
    }

    void Character::setPosition(int row, int col){
        positionRow = row;
        positionColumn = col;
    }

    string Character::moveCharacter(Map& map){
        ofstream writeLogFile; //for writing to log file
        string fileName = "log.txt"; //log file
        writeLogFile.open(fileName, std::ios_base::app); //open & append to file

        int row, column, numItems;
        item treasure;
        bool hasCharacter = false;
        string returnStatement="";

        numItems = (rand() % 3) + 1;

        for (int i = 0; i < map.getNumRows(); i++){
            for (int j = 0; j < map.getNumColumns(); j++){
                if(map.grid[i][j] == "C"){
                    hasCharacter = true;
                    row = i;
                    column = j;
                }     
            }
        }
        
        if(hasCharacter){
            int move;
            cout << "Move where?" << endl;
            cout << "[1] Left" << endl;
            cout << "[2] Right" << endl;
            cout << "[3] Up" << endl;
            cout << "[4] Down" << endl;
            cin >> move;

            switch(move){
                case 1: //Left
                {
                    if(map.getCellContent(row,column - 1) == "0"){
                        map.setCellContent(row,column,"0");
                        map.setCellContent(row,column - 1,"C");
                        setPosition(row, column - 1);
                        returnStatement = "Character moved left.";

                    } else if(map.getCellContent(row,column - 1) == "T"){
                        map.setCellContent(row,column,"0");
                        map.setCellContent(row,column - 1, "C");
                        setPosition(row, column - 1);
                        for(int i = 0;i < numItems;i++){
                            treasure = createRandomItem();
                            cout << "Obtained " << treasure.getName() << "!" << endl;
                            writeLogFile << "Obtained " << treasure.getName() << "!" << endl;
                            addToBackpack(treasure);
                        }
                        returnStatement = "\n";
                    }
                    else{
                        returnStatement = "Cannot move in this direction.";
                        cout << returnStatement << endl;
                    }
                    writeLogFile.close();
                    return returnStatement;
                }
                case 2: //Right
                {
                    if(map.getCellContent(row,column + 1) == "0"){
                        map.setCellContent(row,column,"0");
                        map.setCellContent(row,column + 1, "C");
                        setPosition(row, column + 1);
                        returnStatement = "Character moved right.";

                    } else if(map.getCellContent(row,column +1) == "T"){
                        map.setCellContent(row,column,"0");
                        map.setCellContent(row,column +1, "C");
                        setPosition(row, column + 1);
                        for(int i = 0;i < numItems;i++){
                            treasure = createRandomItem();
                            cout << "Obtained " << treasure.getName() << "!" << endl;
                            writeLogFile << "Obtained " << treasure.getName() << "!" << endl;
                            addToBackpack(treasure);
                        }
                        returnStatement = "\n";

                    } else{
                        returnStatement = "Cannot move in this direction.";
                        cout << returnStatement << endl;
                    }
                    writeLogFile.close();
                    return returnStatement;
                }
                case 3: //Up 
                {
                    if(map.getCellContent(row - 1,column) == "0"){
                        map.setCellContent(row,column,"0");
                        map.setCellContent(row - 1,column, "C");
                        setPosition(row - 1, column);
                        returnStatement = "Character moved up.";

                    } else if(map.getCellContent(row - 1,column) == "T"){
                        map.setCellContent(row,column,"0");
                        map.setCellContent(row - 1,column, "C");
                        setPosition(row - 1, column);
                        for(int i = 0;i < numItems;i++){
                            treasure = createRandomItem();
                            cout << "Obtained " << treasure.getName() << "!" << endl;
                            writeLogFile << "Obtained " << treasure.getName() << "!" << endl;
                            addToBackpack(treasure);
                        }
                        returnStatement = "\n";
                    }

                    else{
                        returnStatement = "Cannot move in this direction.";
                        cout << returnStatement << endl;
                    }
                    writeLogFile.close();
                    return returnStatement;
                }
                case 4: //Down
                {
                    if(map.getCellContent(row + 1,column) == "0"){
                        map.setCellContent(row,column,"0");
                        map.setCellContent(row + 1,column, "C");
                        setPosition(row + 1, column);
                        returnStatement = "Character moved down.";
                        
                    } else if(map.getCellContent(row + 1,column) == "T"){
                        map.setCellContent(row,column,"0");
                        map.setCellContent(row + 1,column, "C");
                        setPosition(row + 1, column);
                        for(int i = 0;i < numItems;i++){
                            treasure = createRandomItem();
                            cout << "Obtained " << treasure.getName() << "!" << endl;
                            writeLogFile << "Obtained " << treasure.getName() << "!" << endl;
                            addToBackpack(treasure);
                        }
                        returnStatement = "\n";

                    } else {
                        returnStatement = "Cannot move in this direction.";
                        cout << returnStatement << endl;
                    }
                    writeLogFile.close();
                    return returnStatement;
                }
                default:
                {
                    returnStatement = "Incorrect input for character movement.";
                    cout << returnStatement << endl;
                    writeLogFile.close();
                    return returnStatement;
                }
            }
        }
        returnStatement = "No character in game or no possible movements.";
        writeLogFile.close();
        return returnStatement;
    }

     // Strategy functions
    bool Character::getIsAggressive(){
        return isAggressive;
    }

    void Character::setIsAggressive(bool newBool){
        isAggressive = newBool;
    }

    Strategy* Character::getStrategy(){
        return strategy;
    }

    void  Character::setStrategy(Strategy* newStrategy){
        strategy = newStrategy;
    }


    void Character::performTurn(){
        if (isAggressive) {
            setStrategy(new AggressorStrategy());
        }
        strategy->freeActions(*this);
    }



    //Character backpack manipulation functions
    void Character::addToBackpack(item itemToAdd){
        backpack.addItem(itemToAdd);
    }

    void Character::removeFromBackpack(int index){
        backpack.removeItem(index);
    }

    void Character::backpackInfo(){
        backpack.containerInfo();
    }

    void Character::backpackItemInfo(int index){
        backpack.containerItemInfo(index);
    }

    std::pair<string, int> Character::getBackpackItemEnchantment(int index){
        return (backpack.getContainerItemEnchantment(index));
    }



    //Function for item equipping
    //Get methods for the stats
int Character::getStrengthScore(){
    return strength;
}

int Character::getDexterityScore(){
    return dexterity;
}

int Character::getConstitutionScore(){
    return constitution;
}

int Character::getIntelligenceScore(){
    return intelligence;
}

int Character::getWisdomScore(){
    return wisdom;
}

int Character::getCharismaScore(){
    return charisma;
}

int Character::getAttackScore(){
    return attackBonus;
}

int Character::getDamageScore(){
    return damageBonus;
}

int Character::getArmorClassScore(){
    return armorClass;
}




    BullyBuilder::BullyBuilder(int level) : character(new Character(level)) {
        character->setType("Bully");
    }

    BullyBuilder::BullyBuilder() : character(new Character()) {character->setType("Bully");}

    void BullyBuilder::setHP()
    {
        int* temp = new int;
        *temp = 0;
        for(int i = 0; i<character-> getLevel(); i++)
        {
            *temp += rolld10()+character-> getConstitution(); 
        }
        int newHp =  *temp;
        character->setcurrentHp(newHp); 
        character->setmaxHp(newHp); 
        delete temp;
        temp = NULL;
    }

    void BullyBuilder::setAbilityScores() {
        vector<int> scores;
        for (int i = 0; i < 6; ++i) {
            scores.push_back(rollAbilityScore());
        }
        sort(scores.begin(), scores.end(), greater<int>());
        character->setStrength(scores[0]);
        character->setConstitution(scores[1]);
        character->setDexterity(scores[2]);
        character->setIntelligence(scores[3]);
        character->setCharisma(scores[4]);
        character->setWisdom(scores[5]);
    }

    void BullyBuilder::setLevelDependentCharacteristics() {
        for (int i = 0; i<character->getLevel(); i ++)
        {
            character->setAttackBonus(character->getAttackBonus()+1);
            if((i+1)%5==0){character->setAttacksPerRound(character->getAttacksPerRound()+1);}
        }
    }

    void BullyBuilder::setDamageBonus()  {character->setDamageBonus(character->getStrength() + rand() % 8 + 1);}
    void BullyBuilder::setAttackBonus()  {character->setAttackBonus(character->getLevel() + character->getStrength() + character->getDexterity());}
    void BullyBuilder::setArmorClass()  {character->setArmorClass(10 + character->getDexterity());}

    Character* BullyBuilder::getCharacter()  {
    return character;
    }

    int BullyBuilder::rollAbilityScore() {
        int rolls[4];
        for (int i = 0; i < 4; ++i) {
            rolls[i] = rand() % 6 + 1;
        }
        std::sort(rolls, rolls + 4, std::greater<int>());
        return rolls[0] + rolls[1] + rolls[2];
    }


    int BullyBuilder::rolld10() {
        return rand() % 10 + 1 ;
    }

    NimbleBuilder::NimbleBuilder(int level) : character(new Character(level)){character->setType("Nimble");}
    NimbleBuilder::NimbleBuilder() : character(new Character()) {character->setType("Nimble");}
    
    void NimbleBuilder::setHP()
    {
        
        int* temp = new int;
        *temp = 0;
        for(int i = 0; i<character-> getLevel(); i++)
        {
            *temp += rolld10()+character-> getConstitution(); 
        }
        int newHp =  *temp;
        character->setcurrentHp(newHp); 
        character->setmaxHp(newHp); 
        delete temp;
        temp = NULL;
        
    }

    void NimbleBuilder::setAbilityScores()  {
        vector<int> scores;
        for (int i = 0; i < 6; ++i) {
            scores.push_back(rollAbilityScore());
        }
        sort(scores.begin(), scores.end(), greater<int>());
        character->setDexterity(scores[0]);
        character->setConstitution(scores[1]);
        character->setStrength(scores[2]);
        character->setIntelligence(scores[3]);
        character->setCharisma(scores[4]);
        character->setWisdom(scores[5]);
    }

    void NimbleBuilder::setLevelDependentCharacteristics()  {
        for (int i = 0; i<character->getLevel(); i ++)
        {
            character->setAttackBonus(character->getAttackBonus()+1);
            if((i+1)%5==0){character->setAttacksPerRound(character->getAttacksPerRound()+1);}
        }
    }

    void NimbleBuilder::setDamageBonus()  {character->setDamageBonus(character->getStrength() + rand() % 8 + 1);}
    void NimbleBuilder::setAttackBonus()  {character->setAttackBonus(character->getLevel() + character->getStrength() + character->getDexterity());}
    void NimbleBuilder::setArmorClass()  {character->setArmorClass(10 + character->getDexterity());}


    Character* NimbleBuilder::getCharacter()  {
        return character;
    }

    int NimbleBuilder::rollAbilityScore() {
        int rolls[4];
        for (int i = 0; i < 4; ++i) {
            rolls[i] = rand() % 6 + 1;
        }
        std::sort(rolls, rolls + 4, std::greater<int>());
        return rolls[0] + rolls[1] + rolls[2];
    }
    int NimbleBuilder::rolld10() {
        return rand() % 10 + 1 ;
    }

    TankBuilder::TankBuilder(int level) : character(new Character(level)){character->setType("Tank");}
    TankBuilder::TankBuilder() : character(new Character()) {character->setType("Tank");}

    void TankBuilder::setHP()
    {
        int* temp = new int;
        *temp = 0;
        for(int i = 0; i<character-> getLevel(); i++)
        {
            *temp += rolld10()+character-> getConstitution(); 
        }
        int newHp =  *temp;
        character->setcurrentHp(newHp); 
        character->setmaxHp(newHp); 
        delete temp;
        temp = NULL;
    }

    void TankBuilder::setAbilityScores()  {
        vector<int> scores;
        for (int i = 0; i < 6; ++i) {
            scores.push_back(rollAbilityScore());
        }
        sort(scores.begin(), scores.end(), greater<int>());
        character->setConstitution(scores[0]);
        character->setDexterity(scores[1]);
        character->setStrength(scores[2]);
        character->setIntelligence(scores[3]);
        character->setCharisma(scores[4]);
        character->setWisdom(scores[5]);
    }

    void TankBuilder::setLevelDependentCharacteristics()  {
        for (int i = 0; i<character->getLevel(); i ++)
        {
            character->setAttackBonus(character->getAttackBonus()+1);
            if((i+1)%5==0){character->setAttacksPerRound(character->getAttacksPerRound()+1);}
        }
    }

    void TankBuilder::setDamageBonus()  {character->setDamageBonus(character->getStrength() + rand() % 8 + 1);}
    void TankBuilder::setAttackBonus()  {character->setAttackBonus(character->getLevel() + character->getStrength() + character->getDexterity());}
    void TankBuilder::setArmorClass()  {character->setArmorClass(10 + character->getDexterity());}

    Character* TankBuilder::getCharacter()  {
        return character;
    }


    int TankBuilder::rollAbilityScore() {
        int rolls[4];
        for (int i = 0; i < 4; ++i) {
            rolls[i] = rand() % 6 + 1;
        }
        std::sort(rolls, rolls + 4, std::greater<int>());
        return rolls[0] + rolls[1] + rolls[2];
    }
    int TankBuilder::rolld10() {
        return rand() % 10 + 1 ;
    }

    Character* CharacterDirector::createCharacter(CharacterBuilder* builder) {
        builder->setAbilityScores();
        builder->setLevelDependentCharacteristics();
        builder->setHP();
        builder->setDamageBonus();
        builder->setAttackBonus();
        builder->setArmorClass();
        return builder->getCharacter();
    }
