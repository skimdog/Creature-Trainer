#include <iostream>
#include <string>
#include <sstream>
#include "Creature.h"
#include "Trainer.h"
#include "EECSRandom.h"
#include "Battle.h"
#include "PrintHelper.h"
#include "Party.h"
#include "Item.h"

using namespace std;

//to run a battle
//we need a trainer,
//their party,
//the situation stream,
//and their win count
//the battle is a series of informative outputs of situations
void runBattle(Trainer &player1, Party &party, Item &items, stringstream& ss,
               int winCount, int& moveCount, int& illegalMoveCount){
    
    
    // generate enemy
    int tNum = EECSRandom::range(0,CreatureType::NUM_TYPES);
    
    Creature enemy;
    int maxLevel = winCount / 20;
    if(maxLevel >= 9) {
        maxLevel = 9;
    }
    if (!CreatureType::REACH_VERSION){
        maxLevel = 0;
    }
    enemy = Creature::factory( tNum, EECSRandom::range(0, maxLevel + 1) );
    
    //This simply introduces the enemy. The trainer can make the first move.
    PrintHelper::printHR(ss);
    PrintHelper::printWinCount(winCount, ss);
    ss << "\nA new challenger approaches...\n";
    ss << "It's an enemy " << enemy.getTypeName(0) << "!\n\n";
    
    string playerMove;
    while ( party.alive() && enemy.getHealthCurr() > 0 ) {
        // Set up the current move
        PrintHelper::printHR(ss);
        party.printStatus(ss);
        PrintHelper::printItems(items, ss);
        PrintHelper::printHR(ss);
        
        if (party.getActiveCreature().getHealthCurr() == 0) {
            ss << "You must swap to another creature!\n";
        }
        
        
        if (party.attackBoostTurns > 0) {
            ss << "AtkBst turns remaining: " << party.attackBoostTurns << "\n";
        }
        
        if (party.defenseBoostTurns > 1) {
            ss << "DefBst turns remaining: " << (party.defenseBoostTurns-1) << "\n";
        }
        
        PrintHelper::printBattleOptions(ss);
        
        // Ask the player for her next move…
        playerMove = player1.makeMove(ss);
        moveCount++;
        
        parseMove(playerMove, party, items, enemy, ss, illegalMoveCount);
        
        // Everyone in the party who is not the active creature rest()s
        party.restInactive();
        
        // Enemy move
        // For now, this is always to attack
        if (enemy.getHealthCurr() > 0) {
            if (party.getActiveCreature().getHealthCurr() > 0) {
                creatureAttack(enemy, party.getActiveCreature(), false, party, ss);
            } else {
                creatureRest(enemy, false, ss);
            }
        }
    }
    
    if (party.alive()) {
        // Enemy just fainted
        //If you defeat an enemy, you regenerate some health and pick up an item
        ss << "\nYou have defeated the Enemy ";
        ss << enemy.getTypeName(0) << "! Congratulations!\n";
        
        string newItem = Item::randomItem();
        if (!CreatureType::REACH_VERSION){
            newItem = "nothing";
        }
        if ( newItem.compare("nothing") == 0 ) {
            // You got "nothing"
            ss << "You did not find any items.\n";
        } else {
            ss << "You receive: " + newItem + ".\n";
            items.addItem(newItem);
        }
        
        if (CreatureType::REACH_VERSION){
            // Leveling
            bool levelUp = party.getActiveCreature().updateXP();
            if (levelUp){
                ss << party.getActiveCreature().getTypeName() << " grows to level "
                << party.getActiveCreature().getLevel() << "!!!\n\n";
            }
        }
        
        PrintHelper::printHR(ss);
        party.printStatus(ss);
        PrintHelper::printItems(items, ss);
        PrintHelper::printHR(ss);
        
        if (party.attackBoostTurns > 0) {
            ss << "AtkBst turns remaining: " << party.attackBoostTurns << "\n";
        }
        
        if (party.defenseBoostTurns > 0) {
            ss << "DefBst turns remaining: " << party.defenseBoostTurns << "\n";
        }
        
        ss  << "Trainer, make your move.\n"
        << "(s#-Swap to slot #, r-Rest, item code, or Collar(co#)): ";
        
        // we get a player move as above, but attacking and scrolls are illegal
        playerMove = player1.makeMove(ss);
        moveCount++;
        
        parseMove(playerMove, party, items, enemy, ss, illegalMoveCount);
        
        // Everyone in the party who is not the active creature rest()s
        party.restInactive();
    } else {
        // Hero party is all dead
    }
    
}


