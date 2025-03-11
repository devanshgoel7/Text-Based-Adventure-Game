#ifndef AREA_H
#define AREA_H

#include <iostream>
#include <string>

using namespace std;

class Area {
    private:
    string name;
    string desc;
    bool locked;
    bool enemey;
    bool chest;
    Area* north;
    Area* south;
    Area* east;
    Area* west;

public:

    Area();

    Area(string n, string d, bool lock, bool ene, bool c);

    void setExit(Area* north, Area* south, Area* east, Area* west);

    Area* getExit(string direction);

    void displayInfo();

    void setdesc(string newdesc);

    bool hasEnemy();

    bool hasChest();

};

#endif 
