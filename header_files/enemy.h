#ifndef ENEMY_H
#define ENEMY_H

#include "fight.h"
#include <iostream>
using namespace std;

class Enemy: public fight{

    private:

    string name;
    bool defeated;

    public:
    
    Enemy();

    Enemy(string n,int pow, int h, bool def);

    bool isDefeated();

    void display_status();
};

#endif