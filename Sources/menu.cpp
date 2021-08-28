#include<stdio.h>
#include<graphics.h>
#include "header.hpp"
#include<utility>
#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

bool TWO_PLAYER_MODE = false;       //Game mode indicator
bool AI_MODE = false;
bool AI_AI = false;
bool REG_AI = false;



/*

    - This is the very first menu come into view after launching the application

    - Game Background color is set to WHITE

    - Pieces are BLACK and RED

*/


void menu()
{

    AI_AI = TWO_PLAYER_MODE = AI_MODE = false;
    //Game Window
    initwindow(1530,850,"MENU",0,0,false,true);

    cleardevice();

    //Menu Items
    settextstyle(10,0,5);
    setcolor(WHITE);
    outtextxy(600,150,"Two Player");
    rectangle(590,150,860,190);
    outtextxy(600,200,"vs Machine");
    rectangle(590,200,860,240);
    outtextxy(600,250,"AI vs AI");
    rectangle(590,250,860,290);
    outtextxy(600,450,"Scoreboard");
    rectangle(590,450,900,490);
    //rectangle(590,150,860,190);

    rectangle(550,80,950,600);
    rectangle(549,79,949,599);
    rectangle(548,78,948,598);
    //leaderboardView();
    //getch();


    int turn = 45,X,Y;
    int selected = -1;


    POINT cursor;

    while(1)
    {
        delay(100);

        GetCursorPos(&cursor);

        if(GetAsyncKeyState(VK_LBUTTON))
        {
            if(turn == 0) selected = 1;
            else if(turn == 1) selected = 2;
            else if(turn == 2) selected = 3;
            else if(turn == 3) selected = 4;
            else continue;
            break;
        }

        if(cursor.x>=600&&cursor.x<=800&&cursor.y>=175&&cursor.y<=220)
        {
            cleardevice();
            settextstyle(10,0,5);
            setcolor(LIGHTRED);
            outtextxy(600,150,"Two Player");
            rectangle(590,150,860,190);
            rectangle(550,80,950,600);
            rectangle(549,79,949,599);
            rectangle(548,78,948,598);
            setcolor(WHITE);
            outtextxy(600,200,"vs Machine");
            rectangle(590,200,860,240);
            outtextxy(600,250,"AI vs AI");
            rectangle(590,250,860,290);
            outtextxy(600,450,"Scoreboard");
            rectangle(590,450,900,490);
            turn=0;

        }

        else if(cursor.x>=600&&cursor.x<=800&&cursor.y>=225&&cursor.y<=275)
        {
            cleardevice();
            settextstyle(10,0,5);
            setcolor(WHITE);
            outtextxy(600,150,"Two Player");
            rectangle(590,150,860,190);
            setcolor(LIGHTRED);
            outtextxy(600,200,"vs Machine");
            rectangle(590,200,860,240);
            rectangle(550,80,950,600);
            rectangle(549,79,949,599);
            rectangle(548,78,948,598);
            setcolor(WHITE);
            outtextxy(600,250,"AI vs AI");
            rectangle(590,250,860,290);
            outtextxy(600,450,"Scoreboard");
            rectangle(590,450,900,490);
            turn=1;

        }

        else if(cursor.x>=600&&cursor.x<=800&&cursor.y>=275&&cursor.y<=320)
        {

            cleardevice();
            settextstyle(10,0,5);
            setcolor(WHITE);
            outtextxy(600,150,"Two Player");
            rectangle(590,150,860,190);
            outtextxy(600,200,"vs Machine");
            rectangle(590,200,860,240);
            outtextxy(600,450,"Scoreboard");
            rectangle(590,450,900,490);
            setcolor(LIGHTRED);
            outtextxy(600,250,"AI vs AI");
            rectangle(590,250,860,290);
            rectangle(550,80,950,600);
            rectangle(549,79,949,599);
            rectangle(548,78,948,598);
            turn=2;

        }

        else if(cursor.x>=600&&cursor.x<=800&&cursor.y>=475&&cursor.y<=520)
        {

            cleardevice();
            settextstyle(10,0,5);
            setcolor(WHITE);
            outtextxy(600,150,"Two Player");
            rectangle(590,150,860,190);
            outtextxy(600,200,"vs Machine");
            rectangle(590,200,860,240);
            outtextxy(600,250,"AI vs AI");
            rectangle(590,250,860,290);
            setcolor(LIGHTRED);
            outtextxy(600,450,"Scoreboard");
            rectangle(590,450,900,490);
            rectangle(550,80,950,600);
            rectangle(549,79,949,599);
            rectangle(548,78,948,598);
            turn=3;

        }

        else if(turn<4)
        {
            turn+=4;
            settextstyle(10,0,5);
            setcolor(WHITE);
            outtextxy(600,150,"Two Player");
            rectangle(590,150,860,190);
            outtextxy(600,200,"vs Machine");
            rectangle(590,200,860,240);
            outtextxy(600,250,"AI vs AI");
            rectangle(590,250,860,290);
            outtextxy(600,450,"Scoreboard");
            rectangle(590,450,900,490);
            rectangle(550,80,950,600);
            rectangle(549,79,949,599);
            rectangle(548,78,948,598);
        }

    }



    if(selected == 1)
    {
        setbkcolor(WHITE);
        TWO_PLAYER_MODE = true;
        initializePieces();
        cleardevice();
        setbkcolor(WHITE);
        drawBoard();
        mouseControl();
    }

    else if(selected == 2)
    {
        cleardevice();
        settextstyle(10,0,5);
        setcolor(WHITE);
        outtextxy(600,150,"Regular");
        rectangle(590,150,860,190);
        outtextxy(600,200,"Tough");
        rectangle(590,200,860,240);
        rectangle(550,80,950,600);
        rectangle(549,79,949,599);
        rectangle(548,78,948,598);
        selected = -1;
        turn = 45;

        //
        while(1)
        {
            delay(100);
            GetCursorPos(&cursor);

            if(GetAsyncKeyState(VK_LBUTTON))
            {
                if(turn == 0) selected = 1;
                else if(turn == 1) selected = 2;
                else continue;
                break;
            }

            if(cursor.x>=600&&cursor.x<=800&&cursor.y>=175&&cursor.y<=220)
            {
                cleardevice();
                settextstyle(10,0,5);
                setcolor(LIGHTRED);
                outtextxy(600,150,"Regular");
                rectangle(590,150,860,190);
                rectangle(550,80,950,600);
                rectangle(549,79,949,599);
                rectangle(548,78,948,598);
                setcolor(WHITE);
                outtextxy(600,200,"Tough");
                rectangle(590,200,860,240);
                turn=0;

            }

            else if(cursor.x>=600&&cursor.x<=800&&cursor.y>=225&&cursor.y<=275)
            {
                cleardevice();
                settextstyle(10,0,5);
                setcolor(WHITE);
                outtextxy(600,150,"Regular");
                rectangle(590,150,860,190);
                setcolor(LIGHTRED);
                outtextxy(600,200,"Tough");
                rectangle(590,200,860,240);
                rectangle(550,80,950,600);
                rectangle(549,79,949,599);
                rectangle(548,78,948,598);
                turn=1;

            }

            else if(turn<2)
            {
                turn+=2;
                settextstyle(10,0,5);
                setcolor(WHITE);
                outtextxy(600,150,"Regular");
                rectangle(590,150,860,190);
                outtextxy(600,200,"Tough");
                rectangle(590,200,860,240);
                rectangle(550,80,950,600);
                rectangle(549,79,949,599);
                rectangle(548,78,948,598);

            }

        }
        //

        setbkcolor(WHITE);
        REG_AI = false;
        AI_AI = false;
        if(selected == 1) REG_AI = true;
        AI_MODE = true;
        initializePieces();
        cleardevice();
        setbkcolor(WHITE);
        drawBoard();
        mouseControl();

    }

    else if(selected == 3)
    {
        setbkcolor(WHITE);
        AI_MODE = true;
        AI_AI = true;
        initializePieces();
        cleardevice();
        setbkcolor(WHITE);
        drawBoard();
        AIvAI();

    }
    else if(selected == 4)
    {
        //setbkcolor(WHITE);
        //AI_MODE = true;
        //initializePieces();
        cleardevice();
        leaderboardView();
        //setbkcolor(WHITE);
        //drawBoard();
        //AIvAI();

    }
}
