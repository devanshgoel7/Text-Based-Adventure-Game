#include "header_files/game_headers.h"
#include <iostream>
#include "cstdlib"
#include "ctime"
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
    Enemy e1("Echo Warden",100,1,false);
    Enemy e2("Varek",100,2,false);
    Enemy e3("Azrith",200,4,false);

    // fight class
    fight bt;

    // item class
    atk woodenSword("Wooden Sword",2);
    atk stoneSword("Stone Sword", 3);
    atk ironSword("Iron Sword", 4);
    atk diamondSword("Diamond Sword", 5);
    heal bread("Bread",15);
    heal apple("Apple",25);
    heal carrot("Carrot",30);
    heal mushroom_stew("Mushroom Stew",50);
    heal god_apple("God Apple", 100);
    
    // Puzzle class
    puzzles puzzle;

    // Area class

    Area marketplace("Market Place",false,false,true);
    Area hall_of_echoes("Hall of Echoes",false,true,true);
    Area chamber_of_trials("Chamber of Trials", false,false,false);
    Area hollow_vault("The Hollow Vault",false,false,true);
    Area tales_of_zerzura("Tales of Zerzura",false,false,false);
    Area veiled_sanctum("Veiled Sanctum",false,false,true);
    Area trapRoom("Trap Room",false,false,false);
    Area chamber_of_blades("Chamber of Blades", false, true , true);
    Area vault_of_zerzura("Vault of Zerzura", false,false,true);

    marketplace.setExit(&hall_of_echoes,nullptr,nullptr,nullptr);
    hall_of_echoes.setExit(nullptr,nullptr,&hollow_vault,&chamber_of_trials);
    chamber_of_trials.setExit(nullptr,nullptr,nullptr,&veiled_sanctum);
    hollow_vault.setExit(&tales_of_zerzura,nullptr,nullptr,nullptr);
    veiled_sanctum.setExit(&tales_of_zerzura,nullptr,nullptr,nullptr);
    tales_of_zerzura.setExit(&trapRoom,&chamber_of_blades,nullptr,nullptr);
    chamber_of_blades.setExit(nullptr,nullptr,nullptr,&vault_of_zerzura);

    Area* current_room;
    
    // MARKET PLACE
    current_room = &marketplace;
    u.market_desc();
    
    int gameloop = true;
    while(gameloop){
        string exitChoice;

        // 1ST ROOM
        int market_choice = u.chest_choice();
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
                    p.power(woodenSword.getPow());
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
                        p.power(woodenSword.getPow());
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
        u.enterContinue();
        u.hallofEchoes_desc();
        gameloop = bt.battle(e1,p,gameloop); // FIGHT FUNCTION 
        if (gameloop == false){
            break;
        }

        u.hallofEchoes_awards();
        p.take_item(apple);
        exitChoice = current_room->displayInfo();

        if (exitChoice == "west"){
            // 1ST ROOM (left)
            current_room = &chamber_of_trials;
            u.enterContinue();
            u.chamberofTrials_desc();

            bool puzzle_solved = false;
            int puzzle_count = 3;

            for (int i = 0; i<puzzle_count;i++){
                int random = (rand() % 7) + 1;
                while(true){
                    puzzle_solved = puzzle.getpuzzle(random);

                    if(!puzzle_solved){
                        cout << "\nWrong Answer!\nTry Again\n" << endl;
                        continue;
                    }
                    break;
                }
            }
            
            u.chamberofTrials_exit();

            // 2ND ROOM (left)
            current_room = &veiled_sanctum;
            u.enterContinue();
            u.sanctum_desc();
            int sanctum_choice = u.chest_choice();

            while(true){

                switch (sanctum_choice)
                {
                    case 1:
                        int sanctum_choice2;
                        cout << "\nYou walk cautiously towards the chest. You found:\n> A Iron Sword\n> A Mushroom Stew\n\nWould you like to:\n1. Take all the items\n2. Choose a specific item\nEnter your choice: ";
                        
                        cin >> sanctum_choice2;
                        switch (sanctum_choice2)
                        {
                        case 1:
                            cout << "You have successfully equiped all the items" << endl;
                            p.take_item(mushroom_stew);
                            p.power(ironSword.getPow());
                            exitChoice = current_room->displayInfo();
                            u.hollowVault_sanctum_exit(exitChoice);
                            current_room = &tales_of_zerzura;
                            break;

                        case 2:
                            int sanctum_choice3;
                            cout << "\nWhich item would you like to take:\n1. Iron Sword\n2. Mushroom Stew\nEnter your choice: ";
                            cin >> sanctum_choice3;

                            switch (sanctum_choice3)
                            {
                            case 1:
                                cout << "You successfully took the sword!" << endl;
                                p.power(ironSword.getPow());
                                exitChoice = current_room->displayInfo();
                                u.hollowVault_sanctum_exit(exitChoice);
                                current_room = &tales_of_zerzura;
                                break;
                            
                            case 2:
                                cout << "You successfully took the Mushroom Stew" << endl;
                                p.take_item(mushroom_stew);
                                exitChoice = current_room->displayInfo();
                                u.hollowVault_sanctum_exit(exitChoice);
                                current_room = &tales_of_zerzura;
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
                        u.hollowVault_sanctum_exit(exitChoice);
                        current_room = &tales_of_zerzura;
                        break;

                    default:
                        cout << "\nPlease only choose from 1 or 2";
                        continue;
                }
                break;
            }


        }
        else if(exitChoice == "east"){
            // 1ST ROOM (Right)
            current_room = &hollow_vault;
            u.enterContinue();
            u.hollowVault_desc();

            start_hollowVault_switch:
            int hollowVault_choice = u.chest_choice();
            bool puzzle_loop;
            bool isSolved;
            int randomNo = (rand() % 7) + 1;

            while(true){
                switch(hollowVault_choice){
                    case 1:
                        
                        cout << "\nYou walk cautiously towards the chest, Its locked\nOnly way to open it is to solve a ridde\n";
                        
                        puzzle_loop = true;
                        while(puzzle_loop){
                            
                            isSolved = puzzle.getpuzzle(randomNo);
                            if(isSolved){
                                puzzle_loop = false;
                                cout << "You successfully opened the chest and found a worn stone sword and a carrot simple, but useful for the trials ahead.";

                                int hollowVault_choice2;
                                cout << "\nWould you like to:\n1. Take all the items\n2. Choose a specific item\nEnter your choice: ";
                                cin >> hollowVault_choice2;

                                start_hollowVault_switch2:
                                switch (hollowVault_choice2)
                                {
                                case 1:
                                    cout << "You have successfully equiped all the items" << endl;
                                    p.take_item(carrot);
                                    p.power(stoneSword.getPow());
                                    exitChoice = current_room->displayInfo();
                                    u.hollowVault_sanctum_exit(exitChoice);
                                    current_room = &tales_of_zerzura;
                                    break;

                                case 2:
                                    int hollowVault_choice3;
                                    cout << "\nWhich item would you like to take:\n1. Stone Sword\n2. Carrot\nEnter your choice: ";
                                    cin >> hollowVault_choice3;

                                    start_hollowVault_switch3:
                                    switch (hollowVault_choice3)
                                    {
                                    case 1:
                                        cout << "You successfully took the sword!" << endl;
                                        p.power(stoneSword.getPow());
                                        exitChoice = current_room->displayInfo();
                                        u.hollowVault_sanctum_exit(exitChoice);
                                        current_room = &tales_of_zerzura;
                                        break;
                                    
                                    case 2:
                                        cout << "You successfully took the carrot" << endl;
                                        p.take_item(carrot);
                                        exitChoice = current_room->displayInfo();
                                        u.hollowVault_sanctum_exit(exitChoice);
                                        current_room = &tales_of_zerzura;
                                        break;

                                    default:
                                        cout << "\nPlease only choose from 1 or 2";
                                        goto start_hollowVault_switch3;
                                    }

                                    break;

                                default:
                                    cout << "\nPlease only choose from 1 or 2";
                                    goto start_hollowVault_switch2;
                                }

                                break;
                            }
                            else{
                                cout << "Wrong answer! Try Again\n";
                            }
                    }
                    break;

                    case 2:
                        exitChoice = current_room->displayInfo();
                        u.hollowVault_sanctum_exit(exitChoice);
                        current_room = &tales_of_zerzura;
                        break;

                    default:
                        cout << "\nPlease only choose from 1 or 2";
                        goto start_hollowVault_switch;
                    

                }
                break;
            }

        }

        // 3rd ROOM 
        u.enterContinue();
        u.taleofZerzura_desc();
        exitChoice = current_room->displayInfo();

        if (exitChoice == "north"){
            current_room = &trapRoom;
            u.trapRoom_desc();

            int trapRoom_choice;
            cout << "What do you want to do:\n1. Give all your belongings to Ryuk\n2. Dont give all your belongings\nEnter your choice: ";
            cin >> trapRoom_choice;

            while (true){
                switch (trapRoom_choice)
                {
                case 1:
                    cout << "\nRyuk chuckles, impressed by your spirit. He gives you a wooden sword.\nWith a wave of his hand, he sends you back stripped of your belongings, yet ready to face the temple's final trial.\nHe sends you to the chamber of blades\n";
                    p.emptyInventory();
                    p.power(2);
                    current_room = &chamber_of_blades;
                    break;

                case 2:
                    cout << "Ryuk get angry, and says 'You were never meant to get success in your life, your greedy and never learning behaviour leads you here'\nand after that he absolutely yeet you to the hell\nGame Over\nThanks for Playing!" << endl;
                    gameloop = false;
                    break;
                
                default:
                    cout << "\nPlease choose from 1 and 2 only\n";
                    continue;
                }

                break;
            }    
        }
        else{
            current_room = &chamber_of_blades;
        }

        // 4TH ROOM
        u.enterContinue();
        u.chamberofBlades_desc();
        gameloop = bt.battle(e2,p,gameloop);
        if(gameloop == false){
            break;
        }

        u.chamberofBlades_awards();
        p.take_item(god_apple);
        exitChoice = current_room->displayInfo();

        if(exitChoice == "west"){
            current_room = &vault_of_zerzura;
            u.enterContinue();
            u.vaultofZerzura_desc();
            gameloop = bt.battle(e3,p,gameloop);
            if (gameloop == false){
                break;
            }


            u.gameEnd(); // game end
            gameloop = false;
        }
    } // game loop

    return 0;
}