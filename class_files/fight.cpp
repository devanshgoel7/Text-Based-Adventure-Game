#include "header_files\fight.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

fight :: fight(){
    atk_pow = 0;
}

fight :: fight(int pow){
    atk_pow = pow;
}

int fight :: attack(int atk_pow){
    srand(time(0));
    int random = (rand() % 10) + 1;

    return atk_pow*random;
}

void fight :: atk_dmg(int damage, string name){
    health -= damage;

    cout << name << " took " << damage << " damage" << endl;
    cout << "Remaining Health: " << health << endl;
}

int fight :: defence(int atk_dmg){
    srand(time(0));
    float random = (rand() % 60) + 1;
    int new_dmg = atk_dmg - (atk_dmg*(random/100));

    return new_dmg;
}

void fight :: def_dmg(int new_dmg, string name){
    health -= new_dmg;

    cout << name << " took " << new_dmg << " damage" << endl;
    cout << "Remaining Health: " << health << endl;
}