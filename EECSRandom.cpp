//
//  EECSRandom.cpp
//  CreatureTrainer
//
//  Created by Jeremy Gibson on 11/4/14.
//  Copyright (c) 2014 Jeremy Richard Gibson. All rights reserved.
//

#include "EECSRandom.h"

int EECSRandom::getInt() {
    return rand();
}

double EECSRandom::getDouble() {
    double r = (double) rand();
    double d = r / RAND_MAX;
    return d;
}

void EECSRandom::setSeed(int u) {
    std::srand(u);
}

int EECSRandom::range(int low, int high) {
    double f = getDouble();
    double r = (high-low)*f + low;
    int n = (int) r;
    if (n == high) n = high-1;
    return(n);
}

double EECSRandom::range(double low, double high) {
    float f = getDouble();
    float r = (high-low)*f + low;
    return(r);
}