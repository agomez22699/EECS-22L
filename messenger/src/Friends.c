/*This file includes the functions to do with friends: add, block, show friends list*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addFriend(char* current_username, char* friend_username)
{
	FILE *fp;

	char c_user[99], f_user[99];
	strcpy(c_user, current_username);
	strcpy(f_user, friend_username);

	/*creates .txt file name*/
	char username_txt[99];
	char friend[99];
	int same = 0;
	strcpy(username_txt, c_user);
	strcat(username_txt, ".txt");
	fp = fopen(username_txt, "r");

	/*scans for if the friend has been added already*/
	rewind(fp);
	while(fscanf(fp,"\n%s",friend) != EOF)
	{
                if(strcmp(friend, f_user) == 0)
		{
			printf("Friend already added.\n");
			same++;
		}
	}	

	/*if friend is not on the list already*/
	if(same == 0)
	{
		/*appending friend to list*/
		strcpy(username_txt, c_user);
		strcat(username_txt, ".txt");
		fp = fopen(username_txt, "a");
		fprintf(fp,"%s\n",f_user);
	
		fclose(fp);
		
		/*appending user to friend's list*/
		char f_user_txt[99];
		strcpy(f_user_txt, f_user);
		strcat(f_user_txt, ".txt");
		fp = fopen(f_user_txt, "a");
		fprintf(fp, "%s\n", c_user);

		fclose(fp);

		/*creating a chat history between the two users*/
		char friend_txt[200];
		strcpy(friend_txt, c_user);
		strcat(friend_txt, "2");
		strcat(friend_txt, f_user);
		strcat(friend_txt, ".txt");
		fp = fopen(friend_txt, "w");
		fprintf(fp,"User: %s Friend: %s", c_user, f_user);
	}
	
	fclose(fp);
	printf("%s has been added as your friend\n", f_user);
}

int friendsList(char* username)
{
	FILE *fp;
		
	char user[99];
	strcpy(user, username);
	
	/*creating .txt file name*/
	char username_txt[99];
        strcpy(username_txt, user);
        strcat(username_txt, ".txt");
        fp = fopen(username_txt, "r");
	
	int count = -3; /*disregarding the first name, last name, and password*/
	char friendslist[50][99];
	char friend[99];

	/*scanning for friends*/
	rewind(fp);
	while(fscanf(fp, "\n%s", friend) != EOF)
	{
		strcpy(friendslist[count], friend);
		count++;
	}

	fclose(fp);
	return count;
}

void blockFriend(char* username, char* block_user)
{
	char user[99], b_user[99];
	strcpy(user, username);
	strcpy(b_user, block_user);

	/*creating .txt file name of chat history*/
	char friend_txt[200];
	strcpy(friend_txt, user);
	strcat(friend_txt, "2");
	strcat(friend_txt, b_user);
	strcat(friend_txt, ".txt");

	/*deleting chat history .txt file*/
	if(remove(friend_txt) == 0)
		printf("Removed chat history with %s\n", b_user);
	
	FILE *fp;

	/*creating .txt file name*/
	char username_txt[99];
	strcpy(username_txt, user);
	strcat(username_txt, ".txt");
	fp = fopen(username_txt, "r");
	
	char holder[50][300] = {}, holder2[300] = "";
	int count = 0;

	/*copying contents of .txt file to a placeholder*/
	while(fscanf(fp, "\n%s", holder2) != EOF)
	{
		strcpy(holder[count], holder2);
		count++;
	}
	
	/*finding the user to block and emptying the string*/
	for(int i = 0; i < 50; i++)
	{
		if(strcmp(holder[i], b_user) == 0)
		{
			strcpy(holder[i], "");
		}
	}

	/*rewriting the file without the blocked user*/	
	fp = fopen(username_txt, "w");
	for(int i = 0; i < 50; i++)
	{
		if(strcmp(holder[i], "") != 0)
		{
			fprintf(fp, "%s\n", holder[i]);
		}
	}
	
	fclose(fp);

	/*creating .txt file name*/
	char b_username_txt[99];
	strcpy(b_username_txt, b_user);
	strcat(b_username_txt, ".txt");
	fp = fopen(b_username_txt, "r");
	
	char holder3[50][300] = {}, holder4[300] = "";
	count = 0;
	
	/*copying contents of .txt file to a placeholder*/
	while(fscanf(fp, "\n%s", holder4) != EOF)
	{
		strcpy(holder3[count], holder4);
		count++;
	}

	/*finding the user to block and emptying the string*/
	for(int i = 0; i < 50; i++)
	{
		if(strcmp(holder3[i], user) == 0)
		{
			strcpy(holder3[i], "");
		}
	}

	/*rewriting the file without the blocked user*/
	fp = fopen(b_username_txt, "w");
	for(int i = 0; i < 50; i++)
	{
		if(strcmp(holder3[i], "") != 0)
		{
			fprintf(fp, "%s\n", holder3[i]);
		}
	}
	
	fclose(fp);

	printf("%s has been blocked\n", b_user);	
}

