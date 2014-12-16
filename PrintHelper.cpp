#include <iostream>
#include "PrintHelper.h"
//#include "Item.h"

void PrintHelper::printIntro(stringstream & ss) {
    ss << "Hello, Trainer! Welcome to the world of EECS 183 Creature Trainer!\n";
    ss << "In this world, you will encounter many different creatures in battle.\n";
    ss << "It is up to you to compete and unravel the mysteries of these creatures.\n";
    ss << "The challenge is one that cannot be faced alone. In order to succeed, \n";
    ss << "you must work together with your own team of creatures.\n\n";
        
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

void PrintHelper::printItems(const Item& item, stringstream& ss) {
    /*
     ss  << ": POTION " << formatItemCount(item.getItemCount(1))
     << " : SHIELD " << formatItemCount(item.getItemCount(2))
     << " : DMG-BOOST " << formatItemCount(item.getItemCount(3))
     << " : REVIVE " << formatItemCount(item.getItemCount(4))
     << " : LASSO " << formatItemCount(item.getItemCount(5)) << " :\n"
     << ": S-A " << formatItemCount(item.getItemCount(6))
     << " : S-B " << formatItemCount(item.getItemCount(7))
     << " : S-C " << formatItemCount(item.getItemCount(8))
     << " : S-D " << formatItemCount(item.getItemCount(9))
     << " : S-E " << formatItemCount(item.getItemCount(10))
     << " : S-F " << formatItemCount(item.getItemCount(11))
     << " : S-G " << formatItemCount(item.getItemCount(12))
     << " : S-H " << formatItemCount(item.getItemCount(13)) << " :\n";
     */
    stringstream sst;
    
    //    string headings[] = { "! Potion:", "! Shield:", "! Dmg-Boost:", "! Revive:",
    //        "! Lasso:", "!\n! Scrolls      ! S-A:", "! S-B:", "! S-C:", "! S-D:",
    //        "! S-E:", "! S-F:", "! S-G:", "! S-H:" };
    string headings[Item::NUM_ITEMS];
    for (int i=0; i<Item::NUM_ITEMS; i++) {
        if (i<5) {
            headings[i] = "! "+Item::ITEM_NAMES[i]+"("+Item::ITEM_CODES[i]+"):";
        } else if (i == 5) {
            headings[i] = "!\n! Scrolls      ! "+Item::ITEM_CODES[i]+":";
        } else {
            headings[i] = "! "+Item::ITEM_CODES[i]+":";
        }
    }
    //    = { "! Potion(po):", "! Shield(sh):", "! Enrage(en):", "! Revive(re):",
    //        "! Lasso(la):", "!\n! Scrolls      ! sa:", "! sb:", "! sc:", "! sd:",
    //        "! se:", "! sf:", "! sg:", "! sh:" };
    int paddings[] = { 15, 16, 16, 16, 16, 25, 8, 8, 8, 8, 8, 8, 8 };
    
    printHR(ss);
    for (int i=0; i<13; i++) {
        sst.str("");
        sst << headings[i] << item.getItemCount(i);
        padString( sst, paddings[i] );
        ss << sst.str();
    }
    ss << "!\n";
    
}

/*
 --------------------------------------------------------------------------------
 | Kiwi       12/12 | *Bittern    17/17 | Pika       14/14 | Loris      17/17   |
 --------------------------------------------------------------------------------
 ! Potion:0     ! Shield:0      ! Dmg-Boost:0   ! Revive:0      ! Lasso:0       !
 ! Scrolls      ! S-A:0 ! S-B:0 ! S-C:0 ! S-D:1 ! S-E:0 ! S-F:0 ! S-G:0 ! S-H:0 !
 --------------------------------------------------------------------------------
 */

string PrintHelper::formatItemCount(int i) {
    string s = " ";
    if (i < 10) {
        s.append(to_string(i));
    }
    else {
        s = to_string(i);
    }
    return s;
}

void PrintHelper::printSingleCreature(Creature& c, bool current, stringstream& ss) {
	ss << "|";
	if ( current ) {
		ss << " *";
	} else {
		ss << " ";
	}
    // 10 char wide for name, filled with spaces by c.getTypeName()
    ss << c.getTypeName(CreatureType::TYPE_NAME_LENGTH+1);
    
	// space, then current/max health
    int health = c.getHealthCurr();
    if (health < 10) {
        ss << " ";
    }
    ss << " " << health << "/" << c.getHealthMax();// << " ";
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
    ss << "   Creatures in your party who are inactive rest every turn.\n";
    ss << "Items are used by entering their two-letter code (if you have the item):\n";
    ss << "   " << Item::ITEM_NAMES[0] << "(" << Item::ITEM_CODES[0]
    << ") - Use a potion on the active Creature\n";
    ss << "   " << Item::ITEM_NAMES[1] << "(" << Item::ITEM_CODES[1]
    << ") - Boost defense for the whole party for " << Item::BOOST_TURNS
    << " turns\n";
    ss << "   " << Item::ITEM_NAMES[2] << "(" << Item::ITEM_CODES[2]
    << ") - Boost attack for the whole party for " << Item::BOOST_TURNS
    << " turns\n";
    ss << "   " << Item::ITEM_NAMES[3] << "(" << Item::ITEM_CODES[3]
    << ") - Revives a fainted Creature. You must choose which Creature\n"
    << "\tto revive (ex: 're3' would revive Creature 3 in your party).\n";
    ss << "   " << Item::ITEM_NAMES[4] << "(" << Item::ITEM_CODES[4]
    << ") - Capture a fainted enemy. You must choose which of your party\n"
    << "\tto replace (ex: 'co4' would collar the fainted enemy and replace\n"
    << "\tCreature 4 in your party).\n";
    ss << "Scrolls are cast on the enemy by entering a two-letter scroll code:\n";
    ss << "   Scroll Codes: sa, sb, sc, sd, se, sf, sg, sh\n";
    ss << "   (ex. 'sf' to cast a Funk scroll on the enemy)\n\n";
}

void PrintHelper::printBattleOptions(stringstream & ss){
    ss  << "Trainer, make your move.\n"
    << "(a-Attack, s#-Swap to slot #, r-Rest, item code, or scroll code): ";
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

string PrintHelper::padString(string sIn, int len) {
    while (sIn.length() < len) {
        sIn = sIn + " ";
    }
    return(sIn);
}

void PrintHelper::padString(stringstream& ss, int len) {
    while (ss.str().length() < len) {
        ss << " ";
    }
}








