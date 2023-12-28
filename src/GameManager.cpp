// Class definition for connect_four_GameManager class
// author1:  Abulrahman Salah
// author2:  Ahmed osama
// author3:  mohamed ali
// Date:    6/12/2023

#include <iostream>
#include "../include/BoardGame_Classes.hpp"
using namespace std;

GameManager::GameManager(Board *bPtr, Player *playerPtr[2])
{
    boardPtr = bPtr;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}

void GameManager::run()
{
    int x, y;

    boardPtr->display_board();

    while (!boardPtr->game_is_over())
    {
        for (int i : {0, 1})
        {
            char **myboard = boardPtr->get_board();
            players[i]->get_move(x, y, myboard);
            cout << x << y << endl;
            while (!boardPtr->update_board(x, y, players[i]->get_symbol()))
            {
                if (i == 0)
                    cout << "Invalid move. Please try again: ";

                players[i]->get_move(x, y, myboard);
            }
            boardPtr->display_board();
            if (boardPtr->is_winner())
            {
                cout << players[i]->to_string() << " wins\n";
                return;
            }
            if (boardPtr->is_draw())
            {
                cout << "Draw!\n";
                return;
            }
        }
    }
}

void GameManager::connect_four_run()
{
    boardPtr->display_board();
    int column;
    while (!boardPtr->game_is_over())
    {
        for (int i : {0, 1})
        {
            players[i]->get_connect_move(column);
            while (!boardPtr->update_board(get_available_row(column, boardPtr->get_board(), boardPtr->get_n_rows()), column, players[i]->get_symbol()))
            {
                cout << "Invalid move. Please try again: ";
                players[i]->get_connect_move(column);
            }
            boardPtr->display_board();
            if (boardPtr->is_winner())
            {
                cout << players[i]->to_string() << " is the winner!" << endl;
                return;
            }
            if (boardPtr->is_draw())
            {
                cout << "It's a draw!" << endl;
                return;
            }
        }
    }
}

int GameManager::get_available_row(int column, char **board, int n_rows)
{
    for (int row = n_rows - 1; row >= 0; --row)
    {
        if (board[row][column] == '.')
        {
            return row;
        }
    }
    return -1;
}
