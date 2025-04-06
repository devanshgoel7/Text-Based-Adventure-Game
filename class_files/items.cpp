#include "header_files\items.h"
#include <iostream> 
using namespace std;

item :: item(string n, string t){
    name = n;
    type = t;
}

atk :: atk(string n, string t, int ap) : item(n,t){
    atk_pow = ap;
}

int atk :: atkpow(){
    return atk_pow;
}

health :: health(string n, string t, int h): item(n,t) {
    heal = h;
}

int health :: healpow(){
    return heal;
}