void parseMove(string playerMove, Party &party, Item &items, Creature& enemy,
               stringstream& ss, int& illegalMoveCount){
    
    ss.str("");
    ss << "\n\n";
    PrintHelper::printHRL(ss);
    ss << "\n";
    
    // Act on it
    switch (playerMove[0]){
        case 'a': { // Attack
            if (playerMove.length()>1) { // This is an AtkBst(ab)
                // Tell the item function to manage this
                items.useItem(playerMove, party, enemy, ss, illegalMoveCount);
                break;
            }
            bool valid = creatureAttack(party.getActiveCreature(), enemy, true, party, ss);
            if (!valid) {
                illegalMoveCount++;
            }
            break;
        }
            
        case 's': { // Swap for another party member
            // You cannot swap to a fainted party member
            if (playerMove.length() < 2) {
                PrintHelper::printError(ss);
                illegalMoveCount++;
                break;
            }
            switch (playerMove[1]) {
                case 'a':  // Check for scroll usage
                case 'b':
                case 'c':
                case 'd':
                case 'e':
                case 'f':
                case 'g':
                case 'h': {
                    // Tell the item function to manage this
                    items.useItem(playerMove, party, enemy, ss, illegalMoveCount);
                    break;
                }
                default: {
                    // Use this as a swap
                    int oldIndex = party.getActiveCreatureNum();
                    int swapIndex = playerMove[1] - '1';
                    if (swapIndex >= Party::MAX_PARTY_SIZE || swapIndex < 0) {
                        PrintHelper::printError(ss);
                        illegalMoveCount++;
                    } else {
                        party.setActiveCreatureNum(swapIndex);
                        if (party.getActiveCreatureNum() == oldIndex) {
                            ss << party.creatures[swapIndex].getTypeName();
                            ss << " couldn't swap in! ";
                            ss << party.creatures[oldIndex].getTypeName();
                            ss << " is still fighting.\n";
                            illegalMoveCount++;
                        } else {
                            ss << party.creatures[oldIndex].getTypeName();
                            ss << " swaps out, and ";
                            ss << party.creatures[swapIndex].getTypeName();
                            ss << " swaps in!\n";
                        }
                    }
                    break;
                }
            }
            break;
        }
            
        case 'r': { // Rest or Revive
            if (playerMove.length() > 1) {
                // Tell the item function to manage this
                items.useItem(playerMove, party, enemy, ss, illegalMoveCount);
            } else {
                // Rest and regain a bit of health. Usually a bad move.
                creatureRest(party.getActiveCreature(), true, ss);
            }
            break;
        }
            
        default: {
            // Pass any unknown command to the item command parser
            items.useItem(playerMove, party, enemy, ss, illegalMoveCount);
            break;
        }
    }
    
    party.decreaseBoostTurns();
    
}

