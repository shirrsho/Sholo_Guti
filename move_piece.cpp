#include<stdio.h>
#include<graphics.h>
#include<iostream>
#include "header.hpp"
#include<list>
#include<math.h>
#include<queue>

using namespace std;

extern pair<int,int> yellow_pcs[16];
extern pair<int,int> white_pcs[16];
extern struct Board{
    pair<int,int> coord;
    queue< pair<int,int> > neighs;
    queue< pair<int,int> > lines;
}board[37];



double calculateDistance(pair<int,int> X,pair<int,int> Y){
    return sqrt(pow((Y.first-X.first),2)+pow((Y.second-X.second),2));
}





//bool killMove(int from, int to, int whichPlayer){
//    printf("KILL");
//    pair<int,int> killed;
//    if(whichPlayer==PLAYER_WHITE){
//        killed.first = (white_pcs[from].first+board[to].coord.first)/2;
//        killed.second = (white_pcs[from].second+board[to].coord.second)/2;
//
//        for(int i = 0 ; i < 16 ; i++){
//            if(killed == yellow_pcs[i]){
//                white_pcs[from] = board[to].coord;
//                yellow_pcs[i].first = 0; yellow_pcs[i].second = 0;
//                return true;
//            }
//        }
//    }
//    else{
//        killed.first = (yellow_pcs[from].first+board[to].coord.first)/2;
//        killed.second = (yellow_pcs[from].second+board[to].coord.second)/2;
//
//        for(int i = 0 ; i < 16 ; i++){
//            if(killed == white_pcs[i]){
//                yellow_pcs[from] = board[to].coord;
//                white_pcs[i].first = 0; white_pcs[i].second = 0;
//                return true;
//            }
//        }
//    }
//    return false;
//}

bool generalMove(int from, int to, int whichPlayer){
    printf("GEN");
//    if(whichPlayer==PLAYER_WHITE){
//        if(calculateDistance(white_pcs[from],board[to].coord)>TRIANGLE_BASE/2||white_pcs[from]==board[to].coord) return false;
//        else{white_pcs[from]=board[to].coord;return true;}
//    }
//    else{
//        if(calculateDistance(yellow_pcs[from],board[to].coord)>TRIANGLE_BASE/2||yellow_pcs[from]==board[to].coord) return false;
//        else{yellow_pcs[from]=board[to].coord;return true;}
//    }


    if(whichPlayer==PLAYER_WHITE){
        //if(calculateDistance(white_pcs[from],board[to].coord)>TRIANGLE_BASE/2||white_pcs[from]==board[to].coord) return false;
        while(!board[to].neighs.empty()){
            if(board[to].neighs.front() == white_pcs[from]){
                //if(board[to].neighs.front().second ==)
                white_pcs[from]=board[to].coord;generalMoveSelector();return true;
            }
            board[to].neighs.pop();
        }
        generalMoveSelector();
        return false;
    }
    else{
        //if(calculateDistance(yellow_pcs[from],board[to].coord)>TRIANGLE_BASE/2||yellow_pcs[from]==board[to].coord) return false;
        while(!board[to].neighs.empty()){
            if(board[to].neighs.front() == yellow_pcs[from]){
                //if(board[to].neighs.front().second ==  yellow_pcs[from].second)
                yellow_pcs[from]=board[to].coord;generalMoveSelector();return true;
            }
            board[to].neighs.pop();
        }
        generalMoveSelector();
        return false;
    }
}

bool pieceAvailable(pair<int,int>here){
    for(int i = 0 ; i < 16 ; i++){
        if(white_pcs[i] == here)
            return true;
        if(yellow_pcs[i] == here)
            return true;
    }
    return false;
}

bool move_piece(int from,int to,int whichPlayer){

    printf("MOVE");

    bool take = false;

    take = generalMove(from,to,whichPlayer);
    if(take) return take;

    take = killMove(from,to,whichPlayer);
    killMoveSelector();

    return take;

//    double theDistance;
//
//    if(whichPlayer==PLAYER_WHITE){
//        theDistance = calculateDistance(white_pcs[from],board[to].coord);
//    }
//    else{
//        theDistance = calculateDistance(yellow_pcs[from],board[to].coord);
//    }
//
//    if(theDistance > TRIANGLE_BASE/2) {
//        take = killMove(from,to,whichPlayer); killMoveSelector(); printf("killll");
//    }
//    else {take = generalMove(from,to,whichPlayer);}
//
//    return take;

}
