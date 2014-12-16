//
//  Item.h
//  CreatureTrainer
//
//  Created by Jeremy Gibson on 11/28/14.
//  Copyright (c) 2014 Jeremy Richard Gibson. All rights reserved.
//

#ifndef __CreatureTrainer__Item__
#define __CreatureTrainer__Item__

#include <stdio.h>
#include <vector>
#include "Creature.h"
#include "Party.h"


class Item{
public:
    const static int    NUM_ITEMS = 13;
    const static int    MAX_ITEM_COUNT = 99;
    const static int    BOOST_TURNS = 4;
    const static int    POTION_HEALTH = 20;
    const static int    SCROLL_DAMAGE = 20;
    const static int    REVIVE_HEALTH = 1;
    const static int    COLLAR_HEALTH = 1;
    // Below is the damage multiplier that the two Boosts apply
    // constexpr const static double ATKBST_MULT = 2.0;
    //constexpr const static double DEFBST_MULT = 0.5;
    
    //really ugly, but now it compiles in visual studio
    struct ATKBST_MULT{
        static double value(){ return 2.0; }
    };
    struct DEFBST_MULT{
        static double value(){ return 0.5; }
    };
    
    // Change this to have items when the game starts.
    const static int STARTING_ITEM_COUNT = 0;
    const static int STARTING_COLLAR_COUNT = 20;
    
private:
    int itemCounts[NUM_ITEMS];
    
public:
    const static string ITEM_NAMES[];
    const static string ITEM_CODES[];
    const static int    ITEM_CHANCE[];
    const static int    NOTHING_CHANCE = 25;
    
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Sets all item counts to 0.
     */
    Item();
    
    /**
     * Requires: Nothing
     * Modifies:
     * Effects:  Generates a random item
     */
    static string randomItem();
    
    /**
     * Requires: Nothing
     * Modifies: Nothing
     * Effects:  returns the item index for the code entered by the trainer
     */
    int getIndexForCode(string code);
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Gets and returns a pointer to itemCounts.
     */
    int* getItemArray();
    
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Gets and returns the number the trainer has of Item[index].
     */
    int getItemCount(int index) const;
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Applies item effects
     */
    string useItem(string itemCommand, Party& party, Creature& enemy,
                   stringstream & ss, int& illegal);
    
    /**
     * Requires: Nothing.
     * Modifies: defender, ss
     * Effects:  Applies damage to defender, prints out message
     about how much damage a scroll does to a creature
     Returns true if attacking was valid. False if not.
     */
    static bool scrollDmg(int scrollElt, int dmg, Creature& defender, stringstream& ss);
    
    /**
     * Requires: Nothing.
     * Modifies: toBoost, ss
     * Effects:  Grants the creature a shield or dmgBoost (depending on item)
     that lasts for 4 turns
     */
    void applyBoost(Creature& toBoost, string item, stringstream& ss);
    
    /**
     * Requires: Nothing.
     * Modifies: itemCounts
     * Effects:  Adds the new item to itemCounts
     */
    void addItem(string item);
    
};


#endif /* defined(__CreatureTrainer__Item__) */