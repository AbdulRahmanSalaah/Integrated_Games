#include <iostream>
#include <random>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "../include/BoardGame_Classes.hpp"
using namespace std;

Aiconnect4::Aiconnect4(char symbol) : AiPlayer(symbol) {}

void Aiconnect4::get_move(int &x, int &y, char **&myboard)
{
    int bestScore = -100;
    for (int j = 0; j < 7; ++j)
    {
        int i = getrow(myboard, j);
        if (i != -1)
        {
            myboard[i][j] = 'O';
            int currantScore = minimax(0, false, myboard, -100, 100);
            myboard[i][j] = '.';
            cout << "Move: (" << i << ", " << j << "), Score: " << currantScore << endl;
            if (currantScore > bestScore)
            {
                bestScore = currantScore;
                x = i;
                y = j;
            }
        }
    }
}

int Aiconnect4::minimax(int depth, bool isMaximizing, char **&board, int alpha, int beta)
{
    int res;
    res = status(board);
    if (res != 1 || depth >= 10)
        return res;

    if (isMaximizing)
    {
        int ourbestcscore = -100;
        for (int j = 0; j < 7; ++j)
        {
            int i = getrow(board, j);

            if (i != -1)
            {
                if (board[i][j] == '.')
                {
                    board[i][j] = 'O';
                    int Score = minimax(depth + 1, false, board, alpha, beta);
                    board[i][j] = '.';
                    ourbestcscore = max(Score, ourbestcscore);
                    alpha = max(alpha, Score);
                    if (beta <= alpha)
                        break;
                }
            }
        }
        return ourbestcscore;
    }
    else
    {
        int ourbestcscore = 100;
        for (int j = 0; j < 7; ++j)
        {
            int i = getrow(board, j);

            if (i != -1)
            {
                if (board[i][j] == '.')
                {
                    board[i][j] = 'X';
                    int Score = minimax(depth + 1, true, board, alpha, beta);
                    board[i][j] = '.';
                    ourbestcscore = min(Score, ourbestcscore);
                    beta = min(beta, Score);
                    if (beta <= alpha)
                        break;
                }
            }
        }
        return ourbestcscore;
    }
}

int Aiconnect4::status(char **&board)
{
    //    return -2;
    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j <= 7 - 4; ++j)
        {
            if (board[i][j] != '.' && board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] && board[i][j] == board[i][j + 3])
            {
                if (board[i][j] == 'O')
                    return 2;
                else
                    return -2;
            }
        }
    }

    for (int i = 0; i <= 6 - 4; ++i)
    {
        for (int j = 0; j < 7; ++j)
        {
            if (board[i][j] != '.' && board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j] && board[i][j] == board[i + 3][j])
            {
                if (board[i][j] == 'O')
                    return 2;
                else
                    return -2;
            }
        }
    }

    for (int i = 3; i < 6; ++i)
    {
        for (int j = 0; j <= 7 - 4; ++j)
        {
            if (board[i][j] != '.' &&
                board[i][j] == board[i - 1][j + 1] &&
                board[i][j] == board[i - 2][j + 2] &&
                board[i][j] == board[i - 3][j + 3])
            {
                if (board[i][j] == 'O')
                    return 2;
                else
                    return -2;
            }
        }
    }

    for (int i = 0; i <= 6 - 4; ++i)
    {
        for (int j = 0; j <= 7 - 4; ++j)
        {
            if (board[i][j] != '.' &&
                board[i][j] == board[i + 1][j + 1] &&
                board[i][j] == board[i + 2][j + 2] &&
                board[i][j] == board[i + 3][j + 3])
            {
                if (board[i][j] == 'O')
                    return 2;
                else
                    return -2;
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < 7; ++j)
        {
            cnt += board[i][j] != '.';
        }
    }

    if (cnt == 42)
        return 0;
    //    return 2;
    return 1;
}

int Aiconnect4::getrow(char **&board, int y)
{
    for (int row = 5; row >= 0; --row)
    {
        if (board[row][y] == '.')
        {
            cout << "Found empty row at (" << row << ", " << y << ")." << endl;
            return row;
        }
    }
    cout << "No available row in column " << y << "." << endl;
    return -1;
}
