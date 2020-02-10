#include<stdio.h>
#include<graphics.h>
#include "header.h"

struct Piece{
    int coX;
    int coY;
    int color;
}redPieces[16],grayPiece[16];

int main(){

    drawBoard();
    //placePieces();
    return 0;
}
