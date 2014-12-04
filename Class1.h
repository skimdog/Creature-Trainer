//
//  Class1.h
//  Class1
//
//  These class heaaders are for use in your Trainer class. If you wish to 
//  write helper classes, write them in these 5 classes. 
//  Use of these classes is optional. You may use none or any or all of them. 
//  You still may NOT #include any.h files we provide you
//  (Battle, Creature, CreatureType, EECSRandom, Party, PrintHelper)
//  This class is for Creature CLASSES; Namely, for recording strengths and weakness, move type, and damage amount.

#ifndef __CreatureTrainer__Class1__
#define __CreatureTrainer__Class1__
#include <iostream>
using namespace std;
// vvvvvv Your implementations go between this line…

/**
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects:  runs a battle given the trainer, their party, the current
 situation, and the trainer's current win count
 */
string decide(string name, int health, int maxHealth);


// ^^^^^^ And this line. That's it!

#endif /* defined(__CreatureTrainer__Class1__) */
