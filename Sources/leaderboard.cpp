#include<stdio.h>
#include<graphics.h>
#include "header.hpp"
#include<utility>
#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

void leaderboardSave(int who, int score)
{
    FILE* fp = fopen("leaderboard.txt","a+");

    if(who == PLAYER_WHITE){
        fprintf(fp,"AI       %d\n",score);
    }

    else{
        fprintf(fp,"PL       %d\n",score);
    }
    fclose(fp);
}


int waitforCon()
{
    setcolor(LIGHTRED);
    outtextxy(800,750,"+");
    setcolor(WHITE);

    POINT cursor;

    while(1)
    {
        if(GetAsyncKeyState(VK_LBUTTON))
        {
            GetCursorPos(&cursor);

            int x=cursor.x;
            int y=cursor.y-25;

            printf("%d %d\n",x, y);

            //Newlyadded

            if(x>=790&&x<=840&&y>=750&&y<790){
                return 1;
            }
            else if(x>=490&&x<=600&&y>=90&&y<=150){
                return 0;
            }
        }
    }
}

void leaderboardView()
{
    FILE* fp = fopen("leaderboard.txt","r");

    char buff[100];
    int i = 0, f = 1;

    cleardevice();

    setcolor(LIGHTRED);
    outtextxy(500,100,"<<<");
    setcolor(WHITE);

    while(!feof(fp)) //j<37 chilo
    {
        f = 1;
        fgets(buff, 100, fp);
        outtextxy(600,150+50*i,buff);
        i++;

        if(i==12) {
            f = waitforCon();
            i = 0;
            cleardevice();

            setcolor(LIGHTRED);
            outtextxy(500,100,"<<<");
            setcolor(WHITE);
        }

        if(!f) break;
        buff[0] = '\0';
    }


    if(!f)
    {
        closegraph();
        main();
    }

    POINT cursor;

    while(1)
    {
        if(GetAsyncKeyState(VK_LBUTTON))
        {
            GetCursorPos(&cursor);

            int x=cursor.x;
            int y=cursor.y-25;

            printf("%d %d\n",x, y);

            //Newlyadded

            if(x>=490&&x<=600&&y>=90&&y<=150){
                closegraph();
                main();
            }
        }
    }

    fclose(fp);
}
