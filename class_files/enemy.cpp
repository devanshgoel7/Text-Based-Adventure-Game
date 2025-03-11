#include "enemy.h"
#include <iostream>
using namespace std;


Enemy::Enemy(){}

Enemy::Enemy(string n, int h, int atk){
    name = n;
    health = h;
    atk_pow = atk;
}

int Enemy::attack(){
    return atk_pow;
}

void Enemy::take_dmg(int damage) {
    health -= damage;
    cout << name << " took " << damage << " damage! Remaining health: " << health << endl;
    if (health <= 0) {
        defeated = true;
        cout << name << " has been defeated!" << endl;
    }
}