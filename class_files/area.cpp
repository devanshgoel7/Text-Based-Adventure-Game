#include <iostream>
#include "area.h"

Area::Area() {
    locked = false;
    enemey = false;
    chest = false;
}

Area::Area(string n, string d, bool lock, bool ene, bool c) {
    name = n;
    desc = d;
    locked = lock;
    enemey = ene;
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

void Area::displayInfo() {
    cout << "You are in: " << name << endl;
    cout << desc << endl;
    
    cout << "Available exits: ";
    if (north) cout << "north ";
    if (south) cout << "south ";
    if (east) cout << "east ";
    if (west) cout << "west ";
    cout << endl;
}

void Area::setdesc(string newdesc) {
    desc = newdesc;
}

bool Area::hasEnemy() {
    return enemey;
}

bool Area::hasChest() {
    return chest;
}
