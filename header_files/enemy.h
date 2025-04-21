#ifndef ENEMY_H
#define ENEMY_H

#include "fight.h"
#include <iostream>
using namespace std;

class Enemy: public fight{

    private:

    string name;
    int hp;
    int atk_pow;
    bool defeated;

    public:
    
    Enemy();

    Enemy(string n,int pow, int h, bool def);

    int getHP();

    int getpow();

    string getName();

    void atk_dmg(int damage);

    bool isDefeated();

    void display_status();
};

#endif