#ifndef ITEMS_H
#define ITEMS_H

#include <iostream>
using namespace std;

class item{

    protected:

    string name;
    string type;

    public:
        item(string n, string t);

};

class atk: public item{

    int atk_pow;

    public:
        atk(string n, string t, int ap);

        int atkpow();
};

class health: public item{
    
    int heal;

    public:
        health(string n, string t, int h);

        int healpow();
};

#endif 