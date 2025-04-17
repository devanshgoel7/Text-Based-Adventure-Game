#include "fight.h"
#include "player.h"
#include "enemy.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


int fight :: attack(int atk_pow){

    int random = (rand() % 10) + 1;

    return atk_pow*random;
}

void fight :: atk_dmg(int hp, int damage, string name){
    hp -= damage;

    cout << name << " took " << damage << " damage" << endl;
    cout << "Remaining Health: " << hp << endl;
}

int fight :: defence(int atk_dmg){
    srand(time(0));
    float random = (rand() % 60) + 1;
    int new_dmg = atk_dmg - (atk_dmg*(random/100));

    return new_dmg;
}


bool fight ::  battle(Enemy &e, Player &p, bool gameloop){
    bool loop = true;
    int dmg;
    int def_dmg;
    int enemy_dmg;
    int item_choice;

    while(loop){
        if(e.getHP() != 0 || p.getHP() != 0){
            int choice;
            cout << "\nWhat do you want to do\n1. Attack\n2. Defence\n3. Use inventory\nEnter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                
                dmg = attack(p.getpow());
                e.atk_dmg(dmg);
                if(e.getHP() == 0){
                    cout << "With a final blow, the " << e.getname() << " collapses!";
                    loop = false;
                    gameloop = true;
                    break;
                }

                cout << endl;
                cout << e.getname() << " fights back!";
                enemy_dmg = attack(e.getpow());
                p.atk_dmg(enemy_dmg);
                if(p.getHP() == 0){
                    cout << "\nYou Died!\nGame Over\nThanks for playing";
                    loop = false;
                    gameloop = false;
                    break;
                }
                break;
            
            case 2:
                
                cout << endl;
                cout << e.getname() << " Attacks!";
                dmg = attack(e.getpow());
                def_dmg = defence(dmg);

                p.atk_dmg(def_dmg);
                if(p.getHP() == 0){
                    cout << "\nYou Died!\nGame Over\nThanks for playing";
                    loop = false;
                    gameloop = false;
                    break;
                }
                else
                    break;

            case 3:
                
                cout << "\nWhich item do you want to use\n";
                p.show_inventory();
                cout << "\nEnter your choice: ";
                cin >> item_choice;
                p.use_item(item_choice);
                break;
            
            default:
                cout << "\nPlease only choose from 1 or 2\n";
                continue;
            }


        }
    }
    return gameloop;
}