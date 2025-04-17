#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
using namespace std;

class Enemy{

    string name;
    bool defeated;
    int atk_pow;
    int hp;
    public:
    
    Enemy();

    Enemy(string n,int pow, int h, bool def);

    int getHP();
    
    int getpow();

    string getname();

    void atk_dmg(int damage);

    bool isDefeated();

    void display_status();
};

#endif