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


/*

    - The following funtions find the recursive killing moves if possible

*/


bool recursiveKill2(int from, int whichPlayer)
{

    killMoveSelector();
    generalMoveSelector();
    printf("----choleashchi---\n");
    pair<int,int>x;

    if(whichPlayer==PLAYER_RED)
    {

        for(int i = 0 ; i < 20 ; i++)
        {
            //printf("\nggsize..%d\n",board[i].lines.size());

            while(!board[i].lines.empty())
            {
                //printf("i>>%d ",i);
                if(!pieceAvailable(board[i].lines.front()))
                {
                    x = board[i].lines.front();
                    //printf("iniffelse");
                    board[i].lines.pop();

                    if(board[i].lines.empty())break;

                    for(int j = 0 ; j < 16 ; j++)
                    {
                        //printf("j>>%d ",j);

                        if(black_pcs[j]==make_pair(0,0)) continue;

                        if(black_pcs[j] == board[i].lines.front())
                        {
                            board[i].lines.pop();
                            printf("__oo__");

                            if(board[i].lines.empty())break;

                            if(red_pcs[from] == board[i].lines.front())
                            {
                                //printf("__oo__");
                                red_pcs[from] = x;
                                black_pcs[j] = make_pair(0,0);
                                killMoveSelector();
                                return true;
                            }

                            else
                            {
                                break;
                            }
                        }
                    }
                    //break;
                }


                else
                    board[i].lines.pop();
            }
        }
    }


    else
    {

        for(int i = 0 ; i < 20 ; i++)
        {
            //printf("\nggsize..%d\n",board[i].lines.size());

            while(!board[i].lines.empty())
            {
                //printf("i>>%d ",i);

                if(!pieceAvailable(board[i].lines.front()))
                {
                    x=board[i].lines.front();
                    //printf("iniffelse");
                    board[i].lines.pop();

                    if(board[i].lines.empty())break;
                    //if(i==5){while(!board[i].lines.empty()){printf("\n\n%d %d\n\n",board[i].lines.front().first,board[i].lines.front().second);board[i].lines.pop();}getch();}

                    for(int j = 0 ; j < 16 ; j++)
                    {
                        //printf("j>>%d ",j);
                        //if(i==5)printf("\n\n%d %d\n\n",red_pcs[j].first,red_pcs[j].second);

                        if(red_pcs[j] == make_pair(0,0)) continue;

                        if(red_pcs[j] == board[i].lines.front())
                        {
                            printf("--oo--");
                            board[i].lines.pop();

                            if(board[i].lines.empty())break;

                            if(black_pcs[from] == board[i].lines.front())
                            {
                                black_pcs[from] = x;
                                red_pcs[j] = make_pair(0,0);

                                killMoveSelector();

                                return true;
                            }

                            else break;
                        }
                    }
                    //break;
                }


                else
                    board[i].lines.pop();
            }
        }
    }

    return false;
}



bool recursiveKill(int from, int whichPlayer)
{
    killMoveSelector();
    generalMoveSelector();

    //printf("----choleashchi---\n");
    pair<int,int>x;

    if(whichPlayer==PLAYER_RED)
    {

        for(int i = 0 ; i < 20 ; i++)
        {
            printf("\nggsize..%d\n",board[i].lines.size());

            while(!board[i].lines.empty())
            {
                printf("i>>%d ",i);

                if(red_pcs[from] == board[i].lines.front())
                {
                    printf("iniff");
                    board[i].lines.pop();

                    if(board[i].lines.empty())break;

                    for(int j = 0 ; j < 16 ; j++)
                    {
                        printf("j>>%d ",j);

                        if(black_pcs[j] == board[i].lines.front())
                        {
                            ////printf("\n%d\t%d\n",board[i].lines.front().first,board[i].lines.front().second);
                            board[i].lines.pop();

                            if(board[i].lines.empty())break;

                            if(!pieceAvailable(board[i].lines.front()))
                            {
                                //printf("\n%d\t%d\n",board[i].lines.front().first,board[i].lines.front().second);
                                //printf("i>>%d ",i);
                                red_pcs[from] = board[i].lines.front();
                                black_pcs[j] = make_pair(0,0);
                                killMoveSelector();
                                return true;
                            }

                            else break;
                        }
                    }
                    //break;
                }


                else
                    board[i].lines.pop();
            }
        }
    }


    else
    {

        for(int i = 0 ; i < 20 ; i++)
        {
            //printf("\nggsize..%d\n",board[i].lines.size());

            while(!board[i].lines.empty())
            {
                //printf("i>>%d ",i);

                if(black_pcs[from] == board[i].lines.front())
                {
                    //printf("iniff");
                    board[i].lines.pop();

                    if(board[i].lines.empty())break;

                    for(int j = 0 ; j < 16 ; j++)
                    {
                        //printf("j>>%d ",j);

                        if(red_pcs[j] == board[i].lines.front())
                        {
                            //printf("\n%d\t%d\n",board[i].lines.front().first,board[i].lines.front().second);
                            board[i].lines.pop();

                            if(board[i].lines.empty())break;

                            if(!pieceAvailable(board[i].lines.front()))
                            {
                                //printf("\n%d\t%d\n",board[i].lines.front().first,board[i].lines.front().second);
                                //printf("i>>%d ",i);
                                black_pcs[from] = board[i].lines.front();
                                red_pcs[j] = make_pair(0,0);
                                killMoveSelector();
                                return true;

                            }

                            else break;
                        }
                    }
                    //break;
                }

                else
                    board[i].lines.pop();
            }
        }
    }

    return false;
}




