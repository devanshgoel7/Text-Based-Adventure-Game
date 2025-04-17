#include "header_files/game_headers.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));
    // ui class

    string player_name;
    cout << "THE LOST CROWN\n\nEnter your name: ";
    cin >> player_name;

    ui u(player_name);
    u.startermsg();
    
    // Player class
    Player p(player_name,1,100,true);

    // Enemy class
    Enemy e1("Echo Warden",100,2,false);

    // fight class
    fight bt;

    // item class
    item bread("bread",15);

    // Area class

    Area marketplace("Market Place",false,false,true);
    Area hall_of_echoes("Hall of Echoes",false,true,true);
    marketplace.setExit(&hall_of_echoes,nullptr,nullptr,nullptr);
    hall_of_echoes.setExit(nullptr,nullptr,nullptr,nullptr);
    Area* current_room;
    
    // MARKET PLACE
    current_room = &marketplace;
    u.market_desc();
    
    int gameloop = true;
    while(gameloop){

        int market_choice = u.market_choice();
        string exitChoice;
        switch (market_choice)
        {
            case 1:
                int market_choice2;
                cout << "\nYou walk cautiously towards the chest. You found:\n> A wooden sword\n> A piece of bread\n\nWould you like to:\n1. Take all the items\n2. Choose a specific item\nEnter your choice: ";
                
                cin >> market_choice2;
                switch (market_choice2)
                {
                case 1:
                    cout << "You have successfully equiped all the items" << endl;
                    p.take_item(bread);
                    p.power(2);
                    exitChoice = current_room->displayInfo();
                    u.market_exit(exitChoice);
                    current_room = &hall_of_echoes;
                    break;

                case 2:
                    int market_choice3;
                    cout << "\nWhich item would you like to take:\n1. Wooden Sword\n2. Bread\nEnter your choice: ";
                    cin >> market_choice3;

                    switch (market_choice3)
                    {
                    case 1:
                        cout << "You successfully took the sword!" << endl;
                        p.power(2);
                        exitChoice = current_room->displayInfo();
                        u.market_exit(exitChoice);
                        current_room = &hall_of_echoes;
                        break;
                    
                    case 2:
                        cout << "You successfully took the bread" << endl;
                        p.take_item(bread);
                        exitChoice = current_room->displayInfo();
                        u.market_exit(exitChoice);
                        current_room = &hall_of_echoes;
                        break;

                    default:
                        cout << "\nPlease only choose from 1 or 2";
                        continue;
                    }

                    break;

                default:
                    cout << "\nPlease only choose from 1 or 2";
                    continue;
                }

                break;

            case 2:
                exitChoice = current_room->displayInfo();
                u.market_exit(exitChoice);
                current_room = &hall_of_echoes;
                break;

            default:
                cout << "\nPlease only choose from 1 or 2";
                continue;
        }
        
        // 2ND ROOM
        u.hallofEchoes_desc();
        gameloop = bt.battle(e1,p,gameloop); // FIGHT FUNCTION 

    } // game loop

    return 0;
}