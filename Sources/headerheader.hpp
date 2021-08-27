
//-lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32

#define TRIANGLE_HEIGHT 140
#define TRIANGLE_BASE 300

#define TRIANGLE_ENDING TRIANGLE_STARTING+TRIANGLE_BASE
#define SPACE_VERTICAL 70

#define BOX_LENGTH 400
#define BOX_STARTING 565
#define BOX_ENDING BOX_STARTING+BOX_LENGTH
#define PLACE_WIDTH BOX_LENGTH/4

//#define TRIANGLE_STARTING 615
#define TRIANGLE_STARTING BOX_STARTING+(BOX_LENGTH/2)-(TRIANGLE_BASE/2)

#define PLAYER_WHITE 1
#define PLAYER_YELLOW 2

#include<bits/stdc++.h>



void menu();
void drawBoard();
void placePieces(int,int);
void initializePieces();
void selectPiece(std::pair<int,int>);
void mouseControl();
bool mouseControl2(int,int);
bool move_piece(int,int,int);
bool pieceAvailable(std::pair<int,int>);
bool killMove(int,int,int);
bool generalMove(int,int,int);
double calculateDistance(std::pair<int,int>,std::pair<int,int>);
void initializeGeneralMoves();
void initializeKillMoves();
bool recursiveKill(int,int);
bool recursiveKill2(int,int);
void boardMoveSelector();
void generalMoveSelector();
void killMoveSelector();
double calculateDistance(std::pair<int,int>,std::pair<int,int>);
void set();
void gameAI();
int ifFinished();
void selectPiece(std::pair<int,int>);
int whichPiece(std::pair<int,int>);


