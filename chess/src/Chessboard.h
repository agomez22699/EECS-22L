#ifndef CHESSBOARD_H
#define CHESSBOARD_H 

struct _Cell {
    	int x;
    	int y;
	int state;
    	GtkImage* image;
};

typedef struct _Cell Cell;

int *handle_button_click(Cell* cell, GtkButton* button);

void createChessboard (int boardstate[][8]);

#endif
