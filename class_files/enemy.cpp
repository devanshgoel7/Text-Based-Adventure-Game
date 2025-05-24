#include "enemy.h"
#include <iostream>

using namespace std;


Enemy::Enemy(){}

Enemy::Enemy(string n, int h, int atk, bool def){
    name = n;
    hp = h;
    atk_pow = atk;
    defeated = def;
}

void Enemy :: atk_dmg(int damage){
    hp -= damage;
    if(hp < 0){
        hp = 0;
    }
    cout << endl;
    cout << name << " took " << damage << " damage" << endl;
    cout << "Remaining Health: " << hp << endl;
}

int Enemy :: getHP(){
    return hp;
}

int Enemy :: getpow(){
    return atk_pow;
}

string Enemy :: getName(){
    return name;
}