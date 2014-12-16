//
//  Party.cpp
//  CreatureTrainer
//
//  Created by Jeremy Gibson on 11/14/14.
//  Copyright (c) 2014 Jeremy Richard Gibson. All rights reserved.
//

#include "Party.h"
#include "Creature.h"
#include "EECSRandom.h"
#include "PrintHelper.h"

Party::Party() {
    attackBoostTurns = 0;
    defenseBoostTurns = 0;
    activeCreature = 0;
    maxLevelCaught = 0;
    
    // Makes a random Party of Creatures
    for (int i=0; i<MAX_PARTY_SIZE; i++) {
        // TODO: Make sure the Trainer doesn't get two of the same CreatureType
        Creature temp = Creature::factory(EECSRandom::range(0, CreatureType::NUM_TYPES));
        for (int j = 0; j < i; ++j){
            while (creatures[j] == temp){
                temp = Creature::factory(EECSRandom::range(0, CreatureType::NUM_TYPES));
            }
        }
        creatures[i] = temp;
    }
    
}


Creature& Party::getActiveCreature() {
    return( creatures[activeCreature] );
}


int Party::getActiveCreatureNum() {
    return( activeCreature );
}


bool Party::setActiveCreatureNum(int slotNum) {
    // Make sure it's a valid num
    if (slotNum < 0 || slotNum >= MAX_PARTY_SIZE) {
        return false;
    }
    // Make sure the Creature is at health>0
    if ( creatures[slotNum].getHealthCurr() <= 0 ) {
        return false;
    }
    activeCreature = slotNum;
    return true;
}


void Party::printStatus(stringstream& ss) {
    PrintHelper::printTeamStatus(creatures, activeCreature, ss);
}


bool Party::alive() {
    for (int i=0; i<MAX_PARTY_SIZE; i++) {
        if (creatures[i].getHealthCurr() > 0) {
            return true;
        }
    }
    return false;
}


void Party::restInactive() {
    for (int i=0; i<MAX_PARTY_SIZE; i++) {
        if (i != activeCreature) {
            creatures[i].rest();
        }
    }
}

int Party::getMaxLevelCaught(){
    for (int i=0; i<MAX_PARTY_SIZE; i++) {
        if (creatures[i].getLevel() > maxLevelCaught) {
            maxLevelCaught = creatures[i].getLevel();
        }
    }
    return maxLevelCaught;
}

void Party::decreaseBoostTurns() {
    if (attackBoostTurns > 0) {
        attackBoostTurns--;
    }
    if (defenseBoostTurns > 0) {
        defenseBoostTurns--;
    }
}



