//
//  CreatureType.cpp
//  CreatureTrainer
//
//  Created by Jeremy Gibson on 11/4/14.
//  Copyright (c) 2014 Jeremy Richard Gibson. All rights reserved.
//

#include <vector>
#include "CreatureType.h"
#include "EECSRandom.h"
using namespace std;


const string CreatureType::CREATURE_NAMES[] = { "Axolotyl", "Bittern", "C-lacanth",
"Dugong", "Echidna", "Fossa", "Guanaco", "Honeybdgr", "Ibex", "Jackal",
"Kiwi", "Loris", "Megapode", "Narwhal", "Ovenbird", "Pika", "Quagga",
"RockHyrax", "Solenodon", "Tuatara", "Uromastyx", "Vaquita", "Wolverine",
"Xenops", "Yaminon", "Zebu" };

const string CreatureType::ELEMENT_NAMES[] = { "Air", "Bombast", "Cool", "Dark",
"Earth", "Funk", "Gamma", "Hammer" };

std::vector<CreatureType> CreatureType::TYPES;

CreatureType::CreatureType() {
    // Do nothing
}

CreatureType::CreatureType(int cType) {
    // Generate random values for this type
    randomizeType();
}

void CreatureType::randomizeTypes() {
    vector<int>::size_type num_types = NUM_TYPES;
    CreatureType::TYPES.resize(num_types);
    for (int i = 0; i<NUM_TYPES; i++) {
        CreatureType ct;
        ct.setType(i);
        ct.randomizeType();
        TYPES[i] = ct;
    }
}

void CreatureType::randomizeType() {
    // Randomize the different CreatureType stats
    int num = EECSRandom::range(healthMaxBaseMin, healthMaxBaseMax + 1);
    healthMaxBase = num;
    num = EECSRandom::range(healthMaxPerLevelMin, healthMaxPerLevelMax + 1);
    healthMaxPerLevel = num;
    num = EECSRandom::range(healthRestIncreaseMin, healthRestIncreaseMax + 1);
    healthRestIncrease = num;
    num = EECSRandom::range(attackBaseMin, attackBaseMax + 1);
    if (num % 2 == 1) num--;
    attackBase = num;
    num = EECSRandom::range(attackPerLevelMin, attackPerLevelMax + 1);
    attackPerLevel = num;

    elementalAttackType = EECSRandom::range(0, NUM_ELEMENTS);
    elementalWeakness = EECSRandom::range(0, NUM_ELEMENTS);
    elementalStrength = EECSRandom::range(0, NUM_ELEMENTS);
    //Reroll if elementalWeakness == elementalStrength
    while (elementalWeakness == elementalStrength){
        elementalStrength = EECSRandom::range(0, NUM_ELEMENTS);
    }
}

string CreatureType::typeName(int tN, int pad) {
    // Note: in CreatureType.h pad is set to TYPE_NAME_LENGTH by default.
    string name = CREATURE_NAMES[tN];
    while (name.length() < pad) {
        name += " ";
    }
    return(name);
}

string CreatureType::elementName(int eN, int pad) {
    // Note: in CreatureType.h pad is set to ELEM_NAME_LENGTH by default.
    string name = ELEMENT_NAMES[eN];
    while (name.length() < pad) {
        name += " ";
    }
    return(name);
}

int CreatureType::getType() {
    return type;
}

void CreatureType::setType(int num) {
    type = num;
}

int CreatureType::getHealthMaxBase() {
    return healthMaxBase;
}

void CreatureType::setHealthMaxBase(int num) {
    healthMaxBase = num;
}


int CreatureType::getHealthRestIncrease() {
    return healthRestIncrease;
}

void CreatureType::setHealthRestIncrease(int num) {
    healthRestIncrease = num;
}


int CreatureType::getAttackBase() {
    return attackBase;
}

void CreatureType::setAttackBase(int num) {
    attackBase = num;
}

int CreatureType::getElementalAttackType() {
    return elementalAttackType;
}

void CreatureType::setElementalAttackType(int num) {
    elementalAttackType = num;
}

int CreatureType::getElementalWeakness() {
    return elementalWeakness;
}

void CreatureType::setElementalWeakness(int num) {
    elementalWeakness = num;
}

int CreatureType::getElementalStrength() {
    return elementalStrength;
}

void CreatureType::setElementalStrength(int num) {
    elementalStrength = num;
}


int CreatureType::getHealthMaxPerLevel() {
    return healthMaxPerLevel;
}


void CreatureType::setHealthMaxPerLevel(int num) {
    healthMaxPerLevel = num;
}


int CreatureType::getAttackPerLevel() {
    return attackPerLevel;
}

void CreatureType::setAttackPerLevel(int num) {
    attackPerLevel = num;
}
