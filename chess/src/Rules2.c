//#include "Rules2.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Globals.h"
#include "SpecialMoves.h"


//Taking in first click x and y and the piece value

int board[8][8] = 	{{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0}};

int move[8][8] = 	{{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0}};

int newboard[8][8] = 	{{0,0,0,0,0,0,0,0},
			  {0,0,0,0,0,0,0,0},
			                {0,0,0,0,0,0,0,0},
			                {0,0,0,0,0,0,0,0},
			                {0,0,0,0,0,0,0,0},
			                {0,0,0,0,0,0,0,0},
			                {0,0,0,0,0,0,0,0},
			                {0,0,0,0,0,0,0,0}};

int checkmate = 1;

/*1=pawn,2=knight,3=bishop,4=rook,5=queen,6=king*/

void CheckPossibleMove(int x, int y, int piece){

  int prevloc[8][8] = 	{{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0}};
      
	
	for(int i=0;i<=7;i++)
	{
		for(int j=0;j<=7;j++)
		{
			board[i][j] = 0;
		}
	}
	/*Bottom side pawn*/
	
	if((piece == 1 && playerstart == 0 )||( piece == -1 && playerstart == 1)){
		if(y == 6 && x == 0)
		{
			//printf("Bottom Left Pond\n");
			for (int c = 1; c < 3; c++){			
				if (boardstate[y-c][x] == 0){
					board[y-c][x] = 1;
				}
        else
          break;
			}
			board[y-1][x+1] = 2;
		}
		else if(y == 6 && x == 7)
		{
			//printf("Bottom Right Pond\n");
			for (int c = 1; c < 3; c++){			
				if (boardstate[y-c][x] == 0){
					board[y-c][x] = 1;
				}
        else
          break;
			}
			board[y-1][x-1] = 2;
		}
		else if(x == 0)
		{

		        if (boardstate[y-1][x] == 0){
					board[y-1][x] = 1;
			}
			board[y-1][x+1] = 2;
		}
		else if(x == 7)
		{
		        if (boardstate[y-1][x] == 0){
					board[y-1][x] = 1;
			}
			board[y-1][x-1] = 2;
		}
		else if(y == 6)
                {

			for (int c = 1; c < 3; c++){			
				if (boardstate[y-c][x] == 0){
					board[y-c][x] = 1;
				}
        else
          break;
			}
			board[y-1][x+1] = 2;
			board[y-1][x-1] = 2;
		}

		else
		{
			if (boardstate[y-1][x] == 0){
					board[y-1][x] = 1;
			}
			board[y-1][x-1] = 2;
			board[y-1][x+1] = 2;
	}
}

	/*Top side pawn*/
	if((piece == -1 && playerstart == 0)||(piece == 1 && playerstart == 1)){
		if(y == 1 && x == 0)
                {
			for (int c = 1; c < 3; c++){			
				if (boardstate[y+c][x] == 0){
					board[y+c][x] = 1;
				}
        else
          break;
			}
			 
			board[y+1][x+1] = 2;
			
			
		}
		else if(y == 1 && x == 7)
                {
			for (int c = 1; c < 3; c++){			
				if (boardstate[y+c][x] == 0){
					board[y+c][x] = 1;
				}
        else
          break;
			}
			board[y+1][x-1] = 2;
		}
		else if(x == 0)
                {
			if (boardstate[y+1][x] == 0){
					board[y+1][x] = 1;
			}

			board[y+1][x+1] = 2;
		}
		else if(x == 7)
                {
			if (boardstate[y+1][x] == 0){
					board[y+1][x] = 1;
			}

			board[y+1][x-1] = 2;
		}
		else if(y == 1)
                {
			for (int c = 1; c < 3; c++){			
				if (boardstate[y+c][x] == 0){
					board[y+c][x] = 1;
				}
        else
          break;
			}
			board[y+1][x+1] = 2;
			board[y+1][x-1] = 2;
		}
		else
		{
		        if (boardstate[y+1][x] == 0){
					board[y+1][x] = 1;
			}

			board[y+1][x+1] = 2;
			board[y+1][x-1] = 2;

		}
	}
 
 
	/*Knight*/
	if(abs(piece) == 2){
		if((x-1>=0) && (y-2>=0))  board[y-2][x-1] =1;//top left
		if((x-2>=0) && (y-1>=0))  board[y-1][x-2] =1;
		if((x+1<=7) && (y-2>=0))  board[y-2][x+1] =1;//top right
		if((x+2<=7) && (y-1>=0))  board[y-1][x+2] =1;
		
		if((x-1>=0) && (y+2<=7))  board[y+2][x-1] =1;//bottom left
		if((x-2>=0) && (y+1<=7))  board[y+1][x-2] =1;
		if((x+1<=7) && (y+2<=7))  board[y+2][x+1] =1;//bottom right
		if((x+2<=7) && (y+1<=7))  board[y+1][x+2] =1;
	}
    	
	/*Bishop*/
	if (abs(piece) == 3){
  int i = 1;
  /*Bottom right*/
   while(y + i <= 7 && x + i <= 7 && boardstate[y+i][x+i] == 0)
		{
			board[y+i][x+i] = 1;
      i++;
		}
   /*Checks to see if same color or not*/
   if(piece < 0 && boardstate[y+i][x+i] > 0)
   {
     if(x+i != 8 && y+i != 8)
       board[y+i][x+i] = 1;
   }
   else if(piece > 0 && boardstate[y+i][x+i] < 0)
   {
     if(x+i != 8 && y+i != 8)
       board[y+i][x+i] = 1;
   }
   /*Bottom left*/
   i = 1;
   while(y + i <= 7 && x - i >= 0 && boardstate[y+i][x-i] == 0)
   {
     board[y+i][x-i] = 1;
     i++;
   }
   /*Checks to see if same color or not*/
   if(piece < 0 && boardstate[y+i][x-i] > 0)
   {
     if(x-i != -1 && y+i != 8)
       board[y+i][x-i] = 1;
   }
   else if(piece > 0 && boardstate[y+i][x-i] < 0)
   {
     if(x-i != -1 && y+i != 8)
       board[y+i][x-i] = 1;
   }
   /*Top left*/
   i = 1;
                while(y - i >= 0 && x - i >= 0 && boardstate[y-i][x-i] == 0)
                {
			board[y-i][x-i] = 1;
      i++;
                }
                /*Checks to see if same color or not*/
   if(piece < 0 && boardstate[y-i][x-i] > 0)
   {
     if(x-i != -1 && y-i != -1)
       board[y-i][x-i] = 1;
   }
   else if(piece > 0 && boardstate[y-i][x-i] < 0)
   {
     if(x-i != -1 && y-i != -1)
       board[y-i][x-i] = 1;
   }
                /*Top right*/
                i = 1;
                while(y - i >= 0 && x + i <= 7 && boardstate[y-i][x+i] == 0)
                {
                        board[y-i][x+i] = 1;
                        i++;
                }
                /*Checks to see if same color or not*/
   if(piece < 0 && boardstate[y-i][x+i] > 0)
   {
     if(y-i != -1 && x+i != 8)
       board[y-i][x+i] = 1;
   }
   else if(piece > 0 && boardstate[y-i][x+i] < 0)
   {
     if(y-i != -1 && x+i != 8)
       board[y-i][x+i] = 1;
   }
	}
 
 
	/*Rook*/
	if(abs(piece) == 4){
 int i = 1;
  /*Bottom*/
   while(y + i <= 7 && boardstate[y+i][x] == 0)
		{
			board[y+i][x] = 1;
      i++;
		}
   /*Checks to see if same color or not*/
   if(piece < 0 && boardstate[y+i][x] > 0)
   {
     if(y+i != 8)
       board[y+i][x] = 1;
   }
   else if(piece > 0 && boardstate[y+i][x] < 0)
   {
     if(y+i != 8)
       board[y+i][x] = 1;
   }
   i = 1;
  /*Top*/
   while(y - i >= 0 && boardstate[y-i][x] == 0)
		{
			board[y-i][x] = 1;
      i++;
		}
   /*Checks to see if same color or not*/
   if(piece < 0 && boardstate[y-i][x] > 0)
   {
     if(y-i != -1)
       board[y-i][x] = 1;
   }
   else if(piece > 0 && boardstate[y-i][x] < 0)
   {
     if(y-i != -1)
       board[y-i][x] = 1;
   }
   i = 1;
  /*Right*/
   while(x + i <= 7 && boardstate[y][x+i] == 0)
		{
			board[y][x+i] = 1;
      i++;
		}
   /*Checks to see if same color or not*/
   if(piece < 0 && boardstate[y][x+i] > 0)
   {
     if(x+i != 8)
       board[y][x+i] = 1;
   }
   else if(piece > 0 && boardstate[y][x+i] < 0)
   {
     if(x+i != 8)
       board[y][x+i] = 1;
   }
   i = 1;
   /*Left*/
   while(x - i >= 0 && boardstate[y][x-i] == 0)
		{
			board[y][x-i] = 1;
      i++;
		}
   /*Checks to see if same color or not*/
   if(piece < 0 && boardstate[y][x-i] > 0)
   {
       if(x-i != -1)
         board[y][x-i] = 1;
   }
   else if(piece > 0 && boardstate[y][x-i] < 0)
   {
     if(x-i != -1)
       board[y][x-i] = 1;
   }
	}
 
 
	/*Queen*/
	if(abs(piece) == 5){
   int i = 1;
  /*Bottom right*/
   while(y + i <= 7 && x + i <= 7 && boardstate[y+i][x+i] == 0)
		{
			board[y+i][x+i] = 1;
      i++;
		}
   /*Checks to see if same color or not*/
   if(piece < 0 && boardstate[y+i][x+i] > 0)
   {
     if(x+i != 8 && y+i != 8)
       board[y+i][x+i] = 1;
   }
   else if(piece > 0 && boardstate[y+i][x+i] < 0)
   {
     if(x+i != 8 && y+i != 8)
       board[y+i][x+i] = 1;
   }
   /*Bottom left*/
   i = 1;
   while(y + i <= 7 && x - i >= 0 && boardstate[y+i][x-i] == 0)
   {
     board[y+i][x-i] = 1;
     i++;
   }
   /*Checks to see if same color or not*/
   if(piece < 0 && boardstate[y+i][x-i] > 0)
   {
     if(x-i != -1 && y+i != 8)
       board[y+i][x-i] = 1;
   }
   else if(piece > 0 && boardstate[y+i][x-i] < 0)
   {
     if(x-i != -1 && y+i != 8)
       board[y+i][x-i] = 1;
   }
   /*Top left*/
   i = 1;
                while(y - i >= 0 && x - i >= 0 && boardstate[y-i][x-i] == 0)
                {
			board[y-i][x-i] = 1;
      i++;
                }
                /*Checks to see if same color or not*/
   if(piece < 0 && boardstate[y-i][x-i] > 0)
   {
     if(x-i != -1 && y-i != -1)
       board[y-i][x-i] = 1;
   }
   else if(piece > 0 && boardstate[y-i][x-i] < 0)
   {
     if(x-i != -1 && y-i != -1)
       board[y-i][x-i] = 1;
   }
                /*Top right*/
                i = 1;
                while(y - i >= 0 && x + i <= 7 && boardstate[y-i][x+i] == 0)
                {
                        board[y-i][x+i] = 1;
                        i++;
                }
                /*Checks to see if same color or not*/
   if(piece < 0 && boardstate[y-i][x+i] > 0)
   {
     if(y-i != -1 && x+i != 8)
       board[y-i][x+i] = 1;
   }
   else if(piece > 0 && boardstate[y-i][x+i] < 0)
   {
     if(y-i != -1 && x+i != 8)
       board[y-i][x+i] = 1;
   }
    i = 1;
  /*Bottom*/
   while(y + i <= 7 && boardstate[y+i][x] == 0)
		{
			board[y+i][x] = 1;
      i++;
		}
   /*Checks to see if same color or not*/
   if(piece < 0 && boardstate[y+i][x] > 0)
   {
     if(y+i != 8)
       board[y+i][x] = 1;
   }
   else if(piece > 0 && boardstate[y+i][x] < 0)
   {
     if(y+i != 8)
       board[y+i][x] = 1;
   }
   i = 1;
  /*Top*/
   while(y - i >= 0 && boardstate[y-i][x] == 0)
		{
			board[y-i][x] = 1;
      i++;
		}
   /*Checks to see if same color or not*/
   if(piece < 0 && boardstate[y-i][x] > 0)
   {
     if(y-i != -1)
       board[y-i][x] = 1;
   }
   else if(piece > 0 && boardstate[y-i][x] < 0)
   {
     if(y-i != -1)
       board[y-i][x] = 1;
   }
   i = 1;
  /*Right*/
   while(x + i <= 7 && boardstate[y][x+i] == 0)
		{
			board[y][x+i] = 1;
      i++;
		}
   /*Checks to see if same color or not*/
   if(piece < 0 && boardstate[y][x+i] > 0)
   {
     if(x+i != 8)
       board[y][x+i] = 1;
   }
   else if(piece > 0 && boardstate[y][x+i] < 0)
   {
     if(x+i != 8)
       board[y][x+i] = 1;
   }
   i = 1;
   /*Left*/
   while(x - i >= 0 && boardstate[y][x-i] == 0)
		{
			board[y][x-i] = 1;
      i++;
		}
   /*Checks to see if same color or not*/
   if(piece < 0 && boardstate[y][x-i] > 0)
   {
       if(x-i != -1)
         board[y][x-i] = 1;
   }
   else if(piece > 0 && boardstate[y][x-i] < 0)
   {
     if(x-i != -1)
       board[y][x-i] = 1;
   }
	}


	/*King*/
	if(piece == 6){
		//TOP LEFT WORKS
		if((x-1>=0) && (y-1>=0) && (boardstate[y-1][x-1] <= 0))  board[y-1][x-1]=1;
		//LEFT		
		if((x-1>=0)             && (boardstate[y][x-1] <= 0))  board[y  ][x-1]=1;
		//BOTTOM LEFT
		if((x-1>=0) && (y+1<=7)	&& (boardstate[y+1][x-1] <= 0))  board[y+1][x-1]=1;
		
		if(            (y+1<=7)&& (boardstate[y+1][x] <= 0))  board[y+1][x  ]=1;
		if((x+1<=7) && (y+1<=7)&& (boardstate[y+1][x+1] <= 0))  board[y+1][x+1]=1;
        	if((x+1<=7)            && (boardstate[y][x+1] <= 0))  board[y  ][x+1]=1;
		if((x+1<=7) && (y-1>=0)&& (boardstate[y-1][x+1] <= 0))  board[y-1][x+1]=1;
        	if(            (y-1>=0)&& (boardstate[y-1][x] <= 0))  board[y-1][x  ]=1;
	}
	
	if(piece == -6){
		//TOP LEFT WORKS
		if((x-1>=0) && (y-1>=0) && (boardstate[y-1][x-1] >= 0))  board[y-1][x-1]=1;
		//LEFT		
		if((x-1>=0)             && (boardstate[y][x-1] >= 0))  board[y  ][x-1]=1;
		//BOTTOM LEFT
		if((x-1>=0) && (y+1<=7)	&& (boardstate[y+1][x-1] >= 0))  board[y+1][x-1]=1;
		
		if(            (y+1<=7)&& (boardstate[y+1][x] >= 0))  board[y+1][x  ]=1;
		if((x+1<=7) && (y+1<=7)&& (boardstate[y+1][x+1] >= 0))  board[y+1][x+1]=1;
        	if((x+1<=7)            && (boardstate[y][x+1] >= 0))  board[y  ][x+1]=1;
		if((x+1<=7) && (y-1>=0)&& (boardstate[y-1][x+1] >= 0))  board[y-1][x+1]=1;
        	if(            (y-1>=0)&& (boardstate[y-1][x] >= 0))  board[y-1][x  ]=1;
	}

	
	//printf("BOARD =\n");
	//for(int i=0; i<8; i++) {
      	//	for(int j=0;j<8;j++) {
        //		 printf("%d ", board[i][j]);
         //	if(j==7){
         //   		printf("\n");
         //		}
      	//	}
   	//}
	
	/*prevloc[y][x] = piece;
	printf("PREV LOCATION =\n");
	for(int i=0; i<8; i++) {
      		for(int j=0;j<8;j++) {
        		 printf("%d ", prevloc[i][j]);
         	if(j==7){
            		printf("\n");
         		}
      		}
   	}*/
	
	//create 2d array in global array of all possible move coordinates

}

