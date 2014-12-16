//
//  Item.cpp
//  CreatureTrainer
//
//  Created by Jeremy Gibson on 11/28/14.
//  Copyright (c) 2014 Jeremy Richard Gibson. All rights reserved.
//

#include "Item.h"
#include "CreatureType.h"
#include "EECSRandom.h"
#include "Party.h"
#include <iostream>
#include <sstream>
using namespace std;


const string Item::ITEM_NAMES[] = { "Potion", "DefBst", "AtkBst", "Revive",
    "Collar", "Air Scroll", "Bombast Scroll", "Cool Scroll", "Dark Scroll",
    "Earth Scroll", "Funk Scroll", "Gamma Scroll", "Hammer Scroll" };

const string Item::ITEM_CODES[] = { "po", "db", "ab", "re", "co", "sa", "sb",
    "sc", "sd", "se", "sf", "sg", "sh" };

const int Item::ITEM_CHANCE[] = { 10, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 5 };

Item::Item(){
    for (int i= 0; i < NUM_ITEMS; ++i) {
        itemCounts[i] = STARTING_ITEM_COUNT;
    }
    if (CreatureType::REACH_VERSION){
        // Special case for Collars
        itemCounts[4] = STARTING_COLLAR_COUNT;
    }
}


// Rarities are set by NOTHING_CHANCE and ITEM_CHANCE[]
string Item::randomItem(){
    int totalChances = 0;
    for (int i=0; i<NUM_ITEMS; i++) {
        totalChances += ITEM_CHANCE[i];
    }
    totalChances += NOTHING_CHANCE;
    
    int num = EECSRandom::range(0, totalChances);
    
    for (int i=0; i<NUM_ITEMS; i++) {
        if (num < ITEM_CHANCE[i]) {
            return ITEM_NAMES[i];
        }
        num -= ITEM_CHANCE[i];
    }
    
    return "nothing";
}

int Item::getItemCount(int index) const {
    if (index < 0 || index > NUM_ITEMS) {
        return 0;
    }
    return itemCounts[index];
}

int Item::getIndexForCode(string code) {
    for (int i = 0; i < NUM_ITEMS; ++i) {
        if (ITEM_CODES[i] == code) {
            return i;
        }
    }
    return 0;
}

int* Item::getItemArray(){
    return itemCounts;
}


