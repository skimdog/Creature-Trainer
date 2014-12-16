//
//  Party.h
//  CreatureTrainer
//
//  Created by Jeremy Gibson on 11/14/14.
//  Copyright (c) 2014 Jeremy Richard Gibson. All rights reserved.
//

#ifndef __CreatureTrainer__Party__
#define __CreatureTrainer__Party__

#include <stdio.h>
#include "Creature.h"

class Party {
public:

    static const int MAX_PARTY_SIZE = 4;

    Creature creatures[MAX_PARTY_SIZE];
    
    int attackBoostTurns;
    int defenseBoostTurns;
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Makes a random party of unique creatures
     */
    Party();
     
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns the active Creature
     */
    Creature& getActiveCreature();
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns the index of the active Creature
     */
    int getActiveCreatureNum();
    
    /**
     * Requires: slotNum is in the range [0, MAX_PARTY_SIZE)
     * Modifies: creatures array.
     * Effects:  changes active creature to the one at slotNum and returns a
                 bool describing whether or not the switch was successful
     */
    bool setActiveCreatureNum(int slotNum);
    
    /**
     * Requires: Nothing.
     * Modifies: ss
     * Effects:   Prints out the current party in this format:
     
| *Uromastyx  17/17 | Zebu       19/19 | Echidna    13/13 | Ibex       19/19   |
     
     */
    void printStatus(stringstream& ss);
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  returns true if at least one party member has nonZero healthCurr
     */
    bool alive();
    
    /**
     * Requires: Nothing.
     * Modifies: creatures
     * Effects:  Calls rest() on all non-active members (upping their health)
     */
    void restInactive();
    
    /**
     * Requires: Nothing.
     * Modifies: Decreases attackBoostTurns and defenseBoostTurns by 1
     * Effects:  Nothing else.
     */
    void decreaseBoostTurns();

    /**
    * Requires: Nothing.
    * Modifies: Nothing.
    * Effects:  Returns the max level of entire party 
    */
    int getMaxLevelCaught();
    
private:
    int activeCreature;
    int maxLevelCaught;
};

#endif /* defined(__CreatureTrainer__Party__) */
