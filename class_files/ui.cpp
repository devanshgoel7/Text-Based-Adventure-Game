#include "ui.h"
#include <iostream>

using namespace std;

ui :: ui(string name){
    player_name = name;
}

void ui :: startermsg(){

    cout << "\nIn the Heart of the world, hidden from prying eyes, lay the ancient city af Zerzura. Legends spoke of a" << endl << "magnificent crown hidden within its walls, waiting for the worthy adventurer\n" << endl;

    cout << player_name << ", a curious and determined treasure hunter, have braved the jungle's dangers to find this lost city.\n" << endl;

    cout << "The heavy gates creak shut behind you. Ahead, crumbling stalls line a dusty marketplace.\n" << endl;
}

void ui :: market_desc(){
    cout << "The air is thick with the scent of dust and decay. Whispers seem to echo from the stone walls, remnants of a city long forgotten.\nCrumbling stalls lean into the street, their wares lost to time.\nIn the distance, something catches your eye, a lone chest resting beneath a broken archway, its surface covered in moss and strange carvings.";
}

int ui :: market_choice(){
    int choice;

    cout << "\n\nWhat would you like to do?\n1. Approach the chest\n2. Go to the next area\nEnter your choice: ";
    cin >> choice;

    return choice;
}

void ui :: market_exit(string exitChoice){
    if (exitChoice == "north"){
        cout <<  "As you navigate through the narrow alley, you come across a huge grand stone structure 'THE TEMPLE OF ZERZURA' \nYou push open the heavy stone doors and step inside. Behind you, they grind shut, there's no turning back.\n" << endl;
    }

}

void ui :: hallofEchoes_desc(){
    cout << "You enter a cold, silent chamber where torchlight flickers against dark stone walls. Faded carvings of forgotten rulers stare back at you.\nThe air feels heavy then, a distant clank. A Echo Warden steps from the shadows, blade raised.\nHe approaches you, it's time to FIGHT\n";
}

void ui :: hallofEchoes_awards(){
    cout << "\nIn its place, a fresh apple, gift for your triumph.\nPress Enter to continue: ";
    cin.ignore();
    cin.get();
}

void ui :: hollowVault_desc(){
    cout << "You step into the Hollow Vault , a cold, silent chamber carved from ancient stone.\nAt the center, a lone chest sits atop a worn pedestal, its surface dusty and sealed with an old iron lock. \nThe faint glint of treasure teases you from within, but the chest won't give in easily.";
}