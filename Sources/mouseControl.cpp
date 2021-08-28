#include<stdio.h>
#include<graphics.h>
#include<iostream>
#include "header.hpp"
#include<queue>
#include<stdlib.h>

using namespace std;

extern bool dontChange;

extern pair<int,int> red_pcs[16];
extern pair<int,int> black_pcs[16];

extern struct Board
{
    pair<int,int> coord;
    queue< pair<int,int> > neighs;
    queue< pair<int,int> > lines;
} board[37];

bool WhitesMove = false;

extern bool TWO_PLAYER_MODE;
extern bool AI_MODE;


int score(int who)
{
    int sc = 0;

    if(who==PLAYER_BLACK)
    {

        for(int i = 0 ; i < 16 ; i++)
        {
            if(black_pcs[i]!=make_pair(0,0)) sc++;
        }

    }

    else{

        for(int i = 0 ; i < 16 ; i++)
        {
            if(red_pcs[i]!=make_pair(0,0)) sc++;
        }

    }

    return sc;
}


// End indicating function

int ifFinished()
{


    int take = 0;

    for(int i = 0 ; i < 16 ; i++)
    {

        if(black_pcs[i]!=make_pair(0,0))
        {
            take = PLAYER_BLACK;
            break;

        }
    }


    for(int i = 0 ; i < 16 ; i++)
    {

        if(red_pcs[i]!=make_pair(0,0))
        {

            if(take==PLAYER_BLACK) return 0;

            else{
                leaderboardSave(PLAYER_RED,score(PLAYER_RED));
                return PLAYER_RED;
            }

        }

    }
    leaderboardSave(PLAYER_BLACK,score(PLAYER_BLACK));
    return PLAYER_BLACK;
}


void selectPiece(pair<int,int>select)
{

    setcolor(YELLOW);

    circle(select.first,select.second,11);
    circle(select.first,select.second,10);
    circle(select.first,select.second,9);

}

/*


    - The following two functions are for controlling the game with mouse

    - mouseControl function selects the piece to move

    - mouseControl2 function selects the destination point

    - Then it calls the kill/general move function for moving the piece

    - It controls the player who will make the next move

*/



bool mouseControl2(int j, int color)
{
    POINT cursor;
    int x,y;
    bool take = false;

    while(1)
    {
        delay(100);

        GetCursorPos(&cursor);
        x=cursor.x;
        y=cursor.y-25;

        for(int i = 0 ; i < 37 ; i++)
        {
            if(((x>board[i].coord.first-15)&&(x<board[i].coord.first+15))&&((y>board[i].coord.second-15)&&(y<board[i].coord.second+15)))
            {

                //setcolor(WHITE);circle(board[i].coord.first,board[i].coord.second,11);
            }
        }


        if(GetAsyncKeyState(VK_LBUTTON))
        {
            GetCursorPos(&cursor);
            x = cursor.x;
            y = cursor.y-25;
            for(int i = 0 ; i < 37 ; i++)
            {
                if(((x>board[i].coord.first-15)&&(x<board[i].coord.first+15))&&((y>board[i].coord.second-15)&&(y<board[i].coord.second+15)))
                {
                    if(pieceAvailable(board[i].coord)) break;


                    if(color==PLAYER_BLACK)
                        take = move_piece(j,i,PLAYER_BLACK);

                    else
                        take = move_piece(j,i,PLAYER_RED);


                    cleardevice();

                    drawBoard();

                    return take;
                }
            }

            return take;
        }

    }

}



