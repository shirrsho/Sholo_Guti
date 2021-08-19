#include<graphics.h>
#include "header.h"
#include<utility>
#include<iostream>
#include<stdio.h>
#include<list>
#include<queue>

using namespace std;

extern pair<int,int> yellow_pcs[16];
extern pair<int,int> white_pcs[16];

extern struct Board
{
    pair<int,int> coord;
    queue< pair<int,int> > neighs;
    queue< pair<int,int> > lines;
} board[37];



void generalMoveSelector()                                                                 // Function indicates which
{
    // moves are possible from a place
    for(int i = 0 ; i < 20 ; i++)
    {
        while(!board[i].neighs.empty()) board[i].neighs.pop();
    }
    int i;
    FILE *fp;
    int aa,bb;
    fp = fopen("general_moves.txt","r");
    fscanf(fp,"%d",&i);
    while(!feof(fp)) //j<37 chilo
    {
        fscanf(fp,"%d",&aa);
        if(aa<50)
        {
            i=aa;
            continue;
        }
        fscanf(fp,"%d",&bb);
        pair<int,int> a = make_pair(aa,bb);
        board[i].neighs.push(a);
    }
    fclose(fp);
}

void boardMoveSelector()
{
    FILE *fp = fopen("board_coordinates.txt","r");
    int aa,bb;
    int i = 0;
    while(1) //j<37 chilo
    {

        fscanf(fp,"%d",&aa);
        fscanf(fp,"%d",&bb);
        //printf("%d %d ",aa,bb);
        //fscanf(fp,"%d",&bb);
        board[i].coord.first = aa;
        board[i].coord.second = bb;
        i++;
        if(i==37) break;
        //board[j].coord = make_pair(BOX_STARTING+(j-32)*PLACE_WIDTH,SPACE_VERTICAL+TRIANGLE_HEIGHT+BOX_LENGTH/2);
    }
    //printf("\n\n%d\t%d\n\n",board[36].coord.first,board[36].coord.second);
    fclose(fp);
}

void killMoveSelector()
{
    for(int i = 0 ; i < 20 ; i++)
    {
        while(!board[i].lines.empty()) board[i].lines.pop();
    }
    FILE *fp = fopen("kill_moves.txt","r");
    int aa,bb;
    int i = 0;
    fscanf(fp,"%d",&i);
    while(!feof(fp)) //j<37 chilo
    {
        fscanf(fp,"%d",&aa);
        if(aa<50)
        {
            i=aa;
            continue;
        }
        fscanf(fp,"%d",&bb);
        pair<int,int> a = make_pair(aa,bb);
        board[i].lines.push(a);
    }
    fclose(fp);
//        for(int i = 0 ; i < 18 ; i++){
//        printf("\n\n");
//        while(!board[i].lines.empty()) {
//            printf("%d %d\t",board[i].lines.front().first,board[i].lines.front().second);
//            board[i].lines.pop();
//        }
//    }
}

