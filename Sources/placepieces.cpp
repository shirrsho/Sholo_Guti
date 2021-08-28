#include<graphics.h>
#include "header.hpp"
#include<iostream>
#include<queue>

using namespace std;

extern pair<int,int> red_pcs[16];
extern pair<int,int> black_pcs[16];

extern struct Board
{
    pair<int,int> coord;
    queue< pair<int,int> > neighs;
    queue< pair<int,int> > lines;
} board[37];


// Drawing the pieces

void placePieces(int x, int y)
{


    int radius = 15;

    for(int i = 1 ; i <= radius; i=i++)
    {
        circle(x,y,i);
    }

}



int whichPiece(pair<int,int>x)
{

    for(int i = 0; i<16 ; i++)
    {
        if(x==black_pcs[i]) return PLAYER_BLACK;
        if(x==red_pcs[i]) return PLAYER_RED;
    }

    return 0;
}
