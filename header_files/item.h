#ifndef ITEM_H
#define ITEM_H

#include <iostream>
using namespace std;

class item{
    protected:
    string name;


    public:
        item(string n);
};

class atk : public item{

    int atk_pow;
    public:
        atk(string n, int pow);

        int getPow();
        string getName();
};

class heal : public item{

    int heal_amt;

    public:
        heal(string n, int ha);

        int getHeal();
        string getName();
};

#endif