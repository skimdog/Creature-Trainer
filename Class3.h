//
//  Class3.h
//  Class3
//
//  These class heaaders are for use in your Trainer class. If you wish to 
//  write helper classes, write them in these 5 classes. 
//  Use of these classes is optional. You may use none or any or all of them. 
//  You still may NOT #include any.h files we provide you
//  (Battle, Creature, CreatureType, EECSRandom, Party, PrintHelper)
//

#ifndef __CreatureTrainer__Class3__
#define __CreatureTrainer__Class3__

// vvvvvv Your implementations go between this line…

#include <iostream>
using namespace std;

class Capture{
public:
    
    static const int PARTY_SIZE = 5;
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Default constructor
     */
    Capture();
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns specific capture response (co1, co2,...) based on which party Creature is least useful
     */
    void captureCreature(int enemyMaxHealth, int enemyAttack, int partyHealths[], int partyAttacks[], string& response);
    
private:
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns slot of the least useful Creature in the party, based on sum of its health & attack
     */
    int getLeastUsefulSlot(int partyHealths[], int partyAttacks[]);
    
};

// ^^^^^^ And this line. That's it!

#endif /* defined(__CreatureTrainer__Class3__) */
