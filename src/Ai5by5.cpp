#include <iostream>
#include <random>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "../include/BoardGame_Classes.hpp"
using namespace std;

Ai5by5::Ai5by5(char symbol) : AiPlayer(symbol) {}

void Ai5by5::get_move(int &x, int &y, char **&myboard)
{
    int bestScore = -100;
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
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

int Ai5by5::minimax(int depth, bool isMaximizing, char **&board, int alpha, int beta)
{
    int res;
    res = status(board);
    if (res != 1)
        return res;
    cout << depth << endl;
    if (isMaximizing)
    {
        int ourbestcscore = -100;
        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < 5; ++j)
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
        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < 5; ++j)
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

int Ai5by5::status(char **&board)
{
    int nx = 0, no = 0, n_moves = 0;
    //    return 2;
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            n_moves += board[i][j] != '.';
        }
    }
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

        if (nx == no)
        {
            return 0;
        }
        else if (nx > no)
        {
            return -2;
        }
        else
        {
            return 2;
        }
    }
    return 1;
}
