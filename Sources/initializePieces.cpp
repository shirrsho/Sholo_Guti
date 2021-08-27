
#include<graphics.h>
#include "header.hpp"
#include<utility>
#include<iostream>
#include<stdio.h>
#include<list>
#include<queue>

using namespace std;

pair<int,int> yellow_pcs[16];
pair<int,int> white_pcs[16];


struct Board
{
    pair<int,int> coord;
    queue< pair<int,int> > neighs;
    queue< pair<int,int> > lines;

} board[37];



// Initializing the board


void initializePieces()
{
    int it = 6;
    //placePieces(TRIANGLE_STARTING,SPACE_VERTICAL);
    white_pcs[0] = make_pair(TRIANGLE_STARTING,SPACE_VERTICAL);

    //placePieces(TRIANGLE_STARTING+TRIANGLE_BASE/2,SPACE_VERTICAL);
    white_pcs[1] = make_pair(TRIANGLE_STARTING+TRIANGLE_BASE/2,SPACE_VERTICAL);

    //placePieces(TRIANGLE_ENDING,SPACE_VERTICAL);
    white_pcs[2] = make_pair(TRIANGLE_ENDING,SPACE_VERTICAL);

    //placePieces(TRIANGLE_STARTING+TRIANGLE_BASE/4,SPACE_VERTICAL+TRIANGLE_HEIGHT/2);
    white_pcs[3] = make_pair(TRIANGLE_STARTING+TRIANGLE_BASE/4,SPACE_VERTICAL+TRIANGLE_HEIGHT/2);

    //placePieces(TRIANGLE_STARTING+TRIANGLE_BASE/2,SPACE_VERTICAL+TRIANGLE_HEIGHT/2);
    white_pcs[4] = make_pair(TRIANGLE_STARTING+TRIANGLE_BASE/2,SPACE_VERTICAL+TRIANGLE_HEIGHT/2);

    //placePieces(TRIANGLE_STARTING+TRIANGLE_BASE*3/4,SPACE_VERTICAL+TRIANGLE_HEIGHT/2);
    white_pcs[5] = make_pair(TRIANGLE_STARTING+TRIANGLE_BASE*3/4,SPACE_VERTICAL+TRIANGLE_HEIGHT/2);


    for(int i = BOX_STARTING ; i <= BOX_ENDING ; i = i+PLACE_WIDTH)
    {
        //placePieces(i,SPACE_VERTICAL+TRIANGLE_HEIGHT);
        white_pcs[it] = make_pair(i,SPACE_VERTICAL+TRIANGLE_HEIGHT);
        it++;
    }

    for(int i = BOX_STARTING ; i <= BOX_ENDING ; i = i+PLACE_WIDTH)
    {
        //placePieces(i,SPACE_VERTICAL+TRIANGLE_HEIGHT+PLACE_WIDTH);
        white_pcs[it] = make_pair(i,SPACE_VERTICAL+TRIANGLE_HEIGHT+PLACE_WIDTH);
        it++;
    }

    it = 6;

    //setcolor(YELLOW);
    //placePieces(TRIANGLE_STARTING,SPACE_VERTICAL+TRIANGLE_HEIGHT*2+BOX_LENGTH);
    yellow_pcs[0] = make_pair(TRIANGLE_STARTING,SPACE_VERTICAL+TRIANGLE_HEIGHT*2+BOX_LENGTH);

    //placePieces(TRIANGLE_STARTING+TRIANGLE_BASE/2,SPACE_VERTICAL+TRIANGLE_HEIGHT*2+BOX_LENGTH);
    yellow_pcs[1] = make_pair(TRIANGLE_STARTING+TRIANGLE_BASE/2,SPACE_VERTICAL+TRIANGLE_HEIGHT*2+BOX_LENGTH);

    //placePieces(TRIANGLE_ENDING,SPACE_VERTICAL+TRIANGLE_HEIGHT*2+BOX_LENGTH);
    yellow_pcs[2] = make_pair(TRIANGLE_ENDING,SPACE_VERTICAL+TRIANGLE_HEIGHT*2+BOX_LENGTH);

    //placePieces(TRIANGLE_STARTING+TRIANGLE_BASE/4,SPACE_VERTICAL+TRIANGLE_HEIGHT+BOX_LENGTH+TRIANGLE_HEIGHT/2);
    yellow_pcs[3] = make_pair(TRIANGLE_STARTING+TRIANGLE_BASE/4,SPACE_VERTICAL+TRIANGLE_HEIGHT+BOX_LENGTH+TRIANGLE_HEIGHT/2);

    //placePieces(TRIANGLE_STARTING+TRIANGLE_BASE/2,SPACE_VERTICAL+TRIANGLE_HEIGHT+BOX_LENGTH+TRIANGLE_HEIGHT/2);
    yellow_pcs[4] = make_pair(TRIANGLE_STARTING+TRIANGLE_BASE/2,SPACE_VERTICAL+TRIANGLE_HEIGHT+BOX_LENGTH+TRIANGLE_HEIGHT/2);

    //placePieces(TRIANGLE_STARTING+TRIANGLE_BASE*3/4,SPACE_VERTICAL+TRIANGLE_HEIGHT+BOX_LENGTH+TRIANGLE_HEIGHT/2);
    yellow_pcs[5] = make_pair(TRIANGLE_STARTING+TRIANGLE_BASE*3/4,SPACE_VERTICAL+TRIANGLE_HEIGHT+BOX_LENGTH+TRIANGLE_HEIGHT/2);

    for(int i = BOX_STARTING ; i <= BOX_ENDING ; i = i+PLACE_WIDTH)
    {
        //placePieces(i,SPACE_VERTICAL+TRIANGLE_HEIGHT+BOX_LENGTH);
        yellow_pcs[it] = make_pair(i,SPACE_VERTICAL+TRIANGLE_HEIGHT+BOX_LENGTH);
        it++;
    }

    for(int i = BOX_STARTING ; i <= BOX_ENDING ; i = i+PLACE_WIDTH)
    {
        //placePieces(i,SPACE_VERTICAL+TRIANGLE_HEIGHT-PLACE_WIDTH+BOX_LENGTH);
        yellow_pcs[it] = make_pair(i,SPACE_VERTICAL+TRIANGLE_HEIGHT-PLACE_WIDTH+BOX_LENGTH);
        it++;
    }


    boardMoveSelector();

    generalMoveSelector();

    killMoveSelector();

    return;
}
