//
//  Trainer.cpp
//  CreatureTrainer
//
//  You may NOT #include any .h files we provide you (Battle, Creature, CreatureType,
//  EECSRandom, Party, PrintHelper)
//  other than the ones name "ClassX.h" and "Trainer.h"
//  You may #include other <> libraries if you wish to
//
//  Created by Jeremy Gibson on 11/4/14.
//  Copyright (c) 2014 Jeremy Richard Gibson. All rights reserved.
//

#include <iostream>
#include <sstream>
#include "Trainer.h"
#include "Class1.h"
#include "Class2.h"
#include "Class3.h"
#include "Class4.h"
#include "Class5.h"

//#include "CreatureType.h"

using namespace std;

string Trainer::makeMove(stringstream& situation) {
    
    // pull the entire string out of stringStream& situation
    string situationString = situation.str();
    // situationString now includes ALL of the lines that will be sent to cout
    
    // Here's how to use the stringSplit function
    vector<string> lines = splitString(situationString, "\n");
    // This splits situationString into a vector of individual lines.
    // (it splits on the new line character "\n")
    // To access the 3rd line (as in 0, 1, 2, 3), you would use bracket access
    //   as in: lines[3]
    
    // This loop will iterate through all the lines
    int pipeLine = -1;
    // lines.size() tells us how many elements are in the vector<string> lines
    // In this case, it tells us how many lines we pulled in
    for (int i = 0; i < lines.size(); i++) {
        // Store each line in the string line
        string line = lines[i];
        // Store the first char of line in the char c
        char c = line[0];
        // If c is a pipe ('|'), then this is the line that tells us about our
        //    party and the health of each Creature we own.
        if (c == '|') {
            // Store which line number this is
            pipeLine = i;
        }
    }
    
    //PARSE OUT IS START OF BATTLE
    
    string newBattleLine;
    for (int i = 0; i < lines.size(); i++)
    {
        newBattleLine = lines[i];
        
        // Store the first char of line in the char c
        char c1 = newBattleLine[0];
        char c2 = newBattleLine[1];
        char c3 = newBattleLine[2];
        
        //'E' for Enemy
        if (c1 == 'I' && c2 == 't' && c3 == '\'')
        {
            isStartofBattle = true;
        }
        
    }
    
    
    
 
    string enemyAttackLine;
    stringstream enemySS;

    const int NUM_OF_SKIPS = 8; //number of words to skip before attack damage is read
    
    for (int i = 0; i < lines.size(); i++)
    {
        enemyAttackLine = lines[i];
        
        // Store the first char of line in the char c
        char c = enemyAttackLine[0];
        
        //'E' for Enemy
        if (c == 'E')
        {
            break;
        }
    }
    enemySS << enemyAttackLine;
    string skip;
    for(int j = 0; j < NUM_OF_SKIPS; j++)
    {
        enemySS >> skip;
        if(skip == "faints!" || skip == "rests")
        {
            break;
        }
    }
    
    int enemyATK;
    if(skip == "faints!" || skip == "rests")
    {
        enemyATK = 0;
    }
    else
    {
        enemySS >> enemyATK;
        cout << "Attack damage: " << enemyATK << "\n";
    }
    
    
    
    
    // Now that we know which line has the health, do something with it
    //cout << lines[pipeLine] << "\n"; // Output for testing only
    
    // Split the party health line by pipes "|"
    vector<string> creatureHealthBits = splitString(lines[pipeLine], "|");
    // This gives us something like the vector description below
    /* { "",
     " *Jackal     10/10",
     " Yaminon    17/17",
     " Megapode   13/13",
     " Jackal     10/10",
     "" } */
    // You can see that the first and last pipe caused empty strings
    
    // Now, go through this information and pull out info for each entry
    // We do 1 to <creatureHealthBits.size()-1 because we only need the middle
    //    four elements (and are skipping the empty ones.
    
    
    //new array without first and last empty lines
    //first element (0) is empty; the rest (1,2,3,4) are four slots for four party creatures
    //to make it easier to comprehend
    const int PARTY_SIZE = 5;
    string creatureParty[PARTY_SIZE];
    
    for(int j = 1; j < PARTY_SIZE; j++)
    {
        creatureParty[j] = creatureHealthBits[j];
    }
    
    //storing names and current healths separately
    string partyNames[PARTY_SIZE];
    int partyHealths[PARTY_SIZE];
    
    //storing info about active creature
    bool isActive; //true when name starts with '*'
    string activeName = "";
    int activeHealth = 0;
    //int activeMaxHealth = 0;
    int activeSlot = 0; // [1, 2, 3, 4]
    
    for (int i = 1; i < PARTY_SIZE; i++) {
        
        isActive = false;
        // cout just for testing
        //cout << creatureHealthBits[i] << "\n";
        
        // We are putting the string into a stringStream so we can use >>
        stringstream ss;
        ss << creatureParty[i];
        
        // For example, we have a stringstream ss containing " *Jackal   10/10 "
        // pull the name as a string
        string name;
        ss >> name; // name = "*Jackal"
        
        //if this creature is active
        if(name[0] == '*')
        {
            isActive = true;
            stringstream nameSS; //just to remove asterisk from name
            nameSS << name;
            
            char asterisk;
            nameSS >> asterisk;
            
            nameSS >> activeName;
            partyNames[i] = activeName;
        }
        partyNames[i] = name;
        
        // pull the health
        int health;
        ss >> health; // health = 10
        partyHealths[i] = health;
        
        // Get rid of the slash char
        //char slash;
        //ss >> slash; // slash = '/'
        
        // get max health
        //int maxHealth;
        //ss >> maxHealth; // maxHealth = 10
        
        //if this creature is active
        if(isActive)
        {
            activeHealth = health;
            //activeMaxHealth = maxHealth;
            activeSlot = i;
        }
    }
    
    //cout for testing
    //for (int i = 1; i < PARTY_SIZE; i++)
    //{
    //    cout << "Name: " << partyNames[i] << " health: " << partyHealths[i] << "\n";
    //}
    
    //cout for testing
    //cout << "Active: #" << activeNum << " " << activeName << " " << activeHealth << "/" << activeMaxHealth << "\n";
    
    // This is something else you can do ONLY for testing.
    // In a previous post, I recommended #including CreatureType.h so that you
    //    can make a Trainer::decide() function that will make the right
    //    decision if you have perfect data about creature types.
    // While developing, you can use the static vector<CreatureType> TYPES to
    //    get that perfect information, though you will eventually need to write
    //    your own function to learn that information from the data that is sent
    //    in via stringstream& situation.
    
    /*
     // This makes ct a copy of the CreatureType for Creature 0 (the Axolotyl).
     // All CreatureType and Element names start with a different letter of the
     //    alphabet (CreatureType is A-Z, Element is A-H).
     CreatureType ct = CreatureType::TYPES[0];
     // You can then get the type of ct, which is 0 because it's the Axolotyl
     int type = ct.getType();
     // You can also directly get info from CreatureTypes::TYPES elements.
     int elementalWeakness3 = CreatureType::TYPES[3].getElementalWeakness();
     */
    
    // Output for human player
    // Instead of doing this, you will need to replace the code of Trainer
    // to parse the input situation and create a proper response,
    // (like "a" for attack or "s3" to swap to the creature in slot 3).
    cout << situationString;
    
    
    /*
     * This line is basically what your AI chooses to do
     * When first playing, you may type in your move.
     * For both the core and reach portions, however, you need to
     * comment out "cin >> response" and instead have this function
     * generate a response string.
     */
    
    Class1 class1;
    
    
    string response;
    //cin >> response;
    if (isStartofBattle){
        response = class1.swapToHighestHealth(partyHealths, activeHealth);
    }
    if (!class1.isGonnaDie(activeHealth, enemyATK)){
        response = 'a';
    }
        else {response = class1.swapToHighestHealth(partyHealths, activeHealth);}
    
    isStartofBattle = false;
    return response;
}


void Trainer::finalSituation(stringstream& situation) {
    cout << situation.str();
    
}



vector<string> Trainer::splitString(string inString, string splitOn) {
    vector<string> elements;
    string substring;
    
    size_t splitIndex = inString.find(splitOn),
    substrStart = 0;
    
    // keep searching until no spaces remain
    while (splitIndex != string::npos) {
        substring = inString.substr(substrStart, splitIndex - substrStart);
        elements.push_back(substring);
        substrStart = splitIndex + 1;
        // start at next character after finding substring
        splitIndex = inString.find(splitOn, substrStart);
    }
    // add last element to vector
    substring = inString.substr(substrStart, inString.length() - substrStart);
    elements.push_back(substring);
    
    return elements;
}