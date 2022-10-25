#ifndef PIECES_H
#define PIECES_H

#include <stdlib.h>

/*Values: 0-King, 1-Queen, 2-Bishop, 3-Knight, 4-Rook, 5-Pawn*/
typedef struct
{
  unsigned int value;
  unsigned int x_pos;
  unsigned int y_pos;
  unsigned int prev_x;
  unsigned int prev_y;
  unsigned int prev_prev_x;
  unsigned int prev_prev_y;
  int color;
}PIECE;

//Allocate memory for intial pieces and new pieces, such as pawn promotion
PIECE *CreatePiece(unsigned int x_pos, unsigned int y_pos, int color, unsigned int value);

//Free the memory of pieces, when captured or promoted
void DeletePiece(PIECE *piece);

#endif // added to close if statement
