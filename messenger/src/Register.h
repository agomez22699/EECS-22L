/*This is the header file for Register.c*/
#ifndef REGISTER_H
#define REGISTER_H

/*registers user using first name, last name, username, and password*/
int register_user(char* first_name, char* last_name, char* username, char* password);

/*checks to see if the username and password matches with an existing account*/
int* user_pass_verification(char* username, char* password);

#endif
