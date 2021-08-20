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

    - Background color is set to LIGHTGRAY

    - Pieces are BLACK and RED

*/
void menu()
{
    TWO_PLAYER_MODE = AI_MODE = false;
    //closegraph();
    initwindow(1530,850,"MENU",0,0,false,true);
    //setbkcolor(WHITE);
    cleardevice();
    //setbkcolor(WHITE);
    settextstyle(10,0,5);
    setcolor(WHITE);
    //setbkcolor(WHITE);
    outtextxy(600,150,"Two Player");
    outtextxy(600,200,"AI Mode");
    int turn = 45,X,Y;
    int selected = -1;
    //setbkcolor(LIGHTGRAY);
    POINT cursor;
    while(1)
    {
        delay(100);
        GetCursorPos(&cursor);
        //setbkcolor(LIGHTGRAY);
        if(GetAsyncKeyState(VK_LBUTTON))
        {
            //setbkcolor(LIGHTGRAY);
            if(turn == 0) selected = 1;
            else if(turn == 1) selected = 2;
            else continue;
            break;
        }
        if(cursor.x>=600&&cursor.x<=800&&cursor.y>=175&&cursor.y<=220)
        {
            //setbkcolor(WHITE);
            if(1)//(turn!=0)
            {
                //setbkcolor(WHITE);
                cleardevice();
                //initwindow(1530,850,"MENU",0,0,false,true);
                //setbkcolor(LIGHTGRAY);
                settextstyle(10,0,5);
                setcolor(LIGHTRED);
                outtextxy(600,150,"Two Player");
                setcolor(WHITE);
                outtextxy(600,200,"AI Mode");
                turn=0;
            }
        }

        else if(cursor.x>=600&&cursor.x<=800&&cursor.y>=225&&cursor.y<=275)
        {
            if(1)//(turn!=0)
            {
                //setbkcolor(WHITE);
                cleardevice();
                //initwindow(1530,850,"MENU",0,0,false,true);
                //setbkcolor(LIGHTGRAY);
                settextstyle(10,0,5);
                setcolor(WHITE);
                outtextxy(600,150,"Two Player");
                setcolor(LIGHTRED);
                outtextxy(600,200,"AI Mode");
                turn=1;
            }
        }

        else if(turn<2)
        {
            //setbkcolor(WHITE);
            turn+=2;
            //initwindow(1530,850,"MENU",0,0,false,true);
            //setbkcolor(LIGHTGRAY);
            settextstyle(10,0,5);
            setcolor(WHITE);
            outtextxy(600,150,"Two Player");
            outtextxy(600,200,"AI Mode");
            //turn++;
        }
        //setbkcolor(WHITE);
    }
    //getch();
    printf("\n\n\t\tPlay one of the most common game of rural Bangladesh\n\n");
    printf("\t\t1. Two Player\n\t\t2. vs Computer\n\n\n");
    printf("Enter your choice: ");


    //scanf("%d",&selected);

//    TWO_PLAYER_MODE = true;
//        initializePieces();
//        initwindow(1530,850,"GAME",0,0,false,true);
//        drawBoard();
//        mouseControl();


    if(selected == 1)
    {
        setbkcolor(WHITE);
        TWO_PLAYER_MODE = true;
        initializePieces();
        //initwindow(1530,850,"GAME",0,0,false,true);
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
        //setbkcolor(LIGHTGRAY);
        if(GetAsyncKeyState(VK_LBUTTON))
        {
            //setbkcolor(LIGHTGRAY);
            if(turn == 0) selected = 1;
            else if(turn == 1) selected = 2;
            else continue;
            break;
        }
        if(cursor.x>=600&&cursor.x<=800&&cursor.y>=175&&cursor.y<=220)
        {
            if(1)//(turn!=0)
            {
                cleardevice();
                //initwindow(1530,850,"MENU",0,0,false,true);
                //setbkcolor(LIGHTGRAY);
                settextstyle(10,0,5);
                setcolor(LIGHTRED);
                outtextxy(600,150,"Regular");
                setcolor(WHITE);
                outtextxy(600,200,"Tough");
                turn=0;
            }
        }

        else if(cursor.x>=600&&cursor.x<=800&&cursor.y>=225&&cursor.y<=275)
        {
            if(1)//(turn!=0)
            {
                cleardevice();
                //initwindow(1530,850,"MENU",0,0,false,true);
                //setbkcolor(LIGHTGRAY);
                settextstyle(10,0,5);
                setcolor(WHITE);
                outtextxy(600,150,"Regular");
                setcolor(LIGHTRED);
                outtextxy(600,200,"Tough");
                turn=1;
            }
        }

        else if(turn<2)
        {
            //setbkcolor(WHITE);
            turn+=2;
            //initwindow(1530,850,"MENU",0,0,false,true);
            //setbkcolor(LIGHTGRAY);
            settextstyle(10,0,5);
            setcolor(WHITE);
            outtextxy(600,150,"Regular");
            outtextxy(600,200,"Tough");
            //turn++;
        }
        //setbkcolor(LIGHTGRAY);
    }
        //
        setbkcolor(WHITE);
        AI_MODE = true;
        initializePieces();
        //initwindow(1530,850,"GAME",0,0,false,true);
        cleardevice();
        setbkcolor(WHITE);
        drawBoard();
        //mouseControl();
        AIvAI();
    }
}
