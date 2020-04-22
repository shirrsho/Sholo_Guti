#include<stdio.h>
#include<graphics.h>
#include<iostream>
#include "header.hpp"
#include<queue>
#include<stdlib.h>

using namespace std;

extern pair<int,int> yellow_pcs[16];
extern pair<int,int> white_pcs[16];
extern struct Board{
    pair<int,int> coord;
    queue< pair<int,int> > neighs;
    queue< pair<int,int> > lines;
}board[37];

extern bool WhitesMove;

extern bool TWO_PLAYER_MODE;
extern bool AI_MODE;

std::queue< pair<int,int> > availableGenMoves(std::pair<int,int> x){

    std::queue< pair<int,int> > ret;

    for(int i = 0 ; i < 37 ; i++){
        if(board[i].coord == x){
            while(!board[i].neighs.empty()){
                if(!pieceAvailable(board[i].neighs.front()))
                    ret.push(board[i].neighs.front());
                board[i].neighs.pop();
            }
        }
    }

    return ret;
}


//queue< pair<int,int> > isMoveSafe(int from,std::pair<int,int> to,int whichPlayer){
//
//}


void gameAI(){
    int indexAI = rand();
    indexAI = indexAI%16;
    int to = rand();
    to = to%37;
    bool move = false;
    queue< pair<int,int> > genMoves;
    //bool a = killMove(indexAI,to,PLAYER_WHITE);

    for(int i = 15 ; i>= 0 ; i--){
        while(recursiveKill(i,PLAYER_WHITE)||recursiveKill2(i,PLAYER_WHITE)){
            //delay(500);
            cleardevice(); drawBoard();
            move = true;
        }
        if(move) return;
    }

    for(int i = 15 ; i>= 0 ; i--){
        genMoves = availableGenMoves(white_pcs[i]);
        while(!genMoves.empty()){
            //delay(500);
            //isMoveSafe(i,genMoves.front(),PLAYER_WHITE);
            white_pcs[i] = genMoves.front();
            cleardevice(); drawBoard();
            genMoves.pop();
            move = true;
            break;
        }
        if(move) return;
    }


    return;
}
