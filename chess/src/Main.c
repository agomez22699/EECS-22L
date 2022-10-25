#include <gtk/gtk.h>
#include <gdk/gdkx.h>
#include <gdk/gdktestutils.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "Globals.h"
#include "SpecialMoves.h"

int playerstart;
int click;
int click = 1;
int piececlicked;
int timecount = 0;
int gamemode;
int c = 0;

struct _Cell {
    	int x;
    	int y;
	int state;
    	GtkImage* image;
};

void createChessboard (int boardstate[][8]);
void CheckPossibleMove(int x, int y, int piece);
int CheckMoveValid(int x, int y, int click1x,int click1y, int piece);
void whiteAI();
void blackAI();
int kingCheck(int x, int y, int piece);

int bboardstate[8][8] = 	{{-4,-2,-3,-6,-5,-3,-2,-4}, // Initial Board State
				{-1,-1,-1,-1,-1,-1,-1,-1},
				{0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0},
 				{1, 1, 1, 1, 1, 1, 1, 1},
				{ 4, 2, 3, 6, 5, 3, 2, 4}};

int wboardstate[8][8] = 	{{4,2,3,5,6,3,2,4}, // Initial Board State
				{1,1,1,1,1,1,1,1},
				{0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0},
 				{-1, -1, -1, -1, -1, -1, -1, -1},
				{ -4, -2, -3, -5, -6, -3, -2, -4}};

int boardstate[8][8];
typedef struct _Cell Cell;


static int StartP = 0;
char piecestring[20];
void parraytransfer(int x){
	switch (x){
		case 1:
			strcpy(piecestring,"Black Pawn");	
			break;
		case 2:
			strcpy(piecestring,"Black Knight");
			break;
		case 3:
			strcpy(piecestring,"Black Bishop");
			break;
		case 4:
			strcpy(piecestring,"Black Rook");
			break;
		case 5:
			strcpy(piecestring,"Black Queen");
			break;
		case 6:
			strcpy(piecestring,"Black King");
			break;
		case -1:
			strcpy(piecestring,"White Pawn");
			break;
		case -2:
			strcpy(piecestring,"White Knight");
			break;
		case -3: 
			strcpy(piecestring,"White Bishop");
			break;
		case -4:
			strcpy(piecestring,"White Rook");
			break;
		case -5:
			strcpy(piecestring,"White Queen");
			break;
		case -6:
			strcpy(piecestring,"White King");
			break;
		default:
			strcpy(piecestring,"Unknown Piece");
			break;
			}
				}


