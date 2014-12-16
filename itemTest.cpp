#include "Item.h"
#include "CreatureType.h"
#include "Creature.h"
#include "EECSRandom.h"
#include <iostream>

using namespace std;

/*int main(){
    for (int i = 0; i < 100; ++i){
        cout << Item::randomItem() << endl;
    }/
    CreatureType::randomizeTypes();
    Creature tester = Creature::factory(EECSRandom::range(0, CreatureType::NUM_TYPES));
    Item inventory;

    for (int i = 0; i < Item::NUM_ITEMS; ++i){
        cout << inventory.getItemArray()[i] << endl;
    }


    return 0;
}*/