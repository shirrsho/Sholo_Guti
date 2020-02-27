#include<graphics.h>
#include "header.hpp"

void placePieces(int x, int y){

    //setcolor(WHITE);

    for(int i = 5 ; i <= 10; i++)
        circle(x,y,i);

}
