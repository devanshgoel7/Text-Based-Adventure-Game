#include "item.h"
#include <iostream>
using namespace std;

item :: item(string n){
    name = n;
}

atk :: atk(string n, int pow) : item(n){
    atk_pow = pow;
}

heal :: heal(string n, int ha) : item(n){
    heal_amt = ha;
}

int heal :: getHeal(){
    return heal_amt;
}

int atk :: getPow(){
    return atk_pow;
}

string heal :: getName(){
    return name;
}

string atk :: getName(){
    return name;
}