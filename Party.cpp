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
#include <unordered_set>

Party::Party() {
    // Makes a random Party of Creatures
    std::unordered_set<int> typesAlreadyUsed;
    for (int i=0; i<MAX_PARTY_SIZE; i++) {
        int nextType = EECSRandom::range(0, CreatureType::NUM_TYPES);
        //while we already have a pokemon of that type get a new type
        while (typesAlreadyUsed.count(nextType)){
            nextType = EECSRandom::range(0, CreatureType::NUM_TYPES);
        }
        creatures[i] = Creature::factory(nextType);
        typesAlreadyUsed.insert(nextType);
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


