//
//  Creature.h
//  CreatureTrainer
//
//  Created by Jeremy Gibson on 11/4/14.
//  Copyright (c) 2014 Jeremy Richard Gibson. All rights reserved.
//

#ifndef __CreatureTrainer__Creature__
#define __CreatureTrainer__Creature__

#include <stdio.h>
#include <vector>
#include "CreatureType.h"

class Creature{
private:
    int type; // Creature's type
    int healthCurr; // Current amount of health. If healthCurr reaches 0, the creature faints.
    int healthMax; // Max amount of health
    //--Reach--
    int level; 	// The numerical level of the creature. Starts at 0.
    int xp; // The amount of experience that this creature has
    
public:
    const static int WINS_TO_LEVEL = 10;

    /**
    * Requires: Nothing.
    * Modifies: Nothing.
    * Effects:  Default constructor that does nothing
    */
    Creature();
        
    /**
     * Requires: cType must be in the range [0, NUM_TYPES).
     * Modifies: type
     * Effects:  Creates a creature of given creatureType
     *           with indicated level.
     */
    static Creature factory(int cType, int level_in = 0);
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Gets and returns the name of the CreatureType.
     */
    // Note: int pad below has a default value of -1.
    //       This is called a "default parameter"
    string getTypeName(int pad=-1);

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Gets and returns CreatureType - creature with generated stats
                 from CreatureType::TYPES.
     */
    CreatureType& getCreatureType();    
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Gets and returns type - int representing index of creature in 
                 CreatureType::TYPES
     */
    int getType();
    

    /**
     * Requires: int must be in the range [0, NUM_TYPES).
     * Modifies: type
     * Effects:  Sets type to int passed in.
     */
    void setType(int cType);
    
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Gets and returns healthCurr.
     */
    int getHealthCurr();
    
    
    /**
     * Requires: num is in the range [0, healthMax]
     * Modifies: healthCurr
     * Effects:  Sets healthCurr to int passed in
     */
    void setHealthCurr(int num);
    
    /**
    * Requires: Nothing.
    * Modifies: Nothing.
    * Effects:  Gets and returns healthMax.
    */
    int getHealthMax();


    /**
    * Requires: num is in the range [0, healthMax]
    * Modifies: healthMax
    * Effects:  Sets healthMax to int passed in
    */
    void setHealthMax(int num);

    /**
     * Requires: Nothing.
     * Modifies: Increases health.
     * Effects:  Heals the creature a small amount (increases healthCurr)
     */
    void rest();
    

    /**
     * Requires: Nothing.
     * Modifies: Nothing
     * Effects:  returns attack strength (changes with level)
     */
    int getAttackStrength();
    
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  returns creature's elemental attack type
     */
    int getAttackElement();

    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  returns creature's elemental weakness (element that does extra
                 damage to this creature)
     */
    int getElementalWeakness();

    
    /**
     * Requires: Nothing.
     * Modifies: Increases health.
     * Effects:  returns creature's elemental strength (element that this 
                 creature will do extra damage to)
     */
    int getElementalStrength();    
    
    
    /**
     * Requires: Nothing.
     * Modifies: healthCurr
     * Effects:  Returns amount of damage this creature takes, given the enemy
                 attack damage and enemy attack element as well as the amount 
                 of health that this Creature has remaining.
                 Also applies damage to creature's health.
     */
    int damage(int amount, int element);


//--------------Reach----------------
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Gets and returns level.
     */
    int getLevel();
    
    
    /**
     * Requires: num >= 0
     * Modifies: Sets level.
     * Effects:  Nothing.
     */
    void setLevel(int num);
    

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns xp.
     */
    int getXp();
    
    /**
     * Requires: num >= 0.
     * Modifies: Sets xp.
     * Effects:  Nothing.
     */
     //POSSIBLY DELETE
    void setXp(int num);

    /**
     * Requires: The two creatures exist
     * Modifies: Nothing.
     * Effects:  Checks if the creatures are the same.
     */
    bool operator==(const Creature& other);

    /**
    * Requires: battle won
    * Modifies: xp
    * Effects: increments xp. If xp == 10, calls updateLevel() 
    *          and resets xp to 0
    *          Returns true if level increases
    */
    bool updateXP();

    /**
    * Requires: xp == 10
    * Modifies: level, healthMax
    * Effects: increments level iff less than 9. Increases
    *          maxHealth by CreatureType's maxHealthPerLevel
    *          NOTE: attack stats updated in getAttackStrength()
    *          Returns true if level increases
    */
    bool updateLevel();
};


#endif /* defined(__CreatureTrainer__Creature__) */
