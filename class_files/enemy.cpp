#include "enemy.h"
#include <iostream>
#include<thread>
#include<chrono>
using namespace std;


Enemy::Enemy(){}

Enemy::Enemy(string n, int h, int atk, bool def): fight(atk,h){
    name = n;
    defeated = def;
}

