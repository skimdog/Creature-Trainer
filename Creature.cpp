//
//  Creature.cpp
//  CreatureTrainer
//
//  Created by Jeremy Gibson on 11/4/14.
//  Copyright (c) 2014 Jeremy Richard Gibson. All rights reserved.
//

#include "Creature.h"

Creature::Creature() {
    // Do nothing
}

Creature Creature::factory(int cType) {
    Creature c;
    c.setType( cType );
    return c;
}

string Creature::getTypeName(int pad) {
    // Note: In Creature.h, pad is set to a default value of -1
    // CT::typeName() also has a default value for pad
    if (pad == -1) {
        return( CreatureType::typeName(type) );
    } else {
        // Override the default of CT::typeName
        return( CreatureType::typeName(type, pad) );
    }
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
    healthCurr = num;
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
}
int Creature::getXp() {
    return xp;
}

void Creature::setXp(int num) {
    xp = num;
}
