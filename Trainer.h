//
//  Trainer.h
//  CreatureTrainer
//
//  Created by Jeremy Gibson on 11/4/14.
//  Copyright (c) 2014 Jeremy Richard Gibson. All rights reserved.
//

#ifndef __CreatureTrainer__Trainer__
#define __CreatureTrainer__Trainer__

#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Trainer {
public:
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  returns 'a' or 's#' given the situation.
     This is where the bulk of your code will go. The implementation
     of your AI goes here.
     */
    string makeMove(stringstream& situation);
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Prints out the final situation
     */
    void finalSituation(stringstream& situation);
    
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Splits a string into a vector of strings
     */
    vector<string> splitString(string inString, string splitOn=" ");
    
private:
    // vvvvvv Your changes to Trainer.h go between this line…
    
    const static int PARTY_SIZE = 5;
    const static int ITEM_LIST_SIZE = 5;
    const static int SCROLL_LIST_SIZE = 8;
    
    string creatureParty[PARTY_SIZE];
    string partyNames[PARTY_SIZE];
    int partyLevels[PARTY_SIZE];
    string partyAtkElements[PARTY_SIZE];
    string partyWeakElements[PARTY_SIZE];
    string partyStrElements[PARTY_SIZE];
    int partyAttacks[PARTY_SIZE];
    int partyHealths[PARTY_SIZE];
    int partyMaxHealths[PARTY_SIZE];
    int partyDamages[PARTY_SIZE];
    int partyRests[PARTY_SIZE];
    
    bool partyWinOrLose[PARTY_SIZE];
    bool partyLastHopes[PARTY_SIZE];
    int lastHope;
    
    int enemyCurrentHealth;
    
    bool isStartofBattle; //true if new battle has started
    bool isEndofBattle;
    
    bool atkBst_InPlay;
    bool defBst_InPlay;
    
    bool canFinishOff;
    bool canScrollOff;
    
    int itemList[ITEM_LIST_SIZE];
    int scrollList[SCROLL_LIST_SIZE];
    
    // ^^^^^^ And this line. That's it!
    
};

#endif /* defined(__CreatureTrainer__Trainer__) */