void mouseControl()
{
    //set();
    //initializeGeneralMoves();
    //initializeKillMoves();
    //getch();


    POINT cursor;

    int x,y, whoWin = 0;
    bool take = false;

    while(1)
    {

        whoWin = ifFinished();


        if(whoWin){

            initwindow(500,300,"MENU",500,300,false,true);
            setcolor(WHITE);
            outtextxy(100,100,"Game Over. PLAYER BLACK has won");
            outtextxy(100,150,"Return to main menu?");
            outtextxy(300,200,"Yes");

            while(1)
            {

                if(GetAsyncKeyState(VK_LBUTTON))
                {
                    GetCursorPos(&cursor);
                    int x=cursor.x;
                    int y=cursor.y-25;
                    printf("%d %d\n",x, y);

                    //Newlyadded
                    if(x>=790&&x<=840&&y>=490&&y<=520){
                        closegraph();
                        main();
                    }

                }
            }

        }

        delay(100);

        GetCursorPos(&cursor);
        x=cursor.x;
        y=cursor.y-25;

        for(int i = 0 ; i < 37 ; i++)
        {
            if(((x>board[i].coord.first-15)&&(x<board[i].coord.first+15))&&((y>board[i].coord.second-15)&&(y<board[i].coord.second+15)))
            {

                //setcolor(WHITE);circle(board[i].coord.first,board[i].coord.second,11);
            }
        }

        if(GetAsyncKeyState(VK_LBUTTON))
        {
            GetCursorPos(&cursor);
            x=cursor.x;
            y=cursor.y-25;

            //Newlyadded
            if(cursor.x>=1090&&cursor.x<=1250&&cursor.y>=800&&cursor.y<=950){
                main();
            }

            if(dontChange)
            {
                for(int i = 0 ; i < 16 ; i++)
                {

                    if(((x>black_pcs[i].first-15)&&(x<black_pcs[i].first+15))&&
                            ((y>black_pcs[i].second-15)&&(y<black_pcs[i].second+15)))
                    {

                        cleardevice();
                        drawBoard();

                        setcolor(BLACK);
                        circle(black_pcs[i].first,black_pcs[i].second,11);
                        circle(black_pcs[i].first,black_pcs[i].second,12);
                        circle(black_pcs[i].first,black_pcs[i].second,13);

                        take = mouseControl2(i,PLAYER_BLACK);
                        //while(!take) take = mouseControl2(i,PLAYER_BLACK);

                        if(take&&AI_MODE) gameAI();

                        else if(take)WhitesMove = false;

                    }

                }


                for(int i = 0 ; i < 16 ; i++)
                {
                    if(((x>red_pcs[i].first-15)&&(x<red_pcs[i].first+15))&&
                            ((y>red_pcs[i].second-15)&&(y<red_pcs[i].second+15)))
                    {

                        cleardevice();
                        drawBoard();

                        setcolor(RED);
                        circle(red_pcs[i].first,red_pcs[i].second,11);
                        circle(red_pcs[i].first,red_pcs[i].second,12);
                        circle(red_pcs[i].first,red_pcs[i].second,13);

                        take = mouseControl2(i,PLAYER_RED);

                        if(take&&AI_MODE) gameAI();

                        else if(take)WhitesMove = true;
                    }
                }

                continue;
            }


            //Done
            if(WhitesMove)
                for(int i = 0 ; i < 16 ; i++)
                {
                    if(((x>black_pcs[i].first-15)&&(x<black_pcs[i].first+15))&&
                            ((y>black_pcs[i].second-15)&&(y<black_pcs[i].second+15)))
                    {

                        cleardevice();
                        drawBoard();

                        setcolor(BLACK);
                        circle(black_pcs[i].first,black_pcs[i].second,16);//11);
                        circle(black_pcs[i].first,black_pcs[i].second,18);//12);
                        circle(black_pcs[i].first,black_pcs[i].second,20);//13);

                        take = mouseControl2(i,PLAYER_BLACK);
                        //while(!take) take = mouseControl2(i,PLAYER_BLACK);

                        if(take&&AI_MODE) gameAI();

                        else if(take)WhitesMove = false;
                    }
                }


            else
                for(int i = 0 ; i < 16 ; i++)
                {
                    if(((x>red_pcs[i].first-15)&&(x<red_pcs[i].first+15))&&
                            ((y>red_pcs[i].second-15)&&(y<red_pcs[i].second+15)))
                    {

                        cleardevice();
                        drawBoard();

                        setcolor(RED);
                        circle(red_pcs[i].first,red_pcs[i].second,16);//11);
                        circle(red_pcs[i].first,red_pcs[i].second,18);//12);
                        circle(red_pcs[i].first,red_pcs[i].second,20);//13);

                        take = mouseControl2(i,PLAYER_RED);

                        if(take&&AI_MODE) gameAI();

                        else if(take)WhitesMove = true;
                    }
                }

        }
    }

    closegraph();
    //cleardevice();

    initwindow(500,300,"MENU",0,0,false,true);
    printf("\nPLAYER %d WINS THE GAME\n",whoWin);
    menu();
}
