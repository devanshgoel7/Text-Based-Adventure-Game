#include "area.h"
#include <iostream>
using namespace std;

Area::Area() {
    locked = false;
    enemy = false;
    chest = false;
}

Area::Area(string n, bool lock, bool ene, bool c) {
    name = n;
    locked = lock;
    enemy = ene;
    chest = c;
}

void Area::setExit(Area* n, Area* s, Area* e, Area* w) {
    north = n;
    south = s;
    east = e;
    west = w;
}

Area* Area::getExit(string dir) {
    if (dir == "north") return north;
    if (dir == "south") return south;
    if (dir == "east") return east;
    if (dir == "west") return west;
    return nullptr;
}

string Area::displayInfo() {
    string exit_choice;

    cout << "\nAvailable exits: ";
    if (north) cout << "north ";
    if (south) cout << "south ";
    if (east) cout << "east ";
    if (west) cout << "west ";
    cout << endl;

    while(true){
        cout << "Where would you like to exit:\nEnter your choice: ";
        cin >> exit_choice;
        if (exit_choice != "north" && exit_choice != "south" && exit_choice != "east" && exit_choice != "west"){
            cout << "\nPlease enter only from the above choices!\n";
            continue;
        }
        break;
    }
    return exit_choice;
}

bool Area::hasEnemy() {
    return enemy;
}

bool Area::hasChest() {
    return chest;
}

