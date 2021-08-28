#include<stdio.h>
#include<graphics.h>
#include<iostream>
#include "header.hpp"
#include<queue>
#include<stdlib.h>

using namespace std;

extern pair<int,int> red_pcs[16];
extern pair<int,int> black_pcs[16];
extern struct Board
{
    pair<int,int> coord;
    queue< pair<int,int> > neighs;
    queue< pair<int,int> > lines;
} board[37];

extern bool WhitesMove;

extern bool TWO_PLAYER_MODE;
extern bool AI_MODE;
extern bool FINAL_MOVE;
extern bool REG_AI;


/*

    - Finds all possible moves

*/


/*
    - ATTENTION !!!
    - When the AI cannot find any safe move for a piece then it misbehaves
    - Updated:: SOlved
*/



std::queue< pair<int,int> > availableGenMoves(std::pair<int,int> x)
{

    generalMoveSelector();
    killMoveSelector();

    std::queue< pair<int,int> > ret;


    while(!ret.empty()) ret.pop();


    for(int i = 0 ; i < 37 ; i++)
    {

        if(board[i].coord == x)
        {

            while(!board[i].neighs.empty())
            {

                if(!pieceAvailable(board[i].neighs.front()))
                    ret.push(board[i].neighs.front());

                board[i].neighs.pop();
            }
        }
    }


    generalMoveSelector();

    return ret;
}





/*

    - AI search for a safe move from where he won't be killed down

    - Finds if the next move is safe

*/




bool isMoveSafe(int from,std::pair<int,int> to,int whichPlayer)
{

    killMoveSelector();

    pair<int,int> store,check;

    printf("--%d %d--",black_pcs[from].first,black_pcs[from].second);

    printf("--%d %d--",to.first,to.second);


    if(whichPlayer == PLAYER_BLACK)
    {
        store = black_pcs[from];
        black_pcs[from] = to;
        //for(int i = 0 ; i < 37 ; i++){
        //if(board[i].coord == black_pcs[from]){

        for(int j = 0 ; j < 20 ; j++)
        {

            while(!board[j].lines.empty())
            {
                check = board[j].lines.front();

                board[j].lines.pop();

                if(board[j].lines.empty()) break;

                if(board[j].lines.front() == black_pcs[from])
                {
                    printf("????");
                    board[j].lines.pop();

                    if(!pieceAvailable(check)&&whichPiece(board[j].lines.front())==PLAYER_RED)
                    {
                        printf(" ???");
                        //if(whichPiece(board[j].lines.front()) == PLAYER_RED)
                        black_pcs[from] = store;
                        killMoveSelector();
                        return false;
                    }


                    else if(!pieceAvailable(board[j].lines.front())&&whichPiece(check) == PLAYER_RED)
                    {
                        printf("??");
                        //board[j].lines.pop();
                        //if(board[j].lines.front() == store)
                        black_pcs[from] = store;
                        killMoveSelector();
                        return false;
                    }
                }
            }
        }




        black_pcs[from] = store;

        killMoveSelector();

        return true;
        //}
        //}
    }

    return true;
}




std::queue<int> threatenedPieces(int whichPlayer)
{

    queue<int> ret;

    if(REG_AI) return ret;

    while(!ret.empty())ret.pop();

    if(whichPlayer==PLAYER_BLACK)
    {

        for(int i = 0 ; i < 16 ; i++)
        {

            if(!isMoveSafe(i,black_pcs[i],PLAYER_BLACK))
            {
                ret.push(i);
            }
        }
    }

    return ret;
}




