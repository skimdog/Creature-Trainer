//
//  CreatureType.h
//  CreatureTrainer
//
//  Created by Jeremy Gibson on 11/4/14.
//  Copyright (c) 2014 Jeremy Richard Gibson. All rights reserved.
//

#ifndef __CreatureTrainer__CreatureType__
#define __CreatureTrainer__CreatureType__

class Creature;

#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

class CreatureType {
private:
    int type; // Creature's type (first letter of species name)
    int healthMaxBase;	// - The health for a L0 version of this creature
    int healthMaxPerLevel; // - The increase in healthMax for each increase in level (REACH)
    int healthRestIncrease;// - The amount of health that regens for every turn rest() is called
    int attackBase; // The attack strength for a L0 version
    int attackPerLevel; // The increase in attack strength per level (REACH)
    int elementalAttackType; // The elemental type of the attack
    int elementalWeakness; // The elemental type that will do double damage to this creature
    int elementalStrength; // The elemental type that will do half damage to this creature
    
    
    
public:
    const static int    NUM_TYPES = 26; //One for each letter of alphabet
    const static int    NUM_ELEMENTS = 8;
    const static string CREATURE_NAMES[];
    const static string ELEMENT_NAMES[];
    const static int    TYPE_NAME_LENGTH = 9;
    const static int    ELEM_NAME_LENGTH = 7;
    
    static std::vector<CreatureType> TYPES;
    
    const static int healthMaxBaseMin = 10;
    const static int healthMaxBaseMax = 20;
    
    const static int healthMaxPerLevelMin = 2;
    const static int healthMaxPerLevelMax = 6;
    
    const static int healthRestIncreaseMin = 4;
    const static int healthRestIncreaseMax = 6;
    
    const static int attackBaseMin = 4;
    const static int attackBaseMax = 6;
    
    const static int attackPerLevelMin = 2;
    const static int attackPerLevelMax = 4;
    
    
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Default contructor that does nothing.
     */
    CreatureType();
    
    /**
     * Requires: cType must be in the range [0, NUM_TYPES).
     * Modifies: Nothing.
     * Effects:  Creates a creatureType with random stats
     */
    CreatureType(int cType);
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Randomizes stats for all creatues in TYPES vector
     */
    static void randomizeTypes();
    
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns the name of the CreatureType.
     */
    // Note: int pad below has a default value of TYPE_NAME_LENGTH.
    //       This is called a "default parameter"
    static string typeName(int tN, int pad=TYPE_NAME_LENGTH);
    
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns the name of the element of this CreatureType.
     */
    // Note: int pad below has a default value of ELEM_NAME_LENGTH.
    //       This is called a "default parameter"
    static string elementName(int eN, int pad=ELEM_NAME_LENGTH);
    
    
    /**
     * Requires: Nothing.
     * Modifies: CreatureType data.
     * Effects:  Randomizes the various stats for this CreatureType.
     */
    void randomizeType();
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  returns type.
     */
    int getType();
    
    
    /**
     * Requires: num is in the range [0, NUM_TYPES)
     * Modifies: type
     * Effects:  Sets type.
     */
    void setType(int num);
    
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  returns healthMaxBase.
     */
    int getHealthMaxBase();
    
    
    /**
     * Requires: num is in the range [healthMaxBaseMin, healthMaxBaseMax]
     * Modifies: healthMaxBase
     * Effects:  Sets healthMaxBase.
     */
    void setHealthMaxBase(int num);
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  returns healthRestIncrease.
     */
    int getHealthRestIncrease();
    
    
    /**
     * Requires: num is in the range [healthRestIncreaseMin, healthRestIncreaseMax]
     * Modifies: healthRestIncrease
     * Effects:  Sets healthRestIncrease
     */
    void setHealthRestIncrease(int num);
    
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  returns attackBase.
     */
    int getAttackBase();
    
    
    /**
     * Requires: num is in the range [attackBaseMin, attackBaseMax]]
     * Modifies: attackBase
     * Effects:  Sets attackBase.
     */
    void setAttackBase(int num);
    
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  returns elementalAttackType.
     */
    int getElementalAttackType();
    
    
    /**
     * Requires: num is in the range [0, NUM_ELEMENTS).
     * Modifies: elementalAttackType
     * Effects:  Sets elementalAttackType.
     */
    void setElementalAttackType(int num);
    
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  returns elementalWeakness.
     */
    int getElementalWeakness();
    
    
    /**
     * Requires: num is in the range [0, NUM_ELEMENTS).
     * Modifies: elementalWeakness
     * Effects:  Sets elementalWeakness.
     */
    void setElementalWeakness(int num);
    
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  returns elementalStrength.
     */
    int getElementalStrength();
    
    
    /**
     * Requires: num is in the range [0, NUM_ELEMENTS).
     * Modifies: elementalStrength
     * Effects:  Sets elementalStrength.
     */
    void setElementalStrength(int);
    
//--------------Reach----------------
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  returns healthMaxPerLevel.
     */
    int getHealthMaxPerLevel();
    
    
    /**
     * Requires: num is in the range [healthMaxPerLevelMin, healthMaxPerLevelMax]
     * Modifies: healthMaxPerLevel
     * Effects:  Sets healthMaxPerLevel.
     */
    void setHealthMaxPerLevel(int num);
    

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  returns attackPerLevel.
     */
    int getAttackPerLevel();
    
    
    /**
     * Requires: num is in the range [attackPerLevelMin, attackPerLevelMax]
     * Modifies: attackPerLevel
     * Effects:  Sets attackPerLevel.
     */
    void setAttackPerLevel(int num);
    
};



#endif /* defined(__CreatureTrainer__CreatureType__) */