//in battle, have int attackBoost = 4, decrement it each time a turn passes
string Item::useItem(string itemCommand, Party& party, Creature& enemy,
                     stringstream & ss, int& illegal) {
    
    int badMove = 0;
    
    // Parse info from the itemCommand
    int itemNum = -1;
    string iName;
    string iCode;
    int cNum;
    
    // Find the itemNum from the itemCommand
    for (int i=0; i<Item::NUM_ITEMS; i++) {
        if (itemCommand[0] == Item::ITEM_CODES[i][0]) {
            if (itemCommand[1] == Item::ITEM_CODES[i][1]) {
                itemNum = i;
                iName = Item::ITEM_NAMES[i];
                iCode = Item::ITEM_CODES[i];
            }
        }
    }
    
    bool useItem = true;
    
    if (itemNum != -1 && itemCounts[itemNum] == 0) {
        ss << "Illegal Move: You tried to use " << Item::ITEM_NAMES[itemNum]
        << ", but you don't have any.\n";
        badMove = -1;
        useItem = false;
    } else {
        // This is a valid item code, and you actually have one to use!
        switch (itemNum) {
            case -1: { // A non-legal Item Command was entered.
                useItem = false;
                badMove = 1;
                break;
            }
                
            case 0: { // Potion(po)
                // Raise the health of the current Creature by POTION_HEALTH
                int h = party.getActiveCreature().getHealthCurr();
                if (h == 0) {
                    ss << "Illegal Move: You cannot use a Potion on a fainted creature.\n";
                    badMove = -1;
                    useItem = false;
                    break;
                }
                h += Item::POTION_HEALTH;
                party.getActiveCreature().setHealthCurr(h);
                ss << "You used a Potion to raise your active "
                << party.getActiveCreature().getTypeName()
                << "'s health" << " by " << Item::POTION_HEALTH << ".\n";
                break;
            }
                
            case 1: { // DefBst(db)
                party.defenseBoostTurns = Item::BOOST_TURNS+1;
                ss << "You used " << Item::ITEM_NAMES[1] << ", which lasts for "
                << "this turn and " << (Item::BOOST_TURNS-1) << " more.\n";
                break;
            }
                
            case 2: { // AtkBst(ab)
                party.attackBoostTurns = Item::BOOST_TURNS+1;
                ss << "You used " << Item::ITEM_NAMES[2] << ", which lasts for "
                << Item::BOOST_TURNS << " turns.\n";
                break;
            }
                
            case 3: { // Revive(re#)
                if (itemCommand.length() < 3) {
                    badMove = 1;
                    useItem = false;
                    break;
                }
                // Revive a Creature
                cNum = itemCommand[2] - '1';
                if (cNum < 0 || cNum > 3) {
                    badMove = 1;
                    useItem = false;
                    break;
                }
                Creature& cr = party.creatures[cNum];
                if (cr.getHealthCurr() > 0) {
                    badMove = -1;
                    ss << "Illegal Move: You tried to Revive " << cr.getTypeName()
                    << " in slot " << (cNum+1) << ", but it is not fainted.\n";
                    useItem = false;
                    break;
                }
                cr.setHealthCurr(Item::REVIVE_HEALTH);
                ss << "You revived " << cr.getTypeName()
                << " in slot " << (cNum+1) << "!\n";
                break;
            }
                
            case 4: { // Collar(co)
                // This will only work if the enemy Creature has fainted, which
                //   means you can only do it on the turn between enemies.
                if (enemy.getHealthCurr() > 0) {
                    badMove = -1;
                    ss << "Illegal Move: You tried to Collar " << enemy.getTypeName()
                    << ", but it is not fainted.\n";
                    useItem = false;
                    break;
                }
                if (itemCommand.length() < 3) {
                    badMove = -1;
                    ss << "Illegal Move: You tried to Collar " << enemy.getTypeName()
                    << ", but did not specify a party member to replace.\n";
                    useItem = false;
                    break;
                }
                cNum = itemCommand[2] - '1';
                if (cNum > 3 || cNum < 0) {
                    badMove = -1;
                    ss << "Illegal Move: You tried to Collar " << enemy.getTypeName()
                    << ", but did not specify a valid member to replace.\n";
                    useItem = false;
                    break;
                }
                // This is a valid swap, so make it so #1!
                string oldName = party.creatures[cNum].getTypeName();
                string newName = enemy.getTypeName();
                enemy.setHealthCurr(Item::COLLAR_HEALTH);
                party.creatures[cNum] = enemy;
                
                ss << "You used Collar to swap enemy " << newName
                << " for your " << oldName << " in slot " << (cNum+1) << ".\n";
                ss << "Your new " << newName << " has " << Item::COLLAR_HEALTH
                << " health.\n";
                break;
            }
                
            case 5: // Use a scroll!
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
            case 11:
            case 12: {
                int element = itemNum - 5;
                if (!Item::scrollDmg(element, Item::SCROLL_DAMAGE, enemy, ss)) {
                    badMove = 1;
                }
                break;
            }
        }
        
        if (useItem && itemNum > -1 && itemNum < Item::NUM_ITEMS) {
            // If there was nothing wrong with the move, use the item.
            itemCounts[itemNum]--;
        }
        
        if (badMove == 1) {
            illegal++;
            ss << "ERROR: INVALID MOVE" << endl;
            ss << "You lost your turn." << endl;
        } else if (badMove == -1) {
            illegal++;
        }
    }
    
    return "temp";
}


//This is basically Battle::creatureAttack
bool Item::scrollDmg(int scrollElt, int dmg, Creature& defender, stringstream& ss) {
    string dName;
    
    dName = "Enemy " + defender.getTypeName(0);
    
    int damageDone = defender.damage(dmg, scrollElt);
    ss << "You use " << CreatureType::elementName(scrollElt, 0)
    << " Scroll, which does " << damageDone << " damage "
    << "to " << dName << ".\n";
    
    if (defender.getHealthCurr() == 0) {
        ss << dName << " faints!\n";
    }
    
    return true;
}

void Item::addItem(string item){
    for (int i = 0; i < NUM_ITEMS; ++i){
        if ((ITEM_NAMES[i] == item) && (itemCounts[i] < 99)){
            ++itemCounts[i];
        }
    }
}