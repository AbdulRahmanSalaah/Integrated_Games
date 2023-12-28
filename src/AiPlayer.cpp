// Class definition for AiPlayer class
// Author:  ahmad osama
// Date:    10/10/2022
// Version: 1
#include<iostream>
#include<random>
#include <vector>
#include<iomanip>
#include<algorithm>
#include"../include/BoardGame_Classes.hpp"
using namespace std;

// Set player symbol and name as Random Computer Player
AiPlayer::AiPlayer(char symbol) : Player(symbol)
{
    this->name = "Ai";
    cout << "My names is " << name << endl;
}
//
//void AiPlayer::get_move(int &x, int &y,char**& myboard) {
//    vector<pair<int,int>>valid={{0,2},{1,1},{1,2},{1,3},{2,0},{2,1},{2,2},{2,3},{2,4}};
//    int bestScore=-100;
//    for(auto i:valid){
//        if(myboard[i.first][i.second]=='.'){
//            myboard[i.first][i.second]='O';
//            int currantScore=minimax(0, false,myboard);
//            myboard[i.first][i.second]='.';
//            if(currantScore>bestScore){
//                bestScore=currantScore;
//                x=i.first;
//                y=i.second;
//            }
//        }
//    }
//}
//
//int AiPlayer::minimax(int depth, bool isMaximizing,char**& board) {
//
//    vector<pair<int,int>>valid={{0,2},{1,1},{1,2},{1,3},{2,0},{2,1},{2,2},{2,3},{2,4}};
//    int res;
//    if(gamenum==1){
//        res= g1status(board);
//    }
//    else if(gamenum==2){
//        res= g2status(board);
//    }
//    else if(gamenum==4){
//        res=g4status(board);
//    }
//
//    if(res!=1)
//        return res;
//
//    if(isMaximizing){
//        int ourbestcscore=-100;
//        for(auto i:valid){
//            if(board[i.first][i.second]=='.'){
//                board[i.first][i.second]='O';
//                int Score=minimax(depth+1, false,board);
//                board[i.first][i.second]='.';
//                ourbestcscore=max(Score,ourbestcscore);
//            }
//        }
//        return ourbestcscore;
//    }
//    else{
//        int ourbestcscore=100;
//        for(auto i:valid){
//            if(board[i.first][i.second]=='.'){
//                board[i.first][i.second]='X';
//                int Score=minimax(depth+1, true,board);
//                board[i.first][i.second]='.';
//                ourbestcscore=min(Score,ourbestcscore);
//            }
//        }
//        return ourbestcscore;
//    }
//}
//
//int AiPlayer::g1status(char **&board) {
//    for (int i = 0; i+2 < 5; ++i) {
//        if(board[2][i]==board[2][i+1]&&board[2][i+1]==board[2][i+2]&&board[2][i]!='.'){
//            if(board[2][i]=='O')
//                return 2;
//            else
//                return -2;
//        }
//    }
//
//    //second row
//    if(board[1][1]==board[1][2]&&board[1][1]==board[1][3]&&board[1][1]!='.'){
//        if(board[1][1]=='O')
//            return 2;
//        else
//            return -2;
//    }
//
//    //second cols
//    if(board[0][2]==board[1][2]&&board[1][2]==board[2][2]&&board[1][2]!='.'){
//        if(board[1][2]=='O')
//            return 2;
//        else
//            return -2;
//    }
//
//    if(board[1][1]==board[2][0]&&board[1][1]==board[0][2]&&board[1][1]!='.'){
//        if(board[1][1]=='O')
//            return 2;
//        else
//            return -2;
//    }
//
//    if(board[2][4]==board[1][3]&&board[1][3]==board[0][2]&&board[1][3]!='.'){
//        if(board[2][4]=='O')
//            return 2;
//        else
//            return -2;
//    }
//
//    vector<pair<int,int>>valid={{0,2},{1,1},{1,2},{1,3},{2,0},{2,1},{2,2},{2,3},{2,4}};
//    int cnt=0;
//    for(auto i:valid){
//        if(board[i.first][i.second]!='.'){
//            cnt++;
//        }
//    }
//
//    if(cnt==9) return 0;
//
//    return 1;
//}
//
///////////////////////////////////////////////////////
//
//int AiPlayer::g2status(char **&board){
//    for (int i = 0; i < 6; ++i)
//    {
//        for (int j = 0; j <= 7 - 4; ++j)
//        {
//            if (board[i][j] != '.' && board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] && board[i][j] == board[i][j + 3])
//            {
//                if(board[i][j]=='O')
//                    return 2;
//                else
//                    return -2;
//            }
//        }
//    }
//
//    for (int i = 0; i <= 6 - 4; ++i)
//    {
//        for (int j = 0; j < 7; ++j)
//        {
//            if (board[i][j] != '.' && board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j] && board[i][j] == board[i + 3][j])
//            {
//                if(board[i][j]=='O')
//                    return 2;
//                else
//                    return -2;
//            }
//        }
//    }
//
//    for (int i = 3; i < 6; ++i)
//    {
//        for (int j = 0; j <= 7 - 4; ++j)
//        {
//            if (board[i][j] != '.' &&
//                board[i][j] == board[i - 1][j + 1] &&
//                board[i][j] == board[i - 2][j + 2] &&
//                board[i][j] == board[i - 3][j + 3])
//            {
//                if(board[i][j]=='O')
//                    return 2;
//                else
//                    return -2;
//            }
//        }
//    }
//
//    for (int i = 0; i <= 6 - 4; ++i)
//    {
//        for (int j = 0; j <= 7 - 4; ++j)
//        {
//            if (board[i][j] != '.' &&
//                board[i][j] == board[i + 1][j + 1] &&
//                board[i][j] == board[i + 2][j + 2] &&
//                board[i][j] == board[i + 3][j + 3])
//            {
//                if(board[i][j]=='O')
//                    return 2;
//                else
//                    return -2;
//            }
//        }
//    }
//
//    int cnt=0;
//    for (int i = 0; i <= 6 - 4; ++i)
//    {
//        for (int j = 0; j <= 7 - 4; ++j)
//        {
//            cnt+=board[i][j]!='.';
//        }
//    }
//
//    if(cnt==42) return 0;
//
//    return 1;
//}
//
///////////////////////////////////////////////////////
//
//int AiPlayer::g4status(char **&board){
//    for (int i = 0; i < 3; i++)
//    {
//        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '.')
//            if(board[i][0]=='O')
//                    return 2;
//                else
//                    return -2;
//    }
//
//    // check col
//    for (int i = 0; i < 3; i++)
//    {
//        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '.')
//            if(board[0][i]=='O')
//                    return 2;
//                else
//                    return -2;
//    }
//
//    // check diagonal
//    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '.'){
//        if(board[0][0]=='O')
//                    return 2;
//                else
//                    return -2;
//    }
//
//    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '.'){
//        if(board[0][2]=='O')
//                    return 2;
//                else
//                    return -2;
//    }
//
//    int cnt=0;
//    for (int i = 0; i <= 3; ++i)
//    {
//        for (int j = 0; j <= 3; ++j)
//        {
//            cnt+=board[i][j]!='.';
//        }
//    }
//
//    if(cnt==9) return 0;
//
//    return 1;
//}
