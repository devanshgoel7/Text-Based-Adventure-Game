#ifndef ITEM_H
#define ITEM_H

#include <iostream>
using namespace std;

class item{
    string name;
    int heal_amt;

    public:
        item(string n, int ha );

        int getHeal();

        string getName();
};

#endif