#include "testSophia.h"

using namespace std;

void saveCharacter(Character* character, vector<vector<string>> itemResponses, const string& filename) {
    std::ofstream file(filename, std::ios::app);
    if (file.is_open()) {
        file << character->getType() << " " << character->getLevel();
        for (int i = 0; i < itemResponses.size(); ++i) {
        for (int j = 0; j < itemResponses[i].size(); ++j) {
            if(itemResponses[i][j].empty()){}
            else
                file << " " << itemResponses[i][j];
        }
    }
        file<<endl;
        file.close();
    } else {
        std::cerr << "Unable to open file for writing." << std::endl;
    }
}

vector<Character*> loadCharacters(const string& filename) {
    vector<Character*> characters;
    CharacterDirector director;
    Character* createdCharacter;
    bool newCharacter;

    ifstream file(filename);
    if (file.is_open()) {
        string type;
        file>>type;
        int level;
        file>>level;
        label:
        cout<<endl<<"level again: "<<level;
        if (type == "Nimble") {
        NimbleBuilder nimbleBuilder(level);
        Character* nimbleCreated = director.createCharacter(&nimbleBuilder);
        createdCharacter = nimbleCreated;
    } else if (type == "Tank") {
        TankBuilder tankBuilder(level);
        Character* tankCreated = director.createCharacter(&tankBuilder);
        createdCharacter = tankCreated;
    } else if (type == "Bully") {
        cout<<endl<<"bullbull yes"<<endl;
        BullyBuilder bullyBuilder(level);
        Character* bullyCreated = director.createCharacter(&bullyBuilder);
        createdCharacter = bullyCreated;
    } else {
        std::cout <<endl<< "Invalid character type" << std::endl;
        
    }
    string info;
    newCharacter=false;
    while (file >> info && !newCharacter) 
    {
        string name, enchantName;
        int ac, ap, dp, enchantPower;
        //cout <<endl<< "info word: "<<info << " "<<endl;

        if (info == "helmet" || info == "armor" || info == "shield" || info == "ring" || info == "belt" || info == "boots") {
            file >> name >> ac >> enchantName >> enchantPower;
            //cout << name << " " << ac << " " << enchantName << " " << enchantPower<<" ";
            if (info == "helmet") {createdCharacter->addToBackpack(helmet(name, ac, enchantName, enchantPower));} 
            if (info == "armor") {createdCharacter->addToBackpack(armor(name, ac, enchantName, enchantPower));} 
            if (info == "ring") {createdCharacter->addToBackpack(ring(name, ac, enchantName, enchantPower));}
            if (info == "shield") {createdCharacter->addToBackpack(shield(name, ac, enchantName, enchantPower));}
            if (info == "belt") {createdCharacter->addToBackpack(belt(name, ac, enchantName, enchantPower));}
            if (info == "boots") {createdCharacter->addToBackpack(boots(name, ac, enchantName, enchantPower));}
            
        }
        else if (info =="weapon")
        {
            file >> name >> ap >> dp >> enchantName >> enchantPower;
            //cout << name << " " << ap << " " << dp << " " << enchantName << " " << enchantPower<<" ";
            createdCharacter->addToBackpack(weapon(name, dp, ap, enchantName, enchantPower));
        }
        else
        {
            if(info == "Nimble" || info == "Bully" || info == "Tank"){
                characters.emplace_back(createdCharacter);
                type=info;
                file>>level;
                cout<<endl<<"level: "<<level;
                goto label;
            }
            else
                cout<<endl<<"UNEXPECTED"<<info<<endl;
        }
    }

        
    characters.emplace_back(createdCharacter);
    file.close();
    }
        
    else {
        cerr << "Unable to open file for reading." << endl;
    }
    return characters;
}

int createCharacter(CharacterDirector director)
{
    string type;
    int level;
    Character* createdCharacter;
    do
    {
        cout << "Enter character type (nimble, tank, bully): ";
        cin >> type;
    } while (type != "nimble" && type != "tank" && type != "bully");
    
    cout << "Enter character level: ";
    cin >> level;

    vector<string> itemList = {"helmet", "armor", "shield", "ring", "belt", "boots", "weapon"};
    vector<string> itemInfoList = {"name", "armor class", "enchantment name", "enchantment power"};
    vector<string> weaponInfoList = {"name", "attack power", "damage power", "enchantment name", "enchantment power"};
    vector<vector<string>> itemResponses(7, vector<string>(5));
    int addItem = 0;

    for(int i = 0; i<itemList.size(); i++)
    {
        cout << "Would you like to add a "<<itemList[i]<< " item to your character? (0=no, 1=yes):"<<endl;
        cin>>addItem;
        if(cin.fail()) {
            cin.clear(); // Clear the fail bit
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        }
        if(addItem) {
            itemResponses[i].push_back(itemList[i]);
            if(itemList[i]=="weapon")
            {
                for(int j=0; j<weaponInfoList.size();j++)
                {
                    string info;
                    cout << "What is the " << itemList[i] << "'s "<<weaponInfoList[j]<<"?:" << std::endl;
                    std::cin >> info;
                    itemResponses[i].push_back(info);
                }
            }
            else{
                for(int j=0; j<itemInfoList.size();j++)
                {
                    string info;
                    cout << "What is the " << itemList[i] << "'s "<<itemInfoList[j]<<"?:" << std::endl;
                    std::cin >> info;
                    itemResponses[i].push_back(info);
                }
            }
        }
        else{}
    }   
        //use for load
        if (type == "nimble") {
            NimbleBuilder nimbleBuilder(level);
            Character* nimbleCreated = director.createCharacter(&nimbleBuilder);
            createdCharacter = nimbleCreated;
        } else if (type == "tank") {
            TankBuilder tankBuilder(level);
            Character* tankCreated = director.createCharacter(&tankBuilder);
            createdCharacter = tankCreated;
        } else if (type == "bully") {
            BullyBuilder bullyBuilder(level);
            Character* bullyCreated = director.createCharacter(&bullyBuilder);
            createdCharacter = bullyCreated;
        } else {
            std::cout << "Invalid character type" << std::endl;
        }

        saveCharacter(createdCharacter, itemResponses, "characters.txt");
        cout<<"Do you wish to create another character? (0 = no, 1 = yes)"<<endl;
        int createCharacter;
        cin>> createCharacter;
        return createCharacter;
}
