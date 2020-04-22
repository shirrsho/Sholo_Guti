#include<stdio.h>
#include<graphics.h>
#include<iostream>
#include "header.hpp"
#include<list>
#include<queue>

using namespace std;

extern pair<int,int> yellow_pcs[16];
extern pair<int,int> white_pcs[16];

extern struct Board{
    pair<int,int> coord;
    queue< pair<int,int> > neighs;
    queue< pair<int,int> > lines;

}board[37];

void drawBoard(){


    //setbkcolor(2);

    //int x = BOX_STARTING;
    //int y = SPACE_VERTICAL+TRIANGLE_HEIGHT;


    setcolor(LIGHTBLUE);


    //top triangle
    line(TRIANGLE_STARTING,SPACE_VERTICAL,TRIANGLE_ENDING,SPACE_VERTICAL);
    line(TRIANGLE_STARTING+TRIANGLE_BASE/4,SPACE_VERTICAL+TRIANGLE_HEIGHT/2,
         TRIANGLE_STARTING+3*TRIANGLE_BASE/4,SPACE_VERTICAL+TRIANGLE_HEIGHT/2);
    line(TRIANGLE_STARTING,SPACE_VERTICAL,BOX_STARTING+BOX_LENGTH/2,SPACE_VERTICAL+TRIANGLE_HEIGHT);
    line(TRIANGLE_ENDING,SPACE_VERTICAL,BOX_STARTING+BOX_LENGTH/2,SPACE_VERTICAL+TRIANGLE_HEIGHT);
    line(TRIANGLE_STARTING+TRIANGLE_BASE/2,SPACE_VERTICAL,TRIANGLE_STARTING+TRIANGLE_BASE/2,SPACE_VERTICAL+TRIANGLE_HEIGHT);


    //box
    line(BOX_STARTING,SPACE_VERTICAL+TRIANGLE_HEIGHT,BOX_ENDING,SPACE_VERTICAL+TRIANGLE_HEIGHT);
    line(BOX_STARTING,SPACE_VERTICAL+TRIANGLE_HEIGHT,BOX_STARTING,SPACE_VERTICAL+TRIANGLE_HEIGHT+BOX_LENGTH);
    line(BOX_STARTING,SPACE_VERTICAL+TRIANGLE_HEIGHT+BOX_LENGTH,
         BOX_STARTING+BOX_LENGTH,SPACE_VERTICAL+TRIANGLE_HEIGHT+BOX_LENGTH);
    line(BOX_ENDING,SPACE_VERTICAL+TRIANGLE_HEIGHT,BOX_ENDING,SPACE_VERTICAL+TRIANGLE_HEIGHT+BOX_LENGTH);

    //grid
    line(BOX_STARTING,SPACE_VERTICAL+TRIANGLE_HEIGHT+PLACE_WIDTH,BOX_ENDING,SPACE_VERTICAL+TRIANGLE_HEIGHT+PLACE_WIDTH);
    line(BOX_STARTING,SPACE_VERTICAL+TRIANGLE_HEIGHT+2*PLACE_WIDTH,BOX_ENDING,SPACE_VERTICAL+TRIANGLE_HEIGHT+2*PLACE_WIDTH);
    line(BOX_STARTING,SPACE_VERTICAL+TRIANGLE_HEIGHT+3*PLACE_WIDTH,BOX_ENDING,SPACE_VERTICAL+TRIANGLE_HEIGHT+3*PLACE_WIDTH);

    line(BOX_STARTING+PLACE_WIDTH,SPACE_VERTICAL+TRIANGLE_HEIGHT,BOX_STARTING+PLACE_WIDTH,SPACE_VERTICAL+BOX_LENGTH+TRIANGLE_HEIGHT);
    line(BOX_STARTING+2*PLACE_WIDTH,SPACE_VERTICAL+TRIANGLE_HEIGHT,BOX_STARTING+2*PLACE_WIDTH,SPACE_VERTICAL+BOX_LENGTH+TRIANGLE_HEIGHT);
    line(BOX_STARTING+3*PLACE_WIDTH,SPACE_VERTICAL+TRIANGLE_HEIGHT,BOX_STARTING+3*PLACE_WIDTH,SPACE_VERTICAL+BOX_LENGTH+TRIANGLE_HEIGHT);

        //diagonals
        line(BOX_STARTING,SPACE_VERTICAL+TRIANGLE_HEIGHT,BOX_ENDING,SPACE_VERTICAL+TRIANGLE_HEIGHT+BOX_LENGTH);
        //line(BOX_STARTING+PLACE_WIDTH,SPACE_VERTICAL+TRIANGLE_HEIGHT,BOX_ENDING,SPACE_VERTICAL+TRIANGLE_HEIGHT+BOX_LENGTH-PLACE_WIDTH);
        line(BOX_STARTING+2*PLACE_WIDTH,SPACE_VERTICAL+TRIANGLE_HEIGHT,BOX_ENDING,SPACE_VERTICAL+TRIANGLE_HEIGHT+BOX_LENGTH-2*PLACE_WIDTH);
        //line(BOX_STARTING+3*PLACE_WIDTH,SPACE_VERTICAL+TRIANGLE_HEIGHT,BOX_ENDING,SPACE_VERTICAL+TRIANGLE_HEIGHT+BOX_LENGTH-3*PLACE_WIDTH);
        //line(BOX_STARTING,SPACE_VERTICAL+TRIANGLE_HEIGHT+PLACE_WIDTH,BOX_ENDING-PLACE_WIDTH,SPACE_VERTICAL+TRIANGLE_HEIGHT+BOX_LENGTH);
        line(BOX_STARTING,SPACE_VERTICAL+TRIANGLE_HEIGHT+2*PLACE_WIDTH,BOX_ENDING-2*PLACE_WIDTH,SPACE_VERTICAL+TRIANGLE_HEIGHT+BOX_LENGTH);
        //line(BOX_STARTING,SPACE_VERTICAL+TRIANGLE_HEIGHT+3*PLACE_WIDTH,BOX_ENDING-3*PLACE_WIDTH,SPACE_VERTICAL+TRIANGLE_HEIGHT+BOX_LENGTH);

        line(BOX_ENDING,SPACE_VERTICAL+TRIANGLE_HEIGHT,BOX_STARTING,SPACE_VERTICAL+TRIANGLE_HEIGHT+BOX_LENGTH);
        //line(BOX_ENDING-PLACE_WIDTH,SPACE_VERTICAL+TRIANGLE_HEIGHT,BOX_STARTING,SPACE_VERTICAL+TRIANGLE_HEIGHT+BOX_LENGTH-PLACE_WIDTH);
        line(BOX_ENDING-2*PLACE_WIDTH,SPACE_VERTICAL+TRIANGLE_HEIGHT,BOX_STARTING,SPACE_VERTICAL+TRIANGLE_HEIGHT+BOX_LENGTH-2*PLACE_WIDTH);
        //line(BOX_ENDING-3*PLACE_WIDTH,SPACE_VERTICAL+TRIANGLE_HEIGHT,BOX_STARTING,SPACE_VERTICAL+TRIANGLE_HEIGHT+BOX_LENGTH-3*PLACE_WIDTH);
        //line(BOX_ENDING,SPACE_VERTICAL+TRIANGLE_HEIGHT+PLACE_WIDTH,BOX_STARTING+PLACE_WIDTH,SPACE_VERTICAL+TRIANGLE_HEIGHT+BOX_LENGTH);
        line(BOX_ENDING,SPACE_VERTICAL+TRIANGLE_HEIGHT+2*PLACE_WIDTH,BOX_STARTING+2*PLACE_WIDTH,SPACE_VERTICAL+TRIANGLE_HEIGHT+BOX_LENGTH);
        //line(BOX_ENDING,SPACE_VERTICAL+TRIANGLE_HEIGHT+3*PLACE_WIDTH,BOX_STARTING+3*PLACE_WIDTH,SPACE_VERTICAL+TRIANGLE_HEIGHT+BOX_LENGTH);



    //bottom triangle
    line(TRIANGLE_STARTING,SPACE_VERTICAL+TRIANGLE_HEIGHT+BOX_LENGTH+TRIANGLE_HEIGHT,
         TRIANGLE_ENDING,SPACE_VERTICAL+TRIANGLE_HEIGHT+BOX_LENGTH+TRIANGLE_HEIGHT);
    line(TRIANGLE_STARTING+TRIANGLE_BASE/4,SPACE_VERTICAL+TRIANGLE_HEIGHT+BOX_LENGTH+TRIANGLE_HEIGHT/2,
         TRIANGLE_STARTING+3*TRIANGLE_BASE/4,SPACE_VERTICAL+TRIANGLE_HEIGHT+BOX_LENGTH+TRIANGLE_HEIGHT/2);
    line(TRIANGLE_STARTING,SPACE_VERTICAL+TRIANGLE_HEIGHT+BOX_LENGTH+TRIANGLE_HEIGHT,
         BOX_STARTING+BOX_LENGTH/2,SPACE_VERTICAL+TRIANGLE_HEIGHT+BOX_LENGTH);
    line(TRIANGLE_ENDING,SPACE_VERTICAL+TRIANGLE_HEIGHT+BOX_LENGTH+TRIANGLE_HEIGHT,
         BOX_STARTING+BOX_LENGTH/2,SPACE_VERTICAL+TRIANGLE_HEIGHT+BOX_LENGTH);
    line(TRIANGLE_STARTING+TRIANGLE_BASE/2,SPACE_VERTICAL+TRIANGLE_HEIGHT+BOX_LENGTH,
         TRIANGLE_STARTING+TRIANGLE_BASE/2,SPACE_VERTICAL+TRIANGLE_HEIGHT+BOX_LENGTH+TRIANGLE_HEIGHT);

    //placePieces(x,y);

    //WhitePiecs piece();
    //(BOX_STARTING,SPACE_VERTICAL+TRIANGLE_HEIGHT,10);
    //piece.placePieces(BOX_STARTING,SPACE_VERTICAL+TRIANGLE_HEIGHT);


    //getch();

    //scanf("%d%d",&x,&y);

    //drawBoard();

    for(int i = 0 ; i < 16 ; i++){
        //printf("%d %d\n",white_pcs[i].first,white_pcs[i].second);
        setcolor(WHITE);
        placePieces(white_pcs[i].first,white_pcs[i].second);
        setcolor(LIGHTGREEN);
        placePieces(yellow_pcs[i].first,yellow_pcs[i].second);
    }
    setcolor(WHITE);
    for(int i = 0 ; i < 37 ; i++){
        circle(board[i].coord.first,board[i].coord.second,5);
    }
//
//    for(int i = 0 ; i < 16 ;i ++){
//        printf("%d %d\t%d %d\n",white_pcs[i].first,white_pcs[i].second,yellow_pcs[i].first,yellow_pcs[i].second);
//    }
    //getch();
    //scanf("%d%d",&x,&y);
//    POINT cursor;
//    while(1){
//    if(GetAsyncKeyState(VK_LBUTTON)){
//        GetCursorPos(&cursor);x=cursor.x;y=cursor.y-25;
//        printf("\n%d %d",x,y);
//        //for(int i = 0 ; i < 16 ; i++){
//            if(((x>white_pcs[0].first-10)&&(x<white_pcs[0].first+10))&&((y>white_pcs[0].second-10)&&(y<white_pcs[0].second+10)))
//                //if((y>white_pcs[0].second-10)&&(y<white_pcs[0].second+10))
//                move_piece(white_pcs[0],make_pair(BOX_STARTING,SPACE_VERTICAL+TRIANGLE_HEIGHT+PLACE_WIDTH*2),1);
//            //}
//        //}
//        break;
//    }}

    //mouseControl();
    //getch();

    //closegraph();
}