void logprint(int datastate, int x, int y){
        FILE * FP;
        char z;
	if (playerstart == 1){
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

	if (playerstart == 0){
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
        if (StartP == 0){
                FP = fopen("Log.txt", "w");
                fprintf(FP, "------------------------------ Beginning Of Chess Game ------------------------------\n");
                fprintf(FP, "%s moved from (%c,%d) ---> ",piecestring, z,x);
                StartP++;
                fclose(FP);
                               }
        else{
                if (datastate == 1){
                        FP = fopen("Log.txt", "a");
                        fprintf(FP, "%s moved from (%c,%d) ---> ",piecestring, z, x);
                        fclose(FP);
                                        }

                else if (datastate == 2){
                        FP = fopen("Log.txt", "a");
                        fprintf(FP, "(%c,%d)\n", z, x);
                        fclose(FP);
                                        }

                else if (datastate == 3){
                        FP = fopen("Log.txt", "a");
                        fprintf(FP, "--------------------------------- End Of Chess Game ---------------------------------\n\n");
                        fclose(FP);

                                        }

		else if (datastate == 4){
                        FP = fopen("Log.txt", "a");
                        fprintf(FP, "Black Player Lost because of an Invalid move!\nWhite Player Wins!\n");
                        fclose(FP);

                                        }
		else if (datastate == 5){
                        FP = fopen("Log.txt", "a");
                        fprintf(FP, "White Player Lost because of an Invalid move!\nBlack Player Wins!\n");
                        fclose(FP);

                                        }
		else if (datastate == 6){
                        FP = fopen("Log.txt", "a");
                        fprintf(FP, "Checkmate!\nWhite Player Wins!");
                        fclose(FP);

                                        }
		else if (datastate == 7){
                        FP = fopen("Log.txt", "a");
                        fprintf(FP, "Checkmate!\nBlack Player Wins!");
                        fclose(FP);

                                        }



                }
                                                }


//0 black 1 white
int playerturn;
int click1x, click1y;
int bkingalive = 0;
int wkingalive = 0;
int p = 0;
int q = 0;

int *handle_button_click(Cell* cell, GtkButton* button) {
    	//g_warning("clicked x=%d, y=%d\n", cell->x, cell->y);
//	GdkColor color;

if(gamemode == 0){	//Player versus Player
	int x = cell->x;
	int y = cell->y;
	int *coords = malloc (sizeof(int) * 2);

	
	coords[1] = y;
	coords[0] = x;
	//printf("x: %d\n",coords[1]);
	//printf("y: %d\n",coords[0]);
	//printf("Piece clicked is: %d\n", boardstate[y][x]);
	
	if (click == 1){
		//CheckPossibleMove(coords[0],coords[1], boardstate[y][x]);
		//printf("CLICK: %d\n", click);
		click1x = coords[0];
		click1y = coords[1];
	}
	/*else if (click == 2){
		printf("CLICK: %d\n", click);
	}*/
	if(cell->state == 0 && click != 0) {
	  if(click == 1) {
			//printf("click 1");
			piececlicked = boardstate[y][x];
			
			CheckPossibleMove(x,y, piececlicked);	
			//player picked white  piece clicked black  turn 2
			if (piececlicked >= 1 && playerturn == 0 && playerstart == 1){
				gtk_container_remove(GTK_CONTAINER(button), GTK_WIDGET(cell->image));

				//printf("Piece saved in click 1 is: %d\n", piececlicked);
      				cell->image = (GtkImage*) gtk_image_new_from_file("empty.png");
      				cell->state = 0;
				parraytransfer(piececlicked);
				datastate = 1;
				logprint(datastate, y, x);
				boardstate[y][x] = 0;
      				click = 2;
			}
			//player picked white piece clicked white on turn 1

			else if (piececlicked <= -1  && playerturn == 1 && playerstart == 1){
				gtk_container_remove(GTK_CONTAINER(button), GTK_WIDGET(cell->image));
				//printf("Piece saved in click 1 is: %d\n", piececlicked);
      				cell->image = (GtkImage*) gtk_image_new_from_file("empty.png");
      				cell->state = 0;
				parraytransfer(piececlicked);
				datastate = 1;
				logprint(datastate, y, x);
				boardstate[y][x] = 0;
      				click = 2;
			}
			//player picked black piece clicked black turn 2
			else if (piececlicked >= 1 && playerturn == 0 && playerstart == 0){
				gtk_container_remove(GTK_CONTAINER(button), GTK_WIDGET(cell->image));

				//printf("Piece saved in click 1 is: %d\n", piececlicked);
      				cell->image = (GtkImage*) gtk_image_new_from_file("empty.png");
      				cell->state = 0;
				parraytransfer(piececlicked);
				datastate = 1;
				logprint(datastate, y, x);
				boardstate[y][x] = 0;
      				click = 2;
			}
			//player picked black piece clicked white turn 1
			else if (piececlicked <= -1  && playerturn == 1 && playerstart == 0){
				gtk_container_remove(GTK_CONTAINER(button), GTK_WIDGET(cell->image));
				//printf("Piece saved in click 1 is: %d\n", piececlicked);
      				cell->image = (GtkImage*) gtk_image_new_from_file("empty.png");
      				cell->state = 0;
				parraytransfer(piececlicked);
				datastate = 1;
				logprint(datastate, y, x);
				boardstate[y][x] = 0;
      				click = 2;
			}


    		}

    	else if(click == 2){
		
		

		gtk_container_remove(GTK_CONTAINER(button), GTK_WIDGET(cell->image));

		//printf("click 2\n");
		datastate = 2;
		logprint(datastate, y, x);
		//printf("Piece saved after click 1 is: %d\n", piececlicked);
		//printf("Click 1 saved = %d %d\n", click1x, click1y);
		int check = CheckMoveValid(coords[0],coords[1],click1x, click1y, piececlicked);
      		//printf("VALID = %d\n", check);
		
		//printf("BSTATE CHECK = %d\n", boardstate[y][x]);

		
  if (piececlicked == 1){
				if (check != 50){
            boardstate[y][x] = 1; // makes sure the new location is updated
            cell->image = (GtkImage*) gtk_image_new_from_file("bpond.png");
				}
                        }
                        else if (piececlicked == 2){
                                boardstate[y][x] = 2;
                                cell->image = (GtkImage*) gtk_image_new_from_file("bknight.png");
                        }
                        else if (piececlicked == 3){
                                boardstate[y][x] = 3;
                                cell->image = (GtkImage*) gtk_image_new_from_file("bbishop.png");
                        }
                        else if (piececlicked == 4){
                                boardstate[y][x] = 4;
                                cell->image = (GtkImage*) gtk_image_new_from_file("brook.png");
                        }
                        else if (piececlicked == 5){
                                boardstate[y][x] = 5;
                                cell->image = (GtkImage*) gtk_image_new_from_file("bqueen.png");
                        }
                        else if (piececlicked == 6){
                                boardstate[y][x] = 6;
                                cell->image = (GtkImage*) gtk_image_new_from_file("bking.png");
                        }
                        else if (piececlicked == -1){
				if (check != 50){
                                boardstate[y][x] = -1;
                                cell->image = (GtkImage*) gtk_image_new_from_file("wpond.png");
				}
                        }
                        else if (piececlicked == -2){
                                boardstate[y][x] = -2;
                                cell->image = (GtkImage*) gtk_image_new_from_file("wknight.png");
                        }
                        else if (piececlicked == -3){
                                boardstate[y][x] = -3;
                                cell->image = (GtkImage*) gtk_image_new_from_file("wbishop.png");
                        }
                        else if (piececlicked == -4){
                                boardstate[y][x] = -4;
                                cell->image = (GtkImage*) gtk_image_new_from_file("wrook.png");
                        }
                        else if (piececlicked == -5){
                                boardstate[y][x] = -5;
                                cell->image = (GtkImage*) gtk_image_new_from_file("wqueen.png");
                        }
                        else if (piececlicked == -6){
                                boardstate[y][x] = -6;
                                cell->image = (GtkImage*) gtk_image_new_from_file("wking.png");
                        }
  int bx=-1,by,wx=-1,wy; /*black and white king positions*/
  for(int i=0;i<=7;i++)
  {
    for(int j=0;j<=7;j++)
    {
      if(boardstate[i][j] == 6)
      {
        bx = j;
        by = i;
      }
      else if(boardstate[i][j] == -6)
      {
        wx = j;
        wy = i;
      }
    }
  }
  if(bx!=-1 || wx!=-1)
  {
  int bCHECK = kingCheck(bx, by, 6);
  int wCHECK = kingCheck(wx, wy, -6);
		if (bCHECK == 1){
			printf("Black is in Check!\n");
     		if(checkMate(6) == 100){
        		printf("Black is in Checkmate!\n");					}
		}
		if (wCHECK == 1){
			printf("White is in Check!\n");
      		if(checkMate(-6) == -100){
       			printf("White is in Checkmate!\n");
					}
		}
   }

	
    cell->state = 0;
    click = 1;
		if (playerturn == 1){
			playerturn = 0;
		}
		else{
			playerturn = 1;
		}
		if (check == 50){
			createChessboard(boardstate);
		}
		if (check != 1 && check != 50){
			//BLACK TURN
			if (playerstart == 0 && playerturn == 1){
				datastate = 4;
				logprint(datastate, x,y);
				datastate = 3;
				logprint(datastate, x,y);
			printf("ERROR CODE = 100\n");
				printf("Black Player Loses!\n");
				printf("Invalid Move: Game over!\n");
			}
			else if (playerstart == 0 && playerturn == 0){
				datastate = 5;
                                logprint(datastate, x,y);
                                datastate = 3;
                                logprint(datastate, x,y);
			printf("ERROR CODE = 100\n");
				printf("White Player Loses!\n");
				printf("Invalid Move: Game over!\n");
			}
			else if (playerstart == 1 && playerturn == 1){
				datastate = 4;
                                logprint(datastate, x,y);
                                datastate = 3;
                                logprint(datastate, x,y);
				printf("ERROR CODE = 100\n");
				printf("Black Player Loses!\n");
				printf("Invalid Move: Game over!\n");
			}
			else if (playerstart == 1 && playerturn == 0){
				datastate = 5;
                                logprint(datastate, x,y);
                                datastate = 3;
                                logprint(datastate, x,y);
				printf("ERROR CODE = 100\n");
				printf("White Player Loses!\n");
				printf("Invalid Move: Game over!\n");
			}

			exit(0);
		}
    	}
    	gtk_widget_show(GTK_WIDGET(cell->image));
    	gtk_container_add(GTK_CONTAINER(button), GTK_WIDGET(cell->image));
	p = 0;
	q = 0;
	/*for(int i=0; i<8; i++) {
      		for(int j=0;j<8;j++) {
        		 printf("%d ", boardstate[i][j]);
         	if(j==7){
            		printf("\n");
         		}
      		}
   	}*/

	/*for(int i=0; i<8; i++) {
      		for(int j=0;j<8;j++) {
        		 if (boardstate[i][j] == -6){
				printf("test1\n");
				p = 1;
			}
			if (boardstate[i][j] == 6){
				printf("test2\n");
				q = 1;		
			}
      		}	
   	}
	//printf("p = %d\n", p);
	//printf("q = %d\n", q);*/


	}
	
	return coords;
}


	if(gamemode == 1 && playerstart == 0){ //Player versus AI with Black Start
	int x = cell->x;
	int y = cell->y;
	int *coords = malloc (sizeof(int) * 2);
	
	
	coords[1] = y;
	coords[0] = x;
//	printf("x: %d\n",coords[1]);
//	printf("y: %d\n",coords[0]);
//	printf("Piece clicked is: %d\n", boardstate[y][x]);
	
//	if (click == 1){
//		//CheckPossibleMove(coords[0],coords[1], boardstate[y][x]);
//		printf("CLICK: %d\n", click);
//	}
//	else if (click == 2){
//		printf("CLICK: %d\n", click);
//	}
	if(cell->state == 0 && click != 0) {
		    		
		

		
		
    		if(click == 1) {
			//printf("click 1");
			piececlicked = boardstate[y][x];	
			CheckPossibleMove(x,y, piececlicked);			
			//player picked white  piece clicked black  turn 2
			if (piececlicked >= 1 && playerturn == 0 && playerstart == 1){
				gtk_container_remove(GTK_CONTAINER(button), GTK_WIDGET(cell->image));

				//printf("Piece saved in click 1 is: %d\n", piececlicked);
      				cell->image = (GtkImage*) gtk_image_new_from_file("empty.png");
      				cell->state = 0;
				parraytransfer(piececlicked);
				datastate = 1;
				logprint(datastate, y, x);
				boardstate[y][x] = 0;
      				click = 2;
			}
			//player picked white piece clicked white on turn 1

			else if (piececlicked >= 1 && playerturn == 0){
				gtk_container_remove(GTK_CONTAINER(button), GTK_WIDGET(cell->image));

				//printf("Piece saved in click 1 is: %d\n", piececlicked);
      				cell->image = (GtkImage*) gtk_image_new_from_file("empty.png");
      				cell->state = 0;
				parraytransfer(piececlicked);
				datastate = 1;
				logprint(datastate, y, x);
				boardstate[y][x] = 0;
      				click = 2;
			}
    		}

    	else if(click == 2){
		
		

		gtk_container_remove(GTK_CONTAINER(button), GTK_WIDGET(cell->image));

		//printf("click 2\n");
		datastate = 2;
		logprint(datastate, y, x);
		//printf("Piece saved after click 1 is: %d\n", piececlicked);
		
		int check = CheckMoveValid(coords[0],coords[1],click1x, click1y, piececlicked);
      		//printf("VALID = %d\n", check);
		
		//printf("BSTATE CHECK = %d\n", boardstate[y][x]);

		
                        if (piececlicked == 1){
				if (check != 50){
                                boardstate[y][x] = 1; // makes sure the new location is updated
                                cell->image = (GtkImage*) gtk_image_new_from_file("bpond.png");
				}
                        }
                        else if (piececlicked == 2){
                                boardstate[y][x] = 2;
                                cell->image = (GtkImage*) gtk_image_new_from_file("bknight.png");
                        }
                        else if (piececlicked == 3){
                                boardstate[y][x] = 3;
                                cell->image = (GtkImage*) gtk_image_new_from_file("bbishop.png");
                        }
                        else if (piececlicked == 4){
                                boardstate[y][x] = 4;
                                cell->image = (GtkImage*) gtk_image_new_from_file("brook.png");
                        }
                        else if (piececlicked == 5){
                                boardstate[y][x] = 5;
                                cell->image = (GtkImage*) gtk_image_new_from_file("bqueen.png");
                        }
                        else if (piececlicked == 6){
                                boardstate[y][x] = 6;
                                cell->image = (GtkImage*) gtk_image_new_from_file("bking.png");
                        }
                        else if (piececlicked == -1){
				if (check != 50){
                                boardstate[y][x] = -1;
                                cell->image = (GtkImage*) gtk_image_new_from_file("wpond.png");
				}
                        }
                        else if (piececlicked == -2){
                                boardstate[y][x] = -2;
                                cell->image = (GtkImage*) gtk_image_new_from_file("wknight.png");
                        }
                        else if (piececlicked == -3){
                                boardstate[y][x] = -3;
                                cell->image = (GtkImage*) gtk_image_new_from_file("wbishop.png");
                        }
                        else if (piececlicked == -4){
                                boardstate[y][x] = -4;
                                cell->image = (GtkImage*) gtk_image_new_from_file("wrook.png");
                        }
                        else if (piececlicked == -5){
                                boardstate[y][x] = -5;
                                cell->image = (GtkImage*) gtk_image_new_from_file("wqueen.png");
                        }
                        else if (piececlicked == -6){
                                boardstate[y][x] = -6;
                                cell->image = (GtkImage*) gtk_image_new_from_file("wking.png");
                        }
		
      		cell->state = 0;
      		click = 1;
		if (playerturn == 1){
			playerturn = 0;
			whiteAI();
			createChessboard(boardstate);
			playerturn = 1;

		}
		else{
			playerturn = 1;
			whiteAI();
			createChessboard(boardstate);
			playerturn = 0;

		}
	
		if (check != 1 && check != 50){
			//BLACK TURN
				datastate = 4;
				logprint(datastate, x,y);
				datastate = 3;
				logprint(datastate, x,y);
				printf("Black Player Loses!\n");
				printf("ERROR CODE = 100\n");
				printf("Invalid Move: Game over!\n");
			exit(0);
		}
		
    	}
	
    	gtk_widget_show(GTK_WIDGET(cell->image));
    	gtk_container_add(GTK_CONTAINER(button), GTK_WIDGET(cell->image));
	
	
 	
	}
	/*for (int m = 0; m < 8; m++){
		for (int n = 0; n < 8; n++){
			if (boardstate[m][n] == 6){
				bkingalive = 1;
							}
			else if (boardstate[m][n] == -6){
				wkingalive = 1;
							}
						}
					}//m for loop

	if (bkingalive == 0){
		printf("Checkmate, White Player Wins!\n");
		datastate = 6;
		logprint(datastate, x, y);
		exit(0);
				}
	else if (wkingalive == 0){
		printf("Checkmate, Black player Wins!\n");
		datastate = 7;
		logprint(datastate, x, y);
		exit(0);
					}*/


	return coords;
}



if(gamemode == 1 && playerstart == 1){	//Player versus AI with White Start
	int x = cell->x;
	int y = cell->y;
	int *coords = malloc (sizeof(int) * 2);
	
	
	coords[1] = y;
	coords[0] = x;
//	printf("x: %d\n",coords[1]);
//	printf("y: %d\n",coords[0]);
//	printf("Piece clicked is: %d\n", boardstate[y][x]);
	
//	if (click == 1){
//		//CheckPossibleMove(coords[0],coords[1], boardstate[y][x]);
//		printf("CLICK: %d\n", click);
//	}
//	else if (click == 2){
//		printf("CLICK: %d\n", click);
//	}
	if(cell->state == 0 && click != 0) {
		  if(click == 1) {
			//printf("click 1");
			piececlicked = boardstate[y][x];
			CheckPossibleMove(x,y, piececlicked);			
			//player picked white  piece clicked black  turn 2
			if (piececlicked >= 1 && playerturn == 0 && playerstart == 1){
				gtk_container_remove(GTK_CONTAINER(button), GTK_WIDGET(cell->image));

				//printf("Piece saved in click 1 is: %d\n", piececlicked);
      				cell->image = (GtkImage*) gtk_image_new_from_file("empty.png");
      				cell->state = 0;
				parraytransfer(piececlicked);
				datastate = 1;
				logprint(datastate, y, x);
				boardstate[y][x] = 0;
      				click = 2;
			}
			//player picked white piece clicked white on turn 1

			else if (piececlicked <= -1 && playerturn == 1){
				gtk_container_remove(GTK_CONTAINER(button), GTK_WIDGET(cell->image));

				//printf("Piece saved in click 1 is: %d\n", piececlicked);
      				cell->image = (GtkImage*) gtk_image_new_from_file("empty.png");
      				cell->state = 0;
				parraytransfer(piececlicked);
				datastate = 1;
				logprint(datastate, y, x);
				boardstate[y][x] = 0;
      				click = 2;
			}
    		}

    	else if(click == 2){
		
		

		gtk_container_remove(GTK_CONTAINER(button), GTK_WIDGET(cell->image));

		//printf("click 2\n");
		datastate = 2;
		logprint(datastate, y, x);
		//printf("Piece saved after click 1 is: %d\n", piececlicked);
		
		int check = CheckMoveValid(coords[0],coords[1],click1x, click1y, piececlicked);
      		//printf("VALID = %d\n", check);
		
		//printf("BSTATE CHECK = %d\n", boardstate[y][x]);

		
  if (piececlicked == 1){
				if (check != 50){
                                boardstate[y][x] = 1; // makes sure the new location is updated
                                cell->image = (GtkImage*) gtk_image_new_from_file("bpond.png");
				}
                        }
                        else if (piececlicked == 2){
                                boardstate[y][x] = 2;
                                cell->image = (GtkImage*) gtk_image_new_from_file("bknight.png");
                        }
                        else if (piececlicked == 3){
                                boardstate[y][x] = 3;
                                cell->image = (GtkImage*) gtk_image_new_from_file("bbishop.png");
                        }
                        else if (piececlicked == 4){
                                boardstate[y][x] = 4;
                                cell->image = (GtkImage*) gtk_image_new_from_file("brook.png");
                        }
                        else if (piececlicked == 5){
                                boardstate[y][x] = 5;
                                cell->image = (GtkImage*) gtk_image_new_from_file("bqueen.png");
                        }
                        else if (piececlicked == 6){
                                boardstate[y][x] = 6;
                                cell->image = (GtkImage*) gtk_image_new_from_file("bking.png");
                        }
                        else if (piececlicked == -1){
				if (check != 50){
                                boardstate[y][x] = -1;
                                cell->image = (GtkImage*) gtk_image_new_from_file("wpond.png");
				}
                        }
                        else if (piececlicked == -2){
                                boardstate[y][x] = -2;
                                cell->image = (GtkImage*) gtk_image_new_from_file("wknight.png");
                        }
                        else if (piececlicked == -3){
                                boardstate[y][x] = -3;
                                cell->image = (GtkImage*) gtk_image_new_from_file("wbishop.png");
                        }
                        else if (piececlicked == -4){
                                boardstate[y][x] = -4;
                                cell->image = (GtkImage*) gtk_image_new_from_file("wrook.png");
                        }
                        else if (piececlicked == -5){
                                boardstate[y][x] = -5;
                                cell->image = (GtkImage*) gtk_image_new_from_file("wqueen.png");
                        }
                        else if (piececlicked == -6){
                                boardstate[y][x] = -6;
                                cell->image = (GtkImage*) gtk_image_new_from_file("wking.png");
                        }
		
      		cell->state = 0;
      		click = 1;
		if (playerturn == 1){
			playerturn = 0;
			blackAI();
			createChessboard(boardstate);
			playerturn = 1;
		}
		else{
			playerturn = 1;
			blackAI();
			createChessboard(boardstate);
			playerturn = 0;

		}
	
		if (check != 1 && check != 50){
			//BLACK TURN
				datastate = 5;
                                logprint(datastate, x,y);
                                datastate = 3;
                                logprint(datastate, x,y);
				printf("White Player Loses!\n");
				printf("ERROR CODE = 100\n");
				printf("Invalid Move: Game over!\n");
			exit(0);
		}
    	}
    	gtk_widget_show(GTK_WIDGET(cell->image));
    	gtk_container_add(GTK_CONTAINER(button), GTK_WIDGET(cell->image));
	
	
 	
	}
	
	return coords;
}





}

void createChessboard (int boardstate[][8]){
	
	Cell* cells[8][8];
   	GtkWindow* window;
    	GtkTable* table;
    	int x;
    	int y;
     	table = (GtkTable*) gtk_table_new(8, 8, TRUE);
    	for(x = 0; x < 8; x++){ 
        		for(y = 0; y < 8; y++){
            		GtkButton* button;
            		Cell* cell;
            		cell = g_malloc0(sizeof(Cell));
            		cell -> x = x;
            		cell -> y = y;
			cell -> state = 0;
			//printf("x: %d\n", x);
            		//printf("y: %d\n", y);
            		//printf("piece is: %d\n", boardstate[x][y]);
	   		if (boardstate[y][x] == 1){
				cell->image = (GtkImage*) gtk_image_new_from_file("bpond.png");
			}
			else if(boardstate[y][x] == 2){
				cell->image = (GtkImage*) gtk_image_new_from_file("bknight.png");
			}
			else if (boardstate[y][x] == 3){
				cell->image = (GtkImage*) gtk_image_new_from_file("bbishop.png");
			}
			else if (boardstate[y][x] == 4){
				cell->image = (GtkImage*) gtk_image_new_from_file("brook.png");
			}
			else if (boardstate[y][x] == 5){
				cell->image = (GtkImage*) gtk_image_new_from_file("bqueen.png");
			}
			else if (boardstate[y][x] == 6){
				cell->image = (GtkImage*) gtk_image_new_from_file("bking.png");
			}
			else if (boardstate[y][x] == -1){
				cell->image = (GtkImage*) gtk_image_new_from_file("wpond.png");
			}
			else if (boardstate[y][x] == -2){
				cell->image = (GtkImage*) gtk_image_new_from_file("wknight.png");
			}
			else if (boardstate[y][x] == -3){
				cell->image = (GtkImage*) gtk_image_new_from_file("wbishop.png");
			}
			else if (boardstate[y][x] == -4){
				cell->image = (GtkImage*) gtk_image_new_from_file("wrook.png");
			}
			else if (boardstate[y][x] == -5){
				cell->image = (GtkImage*) gtk_image_new_from_file("wqueen.png");
			}
			else if (boardstate[y][x] == -6){
				cell->image = (GtkImage*) gtk_image_new_from_file("wking.png");
			}
			else if (boardstate[y][x] == 0){
				cell->image = (GtkImage*) gtk_image_new_from_file("empty.png");
			}

            		gtk_widget_show(GTK_WIDGET(cell->image));
            		button = (GtkButton*) gtk_button_new();
            		gtk_container_add(GTK_CONTAINER(button), GTK_WIDGET(cell->image));
            		GdkColor color;
			if (x == 1 || x == 3 || x == 5 || x == 7){
				if (y == 0 || y == 2 || y == 4 || y == 6){ 
					gdk_color_parse("black", &color);
					gtk_widget_modify_bg(GTK_WIDGET(button), GTK_STATE_NORMAL, &color);
				}
				else
					gdk_color_parse("white", &color);
					gtk_widget_modify_bg(GTK_WIDGET(button), GTK_STATE_NORMAL, &color);

			}
			else {
				if (y == 0 || y == 2 || y == 4 || y == 6){ 
					gdk_color_parse("white", &color);
					gtk_widget_modify_bg(GTK_WIDGET(button), GTK_STATE_NORMAL, &color);
				}
				else
					gdk_color_parse("black", &color);
					gtk_widget_modify_bg(GTK_WIDGET(button), GTK_STATE_NORMAL, &color);


			}	
			gtk_widget_show(GTK_WIDGET(button));
            		g_object_set_data(G_OBJECT(button), "cell", cell);
            		cells[x][y] = cell;
            		gtk_table_attach(table, GTK_WIDGET(button), x, x+1, y, y+1, GTK_EXPAND|GTK_FILL, GTK_EXPAND|GTK_FILL, 0, 0);
			
			g_signal_connect_swapped(G_OBJECT(button), "clicked", G_CALLBACK(handle_button_click), cell);

			
			/*if (click == 1){
            			g_signal_connect_swapped(G_OBJECT(button), "clicked", G_CALLBACK(handle_button_click1), cell);
			}
			if (click == 2){
				g_signal_connect_swapped(G_OBJECT(button), "clicked", G_CALLBACK(handle_button_click2), cell);
			}*/
        	}
	}
    	gtk_widget_show(GTK_WIDGET(table));
    	window = (GtkWindow*) gtk_window_new(GTK_WINDOW_TOPLEVEL);
  	g_signal_connect(G_OBJECT(window), "delete-event", G_CALLBACK(gtk_main_quit), NULL);
   	gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(table));
	//gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER_ALWAYS);

	gtk_window_move (window,0, 200);
	gtk_window_set_resizable (window, FALSE);
    	gtk_widget_show(GTK_WIDGET(window));

}




void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds; 
  
    // Storing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not achieved 
    while (clock() < start_time + milli_seconds) 
        ; 
} 
//CALLBACK FUNCTIONS FOR GAMEMODE MENU

