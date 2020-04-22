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


bool recursiveKill2(int from, int whichPlayer){
    killMoveSelector();
    printf("----choleashchi---\n");
    pair<int,int>x;
    if(whichPlayer==PLAYER_YELLOW){
        for(int i = 0 ; i < 20 ; i++){
            printf("\nggsize..%d\n",board[i].lines.size());
            while(!board[i].lines.empty()){
                printf("i>>%d ",i);
                if(!pieceAvailable(board[i].lines.front())){
                    x=board[i].lines.front();
                    printf("iniffelse");
                    board[i].lines.pop();
                    if(board[i].lines.empty())break;
                    for(int j = 0 ; j < 16 ; j++){
                        printf("j>>%d ",j);
                        if(white_pcs[j] == board[i].lines.front()){
                            board[i].lines.pop();
                            if(board[i].lines.empty())break;
                            if(yellow_pcs[from] == board[i].lines.front()){
                                yellow_pcs[from] = x;
                                white_pcs[j] = make_pair(0,0);
                                return true;
                            }
                            else break;
                        }
                    }
                    break;
                }
                else
                    board[i].lines.pop();
            }
        }
    }
    else{
        for(int i = 0 ; i < 20 ; i++){
            printf("\nggsize..%d\n",board[i].lines.size());
            while(!board[i].lines.empty()){
                printf("i>>%d ",i);
                if(!pieceAvailable(board[i].lines.front())){
                    x=board[i].lines.front();
                    printf("iniffelse");
                    board[i].lines.pop();
                    if(board[i].lines.empty())break;
                    for(int j = 0 ; j < 16 ; j++){
                        printf("j>>%d ",j);
                        if(yellow_pcs[j] == board[i].lines.front()){
                            board[i].lines.pop();
                            if(board[i].lines.empty())break;
                            if(white_pcs[from] == board[i].lines.front()){
                                white_pcs[from] = x;
                                yellow_pcs[j] = make_pair(0,0);
                                return true;
                            }
                            else break;
                        }
                    }
                    break;
                }
                else
                    board[i].lines.pop();
            }
        }
    }
    return false;
}

bool recursiveKill(int from, int whichPlayer){
    killMoveSelector();
    printf("----choleashchi---\n");
    pair<int,int>x;
    if(whichPlayer==PLAYER_YELLOW){
        for(int i = 0 ; i < 20 ; i++){
            printf("\nggsize..%d\n",board[i].lines.size());
            while(!board[i].lines.empty()){
                printf("i>>%d ",i);
                if(yellow_pcs[from] == board[i].lines.front()){
                    printf("iniff");
                    board[i].lines.pop();
                    if(board[i].lines.empty())break;
                    for(int j = 0 ; j < 16 ; j++){
                        printf("j>>%d ",j);
                        if(white_pcs[j] == board[i].lines.front()){
                            //printf("\n%d\t%d\n",board[i].lines.front().first,board[i].lines.front().second);
                            board[i].lines.pop();
                            if(board[i].lines.empty())break;
                            if(!pieceAvailable(board[i].lines.front())){
                                //printf("\n%d\t%d\n",board[i].lines.front().first,board[i].lines.front().second);
                                printf("i>>%d ",i);
                                yellow_pcs[from] = board[i].lines.front();
                                white_pcs[j] = make_pair(0,0);
                                return true;
                            }
                            else break;
                        }
                    }
                    break;
                }
                else
                    board[i].lines.pop();
            }
        }
    }
    else{
        for(int i = 0 ; i < 20 ; i++){
            printf("\nggsize..%d\n",board[i].lines.size());
            while(!board[i].lines.empty()){
                printf("i>>%d ",i);
                if(white_pcs[from] == board[i].lines.front()){
                    printf("iniff");
                    board[i].lines.pop();
                    if(board[i].lines.empty())break;
                    for(int j = 0 ; j < 16 ; j++){
                        printf("j>>%d ",j);
                        if(yellow_pcs[j] == board[i].lines.front()){
                            //printf("\n%d\t%d\n",board[i].lines.front().first,board[i].lines.front().second);
                            board[i].lines.pop();
                            if(board[i].lines.empty())break;
                            if(!pieceAvailable(board[i].lines.front())){
                                //printf("\n%d\t%d\n",board[i].lines.front().first,board[i].lines.front().second);
                                printf("i>>%d ",i);
                                white_pcs[from] = board[i].lines.front();
                                yellow_pcs[j] = make_pair(0,0);
                                return true;
                            }
                            else break;
                        }
                    }
                    break;
                }
                else
                    board[i].lines.pop();
            }
        }
    }
    return false;
}


