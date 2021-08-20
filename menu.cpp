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


/*

    - This is the very first menu come into view after launching the application

    - Game Background color is set to WHITE

    - Pieces are BLACK and RED

*/


void menu()
{

    TWO_PLAYER_MODE = AI_MODE = false;
    //Game Window
    initwindow(1530,850,"MENU",0,0,false,true);
    cleardevice();

    //Menu Items
    settextstyle(10,0,5);
    setcolor(WHITE);
    outtextxy(600,150,"Two Player");
    outtextxy(600,200,"AI Mode");
    outtextxy(600,250,"AI vs AI");


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
            else continue;
            break;
        }

        if(cursor.x>=600&&cursor.x<=800&&cursor.y>=175&&cursor.y<=220)
        {
            cleardevice();
            settextstyle(10,0,5);
            setcolor(LIGHTRED);
            outtextxy(600,150,"Two Player");
            setcolor(WHITE);
            outtextxy(600,200,"AI Mode");
            outtextxy(600,250,"AI vs AI");
            turn=0;

        }

        else if(cursor.x>=600&&cursor.x<=800&&cursor.y>=225&&cursor.y<=275)
        {
            cleardevice();
            settextstyle(10,0,5);
            setcolor(WHITE);
            outtextxy(600,150,"Two Player");
            setcolor(LIGHTRED);
            outtextxy(600,200,"AI Mode");
            setcolor(WHITE);
            outtextxy(600,250,"AI vs AI");
            turn=1;

        }

        else if(cursor.x>=600&&cursor.x<=800&&cursor.y>=275&&cursor.y<=320)
        {

            cleardevice();
            settextstyle(10,0,5);
            setcolor(WHITE);
            outtextxy(600,150,"Two Player");
            outtextxy(600,200,"AI Mode");
            setcolor(LIGHTRED);
            outtextxy(600,250,"AI vs AI");
            turn=2;

        }

        else if(turn<3)
        {
            turn+=3;
            settextstyle(10,0,5);
            setcolor(WHITE);
            outtextxy(600,150,"Two Player");
            outtextxy(600,200,"AI Mode");
            outtextxy(600,250,"AI vs AI");
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
        outtextxy(600,200,"Tough");
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
                setcolor(WHITE);
                outtextxy(600,200,"Tough");
                turn=0;

            }

            else if(cursor.x>=600&&cursor.x<=800&&cursor.y>=225&&cursor.y<=275)
            {
                cleardevice();
                settextstyle(10,0,5);
                setcolor(WHITE);
                outtextxy(600,150,"Regular");
                setcolor(LIGHTRED);
                outtextxy(600,200,"Tough");
                turn=1;

            }

            else if(turn<2)
            {
                turn+=2;
                settextstyle(10,0,5);
                setcolor(WHITE);
                outtextxy(600,150,"Regular");
                outtextxy(600,200,"Tough");

            }

        }
        //

        setbkcolor(WHITE);
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
        initializePieces();
        cleardevice();
        setbkcolor(WHITE);
        drawBoard();
        AIvAI();

    }
}
