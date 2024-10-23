//Dice implementation file

#include "Dice.h"
#include <iostream>
#include <time.h>
#include <stdlib.h> 
#include <string>
using namespace std;

/**
 * @brief Calculates the result of a dice roll as defined by an input string
 * 
 * @return int 
 */
int Dice::rollDice(){
    
    string diceExpression;

    cout << "Please enter the dice roll expression in th e following format: xdy[+z]." << endl;
    cin >> diceExpression;

    string first, second, third; //separate x, y and z values
    int x, y, z; //convert x, y and z values to ints

    //Checks if values entered are floats or negative. If yes, prints an error and terminates program.
    if(diceExpression.find(".") != std::string::npos || diceExpression.find("-") != std::string::npos){
        fprintf(stderr , "Error: The entered expression is invalid.");
        exit(1);
    }

    //Split string into 3 values x, y & z
    first = diceExpression.substr(0,diceExpression.find("d"));
    second = diceExpression.substr(diceExpression.find("d") + 1,diceExpression.find("[")-2);
    third = diceExpression.substr(diceExpression.find("+") + 1,diceExpression.length()-1);
    third.pop_back();

    try{
        //Convert parsed string values into ints
        x = stoi(first);
        y = stoi(second);
        if(y != 4 && y != 6 && y != 8 && y!= 10 && y != 12 && y != 20 && y != 100){
            fprintf(stderr , "Error: Invalid dice type.");
            exit(1);
        }
        z = stoi(third);

        int r; //holds random value rolled for die dy
        int result; //holds result of dice roll, including bonus
        srand(time(NULL)); //seed to randomize rand()

        //Roll the correct dice and return the result
        switch(y){    
            case 4:
                r = (rand() % (4*x)) + x;
                result = r + z;
                return result;  
            case 6:
                r = (rand() % (6*x)) + x;
                result = r + z;
                return result;
            case 8:
                r = (rand() % (8*x)) + x;
                result = r + z;
                return result;
            case 10:
                r = (rand() % (10*x)) + x;
                result = r + z;
                return result;  
            case 12:
                r = (rand() % (12*x)) + x;
                result = r + z;
                return result;    
            case 20:
                r = (rand() % (20*x))+ x;
                result = r + z;
                return result;   
            case 100:
                r = (rand() % (100*x)) + x;
                result = r + z;
                return result; 
            default: 
                return(0);      
        }

    }catch(exception &err){
        fprintf(stderr , "Error: The entered expression is invalid.");
        exit(1);
    }
}

int Dice::rollGivenDice(string diceExpression){
    
    string first, second, third; //separate x, y and z values
    int x, y, z; //convert x, y and z values to ints

    //Checks if values entered are floats or negative. If yes, prints an error and terminates program.
    if(diceExpression.find(".") != std::string::npos || diceExpression.find("-") != std::string::npos){
        fprintf(stderr , "Error: The entered expression is invalid.");
        exit(1);
    }

    //Split string into 3 values x, y & z
    first = diceExpression.substr(0,diceExpression.find("d"));
    second = diceExpression.substr(diceExpression.find("d") + 1,diceExpression.find("[")-2);
    third = diceExpression.substr(diceExpression.find("+") + 1,diceExpression.length()-1);
    third.pop_back();

    try{
        //Convert parsed string values into ints
        x = stoi(first);
        y = stoi(second);
        if(y != 4 && y != 6 && y != 8 && y!= 10 && y != 12 && y != 20 && y != 100){
            fprintf(stderr , "Error: Invalid dice type.");
            exit(1);
        }
        z = stoi(third);

        int r; //holds random value rolled for die dy
        int result; //holds result of dice roll, including bonus
        srand(time(NULL)); //seed to randomize rand()

        //Roll the correct dice and return the result
        switch(y){    
            case 4:
                r = (rand() % (4*x)) + x;
                result = r + z;
                return result;  
            case 6:
                r = (rand() % (6*x)) + x;
                result = r + z;
                return result;
            case 8:
                r = (rand() % (8*x)) + x;
                result = r + z;
                return result;
            case 10:
                r = (rand() % (10*x)) + x;
                result = r + z;
                return result;  
            case 12:
                r = (rand() % (12*x)) + x;
                result = r + z;
                return result;    
            case 20:
                r = (rand() % (20*x))+ x;
                result = r + z;
                return result;   
            case 100:
                r = (rand() % (100*x)) + x;
                result = r + z;
                return result; 
            default: 
                return(0);      
        }

    }catch(exception &err){
        fprintf(stderr , "Error: The entered expression is invalid.");
        exit(1);
    }
}