//boardstate[y][x];
/*1=valid, 0=invalid*/
int CheckMoveValid(int x, int y, int click1x, int click1y, int piece){
	//Check if there are pieces in between the possible moves with the 2d array from the previous function
 
 
	//printf("BOX CHECK = %d\n", board[y][x]);
 
 
   /*Black Pawn*/
	if (piece == 1 && playerstart == 0){
		if (board[y][x] == 1){
	
			if (boardstate[y][x] == 0){
				if (y == 0){
					boardstate[y][x] = 5;
					return 50;
				}
				else{
				return 1;
				}
			}
			else{
				return 0;	
			}		
		}
		else if (board[y][x] == 2){
			if (boardstate[y][x] < 0){
				return 1;
			}
			else{
				return 0;
			}
		}
		else{
			return 0;
		}
	}
	if (piece == 1 && playerstart == 1){
		if (board[y][x] == 1){
	
			if (boardstate[y][x] == 0){
				if (y == 7){
					boardstate[y][x] = 5;
					return 50;
				}
				else{
				return 1;
				}
			}
			else{
				return 0;	
			}		
		}
		else if (board[y][x] == 2){
			if (boardstate[y][x] < 0){
				return 1;
			}
			else{
				return 0;
			}
		}
		else{
			return 0;
		}
	}


  
  /*White Pawn*/
	if (piece == -1 && playerstart == 0){
		if (board[y][x] == 1){
	
			if (boardstate[y][x] == 0){
				if (y == 7){
					boardstate[y][x] = -5;
					return 50;
				}
				else{
				return 1;
				}
			}
			else{
				return 0;	
			}		
		}
		else if (board[y][x] == 2){
			if (boardstate[y][x] > 0){
				return 1;
			}
			else{
				return 0;
			}
		}
		else{
			return 0;
		}

		
	}
	if (piece == -1 && playerstart == 1){
		if (board[y][x] == 1){
	
			if (boardstate[y][x] == 0){
				if (y == 0){
					boardstate[y][x] = -5;
					return 50;
				}
				else{
				return 1;
				}
			}
			else{
				return 0;	
			}		
		}
		else if (board[y][x] == 2){
			if (boardstate[y][x] > 0){
				return 1;
			}
			else{
				return 0;
			}
		}
		else{
			return 0;
		}

		
	}
  
  
//  /*******Empassant***********/
//  //White Bottom and Black Top
//  //Black Move to White
//  
//  if ((piece == -1 && playerstart == 1)|| (piece == 1 && playerstart == 0)){
//    if((boardstate[4][x] == -1) && (boardstate[4][x+1] == 1)){
//      boardstate[4][x] = 0;
//      boardstate[4][x+1] = 0;
//      boardstate[3][x+1] = 1;
//      printf("Empassant\n");
//      return 50;
//    }
//    else if((boardstate[4][x] == -1) && (boardstate[4][x-1] == 1)){
//      boardstate[4][x] = 0;
//      boardstate[4][x+1] = 0;
//      boardstate[3][x+1] =1;
//      printf("Empassant\n");
//      return 50;
//    }
//    else{
//      printf("No Empassant\n");
//      return 1;
//    }
//  }
//
//  //White Bottom and Black Top
//  //White Move to Black
//  if ((piece == -1 && playerstart == 1)|| (piece == 1 && playerstart == 0)){
//    if((boardstate[3][x] == 1) && (boardstate[3][x+1] == -1)){
//      boardstate[3][x] = 0;
//      boardstate[3][x+1] = 0;
//      boardstate[2][x+1] = 1;
//      printf("Empassant\n");
//      return 50;
//    }
//    else if((boardstate[3][x] == 1) &&  (boardstate[3][x-1] == -1)){
//      boardstate[3][x] = 0;
//      boardstate[3][x-1] = 0;
//      boardstate[2][x-1] =1;
//      printf("Empassant\n");
//      return 50;
//    }
//    else{
//      printf("No Empassant\n");
//      return 1;
//    }
//  }
//
//  //Black Bottom and White Top
//  //Black Move to White
//  if ((piece == -1 && playerstart == 1)|| (piece == 1 && playerstart == 0)){
//    if((boardstate[3][x] == -1) && (boardstate[3][x+1] == 1)){
//      boardstate[3][x] = 0;
//      boardstate[3][x+1] = 0;
//      boardstate[2][x+1] = -1;
//      printf("Empassant\n");
//      return 50;
//    }
//    else if((boardstate[3][x] == -1) && (boardstate[3][x-1] == 1)){
//      boardstate[3][x] = 0;
//      boardstate[3][x-1] = 0;
//      boardstate[2][x-1] = -1;
//      printf("Empassant\n");
//      return 50;
//    }
//    else{
//      printf("No Empassant\n");
//      return 1;
//    }  
//  }
//
//  //Black Bottom and White Top  
//  //White Move to Black
//  if ((piece == -1 && playerstart == 1)|| (piece == 1 && playerstart == 0)){
//    if((boardstate[4][x] == 1)&&(boardstate[4][x+1] == -1)){
//      boardstate[4][x] = 0;
//      boardstate[4][x+1] = 0;
//      boardstate[3][x+1] = -1;
//      printf("Empassant\n");
//      return 50;
//    }
//    else if((boardstate[4][x] == 1) && (boardstate[4][x-1] == -1)){
//      boardstate[4][x] = 0;
//      boardstate[4][x+1] = 0;
//      boardstate[3][x+1] = -1;
//      printf("Empassant\n");
//      return 50;
//    }
//    else{
//      printf("No Empassant\n");
//      return 1;
//    }
//  }

  /*Knight*/
	if(piece == 2)
    	{
        	if (board[y][x] == 1){              // check posibale
            		if(boardstate[y][x] <= 0)       //check not the own piece and null 
                		return 1;
            		else 
                		return 0;
        	}
    	}
    	if(piece == -2)
    	{
        	if (board[y][x] == 1){              // check posibale
            		if(boardstate[y][x] >= 0)       //check not the own piece and null 
                		return 1;
            		else 
                		return 0;
        	}
    	}

	/*Bishop*/
	if(abs(piece) == 3)
	{
   if(board[y][x] == 1)
   {
     
     return 1;
   }
   else
   {
     return 0;
   }
	}

/*Castling for Rook and King*/
	if(piece == 6 && bKingMoves == 0)
	{/*Black Bottom Side*/
   if(playerstart == 0)
   {
		if(boardstate[y][3] == 0)
		{
			if(x-1 == 0)
			{
				if(boardstate[y][x-1] == 4 && blRookMoves == 0)
				{
					if(boardstate[7][1] == 0 && boardstate[7][2] == 0)
					{ 
						if(kingCheck(1,7,6) == 0 && kingCheck(2,7,6) == 0 && kingCheck(3,7,6) == 0)
							{ 
								boardstate[7][1] = 6;
								boardstate[7][2] = 4;
                boardstate[7][0] = 0;
								return 50;
							}
					}
         else
         {
         return 0;
         }
				}
      }
      else if(x+2 == 7)
				{
          if(boardstate[y][x+2] == 4  && brRookMoves == 0)
          {
					  if(boardstate[7][4] == 0 && boardstate[7][5] == 0 && boardstate[7][6] == 0)
                                        {
						if(kingCheck(3,7,6) == 0 && kingCheck(4,7,6) == 0 && kingCheck(5,7,6) == 0)
						{
	                                                boardstate[7][5] = 6;
	                                                boardstate[7][4] = 4;
                                                  boardstate[7][7] = 0;
	                                        	return 50;
						}
					}

        else
        {
          return 0;
        }
        }
			}
		}
   }
  }

	if(piece == -6 && wKingMoves == 0)
	{/*White Top Side*/
   if(playerstart == 0)
   {
		if(boardstate[y][3] == 0)
		{
			if(x-1 == 0)
			{
				if(boardstate[y][x-1] == -4  && wlRookMoves == 0)
				{
					if(boardstate[0][1] == 0 && boardstate[0][2] == 0)
					{
						if(kingCheck(1,0,-6) == 0 && kingCheck(2,0,-6) == 0 && kingCheck(3,0,-6) == 0)
							{ 
								boardstate[0][1] = -6;
								boardstate[0][2] = -4;
                boardstate[0][0] = 0;
								return 50;
							}
					}
         else
         {
         return 0;
         }
				}
      }
      else if(x+2 == 7)
				{
          if(boardstate[y][x+2] == -4  && wrRookMoves == 0)
          {
					  if(boardstate[0][4] == 0 && boardstate[0][5] == 0 && boardstate[0][6] == 0)
                                        {
						if(kingCheck(3,0,-6) == 0 && kingCheck(4,0,-6) == 0 && kingCheck(5,0,-6) == 0)
						{
	                                                boardstate[0][5] = -6;
	                                                boardstate[0][4] = -4;
                                                  boardstate[0][7] = 0;
	                                        	return 50;
						}
					}

        else
        {
          return 0;
        }
        }
			}
		}
   }
  }
  if(piece == 6 && bKingMoves == 0)
	{/*Black Top Side*/
   if(playerstart == 1)
   {
		if(boardstate[y][4] == 0)
		{
			if(x-2 == 0)
			{
				if(boardstate[y][x-2] == 4  && blRookMoves == 0)
				{
					if(boardstate[0][1] == 0 && boardstate[0][2] == 0 && boardstate[0][3] == 0)
					{ 
						if(kingCheck(4,0,6) == 0 && kingCheck(2,0,6) == 0 && kingCheck(3,0,6) == 0)
							{ 
								boardstate[0][2] = 6;
								boardstate[0][3] = 4;
                boardstate[0][0] = 0;
								return 50;
							}
					}
         else
         {
         return 0;
         }
				}
      }
      else if(x+1 == 7)
				{
          if(boardstate[y][x+1] == 4  && brRookMoves == 0)
          {
					  if(boardstate[0][5] == 0 && boardstate[0][6] == 0)
                                        {
						if(kingCheck(4,0,6) == 0 && kingCheck(5,0,6) == 0 && kingCheck(6,0,6) == 0)
						{
	                                                boardstate[0][6] = 6;
	                                                boardstate[0][5] = 4;
                                                  boardstate[0][7] = 0;
	                                        	return 50;
						}
					}

        else
        {
          return 0;
        }
        }
			}
		}
   }
  }

	if(piece == -6 && wKingMoves == 0)
	{/*White Bottom Side*/
   if(playerstart == 1)
   {
		if(boardstate[y][3] == 0)
		{
			if(x+1 == 7)
			{
				if(boardstate[y][x+1] == -4  && wrRookMoves == 0)
				{
					if(boardstate[7][5] == 0 && boardstate[0][6] == 0)
					{ 
						if(kingCheck(4,7,-6) == 0 && kingCheck(5,7,-6) == 0 && kingCheck(6,7,-6) == 0)
							{ 
								boardstate[7][5] = -6;
								boardstate[7][6] = -4;
                boardstate[7][7] = 0;
								return 50;
							}
					}
         else
         {
         return 0;
         }
				}
      }
      else if(x-2 == 0)
				{
          if(boardstate[y][x-2] == -4  && wlRookMoves == 0)
          {
					  if(boardstate[7][1] == 0 && boardstate[7][2] == 0 && boardstate[7][3] == 0)
                                        {
						if(kingCheck(2,7,-6) == 0 && kingCheck(3,7,-6) == 0 && kingCheck(4,7,-6) == 0)
						{
	                                                boardstate[7][2] = -6;
	                                                boardstate[7][3] = -4;
                                                  boardstate[7][0] = 0;
	                                        	return 50;
						}
					}

        else
        {
          return 0;
        }
        }
			}
		}
   }
  }
  

	/*Rook*/
   if(abs(piece) == 4)
   {
	  if(board[y][x] == 1)
     {
       
       return 1;
     }
     else
     {
       return 0;
     }
   }
  

  /*Queen*/
  if(abs(piece) == 5)
   {
	  if(board[y][x] == 1)
     {
       
       return 1;
     }
     else
     {
       return 0;
     }
   }
   
   
   /*King*/
	if(piece == 6)
        {
            if (board[y][x] != 1){ 
		return 0; 
		}              // check posibale
            if(boardstate[y][x] <= 0){       //check not the own piece and null 
      		return 1;
		}
            else{ 
                return 0;
		}

        }
        if(piece == -6)
        {
            if (board[y][x] != 1){ 
		return 0; 
		}// check posibale
            if(boardstate[y][x] >= 0)       // check there not the ownpiece
                    {
			return 1;
			}
                else 
                    {
		return 0;
		}

        } 
        

}

//TESTING PURPOSES
/*int main(){
	int i, j;
	int bboardstate[8][8] = {{-4,-2,-3,-6,-5,-3,-2,-4}, // Initial Board State
				{-1,-1,-1,-1,-1,-1,-1,-1},
				{0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0},
 				{1, 1, 1, 1, 1, 1, 1, 1},
				{ 4, 2, 3, 6, 5, 3, 2, 4}};
	
	CheckPossibleMove(6, 0, 1);

   	for(i=0; i<8; i++) {
      		for(j=0;j<8;j++) {
        		 printf("%d ", board[i][j]);
         	if(j==7){
            		printf("\n");
         		}
      		}
   	}

	
	return 0;
}*/
