//CC     = gcc
//DEBUG  = -g -DDEBUG
//CFLAGS = -ansi  -c -std=c99
//GTK = `pkg-config --cflags --libs gtk+-2.0`


.PHONY: all
all: chat server    

.PHONY: chess
chess: 
	gcc ./src/Main.c ./src/Rules.c ./src/AI.c ./src/SpecialMoves.c -o ./bin/chess -std=c99 -lm `pkg-config --cflags --libs gtk+-2.0`


.PHONY: chat
chat: 	chess
	gcc ./src/Chat.c -o ./bin/chat ./src/Register.c ./src/Encrypt.c ./src/Friends.c -lnsl -lpthread -std=c99 -lm -w `pkg-config --cflags --libs gtk+-2.0` 

.PHONY: server
server: 
	gcc ./src/server.c ./src/ChatHistory.c -o ./bin/server -lnsl -lpthread -std=c99	

.PHONY: servertest
servertest: server
	cd bin && ./server

.PHONY: test
test: chat 
	cd bin && ./chat

.PHONY: clean	
clean:
	cd bin && rm -f chat
	cd bin && rm -f server
	cd bin && rm -f *.o

.PHONY: client
client:
	gcc ./src/client.c -o ./bin/client -lnsl -lpthread -std=c99
	cd bin && ./client

.PHONY: tar
tar: 
	tar -cvf Chat_Beta_src.tar.gz *
