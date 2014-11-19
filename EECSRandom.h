//
//  EECSRandom.h
//  CreatureTrainer
//
//  Created by Jeremy Gibson on 11/4/14.
//  Copyright (c) 2014 Jeremy Richard Gibson. All rights reserved.
//

#ifndef __CreatureTrainer__EECSRandom__
#define __CreatureTrainer__EECSRandom__

#include <iostream>
using namespace std;

class EECSRandom {

public:
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  returns a random integer
     */
    static int getInt();
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  returns a random double
     */
    static double getDouble();
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  sets the random seed to u
     */
    static void setSeed(int u);

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  returns a random integer in the range [low, high)
     */
    static int range(int low, int high);
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  returns a random double in the range [low, high]
     */
    static double range(double low, double high);

};

#endif /* defined(__CreatureTrainer__EECSRandom__) */
