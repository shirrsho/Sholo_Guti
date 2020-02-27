
#include<graphics.h>
#include "header.h"
#include<utility>
#include<iostream>

using namespace std;

extern pair<int,int>white_pcs[16];
extern pair<int,int>yellow_pcs[16];

void move_piece(pair<int,int>from,pair<int,int>to,int whichPlayer){

    if(whichPlayer == 1){
        for(int i = 0 ; i < 16 ; i++){
            if(from == white_pcs[i]){
                white_pcs[i] = to;
            }
        }
    }
    closegraph();
    drawBoard();

}
