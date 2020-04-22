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
    printf("\n\n\t\tPlay one of the most common game of rural Bangladesh\n\n");
    printf("\t\t1. Two Player\n\t\t2. vs Computer\n\n\n");
    printf("Enter your choice: ");

    int selected;
    scanf("%d",&selected);

//    TWO_PLAYER_MODE = true;
//        initializePieces();
//        initwindow(1530,850,"GAME",0,0,false,true);
//        drawBoard();
//        mouseControl();

    if(selected == 1){
        TWO_PLAYER_MODE = true;
        initializePieces();
        initwindow(1530,850,"GAME",0,0,false,true);
        drawBoard();
        mouseControl();
    }
    else if(selected == 2){
        AI_MODE = true;
        initializePieces();
        initwindow(1530,850,"GAME",0,0,false,true);
        drawBoard();
        mouseControl();
    }
}
