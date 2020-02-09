#include<graphics.h>
#include "header.h"

void placePieces(int x, int y){
    setcolor(WHITE);
    circle(x,y,10);
    setfillstyle(SOLID_FILL,LIGHTGRAY);
    floodfill(BOX_STARTING,SPACE_VERTICAL+TRIANGLE_HEIGHT,WHITE);
}
