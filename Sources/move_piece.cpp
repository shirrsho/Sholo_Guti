#include<stdio.h>
#include<graphics.h>
#include<iostream>
#include "header.hpp"
#include<list>
#include<math.h>
#include<queue>

using namespace std;

bool dontChange = false;                                                       // Move changer

extern pair<int,int> red_pcs[16];
extern pair<int,int> black_pcs[16];


extern struct Board
{
    pair<int,int> coord;
    queue< pair<int,int> > neighs;
    queue< pair<int,int> > lines;

} board[37];


extern bool TWO_PLAYER_MODE;

int whoseKill = -1;                                                            // Recursive kill Indicator


double calculateDistance(pair<int,int> X,pair<int,int> Y)
{
    return sqrt(pow((Y.first-X.first),2)+pow((Y.second-X.second),2));
}



// Moving a piece to its adjacent place


bool generalMove(int from, int to, int whichPlayer)
{
    printf("GEN");



    if(whichPlayer==PLAYER_BLACK)
    {

        //if(calculateDistance(black_pcs[from],board[to].coord)>TRIANGLE_BASE/2||black_pcs[from]==board[to].coord) return false;
        while(!board[to].neighs.empty())
        {

            if(board[to].neighs.front() == black_pcs[from])
            {

                //if(board[to].neighs.front().second ==)
                black_pcs[from]=board[to].coord;
                generalMoveSelector();
                return true;

            }

            board[to].neighs.pop();

        }

        generalMoveSelector();
        return false;
    }

    else
    {
        //if(calculateDistance(red_pcs[from],board[to].coord)>TRIANGLE_BASE/2||red_pcs[from]==board[to].coord) return false;

        while(!board[to].neighs.empty())
        {

            if(board[to].neighs.front() == red_pcs[from])
            {
                //if(board[to].neighs.front().second ==  red_pcs[from].second)
                red_pcs[from]=board[to].coord;
                generalMoveSelector();
                return true;

            }

            board[to].neighs.pop();
        }

        generalMoveSelector();
        return false;
    }
}



// Checking if a place is available for placing a new piece


bool pieceAvailable(pair<int,int>here)
{

    for(int i = 0 ; i < 16 ; i++)
    {
        if(black_pcs[i] == here)
            return true;

        if(red_pcs[i] == here)
            return true;
    }

    return false;
}


// Parent function for moving a piece


bool move_piece(int from,int to,int whichPlayer)
{

    printf("MOVE");

    bool take = false;

    if(whichPlayer!=whoseKill)
    {
        take = generalMove(from,to,whichPlayer);
        dontChange = false;
        whoseKill = -1;
    }

    if(take) return take;

    take = killMove(from,to,whichPlayer);

    killMoveSelector();

    if(TWO_PLAYER_MODE&&take)
    {
        dontChange = true;
        whoseKill = whichPlayer;
    }

    return take;

}