void gamemode_select( GtkWidget *item, gpointer data)
{
	if (data == "PvP"){
    		g_print ("Player has selected gamemode: Player vs Player.\n");
		gamemode = 0;
	}
	if (data == "PvAI"){
		g_print ("Player has selected gamemode: Player vs AI.\n");
		gamemode = 1;
	}
	if (data == "AIvAI"){
		g_print ("Player has selected gamemode: AI vs AI.\n");
		gamemode = 2;
	}

}

//CALLBACK FUNCTIONS FOR FEATURE 2 MENU

void feature2_select( GtkWidget *item, gpointer data)
{
	if (data == "Beginner"){
    		g_print ("Player has selected AI Level Beginner.\n");
	}
	if (data == "Intermediate"){
		g_print ("Player has selected AI Level Intermediate.\n");
	}
	if (data == "Expert"){
		g_print ("Player has selected AI Level Expert.\n");
	}

    
}

//DRAW DOWN MENU CREATION FUNCTION

static GtkWidget *make_menu_item ( gchar *name, GCallback  callback, gpointer data )
{
    	GtkWidget *item;
  
    	item = gtk_menu_item_new_with_label (name);
    	g_signal_connect (item, "activate",
	              callback, (gpointer) data);
    	gtk_widget_show (item);

    	return item;
}

