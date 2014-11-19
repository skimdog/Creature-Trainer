#ifndef __CreatureTrainer__PrintHelper__
#define __CreatureTrainer__PrintHelper__

#include <iostream>
#include <sstream>
#include "Creature.h"

class PrintHelper {
public:
    /**
     * Requires: Nothing.
     * Modifies: ss
     * Effects:  Prints the introductory Creature Trainer message
     */
    static void printIntro(stringstream & ss);
    
    /**
     * Requires: Nothing.
     * Modifies: ss
     * Effects:  Prints out the current party in this format:
     
| *Uromastyx  17/17 | Zebu       19/19 | Echidna    13/13 | Ibex       19/19   |
     
     */
    static void printTeamStatus(Creature creatures[], int currCreatureIndex, stringstream & ss);

    /**
     * Requires: Nothing.
     * Modifies: ss
     * Effects:  Prints out a single creature in this format:
    
     | *Uromastyx  17/17

     */
    static void printSingleCreature(Creature& c, bool current, stringstream& ss);
    
    /**
     * Requires: Nothing.
     * Modifies: ss
     * Effects:  prints an error if the player chooses an invalid move
     */
    static void printError(stringstream& ss);

    /**
     * Requires: Nothing.
     * Modifies: ss
     * Effects:  Prints explanation of valid keyboard commands during battle
     */
    static void printOptions(stringstream & ss);

    /**
     * Requires: Nothing.
     * Modifies: ss
     * Effects:  Prints message for when each member of your party has fainted
     */
    static void printEnd(int count, stringstream & ss);
    
    /**
     * Requires: Nothing.
     * Modifies: ss
     * Effects:  Prints the situation of a creature attacking in the format:

     Your  C-lacanth attacks Enemy Megapode  with Hammer  for 6 damage.

    or
     
     Enemy Megapode  attacks Your  C-lacanth with Earth   for 4 damage.

     */
    static void printPlayerAttack(Creature &attacker, string &receiverName, stringstream & ss);

    /**
     * Requires: Nothing.
     * Modifies: ss
     * Effects:  Prints the current win count
     */
    static void printWinCount(int count, stringstream & ss);
    
    /**
     * Requires: Nothing.
     * Modifies: ss
     * Effects:  Prints an 80-character wide horizontal line
     
--------------------------------------------------------------------------------
     
     */
    static void printHR(stringstream& ss);
    
    /**
     * Requires: Nothing.
     * Modifies: ss
     * Effects:  Prints an 80-character wide horizontal underscore line
     
________________________________________________________________________________
     
     */
    static void printHRL(stringstream& ss);
};

#endif