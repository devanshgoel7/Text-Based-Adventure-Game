#include <iostream>
#include "area.h"
using namespace std;

int main()
{
    Area marketplace("MarketPlace","a desc ig",false,false,true);
    Area temple("Temple","a desc of temple ig",false,false,true);
    marketplace.setExit(&temple,nullptr,nullptr,nullptr);
    temple.setExit(nullptr,nullptr,nullptr,nullptr);
    
    Area* current_room = &marketplace;
    current_room->displayInfo();

    current_room = current_room->getExit("north");
    current_room->displayInfo();

    return 0;
}