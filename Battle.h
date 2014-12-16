#include <iostream>
#include <string>
#include "Creature.h"
#include "Trainer.h"
#include "EECSRandom.h"
#include "Party.h"
#include "Item.h"
using namespace std;

/**
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects:  runs a battle given the trainer, their party, the current
 situation, and the trainer's current win count
 */
void runBattle(Trainer &player1, Party &party, Item &items, stringstream& ss,
               int winCount, int& moveCount, int& illegalMoveCount);

void parseMove(string playerMove, Party &party, Item &items, Creature& enemy,
               stringstream& ss, int& illegalMoveCount);

//Same as above but attack and scrolls not allowed.
void parseMovePostBattle(string playerMove, Party &party, Item &items, Creature& enemy,
                         stringstream& ss, int& illegalMoveCount);

/**
 * Requires: Nothing.
 * Modifies: defender, ss
 * Effects:  Applies damage to defender, prints out messages
 about which creature attacks, what element they use,
 and how much damage they do.
 Returns true if attacking was valid. False if not.
 */
bool creatureAttack(Creature& attacker, Creature& defender, bool isPlayer,
                    Party& party, stringstream& ss);

/**
 * Requires: Nothing.
 * Modifies: rester, ss
 * Effects:  Increases rester's health, prints message
 */
void creatureRest(Creature& rester, bool isPlayer, stringstream& ss);