// Class definition for X_O_Board class
// Author:  Mohammad ali
// Date:    10/12/2023
// Version: 1
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "../include/BoardGame_Classes.hpp"
using namespace std;

//////////////////////////////////////////////////////
G3::G3()
{
    n_rows = n_cols = 5;
    board = new char *[n_rows];
    for (int i = 0; i < n_rows; i++)
    {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = '.';
    }
}

bool G3::update_board(int x, int y, char mark)
{
    if (!(x < 0 || x > 4 || y < 0 || y > 4) && (board[x][y] == '.'))
    {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}

void G3::display_board()
{
//    system("cls");

    for (int i : {0, 1, 2, 3, 4})
    {
        cout << "\n| ";
        for (int j : {0, 1, 2, 3, 4})
        {
            cout << "(" << i << "," << j << ")";
            cout << setw(4) << board[i][j] << " |";
        }
        cout << "\n----------------------------------------------------------";
    }
    cout << endl;
}

bool G3::is_winner()
{
    int nx = 0, no = 0;

    if (n_moves == 25)
    {
        // check row
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == 'X' and board[i][j + 1] == 'X' and board[i][j + 2] == 'X')
                {
                    nx++;
                }
                else if (board[i][j] == 'O' and board[i][j + 1] == 'O' and board[i][j + 2] == 'O')
                {
                    no++;
                }
            }
        }
        // check colum
        for (int j = 0; j < 5; j++)
        {
            for (int i = 0; i < 3; i++)
            {
                if (board[i][j] == 'X' and board[i + 1][j] == 'X' and board[i + 2][j] == 'X')
                {
                    nx++;
                }
                else if (board[i][j] == 'O' and board[i + 1][j] == 'O' and board[i + 2][j] == 'O')
                {
                    no++;
                }
            }
        }
        // check trig up
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == 'X' and board[i + 1][j + 1] == 'X' and board[i + 2][j + 2] == 'X')
                {
                    nx++;
                }
                else if (board[i][j] == 'O' and board[i + 1][j + 1] == 'O' and board[i + 2][j + 2] == 'O')
                {
                    no++;
                }
            }
        }

        for (int j = 2; j < 5; j++)
        {
            for (int i = 2; i < 5; i++)
            {
                if (board[i][j] == 'X' and board[i - 1][j + 1] == 'X' and board[i - 2][j + 2] == 'X')
                {
                    nx++;
                }
                else if (board[i][j] == 'O' and board[i - 1][j + 1] == 'O' and board[i - 2][j + 2] == 'O')
                {
                    no++;
                }
            }
        }

        if (nx != no)
        {
            if (nx > no)
            {
                cout << "X win\n";
            }
            else
            {
                cout << "O win\n";
            }
            return true;
        }
    }

    return false;
}

bool G3::is_draw()
{
    return (n_moves == 25 && !is_winner());
}

bool G3::game_is_over()
{
    return n_moves >= 25;
}
int G3::get_n_rows()
{
    return n_rows;
}
int G3::get_n_moves()
{
    return n_moves;
}
char **G3::get_board()
{
    return board;
}
