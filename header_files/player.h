#ifndef PLAYER_H
#define PLAYER_H

#include "fight.h"
#include <iostream>
#include <vector>
using namespace std;

class Player: public fight{

    string name;
    vector <string> inventory;
    string move;
    bool isalive;

    public:
        Player(string n, int pow, int h, bool alive);

        void take_item(string item);

        void power(int atkpower);
        
        void show_inventory();

        void isdefeated();

};

#endif