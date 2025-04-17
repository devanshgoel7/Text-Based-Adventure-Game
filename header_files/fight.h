#ifndef FIGHT_H
#define FIGHT_H
#include "player.h"
#include "enemy.h"
#include <iostream>
using namespace std;

class fight{

    public:

        int attack(int atk_pow);

        void atk_dmg(int hp, int damage, string name);

        int defence(int atk_dmg);

        bool battle(Enemy &e1, Player &p, bool gameloop);
};

#endif