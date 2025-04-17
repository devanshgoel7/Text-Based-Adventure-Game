#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "item.h"
#include <vector>
using namespace std;

class Player{

    string name;
    vector <item> inventory;
    string move;
    bool isalive;
    int atk_pow;
    int hp;


    public:
        Player(string n, int pow, int h, bool alive);

        void take_item(item &i);

        void power(int atkpower);
        
        void show_inventory();

        void atk_dmg(int damage);

        void use_item(int choice);

        void isdefeated();

        int getHP();

        int getpow();

};

#endif