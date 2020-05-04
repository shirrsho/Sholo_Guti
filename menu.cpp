#include<stdio.h>
#include<graphics.h>
#include "header.hpp"
#include<utility>
#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

bool TWO_PLAYER_MODE = false;
bool AI_MODE = false;



void menu(){
    closegraph();
    initwindow(1530,850,"MENU",0,0,false,true);
    //setbkcolor(GREEN);
    settextstyle(10,0,5);
    setcolor(LIGHTGREEN);
    outtextxy(600,150,"Two Player");
    outtextxy(600,200,"AI Mode");
    int turn = 45,X,Y;
    int selected;

    POINT cursor;
    while(1){
        delay(100);
        GetCursorPos(&cursor);
        if(GetAsyncKeyState(VK_LBUTTON)){
            if(turn == 0) selected = 1;
            else if(turn == 1) selected = 2;
            else continue;
            break;
        }
        if(cursor.x>=600&&cursor.x<=800&&cursor.y>=175&&cursor.y<=225){\
            if(turn!=0){
            cleardevice();
            //initwindow(1530,850,"MENU",0,0,false,true);
            //setbkcolor(GREEN);
            settextstyle(10,0,5);
            setcolor(LIGHTBLUE);
            outtextxy(600,150,"Two Player");
            setcolor(LIGHTGREEN);
            outtextxy(600,200,"AI Mode");
            turn=0;
            }
        }

        else if(cursor.x>=600&&cursor.x<=800&&cursor.y>=225&&cursor.y<=275){\
            if(turn!=0){
            cleardevice();
            //initwindow(1530,850,"MENU",0,0,false,true);
            //setbkcolor(GREEN);
            settextstyle(10,0,5);
            setcolor(LIGHTGREEN);
            outtextxy(600,150,"Two Player");
            setcolor(LIGHTBLUE);
            outtextxy(600,200,"AI Mode");
            turn=1;
            }
        }

        else if(turn<2){
            turn+=2;
            //initwindow(1530,850,"MENU",0,0,false,true);
            //setbkcolor(GREEN);
            settextstyle(10,0,5);
            setcolor(LIGHTGREEN);
            outtextxy(600,150,"Two Player");
            outtextxy(600,200,"AI Mode");
            //turn++;
        }
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

    if(selected == 1){
        TWO_PLAYER_MODE = true;
        initializePieces();
        //initwindow(1530,850,"GAME",0,0,false,true);
        cleardevice();
        drawBoard();
        mouseControl();
    }
    else if(selected == 2){
        AI_MODE = true;
        initializePieces();
        //initwindow(1530,850,"GAME",0,0,false,true);
        cleardevice();
        drawBoard();
        mouseControl();
    }
}
