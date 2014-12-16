#ifndef __CreatureTrainer__PrintHelper__
#define __CreatureTrainer__PrintHelper__

#include <iostream>
#include <sstream>
#include "Creature.h"
#include "Item.h"
#include <string>

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
     * Effects:  For all possible items, prints the counts that the Trainer
     currently has in the following format:
     
     "NOTHING", "POTION", "SHIELD", "DMG BOOST",
     "SCROLL-A","SCROLL-B","SCROLL-C","SCROLL-D","SCROLL-E","SCROLL-F","SCROLL-G",
     "REVIVE", "LASSO"}
     
     | POTION __ | SHIELD __ | DMG BOOST __ | REVIVE __ | LASSO __ |
     | S-A __ | S-B __ | S-C __ | S-D __ | S-E __ | S-F __ | S-G __ |
     */
    static void printItems(const Item& item, stringstream& ss);
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects: returns the int as a string.
     *          puts a space before it if it is 1 digit.
     */
    static string formatItemCount(int i);
    
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
     * Effects:  Prints shorter explanation of valid keyboard commands during
     *           battle
     */
    static void printBattleOptions(stringstream & ss);
    
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
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing
     * Effects:  Pads a string to a specific length by adding spaces.
     */
    static string padString(string sIn, int len);
    static void   padString(stringstream& ss, int len);
    
};

#endif