/*This file includes registering for a user and user/pass verfication for log in*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Encrypt.h"
#include "Friends.h"

int register_user(char* first_name, char* last_name, char* username, char* password)
{
	FILE *fp;

	char first[99], last[99], user[99];
	strcpy(first, first_name);
	strcpy(last, last_name);
	strcpy(user, username);

	/*creates the .txt file name*/	
	char username_txt[99];
	strcpy(username_txt,user);
	strcat(username_txt, ".txt");
	fp = fopen(username_txt, "r");	
	
	if(fp != NULL)
	{
		return 0;
	}
	
	/*adds first name, last name, and encrypted password to file*/
	fp = fopen(username_txt, "w");
	fprintf(fp,"%s\n",first);
	fprintf(fp,"%s\n",last);
	char en_pass[2000];
	strcpy(en_pass, encrypt(password));
	fprintf(fp,"%s\n",en_pass);

	fclose(fp);
	
	return 1;
}

int* user_pass_verification(char* username, char* password)
{
	FILE *fp;

	char user[99];
	strcpy(user, username);

	/*creates .txt file name*/
	char username_txt[99];
	strcpy(username_txt,user);
	strcat(username_txt, ".txt");
	fp = fopen(username_txt, "r");

	if(fp == NULL)
	{
		return 0;
	}

	/*reads for first name, last name, and encrypted password*/
	char first[99], last[99], pass2[2000];
	rewind(fp);
	fscanf(fp,"%s %s %s", first, last, pass2);
	char en_pass[2000];
	/*compares password from file with entered password*/
	strcpy(en_pass, encrypt(password));
	if(strcmp(en_pass,pass2) != 0)
	{
		return 0;
	}

	fclose(fp);
	
	/*returning the full name of user*/	
	strcat(first, " ");
	strcat(first, last);	
	char* fullname = malloc(sizeof(first)+1);
	for(int i=0;i<sizeof(first);i++)
	{
		fullname[i] = first[i];
	}
	fullname[sizeof(first)+1] = '\0';

	return 1;
}

/*Testing*/
// int main()
// {
// 	char* first="hello";
// 	char* last="world";
// 	char* username="registertest";
// 	char* password="helloworld";
// 	char* friend="good_friend";
	
// 	/*register_user*/
// 	int ru = register_user(first,last,username,password);
	
// 	if(ru == 0)
// 		printf("username already taken!\n");
// 	else
// 	{
// 		char* name;
// 		/*user_pass_verification*/
// 		name = user_pass_verification(username, password);
// 		printf("Here is your name: %s\n", name);
// 	}
// 	/*addFriend*/
// 	addFriend(username, friend);
// 	/*friendsList*/
// 	int numfriends = friendsList(username);
// 	printf("Number of friends: %d\n", numfriends);
// 	/*blockFriend*/
// 	blockFriend(username, friend);

// 	return 0;
// }

