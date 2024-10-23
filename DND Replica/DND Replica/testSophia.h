#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "CharacterP1.cpp"

using namespace std;

void saveCharacter(Character* character, vector<vector<string>> itemResponses, const string& filename);
vector<Character*> loadCharacters(const string& filename);
void saveCharacter(Character* character, vector<vector<string>> itemResponses, const string& filename);

#endif 