//FUNCTION CALLBACK FOR PLAYER SIDE BUTTONS

void player1_side( GtkWidget *widget, gpointer data )
{
	int l = 0;
	if (data == "black"){
		for (int x=0 ; x < 8; x++)
		{
  			for (int y=0 ; y < 8; y++)
  			{
    				boardstate[x][y] = bboardstate[x][y];
				playerturn = 1;
				playerstart = 0;
  			}
		}
		g_print ("Player 1 has selected to play as black.\n");
		if (gamemode == 1){
			whiteAI();
			playerturn = 0;
			createChessboard(boardstate);
		}
		if (gamemode == 0){
    			createChessboard(boardstate);
		}
		if (gamemode == 2){
			while (l==0){
			whiteAI();
			sleep(3);
			blackAI();
			sleep(3);
			}

		}
	}
	if (data == "white"){
		for (int x=0 ; x < 8; x++)
		{
  			for (int y=0 ; y < 8; y++)
  			{
    				boardstate[x][y] = wboardstate[x][y];
				playerturn = 1;
				playerstart = 1;
  			}
		}
		g_print ("Player 1 has selected to play as white.\n");

		createChessboard(boardstate);

		if (gamemode == 2){
			while(l == 0){ 
			whiteAI();
			sleep(3);
			blackAI();
			sleep(3);
			}

			
		}

	}		
}

