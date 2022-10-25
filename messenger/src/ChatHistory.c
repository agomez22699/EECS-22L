/*This file includes reading from and writing to the chat history between 2 users*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void write_chat_history(char* sender, char* receiver, char* message)
{
	FILE *fp;

	char s[99], r[99];
	strcpy(s, sender);
	strcpy(r, receiver);
	
	/*creating .txt file name*/
	char chat_txt[200];
	strcpy(chat_txt, s);
	strcat(chat_txt, " to ");
	strcat(chat_txt, r);
	strcat(chat_txt, "log.txt");
	fp = fopen(chat_txt, "r");
	
	/*or the reverse file name*/
	if(fp == NULL)
	{
		strcpy(chat_txt, r);
		strcat(chat_txt, " to ");
		strcat(chat_txt, s);
		strcat(chat_txt, "log.txt");
	}
	
	/*creating the message format and putting it in the .txt*/
	char the_message[300], format[99];
	strcpy(format, "\n");
	strcat(format, s);
	strcat(format, ": ");
	strcpy(the_message, format);
	strcat(the_message, message);
	fp = fopen(chat_txt, "a");
	fprintf(fp, the_message);

	fclose(fp);
}

char** read_chat_history(char* user1, char* user2)
{
	char** asdf;
	return asdf;
}