bool killMove(int from, int to, int whichPlayer)
{
    //printf("KILL");
    pair<int,int> coor;

    if(whichPlayer==PLAYER_BLACK)
    {

        for(int i = 0 ; i < 20 ; i++)
        {

            while(!board[i].lines.empty())
            {
                //printf("i>>%d ",i);

                if(black_pcs[from] == board[i].lines.front())
                {
                    //printf("iniff");
                    board[i].lines.pop();

                    if(board[i].lines.empty())break;

                    for(int j = 0 ; j < 16 ; j++)
                    {
                        //printf("j>>%d ",j);

                        if(red_pcs[j] == board[i].lines.front())
                        {
                            board[i].lines.pop();

                            if(board[i].lines.empty())break;

                            if(board[to].coord == board[i].lines.front())
                            {
                                black_pcs[from] = board[to].coord;
                                red_pcs[j] = make_pair(0,0);

                                cleardevice();
                                drawBoard();

                                if(TWO_PLAYER_MODE)
                                {
                                    killMoveSelector();
                                    return true;
                                }

                                while(recursiveKill(from,PLAYER_BLACK)||recursiveKill2(from,PLAYER_BLACK))
                                {
                                    delay(500);
                                    cleardevice();
                                    drawBoard();
                                    killMoveSelector();
                                }

                                killMoveSelector();
                                return true;
                            }
                        }
                    }

                    break;
                }


                else if(board[to].coord == board[i].lines.front())
                {
                    //printf("iniffelse");
                    board[i].lines.pop();

                    if(board[i].lines.empty())break;

                    for(int j = 0 ; j < 16 ; j++)
                    {
                        //printf("j>>%d ",j);

                        if(red_pcs[j] == board[i].lines.front())
                        {
                            board[i].lines.pop();

                            if(board[i].lines.empty())break;

                            if(black_pcs[from] == board[i].lines.front())
                            {
                                black_pcs[from] = board[to].coord;
                                red_pcs[j] = make_pair(0,0);

                                cleardevice();
                                drawBoard();

                                if(TWO_PLAYER_MODE)
                                {
                                    killMoveSelector();
                                    return true;
                                }


                                while(recursiveKill(from,PLAYER_BLACK)||recursiveKill2(from,PLAYER_BLACK))
                                {
                                    delay(500);
                                    cleardevice();
                                    drawBoard();
                                    killMoveSelector();
                                }

                                killMoveSelector();
                                return true;
                            }
                        }
                    }

                    break;
                }

                board[i].lines.pop();
            }
        }
    }


    else
    {

        for(int i = 0 ; i < 20 ; i++)
        {

            while(!board[i].lines.empty())
            {
                //printf("i>>%d ",i);

                if(red_pcs[from] == board[i].lines.front())
                {
                    //printf("iniff");
                    board[i].lines.pop();

                    if(board[i].lines.empty())break;

                    for(int j = 0 ; j < 16 ; j++)
                    {
                        //printf("j>>%d ",j);

                        if(black_pcs[j] == board[i].lines.front())
                        {
                            board[i].lines.pop();

                            if(board[i].lines.empty())break;

                            if(board[to].coord == board[i].lines.front())
                            {
                                red_pcs[from] = board[to].coord;
                                black_pcs[j] = make_pair(0,0);

                                cleardevice();
                                drawBoard();

                                if(TWO_PLAYER_MODE)
                                {
                                    killMoveSelector();
                                    return true;
                                }

                                while(recursiveKill(from,PLAYER_RED)||recursiveKill2(from,PLAYER_RED))
                                {
                                    delay(500);
                                    cleardevice();
                                    drawBoard();
                                    killMoveSelector();
                                }

                                killMoveSelector();

                                return true;

                            }

                        }
                    }
                    break;
                }

                else if(board[to].coord == board[i].lines.front())
                {
                    //printf("iniffelse");
                    board[i].lines.pop();

                    if(board[i].lines.empty())break;

                    for(int j = 0 ; j < 16 ; j++)
                    {
                        //printf("j>>%d ",j);

                        if(black_pcs[j] == board[i].lines.front())
                        {
                            board[i].lines.pop();

                            if(board[i].lines.empty())break;

                            if(red_pcs[from] == board[i].lines.front())
                            {
                                red_pcs[from] = board[to].coord;
                                black_pcs[j] = make_pair(0,0);

                                cleardevice();
                                drawBoard();

                                if(TWO_PLAYER_MODE)
                                {
                                    killMoveSelector();
                                    return true;
                                }


                                while(recursiveKill(from,PLAYER_RED)||recursiveKill2(from,PLAYER_RED))
                                {
                                    delay(500);
                                    cleardevice();
                                    drawBoard();
                                    killMoveSelector();
                                }

                                killMoveSelector();

                                return true;
                            }
                        }
                    }

                    break;
                }

                board[i].lines.pop();
            }
        }
    }

    return false;
}
