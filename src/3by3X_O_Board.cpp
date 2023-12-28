// Class definition for X_O_Board class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "../include/BoardGame_Classes.hpp"
using namespace std;

X_O_Board::X_O_Board()
{
    n_rows = n_cols = 3;
    board = new char *[n_rows];
    for (int i = 0; i < n_rows; i++)
    {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = '.';
    }
}

bool X_O_Board::update_board(int x, int y, char mark)
{
    if (!(x < 0 || x > 2 || y < 0 || y > 2) && (board[x][y] == '.'))
    {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}

void X_O_Board::display_board()
{
    //    system("cls");
    for (int i : {0, 1, 2})
    {
        cout << "\n| ";
        for (int j : {0, 1, 2})
        {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board[i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}

bool X_O_Board::is_winner()
{

    // check row
    for (int i = 0; i < n_rows; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '.')
            return true;
    }

    // check col
    for (int i = 0; i < n_cols; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '.')
            return true;
    }

    // check diagonal
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '.')
        return true;

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '.')
        return true;

    return false;
}

bool X_O_Board::is_draw()
{
    return (n_moves == 9 && !is_winner());
}

bool X_O_Board::game_is_over()
{
    return n_moves >= 9;
}

int X_O_Board::get_n_rows()
{
    return n_rows;
}
int X_O_Board::get_n_moves()
{
    return n_moves;
}
char **X_O_Board::get_board()
{
    return board;
}
