#---------------------------------------- Authors -----------------------------------------------------------#
#Team07
#------------------------------------------------------------------------------------------------------------#

#Anson Do 
#Arian Reyes
#Xianzhang Li
#Adrian Gomez
#Kevin Huang

#-------------------------------------- Version -------------------------------------------------------------#

#Release Version: 1.0

#--------------------------------- Known Bugs in 1.0 --------------------------------------------------------#

#Whenver a special move is made in PVP, a new chessboard window is made in the same place. (so the new board contains all the updated positions)
#When in PvAI, a new chessboard is made whenever the AI makes a move. 
#En Passant is currently not working
#No check for check and checkmate in AI
#Checkmate Checker --> Only checks if the king can move out the check. 

#--------------------------------------- Date ---------------------------------------------------------------#

#05/10/2020

#-------------------------------- General Instrunctions -----------------------------------------------------#

#Files Included with Install of Program
#KEEP THE WINDOW IN THE SAME POSITION IT WAS MADE IN FOR FULL IMMERSION 
#When a pawn is promoted, it automatically selects the Queen piece

#------------------------------------------------------------------------------------------------------------#

#COPYRIGHT -----> Author and Copyright
#INSTALL -------> Installation Instructions
#Bin -----------> Binary Directory, -chess (Execuatable File), -pngs for pieces on Chess Board, -Log.txt
#Doc -----------> Documentation Directory, -Chess UserManual -Dev User Manual
#Src -----------> AI.c, Globals.h, Main.c, Rules.c, SpecialMoves.c 

#--------------------------------- General Purpose ---------------------------------------------------------#

#The goal of this program is to learn chess. The goal of chess is to capture the other
# player's king. This capture is never actually completed, but once a king is under 
#attack and unable to avoid capture, it is said to be checkmated and the game is over. 
#The program will allow it’s user to play chess on a virtual chessboard either against 
#a computer or against another user locally.


#--------------------------------- Features Implemented ---------------------------------------------------#

#1. Player vs. Player
#2. Chosing Player Color
#3. Readable Log file with Algebraic Coordinate System.
#4. Player Turns have been implemented in Player vs. Player
#5. Player vs. AI
#6. Illegal move checker
#7. Castling and Pond Promotion
#8. Check and Checkmate (see Bugs)