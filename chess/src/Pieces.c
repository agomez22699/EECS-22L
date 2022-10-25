/*This file creates and deletes pieces*/
#include "Pieces.h"
#include <stdlib.h>
#include <assert.h>

/*Values: 0-King, 1-Queen, 2-Bishop, 3-Knight, 4-Rook, 5-Pawn*/
PIECE *CreatePiece(unsigned int x_pos, unsigned int y_pos, int color, unsigned int value)
{
	PIECE *piece = malloc(sizeof(PIECE));
	if(!piece)
		return NULL;
	piece->value = value;
	piece->prev_prev_x = x_pos;
	piece->prev_prev_y = y_pos;
	piece->prev_x = x_pos;
	piece->prev_y = y_pos;
	piece->x_pos = x_pos;
	piece->y_pos = y_pos;
	piece->color = color;
	return piece;
}

void DeletePiece(PIECE *piece)
{
	assert(piece);
	assert(piece->value);
	assert(piece->x_pos);
	assert(piece->y_pos);
	assert(piece->color);
	assert(piece->prev_x);
	assert(piece->prev_y);
	assert(piece->prev_prev_x);
	assert(piece->prev_prev_y);
	free(piece->value);
	free(piece->x_pos);
	free(piece->y_pos);
	free(piece->color);
	free(piece->prev_x);
	free(piece->prev_y);
	free(piece->prev_prev_x);
	free(piece->prev_prev_y);
	piece->value = NULL;
	piece->x_pos = NULL;
	piece->y_pos = NULL;
	piece->color = NULL;
	piece->prev_x = NULL;
	piece->prev_y = NULL;
	piece->prev_prev_x = NULL;
	piece->prev_prev_y = NULL;
	free(piece);
}
