#include<iostream>
#include<random>
#include <vector>
#include<iomanip>
#include<algorithm>
#include"../include/BoardGame_Classes.hpp"
using namespace std;



AiPyramic::AiPyramic(char symbol) : AiPlayer(symbol) {
}

void AiPyramic::get_move(int &x, int &y,char**& myboard){
    vector<pair<int,int>>valid={{0,2},{1,1},{1,2},{1,3},{2,0},{2,1},{2,2},{2,3},{2,4}};
    int bestScore=-100;
    for(auto i:valid){
        if(myboard[i.first][i.second]=='.'){
            myboard[i.first][i.second]='O';
            int currantScore=minimax(0, false,myboard,-100,100);
            myboard[i.first][i.second]='.';
            if(currantScore>bestScore){
                bestScore=currantScore;
                x=i.first;
                y=i.second;
            }
        }
    }
}

int AiPyramic::minimax(int depth, bool isMaximizing, char **&board,int alpha,int beta) {
    vector<pair<int,int>>valid={{0,2},{1,1},{1,2},{1,3},{2,0},{2,1},{2,2},{2,3},{2,4}};
    int res;
    res=status(board);
    if(res!=1)
        return res;

    if(isMaximizing){
        int ourbestcscore=-100;
        for(auto i:valid){
            if(board[i.first][i.second]=='.'){
                board[i.first][i.second]='O';
                int Score=minimax(depth+1, false,board,alpha,beta);
                board[i.first][i.second]='.';
                ourbestcscore=max(Score,ourbestcscore);
                alpha=max(alpha,Score);
                if(beta<=alpha)
                    break;
            }
        }
        return ourbestcscore;
    }
    else{
        int ourbestcscore=100;
        for(auto i:valid){
            if(board[i.first][i.second]=='.'){
                board[i.first][i.second]='X';
                int Score=minimax(depth+1, true,board,alpha,beta);
                board[i.first][i.second]='.';
                ourbestcscore=min(Score,ourbestcscore);
                beta=min(beta,Score);
                if(beta<=alpha)
                    break;
            }
        }
        return ourbestcscore;
    }
}

int AiPyramic::status(char **&board) {
    for (int i = 0; i+2 < 5; ++i) {
        if(board[2][i]==board[2][i+1]&&board[2][i+1]==board[2][i+2]&&board[2][i]!='.'){
            if(board[2][i]=='O')
                return 2;
            else
                return -2;
        }
    }

    //second row
    if(board[1][1]==board[1][2]&&board[1][1]==board[1][3]&&board[1][1]!='.'){
        if(board[1][1]=='O')
            return 2;
        else
            return -2;
    }

    //second cols
    if(board[0][2]==board[1][2]&&board[1][2]==board[2][2]&&board[1][2]!='.'){
        if(board[1][2]=='O')
            return 2;
        else
            return -2;
    }

    if(board[1][1]==board[2][0]&&board[1][1]==board[0][2]&&board[1][1]!='.'){
        if(board[1][1]=='O')
            return 2;
        else
            return -2;
    }

    if(board[2][4]==board[1][3]&&board[1][3]==board[0][2]&&board[1][3]!='.'){
        if(board[2][4]=='O')
            return 2;
        else
            return -2;
    }

    vector<pair<int,int>>valid={{0,2},{1,1},{1,2},{1,3},{2,0},{2,1},{2,2},{2,3},{2,4}};
    int cnt=0;
    for(auto i:valid){
        if(board[i.first][i.second]!='.'){
            cnt++;
        }
    }

    if(cnt==9) return 0;

    return 1;
}



