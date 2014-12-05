//
//  Class1.h
//  Class1
//
//  These class heaaders are for use in your Trainer class. If you wish to 
//  write helper classes, write them in these 5 classes. 
//  Use of these classes is optional. You may use none or any or all of them. 
//  You still may NOT #include any.h files we provide you
//  (Battle, Creature, CreatureType, EECSRandom, Party, PrintHelper)
//  This class is for Creature CLASSES; Namely, for recording strengths and weakness, move type, and damage amount.

#ifndef __CreatureTrainer__Class1__
#define __CreatureTrainer__Class1__

#include <iostream>
using namespace std;
// vvvvvv Your implementations go between this line…

//maybe "SwapOrAttack"?


class Class1 {
public:
    static const int PARTY_SIZE = 5;
    
 
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns swap command based on which creature has highest health
     */
    string swapToHighestHealth(int partyHealths[], int activeSlot);
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns true if enemy attack next turn will deplete active creature's health
                 Otherwise false
     */
    bool isGonnaDie(int health, int enemyATK);
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns true if enemy attack two turns later will deplete health of any 
                 one of other creatures besides active one
     */
    bool areOthersGonnaDie(int partyHealths[], int partyDamages[]);
    
private:
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns the slot (1,2,3,4) of creature
     with highest health
     */
    int getHighestHealth(int partyHealths[]);
    
};


/**
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects:  runs a battle given the trainer, their party, the current
 situation, and the trainer's current win count
 */




// ^^^^^^ And this line. That's it!

#endif /* defined(__CreatureTrainer__Class1__) */
