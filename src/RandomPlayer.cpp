// Class definition for connect_four_RandomPlayer class
// Which is a computer player playing randomly
// author1:  Abulrahman Salah
// author2:  Ahmed osama
// author3:  mohamed ali
// Date:    6/12/2023

#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "../include/BoardGame_Classes.hpp"
using namespace std;

RandomPlayer::RandomPlayer(char symbol, int dimension) : Player(symbol)
{
    this->dimension = dimension;
    this->name = "Random Computer Player";
    cout << "My names is " << name << endl;
}

void RandomPlayer::get_move(int &x, int &y,char**& myboard)
{
    x = (int)(rand() / (RAND_MAX + 1.0) * dimension);
    y = (int)(rand() / (RAND_MAX + 1.0) * dimension);
}
void RandomPlayer::get_connect_move(int &x)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, dimension - 1);
    x = dis(gen);
}
