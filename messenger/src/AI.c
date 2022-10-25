//File that contains the AI Functionality
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gtk/gtk.h>
#include <gdk/gdkx.h>
#include <gdk/gdktestutils.h>
#include "Globals.h"
#include <string.h> 

void CheckPossibleMove(int x, int y, int piece);
int CheckMoveValid(int x, int y, int piece);
void parraytransfer(int x);
void logprint(int datastate, int x, int y);

int AIside; //black = 0, white = 1;

void AIprint(int l, int x, int y){
        char z;

	if (AIside == 0){
        switch (x){
                        case 0:
                                x = 8;
                                break;
                        case 1:
                                x = 7;
                                break;
                        case 2:
                                x = 6;
                                break;
                        case 3:
                                x = 5;
                                break;
                        case 4:
                                x = 4;
                                break;
                        case 5:
                                x = 3;
                                break;
                        case 6:
                                x = 2;
                                break;
                        case 7:
                                x = 1;
                                break;
                        default:
                                x = 10;
                                break;
                }

        switch (y){
                        case 0:
                                z = 'A';
                                break;
                        case 1:
                                z = 'B';
                                break;
                        case 2:
                                z = 'C';
                                break;
                        case 3:
                                z = 'D';
                                break;
                        case 4:
                                z = 'E';
                                break;
                        case 5:
                                z = 'F';
                                break;
                        case 6:
                                z = 'G';
                                break;
                        case 7:
                                z = 'H';
                                break;
                        default:
                                z = 'X';
                                break;
                }
}

	if (AIside == 1){
        switch (x){
                        case 0:
                                x = 1;
                                break;
                        case 1:
                                x = 2;
                                break;
                        case 2:
                                x = 3;
                                break;
                        case 3:
                                x = 4;
                                break;
                        case 4:
                                x = 5;
                                break;
                        case 5:
                                x = 6;
                                break;
                        case 6:
                                x = 7;
                                break;
                        case 7:
                                x = 8;
                                break;
                        default:
                                x = 10;
                                break;
                }

        switch (y){
                        case 0:
                                z = 'H';
                                break;
                        case 1:
                                z = 'G';
                                break;
                        case 2:
                                z = 'F';
                                break;
                        case 3:
                                z = 'E';
                                break;
                        case 4:
                                z = 'D';
                                break;
                        case 5:
                                z = 'C';
                                break;
                        case 6:
                                z = 'B';
                                break;
                        case 7:
                                z = 'A';
                                break;
                        default:
                                z = 'X';
                                break;
                }
}


                if (l == 1){
                        printf("(%c,%d) ---> ", z, x);
                                        }

                else if (l == 2){
                        printf("(%c,%d)\n", z, x);
                                        }


}

char pieces[3];
void switchVAL(int x){
			switch (x){
		case 1:
			strcpy(pieces,"bP");	
			break;
		case 2:
			strcpy(pieces,"bH");
			break;
		case 3:
			strcpy(pieces,"bB");
			break;
		case 4:
			strcpy(pieces,"bR");
			break;
		case 5:
			strcpy(pieces,"bQ");
			break;
		case 6:
			strcpy(pieces,"bK");
			break;
		case -1:
			strcpy(pieces,"wP");
			break;
		case -2:
			strcpy(pieces,"wH");
			break;
		case -3: 
			strcpy(pieces,"wB");
			break;
		case -4:
			strcpy(pieces,"wR");
			break;
		case -5:
			strcpy(pieces,"wQ");
			break;
		case -6:
			strcpy(pieces,"wK");
			break;
		default:
			strcpy(pieces,"  ");
			break;
			}
				}
