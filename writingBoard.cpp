
#include<stdio.h>
#include<graphics.h>
#include<iostream>
#include "header.hpp"
#include<queue>
#include<stdlib.h>

using namespace std;

extern pair<int,int> yellow_pcs[16];
extern pair<int,int> white_pcs[16];
extern struct Board
{
    pair<int,int> coord;
    queue< pair<int,int> > neighs;
    queue< pair<int,int> > lines;
} board[37];


extern bool TWO_PLAYER_MODE;
extern bool AI_MODE;

/*

    - The following function reads the file to find the positions of the pieces

    - And writes about the new positions

    - Stores the data of the board

*/


void set()
{

    POINT cursor;
    int x,y;
    //FILE* fp = fopen("board_coordinates.txt","w");
    while(1)
    {
        delay(100);
        if(GetAsyncKeyState(VK_LBUTTON))
        {
            GetCursorPos(&cursor);
            x=cursor.x;
            y=cursor.y-25;

            for(int i = 0 ; i < 37 ; i++)
            {
                if(((x>board[i].coord.first-10)&&(x<board[i].coord.first+10))&&
                        ((y>board[i].coord.second-10)&&(y<board[i].coord.second+10)))
                {
                    //fprintf(fp,"%d\t",board[i].coord.first);
                    //fprintf(fp,"%d\n",board[i].coord.second);
                    cleardevice();
                    drawBoard();
                }
            }

        }
        //printf("\nPLAYER %d WINS THE GAME\n",whoWin);
        //menu();
    }
}


void initializeGeneralMoves()
{

    POINT cursor;
    int x,y, whoWin = 0;
    FILE* fp = fopen("general_moves.txt","a");
    fprintf(fp,"\n");


    while(1)
    {
        whoWin = 0;
        delay(100);


        if(GetAsyncKeyState(VK_LBUTTON))
        {
            GetCursorPos(&cursor);
            x=cursor.x;
            y=cursor.y-25;


            for(int i = 0 ; i < 37 ; i++)
            {

                if(((x>board[i].coord.first-10)&&(x<board[i].coord.first+10))&&
                        ((y>board[i].coord.second-10)&&(y<board[i].coord.second+10)))
                {
                    fprintf(fp,"%d ",board[i].coord.first);
                    fprintf(fp,"%d ",board[i].coord.second);
                    cleardevice();
                    drawBoard();
                    whoWin = 1;
                }
            }


            if(whoWin==0)
            {
                fclose(fp);
                initializeGeneralMoves();
            }

        }
        //printf("\nPLAYER %d WINS THE GAME\n",whoWin);
        //menu();
    }
}



void initializeKillMoves()
{

    POINT cursor;
    int x,y, whoWin = 0;

    FILE* fp = fopen("kill_moves.txt","a");
    fprintf(fp,"\n");


    while(1)
    {
        whoWin = 0;
        delay(100);

        if(GetAsyncKeyState(VK_LBUTTON))
        {
            GetCursorPos(&cursor);
            x=cursor.x;
            y=cursor.y-25;

            for(int i = 0 ; i < 37 ; i++)
            {
                if(((x>board[i].coord.first-10)&&(x<board[i].coord.first+10))&&
                        ((y>board[i].coord.second-10)&&(y<board[i].coord.second+10)))
                {
                    fprintf(fp,"%d ",board[i].coord.first);
                    fprintf(fp,"%d ",board[i].coord.second);
                    cleardevice();
                    drawBoard();
                    whoWin = 1;
                }
            }


            if(whoWin==0)
            {
                fclose(fp);
                initializeKillMoves();
            }

        }
        //printf("\nPLAYER %d WINS THE GAME\n",whoWin);
        //menu();
    }

}


//void set(){
//
//    POINT cursor;
//    int x,y, whoWin = 0;
//    bool take = false;
//    //FILE* fp = fopen("board_coordinates.txt","w");
//    while(1){
//        delay(100);
//        if(GetAsyncKeyState(VK_LBUTTON)){
//            GetCursorPos(&cursor);x=cursor.x;y=cursor.y-25;
//
//                    for(int i = 0 ; i < 37 ; i++){
//                    if(((x>board[i].coord.first-10)&&(x<board[i].coord.first+10))&&
//                       ((y>board[i].coord.second-10)&&(y<board[i].coord.second+10))){
//                        //fprintf(fp,"%d\t",board[i].coord.first);
//                        //fprintf(fp,"%d\n",board[i].coord.second);
//                        cleardevice();
//                        drawBoard();
//                    }
//                    }
//
//        }
//    //printf("\nPLAYER %d WINS THE GAME\n",whoWin);
//    //menu();
//}
//}
