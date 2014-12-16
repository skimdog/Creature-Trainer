//
//  main.cpp
//  CreatureTrainer
//
//  Created by Jeremy Gibson on 11/4/14.
//  Copyright (c) 2014 Jeremy Richard Gibson. All rights reserved.
//

#include <iostream>
#include <vector>
#include <sstream>
#include "EECSRandom.h"
#include "Trainer.h"
#include "Creature.h"
#include "CreatureType.h"
#include "PrintHelper.h"
#include "Battle.h"
#include "Party.h"
#include <ctime>

using namespace std;

bool randomizeBattles = true;

int main(int argc, const char * argv[]) {
    stringstream ss;
    PrintHelper::printIntro(ss);
    
    Trainer player;

    // Sets the random number seed. This will be set differently for the various dungeons.
    if (randomizeBattles) {
        srand((int) time(NULL));
    } else {
        srand(1);
    }
    
    //pseudorand generate CreatureTypes
    CreatureType::randomizeTypes();

    Party trainerParty; // Generates a random party for the trainer
    
    
    //Print out team + base stats in the form
    //   |*Horse____# 012/123| Elephant   123/123| Aardvark__ 233/300| Echidna    234/345
    trainerParty.printStatus(ss);
    ss << "\n\n";

    //Explains the possible actions in battle
    PrintHelper::printOptions(ss);

    
    Item trainerItems; // Tracks the items that a Trainer picks up

    // Battle until all Creatures in the party faint.
    int battlesWon = -1;
    int numMovesMade = 0;
    int numIllegalMovesMade = 0;
    
    while (trainerParty.alive()) {
        battlesWon++;
        // Create the situation
        runBattle(player, trainerParty, trainerItems, ss,
                  battlesWon, numMovesMade, numIllegalMovesMade);
    }
    
    // We only get here if the entire party is dead
    PrintHelper::printEnd(battlesWon, ss);
    player.finalSituation(ss);
    return 0;
}



