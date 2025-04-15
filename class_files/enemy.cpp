#include "enemy.h"
#include <iostream>
#include<thread>
#include<chrono>
using namespace std;


Enemy::Enemy(){}

Enemy::Enemy(string n="GOBLIN", int h=150, int atk=50){
    name = n;
    health = h;
    atk_pow = atk;
}

int Enemy::attack(){
    return atk_pow;
}

void Enemy::take_dmg(int damage) {
    health -= damage;   
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << name << " took " << damage << " damage! Remaining health: " << ((health <=0)?0:health) << endl;
    if (health <= 0) {
        defeated = true;
        cout << name << " has been defeated!" << endl;
    }
}