#include "item.h"
#include <iostream>
using namespace std;

item :: item(string n, int ha){
    name = n;
    heal_amt = ha;
}

int item :: getHeal(){
    return heal_amt;
}

string item :: getName(){
    return name;
}