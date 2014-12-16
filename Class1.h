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
// vvvvvv Your implementations go between this line

//maybe "SwapOrAttack"?


class SwapOrAttack {
public:
    static const int PARTY_SIZE = 5;
    
    static const int DOUBLE_FACTOR = 2;
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Default constructor
     */
    SwapOrAttack();
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Swaps to creature with highest current health
     */
    void swapToHighestHealth(int partyHealths[], int partyAttacks[], int activeSlot, string& response);
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  If any, swaps to creature elementally normal to enemy
     */
    void swapToNormal(string enemyAtkElement, string enemyStrElement, string partyAtkElements[], string partyWeakElements[], int partyHealths[], int activeSlot, string& response);
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects: If any, swaps to creature with best defensive stats
     */
    void swapToDefensive(string enemyAtkElement, string enemyStrElement, string partyAtkElements[], string partyStrElements[], int partyHealths[], int activeSlot, string& response);
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  If any, swaps to creature with best offensive stats
     */
    void swapToOffensive(string enemyAtkElement, string enemyWeakElement, string partyAtkElements[], string partyWeakElements[], int partyHealths[], int activeSlot, string& response);
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  If any, swaps to creature that will win 100%
     */
    void swapToWinner(bool partyWinOrLose[], int partyHealths[], int activeSlot, string& response);
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  If any, swaps to the lowest-level creature that will win 100%
     */
    void swapToWeakWinner(bool partyWinOrLose[], int partyLevels[], int activeSlot, string& response);

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns true if attack element equal to enemy's strength element
     */
    bool attackIsNotEffective(string atkElement, string enemyStrElement);
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns true if attack element equal to enemy's weak element
     */
    bool attackIsSuperEffective(string atkElement, string enemyWeakElement);
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns true if attack element equal to any other than enemy's strength/weak elements
     */
    bool attackIsNormal(string atkElement, string enemyStrElement, string enemyWeakElement);
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns true if enemy attack next turn will deplete active creature's health
     */
    bool isGonnaDie(int health, string strElement, string weakElement, int enemyAttack, string enemyAtkElement);
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns true if enemy attack after next turn will deplete active creature's health
     */
    bool isGonnaDieAfterNextTurn(int health, string strElement, string weakElement, int enemyAttack, string enemyAtkElement);
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns true if enemy attack two turns later will deplete health of any
     one of other creatures besides active one
     */
    bool areOthersGonnaDieAfterNextTurn(int partyHealths[], string partyStrElements[], string partyWeakElements[], int enemyAttack, string enemyAtkElement);
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns true if other three creatures have fainted
     */
    bool isLastCreatureStanding(int partyHealths[], int activeSlot);
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns true if creature at specific slot is fainted
     */
    bool isFainted(int slot, int partyHealths[]);
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns usefulness # factor (health+attack) of creature at slot
     */
    int getUsefulness(int slot, int partyHealths[], int partyAttacks[]);
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Revives a creature, assuming it's fainted
     */
    void reviveCommand(int reviveSlot, string& response);
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Revives any fainted creature in party.
                 If more than one, revives the most useful one.
     */
    void reviveMostUsefulCreature(int partyHealths[], int partyAttacks[], string& response);
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Revives any fainted creature in party.
     If more than one, revives the most useful one.
     */
    void useScroll(int scrollPos, string& response);
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns attack after elemental factors are applied
     */
    int getFactoredAttack(int activeAttack, string enemyStrElement, string enemyWeakElement, string activeAtkElement);
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Revives true if all four creatures don't stand a chance
     */
    bool allIsNotWell(bool partyWinOrLose[]);
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns number of turns for creature to kill enemy
                 (Used in calculateWinLose)
     */
    int getTurnsToKill(int enemyCurrentHealth, string enemyWeakElement, string enemyStrElement, int partyAttacks[], string partyAtkElements[], int slot);
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns number of turns for creature to die from enemy
                 (Used in calculateWinLose)
     */
    int getTurnsToDie(int partyHealths[], string partyWeakElements[], string partyStrElements[], int enemyAttack, string enemyAtkElement, int slot);
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns true if turns to kill <= turns to die (-1 if swapping to creature) for creature at slot
     */
    bool calculateWinLose(int enemyAttack, string enemyAtkElement, string enemyWeakElement, string enemyStrElement, int enemyCurrentHealth, int partyAttacks[], string partyAtkElements[], string partyWeakElements[], string partyStrElements[], int partyHealths[], int slot, int activeSlot, bool lastHope);
    
private:
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns the slot (1,2,3,4) of creature
     with highest health
     */
    int getHighestHealth(int partyHealths[], int partyAttacks[]);
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects: Swaps to creature at swapSlot
     */
    void swapCommand(int swapSlot, string& response);
};

// ^^^^^^ And this line. That's it!

#endif /* defined(__CreatureTrainer__Class1__) */