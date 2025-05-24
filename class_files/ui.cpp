#include  "ui.h"
#include <iostream>
#include<string>
using namespace std;

ui :: ui(string name){
    player_name = name;
}

void ui :: startermsg(){
    cout << "\nIn the Heart of the world, hidden from prying eyes, lay the ancient city af Zerzura. Legends spoke of a \nmagnificent crown hidden within its walls, waiting for the worthy adventurer\n"+player_name + ", a curious and determined treasure hunter, have braved the jungle's dangers to find this lost city.\n\n"+"The heavy gates creak shut behind you. Ahead, crumbling stalls line a dusty marketplace.\n\n" ;
}


int ui :: chest_choice(){
    int choice;
    
    cout << "\n\nWhat would you like to do?\n1. Approach the chest\n2. Go to the next area\nEnter your choice: ";
    cin >> choice;
    
    return choice;
}

void ui :: enterContinue(){
    cout << "\nPress Enter to continue: ";
    cin.ignore();
    cin.get();
}

void ui :: market_desc(){
    cout << "The air is thick with the scent of dust and decay. Whispers seem to echo from the stone walls, remnants of a city long forgotten.\nCrumbling stalls lean into the street, their wares lost to time.\nIn the distance, something catches your eye, a lone chest resting beneath a broken archway, its surface covered in moss and strange carvings.";
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

void ui :: hollowVault_sanctum_exit(string exitChoice){
    if (exitChoice == "north"){
        cout << "You step out of the hollow vault and into a quiet chamber where glowing glyphs line the walls.\n Whispers drift through the air , the forgotten truths of Zerzura, waiting to be uncovered.";
    }
}

void ui :: chamberofTrials_desc(){
    cout << "You step into a quiet, dimly lit hall. Faint carvings cover the walls, telling stories long forgotten.\nIn the center, strange symbols line the floor, and ancient mechanisms sit silently, waiting to be solved.\nThe air hums with mystery , the only way forward is through wit, not strength.\n"<< endl;
}

void ui :: chamberofTrials_exit(){
    cout << "As the last puzzle locks into place, the chamber rumbles. A section of the wall slides open, revealing a hidden passage shrouded in shadow.\nYour wit has unlocked a secret long lost to time" << endl;
}

void ui :: sanctum_desc(){
    cout << "You enter a dim, silent chamber. Strange symbols glow faintly on the walls.\nAt the center, a lone chest radiates a soft, eerie light waiting";
}

void ui :: taleofZerzura_desc(){
    cout << "As you enter the room, you found a book with some writings in it.\n";

    cout << "Press Enter to continue: ";
    cin.get();

    cout << "\nIn the deepest chamber of Zerzura's temple, a hidden pittrap claims the unwary victims plummet into darkness, their screams swallowed by ancient stone.\nThere, at the edge of oblivion, stands Ryuk, the God of Death: tall and shadowed, his hollow gaze unblinking.\nHe offers a cruel bargain surrender every possession you've gained in the city, and he will restore your life at the chamber's threshold.\nHesitate, and you become one more whisper in his endless domain." << endl;

    cout << "Press Enter to continue: ";
    cin.get();
}

void ui :: trapRoom_desc(){
    cout << "As you get closer to the crown, all of a sudden bunch of arrows start coming to you.\nTurns out this is the trap, that book was talking about.\nYou Died!";
    enterContinue();
    cout << "You awaken before Ryuk, the shadowed God of Passage, whose hollow gaze demands, 'Surrender all of your possession'\n";
}

void ui :: chamberofBlades_desc(){
    cout << "The Chamber of Blades hums with danger. From the dark, Varek the Crimson Duelist emerges, his blades thirsting for battle.\n";
}

void ui :: chamberofBlades_awards(){
    cout << "In his stead lie a god apple, capable of resorting to full health, and a diamond sword\n";
}

void ui :: vaultofZerzura_desc(){
    cout << "In the Vault of Zerzura, the legendary crown glows in the darkness.\nBut before it stands Azrith, Guardian of the Crown silent, immovable, eternal. To claim the prize, you must defeat him.";
}

void ui :: gameEnd(){
    cout << "The Vault of Zerzura falls silent. You step forward, your hand closing around the Crown , a symbol of triumph. The ancient city's legend lives again, through you.\n" << endl;

    cout << "Press Enter to continue: ";
    cin.get();

    cout << "THE END!\nThanks for Playing!";
}