void gameAI()
{

    int indexAI = rand();
    indexAI = indexAI%16;

    int to = rand();
    to = to%37;

    bool move = false;
    int count=0;


    queue< pair<int,int> > genMoves;
    //bool a = killMove(indexAI,to,PLAYER_BLACK);

    killMoveSelector();

    generalMoveSelector();

    queue<int> thrPcs = threatenedPieces(PLAYER_BLACK);


    for(int i = 0 ; i < 16 ; i++)
    {
        killMoveSelector();


        if(black_pcs[i] == make_pair(0,0)) continue;


        while(recursiveKill(i,PLAYER_BLACK)||recursiveKill2(i,PLAYER_BLACK))
        {
            count++;

            delay(500);

            cleardevice();
            drawBoard();

            killMoveSelector();

            move = true;
        }


        if(move) return;
    }
    //return;

    killMoveSelector();

    generalMoveSelector();


    while(!thrPcs.empty())
    {
        genMoves = availableGenMoves(black_pcs[thrPcs.front()]);

        while(!genMoves.empty())
        {
            delay(750);
            printf("\n\n%d %d\n\n",genMoves.front().first,genMoves.front().second);

            if(!isMoveSafe(thrPcs.front(),genMoves.front(),PLAYER_BLACK))
            {
                printf("__tyhi");
                genMoves.pop();
                continue;
            }

            printf("%d %d",genMoves.front().first,genMoves.front().second);

            black_pcs[thrPcs.front()] = genMoves.front();

            cleardevice();
            drawBoard();

            genMoves.pop();
            move = true;
            break;
        }


        thrPcs.pop();


        if(move) return;
    }



    for(int i = 15 ; i >= 0 ; i--)
    {

        genMoves = availableGenMoves(black_pcs[i]);


        while(!genMoves.empty())
        {
            delay(750);
            printf("\n\n%d %d\n\n",genMoves.front().first,genMoves.front().second);

            /*
                - Find all possible displacement move
            */

            if(!isMoveSafe(i,genMoves.front(),PLAYER_BLACK))
            {
                printf("__aichi");
                genMoves.pop();
                continue;
            }

            printf("%d %d",genMoves.front().first,genMoves.front().second);


            //Move the piece
            //Then calculate its
            black_pcs[i] = genMoves.front();


            cleardevice();
            drawBoard();

            genMoves.pop();
            move = true;

            break;
        }


        if(move) return;
    }



    while(move==false)
    {
        int t = rand();
        int i = (t*456463)%16;

        generalMoveSelector();
        killMoveSelector();

        genMoves = availableGenMoves(black_pcs[i]);


        while(!genMoves.empty())
        {
            delay(500);
            //if(!isMoveSafe(i,genMoves.front(),PLAYER_BLACK)) {printf("__aichi");genMoves.pop();continue;}
            black_pcs[i] = genMoves.front();

            cleardevice();
            drawBoard();
            genMoves.pop();

            move = true;
            break;
        }
    }

    return;
}




// AivAi


