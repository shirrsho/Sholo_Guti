//-lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32

#define TRIANGLE_HEIGHT 140
#define TRIANGLE_BASE 300
#define TRIANGLE_STARTING 615
#define TRIANGLE_ENDING TRIANGLE_STARTING+TRIANGLE_BASE
#define SPACE_VERTICAL 70

#define BOX_LENGTH 400
#define BOX_STARTING 565
#define BOX_ENDING BOX_STARTING+BOX_LENGTH
#define PLACE_WIDTH BOX_LENGTH/4

#include<iostream>

void drawBoard();
void placePieces(int,int);
