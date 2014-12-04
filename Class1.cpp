//  Class1.cpp
//  Helper Class1
//
//  These class heaaders are for use in your Trainer class. If you wish to 
//  write helper classes, write them in these 5 classes. 
//  Use of these classes is optional. You may use none or any or all of them. 
//  You still may NOT #include any.h files we provide you
//  (Battle, Creature, CreatureType, EECSRandom, Party, PrintHelper)
//  

#include "Class1.h"
#include <iostream>
using namespace std;

int Class1::getHighestHealth(int list[])
{
    int highPos = 1;
    int highestHealth = list[1];
    for(int i = 2; i < PARTY_SIZE; i++)
    {
        if(highestHealth < list[i])
        {
            highestHealth = list[i];
            highPos = i;
        }
    }
        
    return highPos;
}

string Class1::swap(int list[], int activeNum)
{
    int swapNum = getHighestHealth(list);
    string response;
    
    
    if(swapNum != activeNum)
    {
        switch(swapNum)
        {
            case 1:
                response = "s1";
                break;
            case 2:
                response = "s2";
                break;
            case 3:
                response = "s3";
                break;
            case 4:
                response = "s4";
                break;
        }
    }
    else
    {
        response = "a";
    }
    return response;
}

