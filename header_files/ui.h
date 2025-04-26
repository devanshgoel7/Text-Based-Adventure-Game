#ifndef UI_H
#define UI_H

#include <iostream>
using namespace std;

class ui{
    string player_name;

    public:
        ui(string name);

        void startermsg();
        int chest_choice();
        void enterContinue();

        void market_desc();
        void market_exit(string exitChoice);

        void hallofEchoes_desc();
        void hallofEchoes_awards();

        void hollowVault_desc();
        void hollowVault_sanctum_exit(string exitChoice);

        void chamberofTrials_desc();
        void chamberofTrials_exit();

        void sanctum_desc();

        void taleofZerzura_desc();

        void trapRoom_desc();

        void chamberofBlades_desc();
        void chamberofBlades_awards();

        void vaultofZerzura_desc();

        void gameEnd();
};

#endif