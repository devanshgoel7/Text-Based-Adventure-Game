#ifndef AREA_H
#define AREA_H

#include <iostream>
#include <string>

using namespace std;

class Area {
    private:
    string name;
    bool locked;
    bool enemy;
    bool chest;
    Area* north;
    Area* south;
    Area* east;
    Area* west;

public:

    Area();

    Area(string n, bool lock, bool ene, bool c);

    void setExit(Area* north, Area* south, Area* east, Area* west);

    Area* getExit(string direction);

    string displayInfo();

    bool hasEnemy();

    bool hasChest();

};

#endif 