void parseMovePostBattle(string playerMove, Party &party, Item &items, Creature& enemy,
                         stringstream& ss, int& illegalMoveCount){
    
    ss.str("");
    ss << "\n\n";
    PrintHelper::printHRL(ss);
    ss << "\n";
    
    // Act on it
    switch (playerMove[0]){
        case 'a': { // Attack not allowed, but Attack boost is
            if (playerMove.length()>1) { // This is an AtkBst(ab)
                // Tell the item function to manage this
                items.useItem(playerMove, party, enemy, ss, illegalMoveCount);
                break;
            }
            // Attack
            PrintHelper::printError(ss);
            illegalMoveCount++;
            break;
        }
            
        case 's': { // Swap for another party member
            // You cannot swap to a fainted party member
            if (playerMove.length() < 2) {
                PrintHelper::printError(ss);
                illegalMoveCount++;
                break;
            }
            switch (playerMove[1]) {
                case 'a':  // Check for scroll usage - NOT allowed at this stage
                case 'b':
                case 'c':
                case 'd':
                case 'e':
                case 'f':
                case 'g':
                case 'h': {
                    // Tell the item function to manage this
                    PrintHelper::printError(ss);
                    illegalMoveCount++;
                    break;
                }
                default: {
                    // Use this as a swap
                    int oldIndex = party.getActiveCreatureNum();
                    int swapIndex = playerMove[1] - '1';
                    if (swapIndex >= Party::MAX_PARTY_SIZE || swapIndex < 0) {
                        PrintHelper::printError(ss);
                        illegalMoveCount++;
                    } else {
                        party.setActiveCreatureNum(swapIndex);
                        if (party.getActiveCreatureNum() == oldIndex) {
                            ss << party.creatures[swapIndex].getTypeName();
                            ss << " couldn't swap in! ";
                            ss << party.creatures[oldIndex].getTypeName();
                            ss << " is still fighting.\n";
                            illegalMoveCount++;
                        } else {
                            ss << party.creatures[oldIndex].getTypeName();
                            ss << " swaps out, and ";
                            ss << party.creatures[swapIndex].getTypeName();
                            ss << " swaps in!\n";
                        }
                    }
                    break;
                }
            }
            break;
        }
            
        case 'r': { // Rest or Revive
            if (playerMove.length() > 1) {
                // Tell the item function to manage this
                items.useItem(playerMove, party, enemy, ss, illegalMoveCount);
            } else {
                // Rest and regain a bit of health. Usually a bad move.
                creatureRest(party.getActiveCreature(), true, ss);
            }
            break;
        }
            
        default: {
            // Pass any unknown command to the item command parser
            items.useItem(playerMove, party, enemy, ss, illegalMoveCount);
            break;
        }
    }
}


bool creatureAttack(Creature& attacker, Creature& defender, bool isPlayer,
                    Party& party, stringstream& ss) {
    
    int aStrength = attacker.getAttackStrength();
    int aElement = attacker.getAttackElement();
    
    // Apply the boosts from items AtkBst and DefBst
    double aStrengthD = aStrength;
    if (isPlayer) {
        if (party.attackBoostTurns > 0) {
            aStrengthD *= Item::ATKBST_MULT::value();
        }
    } else {
        if (party.defenseBoostTurns > 0) {
            aStrengthD *= Item::DEFBST_MULT::value();
        }
    }
    aStrength = (int) (aStrengthD + 0.5);
    
    
    string aName, dName;
    if (isPlayer) {
        aName = "Your  " + attacker.getTypeName(11);
        dName = "Enemy " + defender.getTypeName(11);
    } else {
        aName = "Enemy " + attacker.getTypeName(11);
        dName = "Your  " + defender.getTypeName(11);
    }
    
    // Only allow Attack if the creature has not fainted
    if (attacker.getHealthCurr() == 0) {
        ss << aName << " can't attack because it has fainted!\n";
        return false;
    } else if (defender.getHealthCurr() == 0 && isPlayer) {
        ss << "Can't attack " << dName << " because it has already fainted!\n";
        return false;
    } else {
        int damageDone = defender.damage(aStrength, aElement);
        
        ss << aName << " attacks " << dName;
        ss << " with " << CreatureType::elementName(aElement);
        ss << " for " << damageDone << " damage.\n";
    }
    
    if (defender.getHealthCurr() == 0) {
        ss << dName << " faints!\n";
    }
    
    return true;
}


void creatureRest(Creature& rester, bool isPlayer, stringstream& ss) {
    string resterName;
    if (isPlayer) {
        resterName = "Your  " + rester.getTypeName();
    } else {
        resterName = "Enemy " + rester.getTypeName();
    }
    // Don't allow rest for fainted Creatures
    if (rester.getHealthCurr() == 0) {
        ss << resterName << " could not rest because it has fainted.\n";
        return;
    }
    
    // Rest should be okay
    int preHealth = rester.getHealthCurr();
    rester.rest();
    int increase = rester.getHealthCurr() - preHealth;
    
    ss << resterName << " rests and regains ";
    ss << increase << " health.\n";
}