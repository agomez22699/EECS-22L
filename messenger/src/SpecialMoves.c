#include "SpecialMoves.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Globals.h"
//#include "Rules.h"

/*Checks to see if the king is in check*/
/*Returns 1-king is in check, 0-no check*/
int kingCheck(int x, int y, int piece)
{/*playerstart = 0*/

/*Bottom Black Side*/
	if(piece > 0 && playerstart == 0)
	{
	/*Other king checking*/
		if(y == 0 && x == 0)
		{
			if(boardstate[y+1][x] == -6		||
				boardstate[y+1][x+1] == -6	||
				boardstate[y][x+1] == -6)
			{
				return 1;
			}
		}
		else if(y == 0 && x == 7)
		{
			if(boardstate[y+1][x] == -6             ||
                                boardstate[y+1][x-1] == -6      ||
                                boardstate[y][x-1] == -6)
                        {
                                return 1;
                        }
		}
		else if(y == 7 && x == 0)
		{
			if(boardstate[y-1][x] == -6             ||
                                boardstate[y-1][x+1] == -6      ||
                                boardstate[y][x+1] == -6)
                        {
                                return 1;
                        }
		}
		else if(y == 7 && x == 7)
		{
			if(boardstate[y-1][x] == -6             ||
                                boardstate[y-1][x-1] == -6      ||
                                boardstate[y][x-1] == -6)
                        {
                                return 1;
                        }
		}
		else if(y == 0)
	        {
			if(boardstate[y+1][x] == -6             ||
                                boardstate[y+1][x+1] == -6      ||
                                boardstate[y][x+1] == -6	||
				boardstate[y+1][x-1] == -6	||
				boardstate[y][x-1] == -6)
                        {
                                return 1;
                        }
	        }
	        else if(y == 7)
	        {
	 		if(boardstate[y-1][x] == -6             ||
                                boardstate[y-1][x+1] == -6      ||
                                boardstate[y][x+1] == -6        ||
                                boardstate[y-1][x-1] == -6      ||
                                boardstate[y][x-1] == -6)
                        {
                                return 1;
                        }
	        }
	        else if(x == 0)
	 	{
			if(boardstate[y-1][x] == -6             ||
                                boardstate[y-1][x+1] == -6      ||
                                boardstate[y][x+1] == -6        ||
                                boardstate[y+1][x+1] == -6      ||
                                boardstate[y+1][x] == -6)
                        {
                                return 1;
                        }
	        }
	        else if(x == 7)
	        {
			if(boardstate[y-1][x] == -6             ||
                                boardstate[y-1][x-1] == -6      ||
                                boardstate[y][x-1] == -6        ||
                                boardstate[y+1][x-1] == -6      ||
                                boardstate[y+1][x] == -6)
                        {
                                return 1;
                        }
	        }
		else
		{
			if(boardstate[y+1][x] == -6             ||
                                boardstate[y+1][x+1] == -6      ||
                                boardstate[y][x+1] == -6        ||
                                boardstate[y+1][x-1] == -6      ||
                                boardstate[y][x-1] == -6	||
				boardstate[y-1][x+1] == -6	||
				boardstate[y-1][x-1] == -6	||
				boardstate[y-1][x] == -6)
                        {
                                return 1;
                        }
		}
	/*Knight checking*/
		/*top left*/
		if((y - 2 > 0) && (x - 1 > 0))
		{
			if(boardstate[y-2][x-1] == -2)
			{
				return 1;
			}
		}
		if((y - 1 > 0) && (x - 2 > 0))
                {
                        if(boardstate[y-1][x-2] == -2)
                        {
                                return 1;
                        }
                }
		/*bottom left*/
		if((y - 2 > 0) && (x + 1 < 8))
                {
                        if(boardstate[y-2][x+1] == -2)
                        {
                                return 1;
                        }
                }
                if((y - 1 > 0) && (x + 2 < 8))
                {
                        if(boardstate[y-1][x+2] == -2)
                        {
                                return 1;
                        }
                }
		/*top right*/
		if((y + 2 < 8) && (x - 1 > 0))
                {
                        if(boardstate[y+2][x-1] == -2)
                        {
                                return 1;
                        }
                }
                if((y + 1 < 8) && (x - 2 > 0))
                {
                        if(boardstate[y+1][x-2] == -2)
                        {
                                return 1;
                        }
                }
                /*bottom right*/
                if((y + 2 < 8) && (x + 1 < 8))
                {
                        if(boardstate[y+2][x+1] == -2)
                        {
                                return 1;
                        }
                }
                if((y + 1 < 8) && (x + 2 < 8))
                {
                        if(boardstate[y+1][x+2] == -2)
                        {
                                return 1;
                        }
                }
	/*Rook checking*/	
	/*Bishop checking*/
	/*Queen checking*/
		int tL = 0;	//top left
		int t  = 0;	//top
		int tR = 0;	//top right
		int L  = 0;	//left
		int R  = 0;	//right
		int bL = 0;	//bottom left
		int b  = 0;	//bottom
		int bR = 0;	//bottom right
		int a  = 1;
		while(tL == 0 && (y-a >= 0 && x-a >= 0))
		{
			tL = boardstate[y-a][x-a];
			a++;
		}
		a = 1;
		while(t == 0 && x-a >= 0)
                {
			t = boardstate[y][x-a];
			a++;
                }
		a = 1;
                while(tR == 0 && (y+a <= 7 && x-a >= 0))
                {
                        tR = boardstate[y+a][x-a];
                        a++;
                }
		a = 1;
                while(L == 0 && y-a >= 0)
                {
                        L = boardstate[y-a][x];
                        a++;
                }
		a = 1;
                while(R == 0 && y+a <= 7)
                {
                        R = boardstate[y+a][x];
                        a++;
                }
		a=1;
		while(bL == 0 && (y-a >= 0 && x+a <= 7))
                {
                        bL = boardstate[y-a][x+a];
                        a++;
                }
                a = 1;
                while(b == 0 && x+a <= 7)
                {
                        b = boardstate[y][x+a];
                        a++;
                }
                a = 1;
                while(bR == 0 && (y+a <= 7 && x+a <= 7))
                {
                        bR = boardstate[y+a][x+a];
                        a++;
                }
	/*Rook*/
		if(t == -4 || L == -4 || R == -4 || b == -4)
		{
			return 1;
		}
	/*Bishop*/
		if(tL == -3 || tR == -3 || bL == -3 || bR == -3)
		{
			return 1;
		}
	/*Queen*/
		if(tL == -5 || t == -5 || tR == -5 || L == -5 || R == -5 || bL == -5 || b == -5 || bR == -5)
		{
			return 1;
		}
	/*Pawn Checking*/
		if(x == 0 && y != 0)
		{
			if(boardstate[y-1][x+1] == -1)
			{
				return 1;
			}
		}
		else if(x == 7 && y != 0)
		{
			if(boardstate[y-1][x-1] == -1)
			{
				return 1;
			}
		}
		else if(y != 0)
		{
			if(boardstate[y-1][x-1] == -1	||
				boardstate[y-1][x+1] == -1)
			{
				return 1;
			}
		}
    return 0;
	}   
   
   
   
   
/*Top White Side*/
	if(piece < 0 && playerstart == 0)
	{
	/*Other king checking*/
		if(y == 0 && x == 0)
		{
			if(boardstate[y+1][x] == 6		||
				boardstate[y+1][x+1] == 6	||
				boardstate[y][x+1] == 6)
			{
				return 1;
			}
		}
		else if(y == 0 && x == 7)
		{
			if(boardstate[y+1][x] == 6             ||
                                boardstate[y+1][x-1] == 6      ||
                                boardstate[y][x-1] == 6)
                        {
                                return 1;
                        }
		}
		else if(y == 7 && x == 0)
		{
			if(boardstate[y-1][x] == 6             ||
                                boardstate[y-1][x+1] == 6      ||
                                boardstate[y][x+1] == 6)
                        {
                                return 1;
                        }
		}
		else if(y == 7 && x == 7)
		{
			if(boardstate[y-1][x] == 6             ||
                                boardstate[y-1][x-1] == 6      ||
                                boardstate[y][x-1] == 6)
                        {
                                return 1;
                        }
		}
		else if(y == 0)
	        {
			if(boardstate[y+1][x] == 6             ||
                                boardstate[y+1][x+1] == 6      ||
                                boardstate[y][x+1] == 6	||
				boardstate[y+1][x-1] == 6	||
				boardstate[y][x-1] == 6)
                        {
                                return 1;
                        }
	        }
	        else if(y == 7)
	        {
	 		if(boardstate[y-1][x] == 6             ||
                                boardstate[y-1][x+1] == 6      ||
                                boardstate[y][x+1] == 6        ||
                                boardstate[y-1][x-1] == 6      ||
                                boardstate[y][x-1] == 6)
                        {
                                return 1;
                        }
	        }
	        else if(x == 0)
	 	{
			if(boardstate[y-1][x] == 6             ||
                                boardstate[y-1][x+1] == 6      ||
                                boardstate[y][x+1] == 6        ||
                                boardstate[y+1][x+1] == 6      ||
                                boardstate[y+1][x] == 6)
                        {
                                return 1;
                        }
	        }
	        else if(x == 7)
	        {
			if(boardstate[y-1][x] == 6             ||
                                boardstate[y-1][x-1] == 6      ||
                                boardstate[y][x-1] == 6        ||
                                boardstate[y+1][x-1] == 6      ||
                                boardstate[y+1][x] == 6)
                        {
                                return 1;
                        }
	        }
		else
		{
			if(boardstate[y+1][x] == 6             ||
                                boardstate[y+1][x+1] == 6      ||
                                boardstate[y][x+1] == 6        ||
                                boardstate[y+1][x-1] == 6      ||
                                boardstate[y][x-1] == 6	||
				boardstate[y-1][x+1] == 6	||
				boardstate[y-1][x-1] == 6	||
				boardstate[y-1][x] == 6)
                        {
                                return 1;
                        }
		}
	/*Knight checking*/
		/*top left*/
		if((y - 2 > 0) && (x - 1 > 0))
		{
			if(boardstate[y-2][x-1] == 2)
			{
				return 1;
			}
		}
		if((y - 1 > 0) && (x - 2 > 0))
                {
                        if(boardstate[y-1][x-2] == 2)
                        {
                                return 1;
                        }
                }
		/*bottom left*/
		if((y - 2 > 0) && (x + 1 < 8))
                {
                        if(boardstate[y-2][x+1] == 2)
                        {
                                return 1;
                        }
                }
                if((y - 1 > 0) && (x + 2 < 8))
                {
                        if(boardstate[y-1][x+2] == 2)
                        {
                                return 1;
                        }
                }
		/*top right*/
		if((y + 2 < 8) && (x - 1 > 0))
                {
                        if(boardstate[y+2][x-1] == 2)
                        {
                                return 1;
                        }
                }
                if((y + 1 < 8) && (x - 2 > 0))
                {
                        if(boardstate[y+1][x-2] == 2)
                        {
                                return 1;
                        }
                }
                /*bottom right*/
                if((y + 2 < 8) && (x + 1 < 8))
                {
                        if(boardstate[y+2][x+1] == 2)
                        {
                                return 1;
                        }
                }
                if((y + 1 < 8) && (x + 2 < 8))
                {
                        if(boardstate[y+1][x+2] == 2)
                        {
                                return 1;
                        }
                }
	/*Rook checking*/	
	/*Bishop checking*/
	/*Queen checking*/
		int tL = 0;	//top left
		int t  = 0;	//top
		int tR = 0;	//top right
		int L  = 0;	//left
		int R  = 0;	//right
		int bL = 0;	//bottom left
		int b  = 0;	//bottom
		int bR = 0;	//bottom right
		int a  = 1;
		while(tL == 0 && (y-a >= 0 && x-a >= 0))
		{
			tL = boardstate[y-a][x-a];
			a++;
		}
		a = 1;
		while(t == 0 && x-a >= 0)
                {
			t = boardstate[y][x-a];
			a++;
                }
		a = 1;
                while(tR == 0 && (y+a <= 7 && x-a >= 0))
                {
                        tR = boardstate[y+a][x-a];
                        a++;
                }
		a = 1;
                while(L == 0 && y-a >= 0)
                {
                        L = boardstate[y-a][x];
                        a++;
                }
		a = 1;
                while(R == 0 && y+a <= 7)
                {
                        R = boardstate[y+a][x];
                        a++;
                }
		a=1;
		while(bL == 0 && (y-a >= 0 && x+a <= 7))
                {
                        bL = boardstate[y-a][x+a];
                        a++;
                }
                a = 1;
                while(b == 0 && x+a <= 7)
                {
                        b = boardstate[y][x+a];
                        a++;
                }
                a = 1;
                while(bR == 0 && (y+a <= 7 && x+a <= 7))
                {
                        bR = boardstate[y+a][x+a];
                        a++;
                }
	/*Rook*/
		if(t == 4 || L == 4 || R == 4 || b == 4)
		{
			return 1;
		}
	/*Bishop*/
		if(tL == 3 || tR == 3 || bL == 3 || bR == 3)
		{
			return 1;
		}
	/*Queen*/
		if(tL == 5 || t == 5 || tR == 5 || L == 5 || R == 5 || bL == 5 || b == 5 || bR == 5)
		{
			return 1;
		}
	/*Pawn Checking*/
		if(x == 0 && y != 7)
		{
			if(boardstate[y+1][x+1] == 1)
			{
				return 1;
			}
		}
		else if(x == 7 && y != 7)
		{
			if(boardstate[y+1][x-1] == 1)
			{
				return 1;
			}
		}
		else if(y != 7)
		{
			if(boardstate[y+1][x-1] == 1	||
				boardstate[y+1][x+1] == 1)
			{
				return 1;
			}
		}
    return 0;
	}
   
   
   
   
   
   
   
   
/*playerstart = 1*/
/*Bottom White Side*/
	if(piece < 0 && playerstart == 1)
	{
	/*Other king checking*/
		if(y == 0 && x == 0)
		{
			if(boardstate[y+1][x] == 6		||
				boardstate[y+1][x+1] == 6	||
				boardstate[y][x+1] == 6)
			{
				return 1;
			}
		}
		else if(y == 0 && x == 7)
		{
			if(boardstate[y+1][x] == 6             ||
                                boardstate[y+1][x-1] == 6      ||
                                boardstate[y][x-1] == 6)
                        {
                                return 1;
                        }
		}
		else if(y == 7 && x == 0)
		{
			if(boardstate[y-1][x] == 6             ||
                                boardstate[y-1][x+1] == 6      ||
                                boardstate[y][x+1] == 6)
                        {
                                return 1;
                        }
		}
		else if(y == 7 && x == 7)
		{
			if(boardstate[y-1][x] == 6             ||
                                boardstate[y-1][x-1] == 6      ||
                                boardstate[y][x-1] == 6)
                        {
                                return 1;
                        }
		}
		else if(y == 0)
	        {
			if(boardstate[y+1][x] == 6             ||
                                boardstate[y+1][x+1] == 6      ||
                                boardstate[y][x+1] == 6	||
				boardstate[y+1][x-1] == 6	||
				boardstate[y][x-1] == 6)
                        {
                                return 1;
                        }
	        }
	        else if(y == 7)
	        {
	 		if(boardstate[y-1][x] == 6             ||
                                boardstate[y-1][x+1] == 6      ||
                                boardstate[y][x+1] == 6        ||
                                boardstate[y-1][x-1] == 6      ||
                                boardstate[y][x-1] == 6)
                        {
                                return 1;
                        }
	        }
	        else if(x == 0)
	 	{
			if(boardstate[y-1][x] == 6             ||
                                boardstate[y-1][x+1] == 6      ||
                                boardstate[y][x+1] == 6        ||
                                boardstate[y+1][x+1] == 6      ||
                                boardstate[y+1][x] == 6)
                        {
                                return 1;
                        }
	        }
	        else if(x == 7)
	        {
			if(boardstate[y-1][x] == 6             ||
                                boardstate[y-1][x-1] == 6      ||
                                boardstate[y][x-1] == 6        ||
                                boardstate[y+1][x-1] == 6      ||
                                boardstate[y+1][x] == 6)
                        {
                                return 1;
                        }
	        }
		else
		{
			if(boardstate[y+1][x] == 6             ||
                                boardstate[y+1][x+1] == 6      ||
                                boardstate[y][x+1] == 6        ||
                                boardstate[y+1][x-1] == 6      ||
                                boardstate[y][x-1] == 6	||
				boardstate[y-1][x+1] == 6	||
				boardstate[y-1][x-1] == 6	||
				boardstate[y-1][x] == 6)
                        {
                                return 1;
                        }
		}
	/*Knight checking*/
		/*top left*/
		if((y - 2 > 0) && (x - 1 > 0))
		{
			if(boardstate[y-2][x-1] == 2)
			{
				return 1;
			}
		}
		if((y - 1 > 0) && (x - 2 > 0))
                {
                        if(boardstate[y-1][x-2] == 2)
                        {
                                return 1;
                        }
                }
		/*bottom left*/
		if((y - 2 > 0) && (x + 1 < 8))
                {
                        if(boardstate[y-2][x+1] == 2)
                        {
                                return 1;
                        }
                }
                if((y - 1 > 0) && (x + 2 < 8))
                {
                        if(boardstate[y-1][x+2] == 2)
                        {
                                return 1;
                        }
                }
		/*top right*/
		if((y + 2 < 8) && (x - 1 > 0))
                {
                        if(boardstate[y+2][x-1] == 2)
                        {
                                return 1;
                        }
                }
                if((y + 1 < 8) && (x - 2 > 0))
                {
                        if(boardstate[y+1][x-2] == 2)
                        {
                                return 1;
                        }
                }
                /*bottom right*/
                if((y + 2 < 8) && (x + 1 < 8))
                {
                        if(boardstate[y+2][x+1] == 2)
                        {
                                return 1;
                        }
                }
                if((y + 1 < 8) && (x + 2 < 8))
                {
                        if(boardstate[y+1][x+2] == 2)
                        {
                                return 1;
                        }
                }
	/*Rook checking*/	
	/*Bishop checking*/
	/*Queen checking*/
		int tL = 0;	//top left
		int t  = 0;	//top
		int tR = 0;	//top right
		int L  = 0;	//left
		int R  = 0;	//right
		int bL = 0;	//bottom left
		int b  = 0;	//bottom
		int bR = 0;	//bottom right
		int a  = 1;
		while(tL == 0 && (y-a >= 0 && x-a >= 0))
		{
			tL = boardstate[y-a][x-a];
			a++;
		}
		a = 1;
		while(t == 0 && x-a >= 0)
                {
			t = boardstate[y][x-a];
			a++;
                }
		a = 1;
                while(tR == 0 && (y+a <= 7 && x-a >= 0))
                {
                        tR = boardstate[y+a][x-a];
                        a++;
                }
		a = 1;
                while(L == 0 && y-a >= 0)
                {
                        L = boardstate[y-a][x];
                        a++;
                }
		a = 1;
                while(R == 0 && y+a <= 7)
                {
                        R = boardstate[y+a][x];
                        a++;
                }
		a=1;
		while(bL == 0 && (y-a >= 0 && x+a <= 7))
                {
                        bL = boardstate[y-a][x+a];
                        a++;
                }
                a = 1;
                while(b == 0 && x+a <= 7)
                {
                        b = boardstate[y][x+a];
                        a++;
                }
                a = 1;
                while(bR == 0 && (y+a <= 7 && x+a <= 7))
                {
                        bR = boardstate[y+a][x+a];
                        a++;
                }
	/*Rook*/
		if(t == 4 || L == 4 || R == 4 || b == 4)
		{
			return 1;
		}
	/*Bishop*/
		if(tL == 3 || tR == 3 || bL == 3 || bR == 3)
		{
			return 1;
		}
	/*Queen*/
		if(tL == 5 || t == 5 || tR == 5 || L == 5 || R == 5 || bL == 5 || b == 5 || bR == 5)
		{
			return 1;
		}
	/*Pawn Checking*/
		if(x == 0 && y != 0)
		{
			if(boardstate[y-1][x+1] == 1)
			{
				return 1;
			}
		}
		else if(x == 7 && y != 0)
		{
			if(boardstate[y-1][x-1] == 1)
			{
				return 1;
			}
		}
		else if(y != 0)
		{
			if(boardstate[y-1][x-1] == 1	||
				boardstate[y-1][x+1] == 1)
			{
				return 1;
			}
		}
    return 0;
	}   
   
   
   
   
/*Top Black Side*/
	if(piece > 0 && playerstart == 1)
	{
	/*Other king checking*/
		if(y == 0 && x == 0)
		{
			if(boardstate[y+1][x] == -6		||
				boardstate[y+1][x+1] == -6	||
				boardstate[y][x+1] == -6)
			{
				return 1;
			}
		}
		else if(y == 0 && x == 7)
		{
			if(boardstate[y+1][x] == -6             ||
                                boardstate[y+1][x-1] == -6      ||
                                boardstate[y][x-1] == -6)
                        {
                                return 1;
                        }
		}
		else if(y == 7 && x == 0)
		{
			if(boardstate[y-1][x] == -6             ||
                                boardstate[y-1][x+1] == -6      ||
                                boardstate[y][x+1] == -6)
                        {
                                return 1;
                        }
		}
		else if(y == 7 && x == 7)
		{
			if(boardstate[y-1][x] == -6             ||
                                boardstate[y-1][x-1] == -6      ||
                                boardstate[y][x-1] == -6)
                        {
                                return 1;
                        }
		}
		else if(y == 0)
	        {
			if(boardstate[y+1][x] == -6             ||
                                boardstate[y+1][x+1] == -6      ||
                                boardstate[y][x+1] == -6	||
				boardstate[y+1][x-1] == -6	||
				boardstate[y][x-1] == -6)
                        {
                                return 1;
                        }
	        }
	        else if(y == 7)
	        {
	 		if(boardstate[y-1][x] == -6             ||
                                boardstate[y-1][x+1] == -6      ||
                                boardstate[y][x+1] == -6        ||
                                boardstate[y-1][x-1] == -6      ||
                                boardstate[y][x-1] == -6)
                        {
                                return 1;
                        }
	        }
	        else if(x == 0)
	 	{
			if(boardstate[y-1][x] == -6             ||
                                boardstate[y-1][x+1] == -6      ||
                                boardstate[y][x+1] == -6        ||
                                boardstate[y+1][x+1] == -6      ||
                                boardstate[y+1][x] == -6)
                        {
                                return 1;
                        }
	        }
	        else if(x == 7)
	        {
			if(boardstate[y-1][x] == -6             ||
                                boardstate[y-1][x-1] == -6      ||
                                boardstate[y][x-1] == -6        ||
                                boardstate[y+1][x-1] == -6      ||
                                boardstate[y+1][x] == -6)
                        {
                                return 1;
                        }
	        }
		else
		{
			if(boardstate[y+1][x] == -6             ||
                                boardstate[y+1][x+1] == -6      ||
                                boardstate[y][x+1] == -6        ||
                                boardstate[y+1][x-1] == -6      ||
                                boardstate[y][x-1] == -6	||
				boardstate[y-1][x+1] == -6	||
				boardstate[y-1][x-1] == -6	||
				boardstate[y-1][x] == -6)
                        {
                                return 1;
                        }
		}
	/*Knight checking*/
		/*top left*/
		if((y - 2 > 0) && (x - 1 > 0))
		{
			if(boardstate[y-2][x-1] == -2)
			{
				return 1;
			}
		}
		if((y - 1 > 0) && (x - 2 > 0))
                {
                        if(boardstate[y-1][x-2] == -2)
                        {
                                return 1;
                        }
                }
		/*bottom left*/
		if((y - 2 > 0) && (x + 1 < 8))
                {
                        if(boardstate[y-2][x+1] == -2)
                        {
                                return 1;
                        }
                }
                if((y - 1 > 0) && (x + 2 < 8))
                {
                        if(boardstate[y-1][x+2] == -2)
                        {
                                return 1;
                        }
                }
		/*top right*/
		if((y + 2 < 8) && (x - 1 > 0))
                {
                        if(boardstate[y+2][x-1] == -2)
                        {
                                return 1;
                        }
                }
                if((y + 1 < 8) && (x - 2 > 0))
                {
                        if(boardstate[y+1][x-2] == -2)
                        {
                                return 1;
                        }
                }
                /*bottom right*/
                if((y + 2 < 8) && (x + 1 < 8))
                {
                        if(boardstate[y+2][x+1] == -2)
                        {
                                return 1;
                        }
                }
                if((y + 1 < 8) && (x + 2 < 8))
                {
                        if(boardstate[y+1][x+2] == -2)
                        {
                                return 1;
                        }
                }
	/*Rook checking*/	
	/*Bishop checking*/
	/*Queen checking*/
		int tL = 0;	//top left
		int t  = 0;	//top
		int tR = 0;	//top right
		int L  = 0;	//left
		int R  = 0;	//right
		int bL = 0;	//bottom left
		int b  = 0;	//bottom
		int bR = 0;	//bottom right
		int a  = 1;
		while(tL == 0 && (y-a >= 0 && x-a >= 0))
		{
			tL = boardstate[y-a][x-a];
			a++;
		}
		a = 1;
		while(t == 0 && x-a >= 0)
                {
			t = boardstate[y][x-a];
			a++;
                }
		a = 1;
                while(tR == 0 && (y+a <= 7 && x-a >= 0))
                {
                        tR = boardstate[y+a][x-a];
                        a++;
                }
		a = 1;
                while(L == 0 && y-a >= 0)
                {
                        L = boardstate[y-a][x];
                        a++;
                }
		a = 1;
                while(R == 0 && y+a <= 7)
                {
                        R = boardstate[y+a][x];
                        a++;
                }
		a=1;
		while(bL == 0 && (y-a >= 0 && x+a <= 7))
                {
                        bL = boardstate[y-a][x+a];
                        a++;
                }
                a = 1;
                while(b == 0 && x+a <= 7)
                {
                        b = boardstate[y][x+a];
                        a++;
                }
                a = 1;
                while(bR == 0 && (y+a <= 7 && x+a <= 7))
                {
                        bR = boardstate[y+a][x+a];
                        a++;
                }
	/*Rook*/
		if(t == -4 || L == -4 || R == -4 || b == -4)
		{
			return 1;
		}
	/*Bishop*/
		if(tL == -3 || tR == -3 || bL == -3 || bR == -3)
		{
			return 1;
		}
	/*Queen*/
		if(tL == -5 || t == -5 || tR == -5 || L == -5 || R == -5 || bL == -5 || b == -5 || bR == -5)
		{
			return 1;
		}
	/*Pawn Checking*/
		if(x == 0 && y != 7)
		{
			if(boardstate[y+1][x+1] == -1)
			{
				return 1;
			}
		}
		else if(x == 7 && y != 7)
		{
			if(boardstate[y+1][x-1] == -1)
			{
				return 1;
			}
		}
		else if(y != 7)
		{
			if(boardstate[y+1][x-1] == -1	||
				boardstate[y+1][x+1] == -1)
			{
				return 1;
			}
		}
    return 0;
	}
 return 0;
}


