#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
using namespace std;

class Enemy{

    private:

    string name;
    int health;
    int atk_pow;
    bool defeated;

    public:
    
    Enemy();

    Enemy(string n, int h, int atk);

    int attack();

    void take_dmg(int damage);

    bool isDefeated();

    void display_status();
};

#endif