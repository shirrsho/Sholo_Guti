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


/*

    - Finds all possible moves

*/


/*
    - ATTENTION !!!
    - When the AI cannot find any safe move for a piece then it misbehaves
    - Updated:: SOlved
*/


std::queue< pair<int,int> > availableGenMoves(std::pair<int,int> x){

    generalMoveSelector();
    killMoveSelector();

    std::queue< pair<int,int> > ret;
    while(!ret.empty()) ret.pop();
    for(int i = 0 ; i < 37 ; i++){
        if(board[i].coord == x){
            while(!board[i].neighs.empty()){
                if(!pieceAvailable(board[i].neighs.front()))
                    ret.push(board[i].neighs.front());
                board[i].neighs.pop();
            }
        }
    }

    generalMoveSelector();
    return ret;
}



/*

    - AI search for a safe move from where he won't be killed down

    - Finds if the next move is safe

*/


bool isMoveSafe(int from,std::pair<int,int> to,int whichPlayer){

    killMoveSelector();
    pair<int,int> store,check;
    printf("--%d %d--",white_pcs[from].first,white_pcs[from].second);
    printf("--%d %d--",to.first,to.second);
    if(whichPlayer == PLAYER_WHITE){
        store = white_pcs[from];
        white_pcs[from] = to;
        //for(int i = 0 ; i < 37 ; i++){
            //if(board[i].coord == white_pcs[from]){
                for(int j = 0 ; j < 20 ; j++){
                    while(!board[j].lines.empty()){
                        check = board[j].lines.front();
                        board[j].lines.pop();
                        if(board[j].lines.empty()) break;
                        if(board[j].lines.front() == white_pcs[from]){
                            printf("????");
                            board[j].lines.pop();
                            if(!pieceAvailable(check)&&whichPiece(board[j].lines.front())==PLAYER_YELLOW){
                                printf(" ???");
                                //if(whichPiece(board[j].lines.front()) == PLAYER_YELLOW)
                                    white_pcs[from] = store; killMoveSelector(); return false;
                            }

                            else if(!pieceAvailable(board[j].lines.front())&&whichPiece(check) == PLAYER_YELLOW){
                                printf("??");
                                //board[j].lines.pop();
                                //if(board[j].lines.front() == store)
                                    white_pcs[from] = store; killMoveSelector(); return false;
                            }
                        }
                    }
                }
                white_pcs[from] = store;
                killMoveSelector();
                return true;
            //}
        //}
    }
    return true;
}


std::queue<int> threatenedPieces(int whichPlayer){
    queue<int> ret;
    while(!ret.empty())ret.pop();
    if(whichPlayer==PLAYER_WHITE){
        for(int i = 0 ; i < 16 ; i++){
            if(!isMoveSafe(i,white_pcs[i],PLAYER_WHITE)){
                ret.push(i);
            }
        }
    }
    return ret;
}


void gameAI(){
    int indexAI = rand();
    indexAI = indexAI%16;
    int to = rand();
    to = to%37;
    bool move = false;
    int count=0;
    queue< pair<int,int> > genMoves;
    //bool a = killMove(indexAI,to,PLAYER_WHITE);
    killMoveSelector();
    generalMoveSelector();
    for(int i = 0 ; i < 16 ; i++){
        killMoveSelector();
        if(white_pcs[i] == make_pair(0,0)) continue;
        while(recursiveKill(i,PLAYER_WHITE)||recursiveKill2(i,PLAYER_WHITE)){
            count++;
            printf("\n\n%d\n\n",count);
            delay(500);
            cleardevice(); drawBoard();
            killMoveSelector();
            move = true;
        }
        if(move) return;
    }
    //return;
    killMoveSelector();
    generalMoveSelector();

    queue<int> thrPcs = threatenedPieces(PLAYER_WHITE);
    while(!thrPcs.empty()){
        genMoves = availableGenMoves(white_pcs[thrPcs.front()]);
        while(!genMoves.empty()){
            delay(500);
            printf("\n\n%d %d\n\n",genMoves.front().first,genMoves.front().second);
            if(!isMoveSafe(thrPcs.front(),genMoves.front(),PLAYER_WHITE)) {printf("__aichi");genMoves.pop();continue;}
            printf("%d %d",genMoves.front().first,genMoves.front().second);
            white_pcs[thrPcs.front()] = genMoves.front();
            cleardevice(); drawBoard();
            genMoves.pop();
            move = true;
            break;
        }
        thrPcs.pop();
        if(move) return;
    }

    for(int i = 15 ; i >= 0 ; i--){
        genMoves = availableGenMoves(white_pcs[i]);
        while(!genMoves.empty()){
            delay(500);
            printf("\n\n%d %d\n\n",genMoves.front().first,genMoves.front().second);
            if(!isMoveSafe(i,genMoves.front(),PLAYER_WHITE)) {printf("__aichi");genMoves.pop();continue;}
            printf("%d %d",genMoves.front().first,genMoves.front().second);
            white_pcs[i] = genMoves.front();
            cleardevice(); drawBoard();
            genMoves.pop();
            move = true;
            break;
        }
        if(move) return;
    }


    while(move==false){
    int t = rand();
    int i = (t*456463)%16;
        generalMoveSelector();
        killMoveSelector();
        genMoves = availableGenMoves(white_pcs[i]);
        while(!genMoves.empty()){
            delay(500);
            //if(!isMoveSafe(i,genMoves.front(),PLAYER_WHITE)) {printf("__aichi");genMoves.pop();continue;}
            white_pcs[i] = genMoves.front();
            cleardevice(); drawBoard();
            genMoves.pop();
            move = true;
            break;
        }
    }


    return;
}