bool killMove(int from, int to, int whichPlayer){
    printf("KILL");
    pair<int,int> coor;
    if(whichPlayer==PLAYER_WHITE){
//        while(!board[5].lines.empty()){
//                printf("i...5");
//                board[5].lines.pop();
//        }
        for(int i = 0 ; i < 20 ; i++){
            while(!board[i].lines.empty()){
                //printf("i>>%d ",i);
                if(white_pcs[from] == board[i].lines.front()){
                    printf("iniff");
                    board[i].lines.pop();
                    if(board[i].lines.empty())break;
                    for(int j = 0 ; j < 16 ; j++){
                        //printf("j>>%d ",j);
                        if(yellow_pcs[j] == board[i].lines.front()){
                            board[i].lines.pop();
                            if(board[i].lines.empty())break;
                            if(board[to].coord == board[i].lines.front()){
                                white_pcs[from] = board[to].coord;
                                yellow_pcs[j] = make_pair(0,0);
                                cleardevice(); drawBoard();
                                while(recursiveKill2(from,PLAYER_WHITE)||recursiveKill(from,PLAYER_WHITE)){
                                    delay(500);
                                    cleardevice(); drawBoard();
                                    killMoveSelector();
                                }
                                return true;
                            }
                        }
                    }
                    break;
                }
                else if(board[to].coord == board[i].lines.front()){
                    printf("iniffelse");
                    board[i].lines.pop();
                    if(board[i].lines.empty())break;
                    for(int j = 0 ; j < 16 ; j++){
                        //printf("j>>%d ",j);
                        if(yellow_pcs[j] == board[i].lines.front()){
                            board[i].lines.pop();

                            if(board[i].lines.empty())break;
                            if(white_pcs[from] == board[i].lines.front()){
                                white_pcs[from] = board[to].coord;
                                yellow_pcs[j] = make_pair(0,0);
                                cleardevice(); drawBoard();
                                while(recursiveKill2(from,PLAYER_WHITE)||recursiveKill(from,PLAYER_WHITE)){
                                    delay(500);
                                    cleardevice(); drawBoard();
                                }
                                return true;
                            }
                        }
                    }
                    break;
                }
                board[i].lines.pop();
            }
        }
    }

    else{
        for(int i = 0 ; i < 20 ; i++){
            while(!board[i].lines.empty()){
                //printf("i>>%d ",i);
                if(yellow_pcs[from] == board[i].lines.front()){
                    printf("iniff");
                    board[i].lines.pop();
                    if(board[i].lines.empty())break;
                    for(int j = 0 ; j < 16 ; j++){
                        //printf("j>>%d ",j);
                        if(white_pcs[j] == board[i].lines.front()){
                            board[i].lines.pop();
                            if(board[i].lines.empty())break;
                            if(board[to].coord == board[i].lines.front()){
                                yellow_pcs[from] = board[to].coord;
                                white_pcs[j] = make_pair(0,0);
                                cleardevice(); drawBoard();
                                while(recursiveKill2(from,PLAYER_YELLOW)||recursiveKill(from,PLAYER_YELLOW)){
                                    delay(500);
                                    cleardevice(); drawBoard();
                                }
                                return true;
                            }
                        }
                    }
                    break;
                }
                else if(board[to].coord == board[i].lines.front()){
                    printf("iniffelse");
                    board[i].lines.pop();
                    if(board[i].lines.empty())break;
                    for(int j = 0 ; j < 16 ; j++){
                        //printf("j>>%d ",j);
                        if(white_pcs[j] == board[i].lines.front()){
                            board[i].lines.pop();
                            if(board[i].lines.empty())break;
                            if(yellow_pcs[from] == board[i].lines.front()){
                                yellow_pcs[from] = board[to].coord;
                                white_pcs[j] = make_pair(0,0);
                                cleardevice(); drawBoard();
                                while(recursiveKill2(from,PLAYER_YELLOW)||recursiveKill(from,PLAYER_YELLOW)){
                                    delay(500);
                                    cleardevice(); drawBoard();
                                }
                                return true;
                            }
                        }
                    }
                    break;
                }
                board[i].lines.pop();
            }
        }
    }
        return false;
}
