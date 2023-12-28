// Class definition for connect_four game classes
// author1:  Abulrahman Salah
// author2:  Ahmed osama
// author3:  mohamed ali
// Date:    6/12/2023

#ifndef _BoardGame_CLASSES_H
#define _BoardGame_CLASSES_H
#include <string>

using namespace std;
class Board
{
protected:
    int n_rows, n_cols;
    char **board;
    int n_moves = 0;

public:
    virtual bool update_board(int x, int y, char symbol) = 0;

    virtual bool is_winner() = 0;
    virtual bool is_draw() = 0;
    virtual void display_board() = 0;
    virtual bool game_is_over() = 0;

    virtual int get_n_rows() = 0;
    virtual int get_n_moves() = 0;
    virtual char **get_board() = 0;
};

///////////////////////////////////////////
class X_O_Board : public Board
{
public:
    X_O_Board();
    bool update_board(int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();

    int get_n_rows();
    int get_n_moves();
    char **get_board();
};
class G3 : public Board
{
public:
    G3();

    bool update_board(int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
    int get_n_rows();
    int get_n_moves();
    char **get_board();
};
class connect_four_board : public Board
{

public:
    connect_four_board();
    bool update_board(int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
    int get_n_rows();
    int get_n_moves();
    char **get_board();
};
class pyramic_X_O_Board : public Board
{
public:
    pyramic_X_O_Board();
    bool update_board(int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
    int get_n_rows();
    int get_n_moves();
    char **get_board();
};

///////////////////////////////////////////

class Player
{
protected:
    string name;
    char symbol;

public:
    Player(char symbol);
    Player(int order, char symbol);

    virtual void get_connect_move(int &x);
    virtual void get_move(int &x, int &y,char**& myboard);

    string to_string();
    char get_symbol();
};

///////////////////////////////////////////

class RandomPlayer : public Player
{
protected:
    int dimension;

public:
    RandomPlayer(char symbol, int dimension);
    void get_connect_move(int &x);
    void get_move(int &x, int &y,char**& myboard);
};
///////////////////////////////////////////

class AiPlayer : public Player{
public:
    AiPlayer (char symbol);
    virtual void get_move(int& x, int& y,char**& myboard)=0;
    virtual int minimax(int depth,bool isMaximizing,char**& board,int alpha,int beta)=0;
    virtual int status(char**& board)=0;
};

class AiPyramic : public AiPlayer{
public:
    AiPyramic(char symbol);
    void get_move(int& x, int& y,char**& myboard);
    int minimax(int depth,bool isMaximizing,char**& board,int alpha,int beta);
    int status(char**& board);
};

class Ai3by3 : public AiPlayer{
public:
    Ai3by3(char symbol);
    void get_move(int& x, int& y,char**& myboard);
    int minimax(int depth,bool isMaximizing,char**& board,int alpha,int beta);
    int status(char**& board);
};

class Ai5by5 : public AiPlayer{
public:
    Ai5by5(char symbol);
    void get_move(int& x, int& y,char**& myboard);
    int minimax(int depth,bool isMaximizing,char**& board,int alpha,int beta);
    int status(char**& board);
};

class Aiconnect4 : public AiPlayer{
public:
    Aiconnect4(char symbol);
    void get_move(int& x, int& y,char**& myboard);
    int minimax(int depth,bool isMaximizing,char**& board,int alpha,int beta);
    int status(char**& board);
    int getrow(char**& board,int y);
};


///////////////////////////////////////////
class GameManager
{
private:
    Board *boardPtr;
    Player *players[2];

public:
    GameManager(Board *, Player *playerPtr[2]);
    void run();
    void connect_four_run();

    int get_available_row(int column, char **board, int n_rows);
};

#endif