void gameAI2()
{
    int indexAI = rand();
    indexAI = indexAI%16;

    int to = rand();
    to = to%37;

    bool move = false;
    int count=0;


    queue< pair<int,int> > genMoves;
    //bool a = killMove(indexAI,to,PLAYER_BLACK);
    killMoveSelector();
    generalMoveSelector();


    for(int i = 0 ; i < 16 ; i++)
    {
        killMoveSelector();

        if(red_pcs[i] == make_pair(0,0)) continue;

        while(recursiveKill(i,PLAYER_RED)||recursiveKill2(i,PLAYER_RED))
        {
            count++;
            printf("\n\n%d\n\n",count);
            delay(500);

            cleardevice();
            drawBoard();
            killMoveSelector();
            move = true;
        }

        if(move) return;
    }
    //return;

    killMoveSelector();
    generalMoveSelector();

    queue<int> thrPcs = threatenedPieces(PLAYER_RED);

    while(!thrPcs.empty())
    {
        genMoves = availableGenMoves(red_pcs[thrPcs.front()]);

        while(!genMoves.empty())
        {
            delay(750);
            printf("\n\n%d %d\n\n",genMoves.front().first,genMoves.front().second);

            if(!isMoveSafe(thrPcs.front(),genMoves.front(),PLAYER_RED))
            {
                printf("__aichi");
                genMoves.pop();
                continue;
            }

            printf("%d %d",genMoves.front().first,genMoves.front().second);
            red_pcs[thrPcs.front()] = genMoves.front();

            cleardevice();
            drawBoard();

            genMoves.pop();
            move = true;
            break;
        }

        thrPcs.pop();

        if(move) return;
    }


    for(int i = 15 ; i >= 0 ; i--)
    {
        genMoves = availableGenMoves(red_pcs[i]);

        while(!genMoves.empty())
        {
            delay(750);
            printf("\n\n%d %d\n\n",genMoves.front().first,genMoves.front().second);

            if(!isMoveSafe(i,genMoves.front(),PLAYER_RED))
            {
                printf("__aichi");
                genMoves.pop();
                continue;
            }


            printf("%d %d",genMoves.front().first,genMoves.front().second);
            red_pcs[i] = genMoves.front();

            cleardevice();
            drawBoard();

            genMoves.pop();
            move = true;
            break;
        }

        if(move) return;
    }



    while(move==false)
    {
        int t = rand();
        int i = (t*456463)%16;

        generalMoveSelector();
        killMoveSelector();

        genMoves = availableGenMoves(red_pcs[i]);

        while(!genMoves.empty())
        {
            delay(500);
            //if(!isMoveSafe(i,genMoves.front(),PLAYER_BLACK)) {printf("__aichi");genMoves.pop();continue;}
            red_pcs[i] = genMoves.front();

            cleardevice();
            drawBoard();

            genMoves.pop();
            move = true;
            break;
        }
    }


    return;
}



int Finished(){
    int yc = 0, wc = 0;
    int ans = 0;

    for(int i = 0 ; i < 16 ; i++){

        if(red_pcs[i]==make_pair(0,0)) yc++;

        if(black_pcs[i]==make_pair(0,0)) wc++;
    }

    ans = (max(yc,wc));

    return ans;
}



void AIvAI(){

    POINT cursor;

    int whoWin = 0;

    for(;;){

        gameAI();
        whoWin = ifFinished();

        printf("whowin = %d\n",whoWin);

        if(whoWin) break;

        if(GetAsyncKeyState(VK_LBUTTON))
        {
            GetCursorPos(&cursor);

            int x=cursor.x;
            int y=cursor.y-25;

            printf("%d %d\n",x, y);
            //Newlyadded

            if(cursor.x>=1090&&cursor.x<=1250&&cursor.y>=800&&cursor.y<=950){
                main();
            }
        }


        gameAI2();


        whoWin = ifFinished();

        printf("whowin = %d\n",whoWin);

        if(whoWin) break;

        if(GetAsyncKeyState(VK_LBUTTON))
        {
            GetCursorPos(&cursor);
            int x=cursor.x;
            int y=cursor.y-25;
            printf("%d %d\n",x, y);
            //Newlyadded

            if(cursor.x>=1090&&cursor.x<=1250&&cursor.y>=800&&cursor.y<=950){
                main();
            }

        }
    }


    initwindow(500,300,"MENU",500,300,false,true);

    setcolor(WHITE);
    char a[10];
    sprintf(a,"%d",score(PLAYER_BLACK));
    outtextxy(100,100,"Game Over. PLAYER BLACK has won, Score:");
    outtextxy(100,125,a);
    outtextxy(100,150,"Return to main menu?");
    outtextxy(300,200,"Yes");

    while(1)
    {
        if(GetAsyncKeyState(VK_LBUTTON))
        {
            GetCursorPos(&cursor);

            int x=cursor.x;
            int y=cursor.y-25;

            printf("%d %d\n",x, y);

            //Newlyadded

            if(x>=790&&x<=840&&y>=490&&y<=520){
                closegraph();
                main();
            }
        }
    }

    menu();
}
