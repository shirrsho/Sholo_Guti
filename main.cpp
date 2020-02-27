#include<stdio.h>
#include<graphics.h>
#include "header.hpp"
#include<utility>
#include<iostream>

using namespace std;



//struct Piece{
//    int coX;
//    int coY;
//    int color;
//}redPieces[16],grayPiece[16];

int main(){
    initializePieces();
    drawBoard();
    //placePieces();
    return 0;
}
