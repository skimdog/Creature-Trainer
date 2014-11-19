#include <iostream>
#include <string>
#include "Creature.h"
#include "Trainer.h"
#include "EECSRandom.h"
#include "Party.h"
using namespace std;

/**
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects:  runs a battle given the trainer, their party, the current
             situation, and the trainer's current win count
 */
void runBattle(Trainer &player1, Party &party, stringstream& ss, int winCount);

/**
 * Requires: Nothing.
 * Modifies: defender, ss
 * Effects:  Applies damage to defender, prints out messages
             about which creature attacks, what element they use,
             and how much damage they do
 */
void creatureAttack(Creature& attacker, Creature& defender, bool isPlayer, stringstream& ss);

/**
 * Requires: Nothing.
 * Modifies: rester, ss
 * Effects:  Increases rester's health, prints message
 */
void creatureRest(Creature& rester, bool isPlayer, stringstream& ss);