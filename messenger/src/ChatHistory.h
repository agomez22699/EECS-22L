/*This is the header file for ChatHistory.c*/
#ifndef CHATHISTORY_H
#define CHATHISTORY_H

/*writes the message to the .txt file to keep track*/
void write_chat_history(char* sender, char* receiver, char* message);

/*reads up to 25 of the most recent messages and returns them*/
char** read_chat_history(char* user1, char* user2);

#endif
