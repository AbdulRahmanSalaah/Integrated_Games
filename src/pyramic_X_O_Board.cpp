
// Class definition for pyramic_X_O_Board class
// author:  Ahmed osama
// Date:    10/12/2023
// Version: 1

#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <conio.h>
#include <stdlib.h>
#include "../include/BoardGame_Classes.hpp"
using namespace std;

pyramic_X_O_Board::pyramic_X_O_Board()
{
    n_rows = 3;
    n_cols = 5;
    board = new char *[n_rows];
    for (int i = 0; i < n_rows; i++)
    {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = '.';
    }
}

bool pyramic_X_O_Board::update_board(int x, int y, char mark)
{
    vector<pair<int, int>> valid = {{0, 2}, {1, 1}, {1, 2}, {1, 3}, {2, 0}, {2, 1}, {2, 2}, {2, 3}, {2, 4}};

    if (x >= n_rows || y >= n_cols)
        return false;

    if (board[x][y] != '.')
        return false;

    for (auto it : valid)
    {
        if (make_pair(x, y) == it)
        {
            board[x][y] = toupper(mark);
            n_moves++;
            return true;
        }
    }
    return false;
}

void pyramic_X_O_Board::display_board()
{
    //        -----
    // 0       | . |
    //     |---|---|---|
    // 1    | . | . | . |
    // |---|---|---|---|---|
    // 2| . | . | . | . | . |
    // |---|---|---|---|---|
    //  0   1   2   3   4
//    system("cls");
    cout << "         -----" << endl;
    cout << "0        | " << board[0][2] << " |" << endl;
    cout << "     |---|---|---|" << endl;
    cout << "1    |";
    for (int i = 1; i < 4; ++i)
    {
        cout << " " << board[1][i] << " |";
    }
    cout << endl
         << " |---|---|---|---|---|" << endl;
    cout << "2|";
    for (int i = 0; i < 5; ++i)
    {
        cout << " " << board[2][i] << " |";
    }
    cout << endl
         << " |---|---|---|---|---|" << endl;
    cout << "   0   1   2   3   4" << endl;
}

bool pyramic_X_O_Board::is_winner()
{

    // last row
    for (int i = 0; i + 2 < 5; ++i)
    {
        if (board[2][i] == board[2][i + 1] && board[2][i + 1] == board[2][i + 2] && board[2][i] != '.')
            return true;
    }

    // second row
    if (board[1][1] == board[1][2] && board[1][1] == board[1][3] && board[1][1] != '.')
    {
        return true;
    }

    // second cols
    if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[1][2] != '.')
    {
        return true;
    }

    if (board[1][1] == board[2][0] && board[1][1] == board[0][2] && board[1][1] != '.')
    {
        return true;
    }

    if (board[2][4] == board[1][3] && board[1][3] == board[0][2] && board[1][3] != '.')
    {
        return true;
    }
    return false;
}

bool pyramic_X_O_Board::is_draw()
{
    return (n_moves == 9 && !is_winner());
}

bool pyramic_X_O_Board::game_is_over()
{
    return is_draw();
}
int pyramic_X_O_Board::get_n_rows()
{
    return n_rows;
}
int pyramic_X_O_Board::get_n_moves()
{
    return n_moves;
}
char **pyramic_X_O_Board::get_board()
{
    return board;
}
