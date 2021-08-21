#include<stdio.h>
#include<graphics.h>
#include<iostream>
#include "header.hpp"
#include<queue>
#include<stdlib.h>

using namespace std;

extern bool dontChange;

extern pair<int,int> yellow_pcs[16];
extern pair<int,int> white_pcs[16];

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

    if(who==PLAYER_WHITE)
    {

        for(int i = 0 ; i < 16 ; i++)
        {
            if(white_pcs[i]!=make_pair(0,0)) sc++;
        }

    }

    else{

        for(int i = 0 ; i < 16 ; i++)
        {
            if(yellow_pcs[i]!=make_pair(0,0)) sc++;
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

        if(white_pcs[i]!=make_pair(0,0))
        {
            take = PLAYER_WHITE;
            break;

        }
    }


    for(int i = 0 ; i < 16 ; i++)
    {

        if(yellow_pcs[i]!=make_pair(0,0))
        {

            if(take==PLAYER_WHITE) return 0;

            else{
                leaderboardSave(PLAYER_YELLOW,score(PLAYER_YELLOW));
                return PLAYER_YELLOW;
            }

        }

    }
    leaderboardSave(PLAYER_WHITE,score(PLAYER_WHITE));
    return PLAYER_WHITE;
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
            if(((x>board[i].coord.first-10)&&(x<board[i].coord.first+10))&&((y>board[i].coord.second-10)&&(y<board[i].coord.second+10)))
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
                if(((x>board[i].coord.first-10)&&(x<board[i].coord.first+10))&&((y>board[i].coord.second-10)&&(y<board[i].coord.second+10)))
                {
                    if(pieceAvailable(board[i].coord)) break;


                    if(color==PLAYER_WHITE)
                        take = move_piece(j,i,PLAYER_WHITE);

                    else
                        take = move_piece(j,i,PLAYER_YELLOW);


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
            if(((x>board[i].coord.first-10)&&(x<board[i].coord.first+10))&&((y>board[i].coord.second-10)&&(y<board[i].coord.second+10)))
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

                    if(((x>white_pcs[i].first-10)&&(x<white_pcs[i].first+10))&&
                            ((y>white_pcs[i].second-10)&&(y<white_pcs[i].second+10)))
                    {

                        cleardevice();
                        drawBoard();

                        setcolor(BLACK);
                        circle(white_pcs[i].first,white_pcs[i].second,11);
                        circle(white_pcs[i].first,white_pcs[i].second,12);
                        circle(white_pcs[i].first,white_pcs[i].second,13);

                        take = mouseControl2(i,PLAYER_WHITE);
                        //while(!take) take = mouseControl2(i,PLAYER_WHITE);

                        if(take&&AI_MODE) gameAI();

                        else if(take)WhitesMove = false;

                    }

                }


                for(int i = 0 ; i < 16 ; i++)
                {
                    if(((x>yellow_pcs[i].first-10)&&(x<yellow_pcs[i].first+10))&&
                            ((y>yellow_pcs[i].second-10)&&(y<yellow_pcs[i].second+10)))
                    {

                        cleardevice();
                        drawBoard();

                        setcolor(RED);
                        circle(yellow_pcs[i].first,yellow_pcs[i].second,11);
                        circle(yellow_pcs[i].first,yellow_pcs[i].second,12);
                        circle(yellow_pcs[i].first,yellow_pcs[i].second,13);

                        take = mouseControl2(i,PLAYER_YELLOW);

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
                    if(((x>white_pcs[i].first-10)&&(x<white_pcs[i].first+10))&&
                            ((y>white_pcs[i].second-10)&&(y<white_pcs[i].second+10)))
                    {

                        cleardevice();
                        drawBoard();

                        setcolor(BLACK);
                        circle(white_pcs[i].first,white_pcs[i].second,16);//11);
                        circle(white_pcs[i].first,white_pcs[i].second,18);//12);
                        circle(white_pcs[i].first,white_pcs[i].second,20);//13);

                        take = mouseControl2(i,PLAYER_WHITE);
                        //while(!take) take = mouseControl2(i,PLAYER_WHITE);

                        if(take&&AI_MODE) gameAI();

                        else if(take)WhitesMove = false;
                    }
                }


            else
                for(int i = 0 ; i < 16 ; i++)
                {
                    if(((x>yellow_pcs[i].first-10)&&(x<yellow_pcs[i].first+10))&&
                            ((y>yellow_pcs[i].second-10)&&(y<yellow_pcs[i].second+10)))
                    {

                        cleardevice();
                        drawBoard();

                        setcolor(RED);
                        circle(yellow_pcs[i].first,yellow_pcs[i].second,16);//11);
                        circle(yellow_pcs[i].first,yellow_pcs[i].second,18);//12);
                        circle(yellow_pcs[i].first,yellow_pcs[i].second,20);//13);

                        take = mouseControl2(i,PLAYER_YELLOW);

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
