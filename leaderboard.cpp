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




void leaderboardView()
{
    FILE* fp = fopen("leaderboard.txt","r");

    char buff[100];
    int i = 0;

    cleardevice();
    setcolor(WHITE);

    while(!feof(fp)) //j<37 chilo
    {
        fgets(buff, 100, fp);
        outtextxy(600,150+50*i,buff);
        i++;
        buff[0] = '\0';
    }

    setcolor(LIGHTRED);
    outtextxy(500,100,"<<<");

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
