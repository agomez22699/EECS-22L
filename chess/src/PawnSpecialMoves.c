#include "Rules2.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Globals.h"
void empassant(int x, int y, int piece);
//void promotion(int x, int y, int piece);

int oneBlock = 1;
int twoBlock = 2;
//void castling(int x, int y, int piece);



void empassant(int x, int y, int piece){

//CASES:
 //(ia) Check if bottom moved two position to the 4th row and if top is on row 
 //(ib) Move top to 5th row if satifies empassant
 //(iia) Check if top moved two position to the 3rd row and if bottom is on
 //(iib) Move bottom to 2nd row if satifies empassant 
 //if doesn't satisfy empassant return 0 if so return 1
 //Make an empassant statement 
   
	for(int i=0;i<=7;i++)
	{
		for(int j=0;j<=7;j++)
		{
			board[i][j] = 0;
		}
	}
 
//Pawn must be on the fifth row and the captured on the fourth 
//|| boardstate[y-1][x-1] = 2 

//set criteria of one block versus two block 
  
//Bottom Portion of Board  Moving to Top of Portion of Board 
//start white bottom and black top 
  if(piece == -1){   //pawn piece
    if(y == 6 && x == 0){     
      boardstate[y-1][x] == oneBlock;
      boardstate[y-2][x] == twoBlock;
      
      }
      else {
        printf("error with bottom white to top");
        //return 0;
      }
    }
  }



/*//Top Portion of Board  
  if(abs(piece == 1)){   //pawn piece
    if(y == 1){          
      if(boardstate[y-1][x+1] = 2 || boardstate[y-1][x-1] = 2){ //check to see if bottom moved two spaces
      
    
        //if(y == 1)//check if opponent is on the th row 
        //set capture and proper location of bottom pawn
        printf("Empassant");
      }
      else {
        printf("No empassant");
        return 0;
      }
    }
  }

*/
 
 	/*printf("BOARD =\n");
	for(int i=0; i<8; i++) {
	  for(int j=0;j<8;j++) {
		   printf("%d ", board[i][j]);
  	   if(j==7){
    		  printf("\n");
    		}
 		}
	}*/
    
	printf("BOARDSTATE_EMPASSANT =\n");
	for(int i=0; i<8; i++) {
      		for(int j=0;j<8;j++) {
        		 printf("%d ", boardstate[i][j]);
         	if(j==7){
            		printf("\n");
         		}
      		}
   	}
	
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

}

/*
void promotion(int x, int y, int piece){

int promotedPieceBlack;
int promotedPieceWhite;

	for(int i=0;i<=7;i++)
	{
		for(int j=0;j<=7;j++)
		{
			board[i][j] = 0;
		}
	}

//Bottom Pawn Moves to Top 



//Top Pawn Moves to Bottom 



//Turn into a queen 




//Option of what the Pawn can be converted to 
/*1=pawn,2=knight,3=bishop,4=rook,5=queen,6=king*/
//Can be promoted to anything other than king or pawn
/*switch (promotedPieceBlack){
                        case 2:
                                bpp = 2;
                                break;
                        case 3:
                                bpp = 3;
                                break;
                        case 4:
                                bpp = 4;
                                break;
                        case 5:
                                bpp = 5;
                                break;
                        default:
                                printf("There has been an error");
                                break;
}


switch (promotedPieceWhite){
                        case -2:
                                wpp = -2;
                                break;
                        case -3:
                                wpp = -3;
                                break;
                        case -4:
                                wpp = -4;
                                break;
                        case -5:
                                wpp = -5;
                                break;
                        default:
                                printf("There has been an error);
                                break;
}


	printf("BOARDSTATE_PROMOTION =\n");
	for(int i=0; i<8; i++) {
      		for(int j=0;j<8;j++) {
        		 printf("%d ", boardstate[i][j]);
         	if(j==7){
            		printf("\n");
         		}
      		}
   	}
	

}*/