//MENU, BUTTONS, WINDOW CREATION

static void createSetup( void )
{
    	GtkWidget *window;
    	GtkWidget *box1, *box2, *box3;
    	GtkWidget *button;
    	GtkWidget *separator;
    	GtkWidget *opt, *menu, *item;
    	GtkWidget *label;

	//WINDOW CREATION	

    	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    	g_signal_connect (window, "destroy",
                      G_CALLBACK (gtk_main_quit),
                      NULL);
	gtk_widget_set_size_request (window, 300, 250);
    	gtk_window_set_title (GTK_WINDOW (window), "Chess Setup Menu");
	//gtk_container_set_border_width (GTK_CONTAINER (window),50);
	gtk_window_set_resizable (GTK_WINDOW(window), FALSE);	

    	box1 = gtk_vbox_new (FALSE, 0);
    	gtk_container_add (GTK_CONTAINER (window), box1);
    	gtk_widget_show (box1);

    	box2 = gtk_hbox_new (FALSE, 10);
    	gtk_container_set_border_width (GTK_CONTAINER (box2), 10);
    	gtk_box_pack_start (GTK_BOX (box1), box2, TRUE, TRUE, 0);
    	gtk_widget_show (box2);

    	box3 = gtk_vbox_new (FALSE, 10);
    	gtk_box_pack_start (GTK_BOX (box2), box3, TRUE, TRUE, 0);
    	gtk_widget_show (box3);

    	box2 = gtk_hbox_new (FALSE, 10);
   	gtk_container_set_border_width (GTK_CONTAINER (box2), 10);
   	gtk_box_pack_start (GTK_BOX (box1), box2, TRUE, TRUE, 0);
    	gtk_widget_show (box2);

    	box2 = gtk_hbox_new (FALSE, 10);
    	gtk_container_set_border_width (GTK_CONTAINER (box2), 10);

        
	//GAMEMODE DROP DOWN MENU CREATION

    	label = gtk_label_new ("Game Mode:");
    
    	gtk_box_pack_start (GTK_BOX (box2), label, FALSE, FALSE, 0);
    	gtk_widget_show (label);
  
    	opt = gtk_option_menu_new ();
    	menu = gtk_menu_new ();

    	item = make_menu_item ("Player vs Player", G_CALLBACK (gamemode_select), (gpointer) "PvP");
    
    	gtk_menu_shell_append (GTK_MENU_SHELL (menu), item);
  
    	item = make_menu_item ("Player vs AI", G_CALLBACK (gamemode_select), (gpointer) "PvAI");
    
    	gtk_menu_shell_append (GTK_MENU_SHELL (menu), item);
	item = make_menu_item ("AI vs AI - Text Based", G_CALLBACK (gamemode_select), (gpointer) "AIvAI");
    
    	gtk_menu_shell_append (GTK_MENU_SHELL (menu), item);

    
    	gtk_option_menu_set_menu (GTK_OPTION_MENU (opt), menu);
    	gtk_box_pack_start (GTK_BOX (box2), opt, TRUE, TRUE, 0);
    	gtk_widget_show (opt);

    	gtk_box_pack_start (GTK_BOX (box1), box2, TRUE, TRUE, 0);
    	gtk_widget_show (box2);

    	box2 = gtk_hbox_new (FALSE, 10);
    	gtk_container_set_border_width (GTK_CONTAINER (box2), 10);

	//FEATURE 2 DROP DOWN MENU CREATION

    	label = gtk_label_new ("AI Level:");
    	gtk_box_pack_start (GTK_BOX (box2), label, FALSE, FALSE, 0);
    	gtk_widget_show (label);
  
    	opt = gtk_option_menu_new ();
    	menu = gtk_menu_new ();
  
    	item = make_menu_item ("Beginner",
                           G_CALLBACK (feature2_select),
                           (gpointer) "Beginner");
    	gtk_menu_shell_append (GTK_MENU_SHELL (menu), item);
  
    	item = make_menu_item ("Intermediate",
                           G_CALLBACK (feature2_select),
                           (gpointer) "Intermediate");
    	gtk_menu_shell_append (GTK_MENU_SHELL (menu), item);
  
    	item = make_menu_item ("Expert",
                           G_CALLBACK (feature2_select),
                           (gpointer) "Expert");
    	gtk_menu_shell_append (GTK_MENU_SHELL (menu), item);
  
    	gtk_option_menu_set_menu (GTK_OPTION_MENU (opt), menu);
    	gtk_box_pack_start (GTK_BOX (box2), opt, TRUE, TRUE, 0);
    	gtk_widget_show (opt);
  
    	gtk_box_pack_start (GTK_BOX (box1), box2, TRUE, TRUE, 0);
    	gtk_widget_show (box2);

    	box2 = gtk_hbox_new (FALSE, 10);
    	gtk_container_set_border_width (GTK_CONTAINER (box2), 10);
  
    	gtk_box_pack_start (GTK_BOX (box1), box2, TRUE, TRUE, 0);
    	gtk_widget_show (box2);
  
    	box2 = gtk_hbox_new (FALSE, 10);
    	gtk_container_set_border_width (GTK_CONTAINER (box2), 10);
  
    	gtk_box_pack_start (GTK_BOX (box1), box2, TRUE, TRUE, 0);
    	gtk_widget_show (box2);

	//PLAYER BUTTONS (BLACK AND WHITE)
	
	label = gtk_label_new ("Player 1:");
    	gtk_box_pack_start (GTK_BOX (box2), label, TRUE, TRUE, 10);
    	gtk_widget_show (label);


	button = gtk_button_new_with_label ("Black");
    	g_signal_connect (button, "clicked", G_CALLBACK (player1_side), (gpointer) "black");
    	
	gtk_box_pack_start (GTK_BOX (box2), button, TRUE, TRUE, 0);
   	gtk_widget_set_can_default (button, TRUE);
    	gtk_widget_grab_default (button);
    	gtk_widget_show (button);

	button = gtk_button_new_with_label ("White");
    	g_signal_connect (button, "clicked", G_CALLBACK (player1_side), (gpointer) "white");
    	
	gtk_box_pack_start (GTK_BOX (box2), button, TRUE, TRUE, 0);
    	gtk_widget_set_can_default (button, TRUE);
    	gtk_widget_grab_default (button);
    	gtk_widget_show (button);

    	separator = gtk_hseparator_new ();
    	gtk_box_pack_start (GTK_BOX (box1), separator, FALSE, TRUE, 0);
    	gtk_widget_show (separator);

    	box2 = gtk_vbox_new (FALSE, 10);
    	gtk_container_set_border_width (GTK_CONTAINER (box2), 10);
    	gtk_box_pack_start (GTK_BOX (box1), box2, FALSE, TRUE, 0);
    	gtk_widget_show (box2);

    	button = gtk_button_new_with_label ("Quit");
    	g_signal_connect_swapped (button, "clicked",
                              G_CALLBACK (gtk_main_quit),
                              NULL);
    	gtk_box_pack_start (GTK_BOX (box2), button, TRUE, TRUE, 0);
    	gtk_widget_set_can_default (button, TRUE);
    	gtk_widget_grab_default (button);
    	gtk_widget_show (button);

    	gtk_widget_show (window);
}

int main( int   argc, char *argv[] )
{
    	gtk_init (&argc, &argv);

    	createSetup ();
    	gtk_main ();

    	return 0;
}
