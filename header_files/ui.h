#ifndef UI_H
#define UI_H

#include <iostream>
using namespace std;

class ui{
    string player_name;

    public:
        ui(string name);

        void startermsg();

        void market_desc();
        int market_choice();
        void market_exit(string exitChoice);

        void hallofEchoes_desc();
        void hallofEchoes_awards();

        void hollowVault_desc();
};

#endif