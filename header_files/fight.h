#ifndef FIGHT_H
#define FIGHT_H

#include <iostream>
using namespace std;

class fight{
    protected:

    int atk_pow;
    int hp;

    public:
        fight();

        fight(int pow, int h);

        int attack(int atk_pow);

        void atk_dmg(int damage, string name);

        int defence(int atk_dmg);

        void def_dmg(int damage, string name);
};

#endif