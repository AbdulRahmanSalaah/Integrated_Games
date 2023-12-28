#include <iostream>
#include <random>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "../include/BoardGame_Classes.hpp"
using namespace std;

Ai3by3::Ai3by3(char symbol) : AiPlayer(symbol)
{
}

void Ai3by3::get_move(int &x, int &y, char **&myboard)
{
    int bestScore = -100;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (myboard[i][j] == '.')
            {
                myboard[i][j] = 'O';
                int currantScore = minimax(0, false, myboard, -100, 100);
                myboard[i][j] = '.';
                if (currantScore > bestScore)
                {
                    bestScore = currantScore;
                    x = i;
                    y = j;
                }
            }
        }
    }
}

int Ai3by3::minimax(int depth, bool isMaximizing, char **&board, int alpha, int beta)
{
    int res;
    res = status(board);
    if (res != 1)
        return res;

    if (isMaximizing)
    {
        int ourbestcscore = -100;
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
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
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
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

int Ai3by3::status(char **&board)
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '.')
            if (board[i][0] == 'O')
                return 2;
            else
                return -2;
    }

    // check col
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '.')
            if (board[0][i] == 'O')
                return 2;
            else
                return -2;
    }

    // check diagonal
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '.')
    {
        if (board[0][0] == 'O')
            return 2;
        else
            return -2;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '.')
    {
        if (board[0][2] == 'O')
            return 2;
        else
            return -2;
    }

    int cnt = 0;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cnt += board[i][j] != '.';
        }
    }

    if (cnt == 9)
        return 0;

    return 1;
}