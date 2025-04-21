#include "player.h"
#include "fight.h"
#include <iostream>
#include <vector>
using namespace std;

Player :: Player(string n, int pow, int h, bool alive) : fight(pow, h){
    name = n;
    isalive = alive;
}

void Player :: take_item(string item){
    inventory.push_back(item);
}

void Player :: show_inventory(){
    if(inventory.empty()){
        cout << "You have nothing in your inventory\n";
    }
    else{
        for(size_t i = 0; i< inventory.size();i++){
            cout << "You have:\n";
            cout << i+1 << ". " << inventory[i] << endl;
        }
    }
}

void Player :: atk_dmg(int damage){
    hp -= damage;

    if(hp < 0){
        hp = 0;
    }

    cout << endl;
    cout << "You took " << damage << " damage" << endl;
    cout << "Remaining Health: " << hp << endl;
}

void Player :: use_item(int choice){
    
    hp += inventory[choice-1].getHeal();
    cout << "Used " << inventory[choice - 1].getName() << " and healed " << inventory[choice-1].getHeal() << " HP!\nRemaining Health: " << hp << endl;
    inventory.erase(inventory.begin() + (choice-1));

}

void Player :: power(int atkpower){
    atk_pow = atkpower;
}

void Player :: isdefeated(){
    isalive = false;
}
