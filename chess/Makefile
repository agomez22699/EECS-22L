//CC     = gcc
//DEBUG  = -g -DDEBUG
//CFLAGS = -ansi  -c -std=c99
//GTK = `pkg-config --cflags --libs gtk+-2.0`


.PHONY: all
all:  chess  

.PHONY: chess
chess: 
	gcc ./src/Main.c ./src/Rules.c ./src/AI.c ./src/SpecialMoves.c -o ./bin/chess -std=c99 -lm `pkg-config --cflags --libs gtk+-2.0` 



.PHONY: test
test: chess 
	cd bin && ./chess

.PHONY: clean	
clean:
	cd bin && rm -f chess
	cd bin && rm -f Log.txt
	cd src && rm -f *.o


.PHONY: tar
tar: 
	tar -cvf Chess_V1.0_src.tar.gz *