/*Returns 100 if black king is in Checkmate,
  returns -100 if white king is in Checkmate,
  returns 1 if not in checkmate*/
int checkMate(int piece)
{
  int movesLeft = 0;
  int x = 0;
  int y = 0;
  int wboard[8][8]={{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0}};
  int bboard[8][8]={{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0}};
  int canbeblocked = 0;
  int canbecaptured = 0;
  for(int i=0;i<=7;i++)
  {
    for(int j=0;j<=7;j++)
    {
      if(boardstate[i][j] == piece)
      {
        x = i;
        y = j;
      }
    }
  }
  boardstate[x][y] = 0;
  /*Black*/
  if(piece == 6)
  {
    /*Top Left*/
    if(y>0 && x>0)
    {
      if(boardstate[x-1][y-1]<=0)
      {
        if(kingCheck(y-1,x-1,6)==0)
        {
          movesLeft++;
        }
      }
    }
    /*Top*/
    if(y>0)
    {
      if(boardstate[x][y-1]<=0)
      {
        if(kingCheck(y-1,x,6)==0)
        {
          movesLeft++;
        }
      }
    }
    /*Top Right*/
    if(y>0 && x<7)
    {
      if(boardstate[x+1][y-1]<=0)
      {
        if(kingCheck(y-1,x+1,6)==0)
        {
          movesLeft++;
        }
      }
    }
    /*Left*/
    if(x>0)
    {
      if(boardstate[x-1][y]<=0)
      {
        if(kingCheck(y,x-1,6)==0)
        {
          movesLeft++;
        }
      }
    }
    /*Middle*/
    if(boardstate[x][y]==0)
    {
      if(kingCheck(y,x,6)==0)
      {
          movesLeft++;
      }
    }
    /*Right*/
    if(x<7)
    {
      if(boardstate[x+1][y]<=0)
      {
        if(kingCheck(y,x+1,6)==0)
        {
          movesLeft++;
        }
      }
    }
    /*Bottom Left*/
    if(y<7 && x>0)
    {
      if(boardstate[x-1][y+1]<=0)
      {
        if(kingCheck(y+1,x-1,6)==0)
        {
          movesLeft++;
        }
      }
    }
    /*Bottom*/
    if(y<7)
    {
      if(boardstate[x][y+1]<=0)
      {
        if(kingCheck(y+1,x,6)==0)
        {
          movesLeft++;
        }
      }
    }
    /*Bottom Right*/
    if(y<7 && x<7)
    {
      if(boardstate[x+1][y+1]<=0)
      {
        if(kingCheck(y+1,x+1,6)==0)
        {
          movesLeft++;
        }
      }
    }
    boardstate[x][y] = 6;
    /*for(int i=0;i<=7;i++)
    {
      for(int j=0;j<=7;j++)
      {
        if(boardstate[i][j] < 0)
        {
          CheckPossibleMove(j,i,boardstate[i][j]);
          if(board[y][x] == 1)
          {
            wboard[i][j] = boardstate[i][j];printf("wboard=%d",wboard[i][j]);
            if(kingCheck(i,j,boardstate[i][j]) == 1)
              canbecaptured++;
          }
        }
        if(boardstate[i][j] > 0 && boardstate[i][j] != 6)
        {
          CheckPossibleMove(j,i,boardstate[i][j]);
          for(int a=0;a<=7;a++)
          {
            for(int b=0;b<=7;b++)
            {
              if(board[a][b] == 1)
                bboard[a][b] = board[a][b];
            }
          }
        }
      }
    }
    for(int c=0;c<=7;c++)
    {
      for(int d=0;d<=7;d++)
      {
        if(wboard[c][d] != 0)
        {printf("wboard=%d",wboard[c][d]);
          bboard[c][d] = wboard[c][d];
          bboard[x][y] = boardstate[x][y];
          if(kingCheck(d,c,boardstate[x][y]) == 0)
            canbeblocked++;
        }
      }
    }*/
  }
  
  
  
  
  /*White*/
  else if(piece == -6)
  {
    boardstate[x][y] = 0;
   /*Top Left*/
    if(y>0 && x>0)
    {
      if(boardstate[x-1][y-1]>=0)
      {
        if(kingCheck(y-1,x-1,-6)==0)
        {
          movesLeft++;
        }
      }
    }
    /*Top*/
    if(y>0)
    {
      if(boardstate[x][y-1]>=0)
      {
        if(kingCheck(y-1,x,-6)==0)
        {
          movesLeft++;
        }
      }
    }
    /*Top Right*/
    if(y>0 && x<7)
    {
      if(boardstate[x+1][y-1]>=0)
      {
        if(kingCheck(y-1,x+1,-6)==0)
        {
          movesLeft++;
        }
      }
    }
    /*Left*/
    if(x>0)
    {
      if(boardstate[x-1][y]>=0)
      {
        if(kingCheck(y,x-1,-6)==0)
        {
          movesLeft++;
        }
      }
    }
    /*Middle*/
    if(boardstate[x][y]==0)
    {
      if(kingCheck(y,x,-6)==0)
      {
        movesLeft++;
      }
    }
    /*Right*/
    if(x<7)
    {
      if(boardstate[x+1][y]>=0)
      {
        if(kingCheck(y,x+1,-6)==0)
        {
          movesLeft++;
        }
      }
    }
    /*Bottom Left*/
    if(y<7 && x>0)
    {
      if(boardstate[x-1][y+1]>=0)
      {
        if(kingCheck(y+1,x-1,-6)==0)
        {
          movesLeft++;
        }
      }
    }
    /*Bottom*/
    if(y<7)
    {
      if(boardstate[x][y+1]>=0)
      {
        if(kingCheck(y+1,x,-6)==0)
        {
          movesLeft++;
        }
      }
    }
    /*Bottom Right*/
    if(y<7 && x<7)
    {
      if(boardstate[x+1][y+1]>=0)
      {
        if(kingCheck(y+1,x+1,-6)==0)
        {
          movesLeft++;
        }
      }
    }
    boardstate[x][y] = -6;
    /*for(int i=0;i<=7;i++)
    {
      for(int j=0;j<=7;j++)
      {
        if(boardstate[i][j] > 0)
        {
          CheckPossibleMove(i,j,boardstate[i][j]);
          if(board[x][y] == 1)
          {
            bboard[i][j] = boardstate[i][j];
            if(kingCheck(j,i,boardstate[i][j]) == 1)
              canbecaptured++;
          }
        }
        if(boardstate[i][j] < 0 && boardstate[i][j] != -6)
        {
          CheckPossibleMove(i,j,boardstate[i][j]);
          for(int a=0;a<=7;a++)
          {
            for(int b=0;b<=7;b++)
            {
              if(board[a][b] == 1)
                wboard[a][b] = board[a][b];
            }
          }
        }
      }
    }
    for(int c=0;c<=7;c++)
    {
      for(int d=0;d<=7;d++)
      {
        if(bboard[c][d] != 0)
        {
          wboard[c][d] = bboard[c][d];
          wboard[x][y] = boardstate[x][y];
          if(kingCheck(d,c,boardstate[x][y]) == 0)
            canbeblocked++;
        }
      }
    }*/
  }
  /*else
  {
    printf("\nYou are checking the wrong piece for checkmate\n");
  }*//*printf("AAAAA %d %d %d AAAAA",movesLeft,canbecaptured,canbeblocked);*/
  if(movesLeft == 0 && canbecaptured != 1 && canbeblocked == 0 && piece < 0)
  {
    return -100;
  }
  else if(movesLeft == 0 && canbecaptured != 1 && canbeblocked == 0 && piece > 0)
  {
    return 100;
  }
  else
  {
    return 1;
  }
  
}