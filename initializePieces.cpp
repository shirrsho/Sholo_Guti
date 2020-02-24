
//#include<graphics.h>
#include "header.h"
#include<stdio.h>

struct Piece{
    int coX;
    int coY;
    int color;
}redPieces[16],grayPiece[16];


void initializePieces(){

    int i = 0;

    for( ; i < 16 ; i++){
        redPieces[i].color = REDS;
        grayPiece[i].color = GRAYS;
    }

    redPieces[0].coX = TRIANGLE_STARTING;redPieces[0].coY = SPACE_VERTICAL;
    redPieces[0].coX = TRIANGLE_STARTING;redPieces[0].coY = SPACE_VERTICAL;
    redPieces[0].coX = TRIANGLE_STARTING;redPieces[0].coY = SPACE_VERTICAL;
    redPieces[0].coX = TRIANGLE_STARTING;redPieces[0].coY = SPACE_VERTICAL;
    redPieces[0].coX = TRIANGLE_STARTING;redPieces[0].coY = SPACE_VERTICAL;
    redPieces[0].coX = TRIANGLE_STARTING;redPieces[0].coY = SPACE_VERTICAL;
    redPieces[0].coX = TRIANGLE_STARTING;redPieces[0].coY = SPACE_VERTICAL;
    redPieces[0].coX = TRIANGLE_STARTING;redPieces[0].coY = SPACE_VERTICAL;
    redPieces[0].coX = TRIANGLE_STARTING;redPieces[0].coY = SPACE_VERTICAL;
    redPieces[0].coX = TRIANGLE_STARTING;redPieces[0].coY = SPACE_VERTICAL;
    redPieces[0].coX = TRIANGLE_STARTING;redPieces[0].coY = SPACE_VERTICAL;
    redPieces[0].coX = TRIANGLE_STARTING;redPieces[0].coY = SPACE_VERTICAL;
    redPieces[0].coX = TRIANGLE_STARTING;redPieces[0].coY = SPACE_VERTICAL;
    redPieces[0].coX = TRIANGLE_STARTING;redPieces[0].coY = SPACE_VERTICAL;
    redPieces[0].coX = TRIANGLE_STARTING;redPieces[0].coY = SPACE_VERTICAL;
    redPieces[0].coX = TRIANGLE_STARTING;redPieces[0].coY = SPACE_VERTICAL;
}
