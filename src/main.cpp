// This file is the main file of the project that call all games and run them
//  author1:  Abulrahman Salah
//  author2:  Ahmed osama
//  author3:  mohamed ali
//  Date:    6/12/2023

#include <iostream>
#include "../include/BoardGame_Classes.hpp"
#include "GameManager.cpp"
#include "Player.cpp"
#include "RandomPlayer.cpp"
#include "Connect_Four_Board.cpp"
#include "X_O_Board.cpp"
#include "3by3X_O_Board.cpp"
#include "pyramic_X_O_Board.cpp"
#include "AiPlayer.cpp"
#include "AiPyramic.cpp"
#include "3by3.cpp"
#include "Aiconnect4.cpp"
#include "Ai5by5.cpp"

using namespace std;
int main()
{

    cout << "Welcome to FCAI Game Menu. :)\n";
    while (true)
    {
        cout << "Please choose the game you want to play:\n";
        cout << "1- pyramic_X_O\n";
        cout << "2- Connect_Four\n";
        cout << "3- 5*5 X_O\n";
        cout << "4- 3*3 X_O\n";
        cout << "5- Exit\n";
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            cout << "Welcome to pyramic_X_O game\n";
            cout << "Choose if you want to play with computer or with another player.\n\n";
            cout << "Press 1 if you want to play with computer.\n";
            cout << "Press 2 if you want to play with another player.\n";
            cout << "Press 3 if you want to play with Ai.\n";
            cout << "Press 4 to go back to the main menu.\n";
            int choice2;
            cin >> choice2;
            if (choice2 == 1)
            {
                cout << "Choose the symbol you want to play with.\n";
                cout << "Press 1 if you want to play with X.\n";
                cout << "Press 2 if you want to play with O.\n";
                int symbol;
                cin >> symbol;
                if (symbol == 1)
                {
                    Player *players[2];
                    players[0] = new Player(1, 'X');
                    players[1] = new RandomPlayer('O', 4);
                    GameManager pyramic_X_O_game(new pyramic_X_O_Board(), players);
                    pyramic_X_O_game.run();
                    system("pause");
                }
                else if (symbol == 2)
                {
                    Player *players[2];
                    players[0] = new Player(1, 'O');
                    players[1] = new RandomPlayer('X', 4);
                    GameManager pyramic_X_O_game(new pyramic_X_O_Board(), players);
                    pyramic_X_O_game.run();
                    system("pause");
                }
                else
                {
                    cout << "Invalid input.\n";
                }
            }
            else if (choice2 == 2)
            {
                cout << "Choose the symbol you want to play with.\n";
                cout << "Press 1 if you want to play with X.\n";
                cout << "Press 2 if you want to play with O.\n";
                int symbol;
                cin >> symbol;
                if (symbol == 1)
                {
                    Player *players[2];
                    players[0] = new Player(1, 'X');
                    players[1] = new Player(2, 'O');
                    GameManager pyramic_X_O_game(new pyramic_X_O_Board(), players);
                    pyramic_X_O_game.run();
                    system("pause");
                }
                else if (symbol == 2)
                {
                    Player *players[2];
                    players[0] = new Player(1, 'O');
                    players[1] = new Player(2, 'X');
                    GameManager pyramic_X_O_game(new pyramic_X_O_Board(), players);
                    pyramic_X_O_game.run();
                    system("pause");
                }
                else
                {
                    cout << "Invalid input.\n";
                }
            }
            else if (choice2 == 3)
            {

                Player *players[2];
                players[0] = new Player(1, 'X');
                players[1] = new AiPyramic('O');
                GameManager pyramic_X_O_game(new pyramic_X_O_Board(), players);
                pyramic_X_O_game.run();
                system("pause");
            }
            else if (choice2 == 4)
            {
                continue;
            }
            else
            {
                cout << "Invalid input.\n";
            }
        }
        else if (choice == 2)
        {
            cout << "Welcome to Connect_Four game\n";
            cout << "Choose if you want to play with computer or with another player.\n\n";
            cout << "Press 1 if you want to play with computer.\n";
            cout << "Press 2 if you want to play with another player.\n";
            cout << "Press 3 if you want to play with Ai.\n";
            cout << "Press 4 to go back to the main menu.\n";
            int choice2;
            cin >> choice2;
            if (choice2 == 1)
            {
                cout << "Choose the symbol you want to play with.\n";
                cout << "Press 1 if you want to play with X.\n";
                cout << "Press 2 if you want to play with O.\n";
                int symbol;
                cin >> symbol;
                if (symbol == 1)
                {
                    Player *players[2];
                    players[0] = new Player(1, 'X');
                    players[1] = new RandomPlayer('O', 7);
                    GameManager connect_four_game(new connect_four_board(), players);
                    connect_four_game.connect_four_run();
                    system("pause");
                }
                else if (symbol == 2)
                {
                    Player *players[2];
                    players[0] = new Player(1, 'O');
                    players[1] = new RandomPlayer('X', 7);
                    GameManager connect_four_game(new connect_four_board(), players);
                    connect_four_game.connect_four_run();
                    system("pause");
                }
                else
                {
                    cout << "Invalid input.\n";
                }
            }
            else if (choice2 == 2)
            {
                cout << "Choose the symbol you want to play with.\n";
                cout << "Press 1 if you want to play with X.\n";
                cout << "Press 2 if you want to play with O.\n";
                int symbol;
                cin >> symbol;
                if (symbol == 1)
                {
                    Player *players[2];
                    players[0] = new Player(1, 'X');
                    players[1] = new Player(2, 'O');
                    GameManager connect_four_game(new connect_four_board(), players);
                    connect_four_game.connect_four_run();
                    system("pause");
                }
                else if (symbol == 2)
                {
                    Player *players[2];
                    players[0] = new Player(1, 'O');
                    players[1] = new Player(2, 'X');
                    GameManager connect_four_game(new connect_four_board(), players);
                    connect_four_game.connect_four_run();
                    system("pause");
                }
                else
                {
                    cout << "Invalid input.\n";
                }
            }
            else if (choice2 == 3)
            {
                Player *players[2];
                players[0] = new Player(1, 'X');
                players[1] = new Aiconnect4('O');
                GameManager connect_four_game(new connect_four_board(), players);
                connect_four_game.connect_four_run();
                system("pause");
            }
            else if (choice2 == 4)
            {
                continue;
            }

            else
            {
                cout << "Invalid input.\n";
            }
        }
        else if (choice == 3)
        {
            cout << "Welcome to 5*5 X_O game\n";
            cout << "Choose if you want to play with computer or with another player.\n\n";
            cout << "Press 1 if you want to play with computer.\n";
            cout << "Press 2 if you want to play with another player.\n";
            cout << "Press 3 if you want to play with Ai.\n";
            cout << "Press 4 to go back to the main menu.\n";
            int choice2;
            cin >> choice2;
            if (choice2 == 1)
            {
                cout << "Choose the symbol you want to play with.\n";
                cout << "Press 1 if you want to play with X.\n";
                cout << "Press 2 if you want to play with O.\n";
                int symbol;
                cin >> symbol;
                if (symbol == 1)
                {
                    Player *players[2];
                    players[0] = new Player(1, 'X');
                    players[1] = new RandomPlayer('O', 5);
                    GameManager X_O_game(new G3(), players);
                    X_O_game.run();
                    system("pause");
                }
                else if (symbol == 2)
                {
                    Player *players[2];
                    players[0] = new Player(1, 'O');
                    players[1] = new RandomPlayer('X', 5);
                    GameManager X_O_game(new G3(), players);
                    X_O_game.run();
                    system("pause");
                }
                else
                {
                    cout << "Invalid input.\n";
                }
            }
            else if (choice2 == 2)
            {
                cout << "Choose the symbol you want to play with.\n";
                cout << "Press 1 if you want to play with X.\n";
                cout << "Press 2 if you want to play with O.\n";
                int symbol;
                cin >> symbol;
                if (symbol == 1)
                {
                    Player *players[2];
                    players[0] = new Player(1, 'X');
                    players[1] = new Player(2, 'O');
                    GameManager X_O_game(new G3(), players);
                    X_O_game.run();
                    system("pause");
                }
                else if (symbol == 2)
                {
                    Player *players[2];
                    players[0] = new Player(1, 'O');
                    players[1] = new Player(2, 'X');
                    GameManager X_O_game(new G3(), players);
                    X_O_game.run();
                    system("pause");
                }
                else
                {
                    cout << "Invalid input.\n";
                }
            }
            else if (choice2 == 3)
            {
                Player *players[2];
                players[0] = new Player(1, 'X');
                players[1] = new Ai5by5('O');
                GameManager X_O_game(new G3(), players);
                X_O_game.run();
                system("pause");
            }
            else if (choice2 == 4)
            {
                continue;
            }

            else
            {
                cout << "Invalid input.\n";
            }
        }
        else if (choice == 4)
        {
            cout << "Welcome to 3*3 X_O game\n";
            cout << "Choose if you want to play with computer or with another player.\n\n";
            cout << "Press 1 if you want to play with computer.\n";
            cout << "Press 2 if you want to play with another player.\n";
            cout << "Press 3 if you want to play with Ai.\n";
            cout << "Press 4 to go back to the main menu.\n";
            int choice2;
            cin >> choice2;
            if (choice2 == 1)
            {
                cout << "Choose the symbol you want to play with.\n";
                cout << "Press 1 if you want to play with X.\n";
                cout << "Press 2 if you want to play with O.\n";
                int symbol;
                cin >> symbol;
                if (symbol == 1)
                {
                    Player *players[2];
                    players[0] = new Player(1, 'X');
                    players[1] = new RandomPlayer('O', 3);
                    GameManager X_O_game(new X_O_Board(), players);
                    X_O_game.run();
                    system("pause");
                }
                else if (symbol == 2)
                {
                    Player *players[2];
                    players[0] = new Player(1, 'O');
                    players[1] = new RandomPlayer('X', 3);
                    GameManager X_O_game(new X_O_Board(), players);
                    X_O_game.run();
                    system("pause");
                }
                else
                {
                    cout << "Invalid input.\n";
                }
            }
            else if (choice2 == 2)
            {
                cout << "Choose the symbol you want to play with.\n";
                cout << "Press 1 if you want to play with X.\n";
                cout << "Press 2 if you want to play with O.\n";
                int symbol;
                cin >> symbol;
                if (symbol == 1)
                {
                    Player *players[2];
                    players[0] = new Player(1, 'X');
                    players[1] = new Player(2, 'O');
                    GameManager X_O_game(new X_O_Board(), players);
                    X_O_game.run();
                    system("pause");
                }
                else if (symbol == 2)
                {
                    Player *players[2];
                    players[0] = new Player(1, 'O');
                    players[1] = new Player(2, 'X');
                    GameManager X_O_game(new X_O_Board(), players);
                    X_O_game.run();
                    system("pause");
                }
                else
                {
                    cout << "Invalid input.\n";
                }
            }
            else if (choice2 == 3)
            {
                Player *players[2];
                players[0] = new Player(1, 'X');
                players[1] = new Ai3by3('O');
                GameManager X_O_game(new X_O_Board(), players);
                X_O_game.run();
                system("pause");
            }
            else if (choice2 == 4)
            {
                continue;
            }

            else
            {
                cout << "Invalid input.\n";
            }
        }
        else if (choice == 5)
        {
            cout << "Thank you for playing with us. :)\n";
            break;
        }
        else
        {
            cout << "Invalid input.\n";
        }
    }
}