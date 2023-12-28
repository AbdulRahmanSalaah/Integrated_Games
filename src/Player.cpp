// Class definition for connect_four_Player class
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

Player::Player(char symbol)
{
    this->symbol = symbol;
}

Player::Player(int order, char symbol)
{
    cout << "Welcome player " << order << endl;
    cout << "Please enter your name  play : ";
    cin >> name;
    this->symbol = symbol;
}

void Player::get_move(int &x, int &y,char**& myboard)
{
    cout << "\nPlease enter your move x and y (0 to 2) separated by spaces: ";
    cin >> x >> y;
}
void Player::get_connect_move(int &column)
{
    cout << "\nPlease enter the column number (1 to 7) where you want to place your (" << symbol << ") :";
    cin >> column;
    column -= 1;
}

string Player::to_string()
{
    return "Player: " + name;
}

char Player::get_symbol()
{
    return symbol;
}
