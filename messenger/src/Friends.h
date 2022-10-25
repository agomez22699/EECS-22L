/*This is the header file for Friends.c*/
#ifndef FRIENDS_H
#define FRIENDS_H

/*add friends to the .txt files, and creates a .txt to store chat history*/
void addFriend(char* current_username, char* friend_username);

/*currently, shows how many friends you have*/
int friendsList(char* user);

/*removes another user from friends list of both users and deletes the chat history between the two*/
void blockFriend(char* username, char* block_user);

#endif

