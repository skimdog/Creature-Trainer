//
//  Creature.cpp
//  CreatureTrainer
//
//  Created by Jeremy Gibson on 11/4/14.
//  Copyright (c) 2014 Jeremy Richard Gibson. All rights reserved.
//

#include "Creature.h"
#include <sstream>

Creature::Creature() {
    // Do nothing
}

Creature Creature::factory(int cType, int level_in) {
    Creature c;
    c.setType( cType );
    c.setLevel(level_in);
    c.xp = level_in*WINS_TO_LEVEL;
    return c;
}

string Creature::getTypeName(int pad) {
    // Note: In Creature.h, pad is set to a default value of -1
    // CT::typeName() also has a default value for pad
    stringstream ns;
    ns << CreatureType::typeName(type, 0);
    ns << "-" << level;
    
    if (pad == -1) {
        pad = CreatureType::TYPE_NAME_LENGTH;
    }
    while (ns.str().length() < pad) {
        ns << " ";
    }
    return ns.str();
}

CreatureType& Creature::getCreatureType() {
    return CreatureType::TYPES[type];
}

int Creature::getType() {
    return type;
}

void Creature::setType(int cType) {
    type = cType;
    level = 0;
    healthMax = CreatureType::TYPES[cType].getHealthMaxBase();
    healthCurr = healthMax;
    xp = 0;
}

int Creature::getHealthCurr() {
    return healthCurr;
}

void Creature::setHealthCurr(int num) {
    if (num > healthMax) {
        num = healthMax;
    }
    healthCurr = num;
}

int Creature::getHealthMax() {
    return healthMax;
}

void Creature::setHealthMax(int num) {
    healthMax = num;
}

void Creature::rest() {
    if (healthCurr == 0) return;
    healthCurr += getCreatureType().getHealthRestIncrease();
    if (healthCurr > healthMax) {
        healthCurr = healthMax;
    }
}

int Creature::getAttackStrength() {
    int attack = getCreatureType().getAttackBase();
    attack += getLevel() * getCreatureType().getAttackPerLevel();
    return attack;
}

int Creature::getAttackElement() {
    return getCreatureType().getElementalAttackType();
}

int Creature::getElementalWeakness() {
    return getCreatureType().getElementalWeakness();
}

int Creature::getElementalStrength() {
    return getCreatureType().getElementalStrength();
}

int Creature::damage(int amount, int element) {
    if (element == getElementalWeakness()) {
        amount *= 2;
    } else if (element == getElementalStrength()) {
        amount /= 2;
    }
    if (amount > healthCurr) amount = healthCurr;
    healthCurr -= amount;
    return amount;
}

int Creature::getLevel() {
    return level;
}

void Creature::setLevel(int num) {
    level = num;
    healthMax = getCreatureType().getHealthMaxPerLevel() * level
    + getCreatureType().getHealthMaxBase();
    healthCurr = healthMax;
}

int Creature::getXp() {
    return xp;
}

//POSSIBLY DELETE
void Creature::setXp(int num) {
    xp = num;
}


bool Creature::operator==(const Creature& other){
    return ( (this->type == other.type) && (this->healthCurr == other.healthCurr) &&
            (this->healthMax == other.healthMax) && (this->level == other.level) &&
            (this->xp == other.xp) );
}

bool Creature::updateXP(){
    ++xp;
    if (xp % WINS_TO_LEVEL == 0) {
        // The creature has gained a new level!!!
        return updateLevel();
    }
    return false;
}

bool Creature::updateLevel(){
    //level maxes out at 9
    if(level < 9){
        ++level;
        //POSSIBLY UPDATE CURRENT HEALTH
        healthMax += getCreatureType().getHealthMaxPerLevel();
        healthCurr = healthMax;
        //attack stats update handled in getAttackStrength()
        return true;
    }
    return false;
}
