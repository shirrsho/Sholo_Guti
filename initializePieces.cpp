
#include<graphics.h>
#include "header.hpp"
#include<utility>
#include<iostream>
#include<stdio.h>
#include<list>
#include<queue>

using namespace std;

pair<int,int> yellow_pcs[16];
pair<int,int> white_pcs[16];

struct Board{
    pair<int,int> coord;
    queue< pair<int,int> > neighs;
    queue< pair<int,int> > lines;
}board[37];

//void generalMoveSelector(){
//    int i;
//    FILE *fp;
//    int aa,bb;
//    fp = fopen("general_moves.txt","r");
//    fscanf(fp,"%d",&i);
//    while(!feof(fp)){//j<37 chilo
//        fscanf(fp,"%d",&aa);
//        if(aa<50){i=aa;continue;}
//        fscanf(fp,"%d",&bb);
//        pair<int,int> a = make_pair(aa,bb);
//        board[i].neighs.push(a);
//    }
//}



void initializePieces()
{
    int it = 6;
    //setcolor(LIGHTGRAY);
    //placePieces(TRIANGLE_STARTING,SPACE_VERTICAL);
    white_pcs[0] = make_pair(TRIANGLE_STARTING,SPACE_VERTICAL);

    //placePieces(TRIANGLE_STARTING+TRIANGLE_BASE/2,SPACE_VERTICAL);
    white_pcs[1] = make_pair(TRIANGLE_STARTING+TRIANGLE_BASE/2,SPACE_VERTICAL);
    //placePieces(TRIANGLE_ENDING,SPACE_VERTICAL);
    white_pcs[2] = make_pair(TRIANGLE_ENDING,SPACE_VERTICAL);
    //placePieces(TRIANGLE_STARTING+TRIANGLE_BASE/4,SPACE_VERTICAL+TRIANGLE_HEIGHT/2);
    white_pcs[3] = make_pair(TRIANGLE_STARTING+TRIANGLE_BASE/4,SPACE_VERTICAL+TRIANGLE_HEIGHT/2);
    //placePieces(TRIANGLE_STARTING+TRIANGLE_BASE/2,SPACE_VERTICAL+TRIANGLE_HEIGHT/2);
    white_pcs[4] = make_pair(TRIANGLE_STARTING+TRIANGLE_BASE/2,SPACE_VERTICAL+TRIANGLE_HEIGHT/2);
    //placePieces(TRIANGLE_STARTING+TRIANGLE_BASE*3/4,SPACE_VERTICAL+TRIANGLE_HEIGHT/2);
    white_pcs[5] = make_pair(TRIANGLE_STARTING+TRIANGLE_BASE*3/4,SPACE_VERTICAL+TRIANGLE_HEIGHT/2);
    for(int i = BOX_STARTING ; i <= BOX_ENDING ; i = i+PLACE_WIDTH){
        //placePieces(i,SPACE_VERTICAL+TRIANGLE_HEIGHT);
        white_pcs[it] = make_pair(i,SPACE_VERTICAL+TRIANGLE_HEIGHT);
        it++;
    }
    for(int i = BOX_STARTING ; i <= BOX_ENDING ; i = i+PLACE_WIDTH){
        //placePieces(i,SPACE_VERTICAL+TRIANGLE_HEIGHT+PLACE_WIDTH);
        white_pcs[it] = make_pair(i,SPACE_VERTICAL+TRIANGLE_HEIGHT+PLACE_WIDTH);
        it++;
    }
    it = 6;

    //setcolor(YELLOW);
    //placePieces(TRIANGLE_STARTING,SPACE_VERTICAL+TRIANGLE_HEIGHT*2+BOX_LENGTH);
    yellow_pcs[0] = make_pair(TRIANGLE_STARTING,SPACE_VERTICAL+TRIANGLE_HEIGHT*2+BOX_LENGTH);
    //placePieces(TRIANGLE_STARTING+TRIANGLE_BASE/2,SPACE_VERTICAL+TRIANGLE_HEIGHT*2+BOX_LENGTH);
    yellow_pcs[1] = make_pair(TRIANGLE_STARTING+TRIANGLE_BASE/2,SPACE_VERTICAL+TRIANGLE_HEIGHT*2+BOX_LENGTH);
    //placePieces(TRIANGLE_ENDING,SPACE_VERTICAL+TRIANGLE_HEIGHT*2+BOX_LENGTH);
    yellow_pcs[2] = make_pair(TRIANGLE_ENDING,SPACE_VERTICAL+TRIANGLE_HEIGHT*2+BOX_LENGTH);
    //placePieces(TRIANGLE_STARTING+TRIANGLE_BASE/4,SPACE_VERTICAL+TRIANGLE_HEIGHT+BOX_LENGTH+TRIANGLE_HEIGHT/2);
    yellow_pcs[3] = make_pair(TRIANGLE_STARTING+TRIANGLE_BASE/4,SPACE_VERTICAL+TRIANGLE_HEIGHT+BOX_LENGTH+TRIANGLE_HEIGHT/2);
    //placePieces(TRIANGLE_STARTING+TRIANGLE_BASE/2,SPACE_VERTICAL+TRIANGLE_HEIGHT+BOX_LENGTH+TRIANGLE_HEIGHT/2);
    yellow_pcs[4] = make_pair(TRIANGLE_STARTING+TRIANGLE_BASE/2,SPACE_VERTICAL+TRIANGLE_HEIGHT+BOX_LENGTH+TRIANGLE_HEIGHT/2);
    //placePieces(TRIANGLE_STARTING+TRIANGLE_BASE*3/4,SPACE_VERTICAL+TRIANGLE_HEIGHT+BOX_LENGTH+TRIANGLE_HEIGHT/2);
    yellow_pcs[5] = make_pair(TRIANGLE_STARTING+TRIANGLE_BASE*3/4,SPACE_VERTICAL+TRIANGLE_HEIGHT+BOX_LENGTH+TRIANGLE_HEIGHT/2);

    for(int i = BOX_STARTING ; i <= BOX_ENDING ; i = i+PLACE_WIDTH){
        //placePieces(i,SPACE_VERTICAL+TRIANGLE_HEIGHT+BOX_LENGTH);
        yellow_pcs[it] = make_pair(i,SPACE_VERTICAL+TRIANGLE_HEIGHT+BOX_LENGTH);
        it++;
    }
    for(int i = BOX_STARTING ; i <= BOX_ENDING ; i = i+PLACE_WIDTH){
        //placePieces(i,SPACE_VERTICAL+TRIANGLE_HEIGHT-PLACE_WIDTH+BOX_LENGTH);
        yellow_pcs[it] = make_pair(i,SPACE_VERTICAL+TRIANGLE_HEIGHT-PLACE_WIDTH+BOX_LENGTH);
        it++;
    }

    for(int i = 0; i < 16 ; i++){
        //board[j++].coord = white_pcs[i];
        //board[j++].coord = yellow_pcs[i];
    }

//    board[0].neighs.insert(white_pcs[1]);board[0].neighs.insert(white_pcs[3]);
//    board[1].neighs.insert()

    boardMoveSelector();

    generalMoveSelector();

    killMoveSelector();

//    fp = fopen("general_moves.txt","r");
//    fscanf(fp,"%d",&i);
//    while(!feof(fp)){//j<37 chilo
//        fscanf(fp,"%d",&aa);
//        if(aa<50){i=aa;continue;}
//        fscanf(fp,"%d",&bb);
//        pair<int,int> a = make_pair(aa,bb);
//        board[i].neighs.push(a);
//    }


//    for(int i = 0 ; i < 37 ; i++){
//        printf("\n\n");
//        while(!board[i].neighs.empty()) {
//            printf("%d %d\t",board[i].neighs.front().first,board[i].neighs.front().second);
//            board[i].neighs.pop();
//        }
//    }

    return;
}