void whiteAI(){
	//printf("IM IN AI FUNCTION\n");
	int x;
	int y; 
   	int good = 0;
	int movecounter = 0;
	int piece = 10;
	srand(time(NULL));
    	while(good == 0){
		while (piece >= 0 || movecounter == 0)
		{
        		x = rand()%8; //RANDOM NUMBER 0-7
       	 		//printf("%d\n", x);
       	 		y = rand()%8; //RANDOM NUMBER 0-7
        		//printf("%d %d\n", x, y);
        		piece = boardstate[y][x];
			//printf("piece = %d\n", piece);
		
			CheckPossibleMove(x, y, piece);
			movecounter = 0;
			for(int i=0; i<8; i++){
      				for(int j=0;j<8;j++){
					if (board[i][j] == 1){
        					movecounter = movecounter + 1;
					}
				} 
   			}
	

		}
        	
		//printf("Valid Move Counter = %d\n", movecounter);
		
	
         	int newx = rand()%8; //RANDOM NUMBER 0-7
        	//printf("%d\n", x);
        	int newy = rand()%8; //RANDOM NUMBER 0-7
        	printf("Loading Move = %d %d\n", newx, newy);
        	int check = CheckMoveValid(newy, newx, piece);
		//printf("VALID = %d\n",check);
        	if (check == 1 || check == 50){
			boardstate[y][x] = 0;
            		boardstate[newx][newy] = piece;
			parraytransfer(piece);
			AIside = 1;
			datastate = 1;
			AIprint(datastate, y, x);
			logprint(datastate, y, x);
			datastate = 2;
			AIprint(datastate, newx, newy);
			logprint(datastate, newx, newy);
            		good = 1;
        	}
    	}
	printf("BOARDSTATE AI =\n");
	printf(" +-----------------------------------------+ \n");
	printf(" ¦+---------------------------------------+¦ \n");

	for(int i = 0; i <= 7; i++) {
		printf("%d¦¦", i+1);
		for(int j = 0; j < 8; j++) {
			switchVAL(boardstate[i][j]);
			printf(" %s ¦", pieces);
		}
		printf("¦ \n");
		if(i < 7) {
			printf(" ¦+----+----+----+----+----+----+----+----¦¦ \n");
		}
	}

	printf(" ¦+---------------------------------------+¦ \n");
	printf(" +-----------------------------------------+ \n");
	printf("    H    G    F    E    D    C    B    A    \n");
	printf("\n");

}
void blackAI(){
	//printf("IM IN AI FUNCTION\n");
	int x;
	int y;
   	int good = 0;
	int movecounter = 0;
	int piece = 10;
	srand(time(NULL));
    	while(good == 0){
		while (piece <= 0 || movecounter == 0)
		{
        		x = rand()%8; //RANDOM NUMBER 0-7
       	 		//printf("%d\n", x);
       	 		y = rand()%8; //RANDOM NUMBER 0-7
        		//printf("%d %d\n", x, y);
        		piece = boardstate[y][x];
			//printf("piece = %d\n", piece);
		
			CheckPossibleMove(x, y, piece);
			movecounter = 0;
			for(int i=0; i<8; i++){
      				for(int j=0;j<8;j++){
					if (board[i][j] == 1){
        					movecounter = movecounter + 1;
					}
				} 
   			}
	

		}
        	
		//printf("Valid Move Counter = %d\n", movecounter);
		
	
 
        	int newx = rand()%8; //RANDOM NUMBER 0-7
        	//printf("%d\n", x);
        	int newy = rand()%8; //RANDOM NUMBER 0-7
        	printf("Loading Move = %d %d\n", newx, newy);
        	int check = CheckMoveValid(newy, newx, piece);
		//printf("VALID = %d\n",check);
        	if (check == 1 || check == 50){
			boardstate[y][x] = 0;
            		boardstate[newx][newy] = piece;
			parraytransfer(piece);
			AIside = 0;
			datastate = 1;
			AIprint(datastate, y, x);
			logprint(datastate, y, x);
			datastate = 2;
			AIprint(datastate, newx, newy);
			logprint(datastate, newx, newy);
            		good = 1;
        	}
    	}
	printf("BOARDSTATE AI =\n");
	printf(" +-----------------------------------------+ \n");
	printf(" ¦+---------------------------------------+¦ \n");

	for(int i = 0; i <= 7; i++) {
		printf("%d¦¦", 8 - i);
		for(int j = 0; j < 8; j++) {
			switchVAL(boardstate[i][j]);
			printf(" %s ¦", pieces);
		}
		printf("¦ \n");
		if(i < 7) {
			printf(" ¦+----+----+----+----+----+----+----+----¦¦ \n");
		}
	}

	printf(" ¦+---------------------------------------+¦ \n");
	printf(" +-----------------------------------------+ \n");
	printf("    A    B    C    D    E    F    G    H    \n");
	printf("\n");
}

