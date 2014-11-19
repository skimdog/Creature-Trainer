#include <iostream>
#include "PrintHelper.h"

void PrintHelper::printIntro(stringstream & ss) {
    ss << "Hello, Trainer! Welcome to the world of EECS 183 Creature Trainer!\n";
    ss << "In this world, you will encounter many different creatures in battle.\n";
    ss << "It is up to you to compete and unravel the mysteries of these creatures.\n";
    ss << "The challenge is one that cannot be faced alone. In order to succeed, \n";
    ss << "you must work together with your own team of creatures.\n\n";
    
    /* for implementation 2 (reach)
     cout << "\n\nTo help you in your progress toward becoming an Ace Trainer,\n\n";
     cout << "you may battle in two arenas:\n\n";
     cout << "The \"STOMPING GROUND\" is a great place to perform multiple battles against\n\n";
     cout << "many enemies of a set level [practice for the \"Core\" portion].\n\n";
     cout << "The \"GAUNTLET\" is where you will encounter any range of enemies as well as\n\n";
     cout << "be presented with the opportunity to capture defeated enemies and pick up / use\n\n";
     cout << "the items outlined in the spec.\n\n";
     
     cout << "\n\nChoose your arena.\n\n";
     cout << "Enter \"STOMP\" for The \"STOMPING GROUND\" or \"GAUNT\" for The \"GAUNTLET\":\n\n";
     */
    
    
    ss << "With that, we present your team!\n";
}


void PrintHelper::printTeamStatus(Creature creatures[], int currCreatureIndex, stringstream& ss) {

	if (currCreatureIndex == 0)
		printSingleCreature(creatures[0], true, ss);
	else
		printSingleCreature(creatures[0], false, ss);

	if (currCreatureIndex == 1)
		printSingleCreature(creatures[1], true, ss);
	else
		printSingleCreature(creatures[1], false, ss);

	if (currCreatureIndex == 2)
		printSingleCreature(creatures[2], true, ss);
	else
		printSingleCreature(creatures[2], false, ss);

	if (currCreatureIndex == 3)
		printSingleCreature(creatures[3], true, ss);
	else
		printSingleCreature(creatures[3], false, ss);
    
    ss << "  |\n";
}


void PrintHelper::printSingleCreature(Creature& c, bool current, stringstream& ss) {
	ss << "|";
	if ( current ) {
		ss << " *";
	} else {
		ss << " ";
	}
    // 10 char wide for name, filled with spaces by c.getTypeName()
    ss << c.getTypeName(10);

	// space, then current/max health
	ss << " " << c.getHealthCurr() << "/" << CreatureType::TYPES[c.getType()].getHealthMaxBase() << " ";
}


void PrintHelper::printError(stringstream& ss) {
    ss << "ERROR: INVALID MOVE" << endl;
    ss << "You lost your turn." << endl;
}


void PrintHelper::printOptions(stringstream & ss){
    ss << "During battle, choose from the following for each move:" << endl;
    ss << "'a' to attack." << endl;
    ss << "'s' and a number to swap to that Creature (ex. s1, s2, s3, s4).\n";
    ss << "'r' to rest and regain a little health\n";
    ss << "      Creature in your party who are inactive rest every turn.\n\n";
}


void PrintHelper::printEnd(int count, stringstream & ss) {
    ss << "\nSadly, your entire party of creatures has fallen in battle.\n";
	ss << "You won " << count;
	if (count == 1)
		ss << " battle today.\n\n";
	else
		ss << " battles today.\n\n";

}


void PrintHelper::printPlayerAttack(Creature &attacker, string &receiverName, stringstream & ss){
    string attackerName = CreatureType::CREATURE_NAMES[attacker.getType()];
    CreatureType attackerType = CreatureType::TYPES[attacker.getType()];
    
    ss << attackerName << " attacks " << receiverName;
    ss << " with " << CreatureType::ELEMENT_NAMES[attackerType.getElementalAttackType()];
    ss << " for " << attackerType.getAttackBase()*attackerType.getAttackPerLevel() << " damage.\n";
}


void PrintHelper::printWinCount(int count, stringstream & ss){
    ss << "Current win count: " << count << '\n';
}


void PrintHelper::printHR(stringstream& ss) {
    ss << "----------------------------------------";
    ss << "----------------------------------------\n";
}


void PrintHelper::printHRL(stringstream& ss) {
    ss << "________________________________________";
    ss << "________________________________________\n";
}



