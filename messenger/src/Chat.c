//This is for the Message Area of the GUI
#include <gtk/gtk.h>
#include <gdk/gdkx.h>
#include <stdio.h>
#include <gdk/gdktestutils.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#define NAME_LEN 15
#include "Register.h"

int usernumber;
void fileLogin(char* username, char* password);
void fileUser(char* firstName,char* lastName,char* username, char* password);
char createLogin(int argc, char **argv);
int login_button (GtkButton *LoginButton, GObject *context_object);
int createAccount_button(GtkButton *createButton, GObject *context_object);
int signUp_Button(GtkButton *SignupButton, GObject *context_object);
char chatInterface(int argc, char **argv,char *username);
void close_window(GtkWidget *button,gpointer window);
char createNewUser(int argc, char **argv);
void destroy( GtkWidget *widget, gpointer data);
//int SendMessageButtonFunction (GtkButton *SendMessageButton, GObject *context_object);
const gchar *send_button(GtkButton *SendMessageButton, GObject *context_object);
int chess_button(GtkButton *ChessButton, GObject *context_object);
int first_contact(GtkButton *ContactOneButton, GObject *context_object);
int second_contact(GtkButton *ContactOneButton, GObject *context_object);
int third_contact(GtkButton *ContactOneButton, GObject *context_object);

//Widgets for Message Screen
GtkWidget	*window;
GtkWidget	*MessageImage;
GtkWidget	*AddFriendImage;
GtkWidget	*SendMessageImage;
GtkWidget *AddFriendButton;
GtkWidget	*SendMessageButton;
GtkWidget	*layout;
GtkWidget	*ContactsImage;
GtkWidget	*ContactsButton;
GtkWidget	*ContactOneImage;
GtkWidget	*ContactOneButton;
GtkWidget	*ContactTwoImage;
GtkWidget	*ContactTwoButton;
GtkWidget	*ContactThirdImage;
GtkWidget	*ContactThirdButton;
GtkWidget	*DeleteImage;
GtkWidget	*DeleteButton;
GtkWidget	*BlockImage;
GtkWidget	*BlockButton;
GtkWidget *message;
GtkWidget *textArea;
GtkWidget	*ChessImage;
GtkWidget	*ChessButton;
GObject *context_object;
GdkColor colorWhite;

GtkWidget	*ChatName;


//Widgets for Login Screen
GtkWidget	*window2;
GtkWidget	*user_entry;
GtkWidget	*password_entry;
GtkWidget	*LoginGUI;
GtkWidget	*LoginButton;
GtkWidget	*LoginBImage;
GtkWidget	*SignupButton;
GtkWidget	*SignupBImage;

//Widgets for create user screen 
GtkWidget	*window3;
GtkWidget	*fname_entry;
GtkWidget	*lname_entry;
GtkWidget	*new_user_entry;
GtkWidget	*new_pass_entry;
GtkWidget	*createButton;
GtkWidget	*createButtonImage;
GtkWidget	*CreateAccountImage;

//Widgets for callbacks
//dialog box
GtkWidget *dialog1;
GtkWidget *label1;
GtkWidget *dialog2;
GtkWidget *label2;
GtkTextBuffer *buffer;
GtkTextIter start, end;
GtkTextIter start2, end2;

int clientID;
int click_user;

void newid(char username[NAME_LEN])
{
	char usernames[NAME_LEN];
	char usernamesfile[99];
	strcpy(usernames,username);
	strcpy(usernamesfile,usernames);
	strcat(usernamesfile,"s.txt");
	
	FILE *fp = fopen(usernamesfile,"w"); 
	//fprintf(fp,"%s ",usernames);
	fprintf(fp,"%d",clientID);

	fclose(fp);
}

void search_id(char* username)
{	
	char usernamesfile[99];
	char usernames[NAME_LEN];
	int numbers = 0;
	strcpy(usernamesfile,username);
	strcat(usernamesfile,"s.txt");
	FILE *fp = fopen(usernamesfile,"r"); 
	//rewind(fp);
	fscanf(fp,"%d",&numbers);
	//printf("the usernames is: %s \n", usernames);
	printf("the number is: %d \n", numbers);
	// if(strcmp(usernames,username)==0){
	// 	click_user = (int)numbers;
	// 	printf("the click_user is: %d \n", click_user);
	// }

	click_user = numbers;
 	printf("the click_user is: %d \n", click_user);
	
}



int chess_button(GtkButton *ChessButton, GObject *context_object){
	g_print("Selected the Chess button\n");
	system("./chess");
	return 1;
}


int first_contact(GtkButton *ContactOneButton, GObject *context_object){
	g_print("Selected first contact\n");
	gtk_widget_destroy(ChatName);
	ChatName = gtk_label_new ("Bob S.");
	gtk_layout_put(GTK_LAYOUT(layout), ChatName, 330, 60);
	gtk_widget_show_all(window);
	search_id("bobs");
	return 1;
}

int second_contact(GtkButton *ContactTwoButton, GObject *context_object){
	g_print("Selected second contact\n");
	gtk_widget_destroy(ChatName);
	ChatName = gtk_label_new ("Sally V.");
	gtk_layout_put(GTK_LAYOUT(layout), ChatName, 330, 60);
	gtk_widget_show_all(window);

	search_id("sallyv");
	return 1;
}

int third_contact(GtkButton *ContactThirdButton, GObject *context_object){
	g_print("Selected third contact\n");
	gtk_widget_destroy(ChatName);
	ChatName = gtk_label_new ("Nick S.");
	gtk_layout_put(GTK_LAYOUT(layout), ChatName, 330, 60);
	gtk_widget_show_all(window);

	search_id("nicks");
	return 1;
}


const gchar *send_button(GtkButton *SendMessageButton, GObject *context_object){
  void * sockID;
  int clientSocket = *((int *) sockID);
	//char *recptemp = recipientpointer;
  
  g_print("You clicked send button \n");
// 	char data[1024];
//	int read = recv(clientSocket,data,1024,0);
//	data[read] = '\0';  
//  g_print("data \n");
  //get data from chat box
  GtkWidget *entryMessage = g_object_get_data(context_object,"messageEntered");
  //get data from chat box and display on chat
  GtkWidget *chatView = g_object_get_data(context_object,"textDisplay");
  gtk_text_view_set_editable(GTK_TEXT_VIEW(chatView),TRUE);
  
	GtkTextIter start,end;
 //buffer control messages being transfeerred
  //buffer for message entered in box
	GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(entryMessage));	
 //buffer for message being displayed
	GtkTextBuffer *buffer2 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(chatView));
  //handles the message being inserted
  gtk_text_buffer_get_start_iter(buffer,&start);
	gtk_text_buffer_get_end_iter(buffer,&end);
	gtk_text_iter_forward_chars(&start,50);
	gtk_text_buffer_delete(buffer,&start,&end);

  //handles the message being displayed
	gchar *text;
	gchar *text_temp = "\nME:";
	gtk_text_buffer_get_bounds(buffer,&start,&end);
	text = gtk_text_buffer_get_text(buffer,&start,&end,FALSE);
 
  g_print("MESSAGE SENT: %s\n",text);
	gtk_text_buffer_delete(buffer,&start,&end);
	GtkTextIter start2, end2;
	gtk_text_buffer_get_start_iter(buffer2,&start2);
	gtk_text_buffer_get_end_iter(buffer2,&end2);
	gtk_text_buffer_insert(buffer2,&end2,text,-1);
  gtk_text_buffer_insert(buffer2,&end2,"\n",-1);
 	int read = recv(clientSocket,text,1024,0);
  //printf("datarecieve: %s\n",text); 
	gtk_text_view_set_editable(GTK_TEXT_VIEW(chatView),FALSE);


  	send(usernumber,"SEND",1024,0);
	if (click_user == 1){
		send(usernumber,"1",1024,0);
	}
	if (click_user == 2){
		send(usernumber,"2",1024,0);
	}
	if (click_user == 3){
		send(usernumber,"3",1024,0);
	}
	if (click_user == 4){
		send(usernumber,"4",1024,0);
	}
	if (click_user == 5){
		send(usernumber,"5",1024,0);
	}
	if (click_user == 6){
		send(usernumber,"6",1024,0);
	}

	if (click_user == 7){
		send(usernumber,"7",1024,0);
	}

	if (click_user == 8){
		send(usernumber,"8",1024,0);
	}
	if (click_user == 9){
		send(usernumber,"9",1024,0);
	}
	//send(usernumber,"3",1024,0);
	send(usernumber,text,1024,0); //changed from message to text

	return text;
}
  

void * doRecieving(void * sockID){

	int clientSocket = *((int *) sockID);

	while(1){
    int digit;
		char data[1024];
		int read = recv(clientSocket,data,1024,0);
		data[read] = '\0';
		printf("INCOMING MESSAGE: %s\n",data);
		char ch;
        
    		if(strchr(data,'Ksxiuasdbwioabdiasbdi') != NULL){
    			
    		for(int i=0;i<strlen(data);i++)
    		{
			ch = data[i];
			if(ch>='0' && ch<='9') //to confirm it's a digit
			{
			digit = ch - '0';
			clientID = digit;
			printf("ID : %d\n",clientID);
			}		
		}
		}
	}
}

//Buttons for Login Screen 
int login_button (GtkButton *LoginButton, GObject *context_object){
    g_print("You clicked login button \n");
    
    //Get username inserted in login screen
    GtkEntry *user_entry = g_object_get_data(context_object,"usernameLogin");
    const  gchar *user_text = gtk_entry_get_text(user_entry);
    //print to verify name
    g_print("Username: %s \n",user_text);
    
    GtkEntry *password_entry = g_object_get_data(context_object,"passwordLogin");
    const  gchar *password_text = gtk_entry_get_text(password_entry);
    g_print("Password: %s \n",password_text);	

    char* username = (char*)gtk_entry_get_text(GTK_ENTRY(user_entry));
    char* password = (char*)gtk_entry_get_text(GTK_ENTRY(password_entry));
    
    int check_both = user_pass_verification(username,password);


	if(check_both ==1)
	{
		newid(username);
		gtk_widget_destroy(GTK_WIDGET(window2));
		chatInterface(0,0,username);
	}else{
		printf("Error code: 100 and 101 = WRONG LOGIN INFORMATION.\n");
		return 0;
	}

    fileLogin(username,password);

	//Sam change in here

	/* remove this when the connection done
	int n = write(sockfd,username,strlen(username));
	if( n < 0)
	{
		printf("username empty \n");
	}
	n = 0;
	n = write(sockfd,password,strlen(password))
	if(n < 0)
	{
		printf("password empty\n");
	}
	remove this when the connection done*/
	// end here

    return 1;
}


void fileLogin(char* username, char* password){
//login information is stored here
//information: username,password
//add onto list
  FILE *loginPtr;
  loginPtr = fopen("Login.txt", "w");
  fprintf(loginPtr,"Username: %s\n", username);
  fprintf(loginPtr,"Password: %s\n", password);
  fclose(loginPtr);

}

int signUp_Button(GtkButton *SignupButton, GObject *context_object){
  g_print("Selected the sign up button\n");
  gtk_widget_destroy(GTK_WIDGET(window2));
  createNewUser(0,0);
  return 1;
}

int createAccount_button(GtkButton *createButton, GObject *context_object){

  g_print("Selected create button\n");  
  
  //retrieves and prints the user's first name
  GtkEntry *fname_entry = g_object_get_data(context_object,"fistNameCreateAccount");
  const  gchar *firstName_text = gtk_entry_get_text(fname_entry);
  g_print("First Name: %s \n", firstName_text);
    
  //retrieves and prints the user's last name
  GtkEntry *lname_entry = g_object_get_data(context_object,"lastNameCreateAccount");
  const  gchar *lastName_text = gtk_entry_get_text(lname_entry);
  g_print("Last Name: %s \n", lastName_text);
    
  //retrieves and prints the user's username
  GtkEntry *new_user_entry = g_object_get_data(context_object,"usernameCreateAccount");
  const  gchar *userLogin_text = gtk_entry_get_text(new_user_entry);
  g_print("Username: %s \n",userLogin_text);
    
  //retrieves and prints the user's password
  GtkEntry *new_pass_entry = g_object_get_data(context_object,"passwordCreateAccount");
  const  gchar *passwordLogin_text = gtk_entry_get_text(new_pass_entry);
  g_print("Password: %s \n", passwordLogin_text);


  char* firstName = (char*)gtk_entry_get_text(GTK_ENTRY(fname_entry));
  char* lastName = (char*)gtk_entry_get_text(GTK_ENTRY(lname_entry));
  char* username = (char*)gtk_entry_get_text(GTK_ENTRY(new_user_entry));
  char* password = (char*)gtk_entry_get_text(GTK_ENTRY(new_pass_entry));

  //register_user(firstName, lastName, username, password);

  if(register_user(firstName, lastName, username, password) == 0)
  {
	  g_print("The user already in \n");
	  return 0;
  }else{
	  g_print("Congrats you created an account\n");
  	  chatInterface(0,0,username);
	  gtk_widget_destroy(GTK_WIDGET(window3));
      return 1; 
  }
  
  //fileLogin(username,password);
  //createFile(username);
  //fileUser(firstName,lastName,username, password);//add name stuff
  
  //verification 
  return 1;
}

void close_window(GtkWidget *button,gpointer window){

   /* remove this when the connection done
   close(sockfd); // disconnt the with the server

*/

   gtk_widget_destroy(GTK_WIDGET(window));
   gtk_main_quit();
}

void destroy( GtkWidget *widget, gpointer data)
{
   /* remove this when the connection done
   close(sockfd); // disconnt the with the server

*/
   gtk_main_quit ();
}

char createNewUser(int argc, char **argv){
  gtk_init(&argc, &argv);
	//Creating New Window
	window3 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size(GTK_WINDOW(window3), 720, 580);
  //gtk_window_set_resizable(GTK_WINDOW(window3),FALSE);
	gtk_widget_show(GTK_WIDGET(window3));

	//Layout
	layout = gtk_layout_new(NULL, NULL);
	gtk_container_add(GTK_CONTAINER (window3), layout);
	gtk_widget_show(layout);
	
	//Loading Images
	CreateAccountImage = gtk_image_new_from_file ("createAccount.jpg");
	gtk_layout_put(GTK_LAYOUT(layout), CreateAccountImage, 0,0);
	gtk_widget_show(GTK_WIDGET(CreateAccountImage));

	//TextBoxes
	fname_entry = gtk_entry_new();
	gtk_entry_set_width_chars((GtkEntry *) fname_entry, 30);
	gtk_layout_put(GTK_LAYOUT(layout), fname_entry, 389, 120);
	gtk_widget_set_size_request(fname_entry, 250, 50);
  gtk_entry_set_max_length (GTK_ENTRY(fname_entry),NAME_LEN);

	lname_entry = gtk_entry_new();
	gtk_entry_set_width_chars((GtkEntry *) lname_entry, 30);
	gtk_layout_put(GTK_LAYOUT(layout), lname_entry, 389, 180);
	gtk_widget_set_size_request(lname_entry, 250, 50);
  gtk_entry_set_max_length (GTK_ENTRY(lname_entry),NAME_LEN);

	new_user_entry = gtk_entry_new();
	gtk_entry_set_width_chars((GtkEntry *) new_user_entry, 30);
	gtk_layout_put(GTK_LAYOUT(layout), new_user_entry, 389, 240);
	gtk_widget_set_size_request(new_user_entry, 250, 50);
  gtk_entry_set_max_length (GTK_ENTRY(new_user_entry),NAME_LEN);

	new_pass_entry = gtk_entry_new();
	gtk_entry_set_width_chars((GtkEntry *) new_pass_entry, 30);
	gtk_layout_put(GTK_LAYOUT(layout), new_pass_entry, 389, 300);
	gtk_widget_set_size_request(new_pass_entry, 250, 50);
  gtk_entry_set_max_length (GTK_ENTRY(new_pass_entry),NAME_LEN);
 

	//Buttons
	createButtonImage = gtk_image_new_from_file("create.jpg");
	createButton = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(createButton), createButtonImage);
	gtk_layout_put(GTK_LAYOUT(layout), createButton, 290, 500);
	gtk_widget_set_size_request(createButton, 135, 38);

  /*Handling object and set Sign-up button*/
  g_object_set_data(G_OBJECT(createButton),"fistNameCreateAccount",fname_entry);
  g_object_set_data(G_OBJECT(createButton),"lastNameCreateAccount",lname_entry);
  g_object_set_data(G_OBJECT(createButton),"usernameCreateAccount",new_user_entry);
  g_object_set_data(G_OBJECT(createButton),"passwordCreateAccount",new_pass_entry);
  g_signal_connect(GTK_BUTTON(createButton),"clicked",G_CALLBACK(createAccount_button),createButton);
  
  g_signal_connect (window3, "clicked", G_CALLBACK (createAccount_button), createButton);
  /*Makinga login button close*/
  g_object_set_data(G_OBJECT(createButton),"window",window3);   
	gtk_widget_show_all(window3);
 
  gtk_main();
  return 0;

}

char createLogin(int argc, char **argv){
	

  gtk_init(&argc, &argv);
	//Creating New Window
	window2 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	g_signal_connect (window2, "destroy", G_CALLBACK (gtk_main_quit), NULL);
	gtk_window_set_default_size(GTK_WINDOW(window2), 720, 580);
  //gtk_window_set_resizable(GTK_WINDOW(window2),FALSE);
	gtk_widget_show(GTK_WIDGET(window2));
 

	//Layout
	layout = gtk_layout_new(NULL, NULL);
	gtk_container_add(GTK_CONTAINER (window2), layout);
	gtk_widget_show(layout);

	//Loading Images
	LoginGUI = gtk_image_new_from_file ("login.jpg");
	gtk_layout_put(GTK_LAYOUT(layout), LoginGUI, 0,0);
	gtk_widget_show(GTK_WIDGET(LoginGUI));

	//Buttons
	LoginBImage = gtk_image_new_from_file("loginButton.jpg");
	LoginButton = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(LoginButton), LoginBImage);
	gtk_layout_put(GTK_LAYOUT(layout), LoginButton, 290, 280);
	gtk_widget_set_size_request(LoginButton, 135, 38);

	SignupBImage = gtk_image_new_from_file("signup.jpg");
	SignupButton = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(SignupButton), SignupBImage);
	gtk_layout_put(GTK_LAYOUT(layout), SignupButton, 290, 330);
	gtk_widget_set_size_request(SignupButton, 135, 38);

	//TextBoxes
	user_entry = gtk_entry_new();
	gtk_entry_set_width_chars((GtkEntry *) user_entry, 30);
	gtk_layout_put(GTK_LAYOUT(layout), user_entry, 233, 150);
	gtk_widget_set_size_request(user_entry, 250, 50);
  gtk_entry_set_max_length (GTK_ENTRY(user_entry),NAME_LEN);

	password_entry = gtk_entry_new();
	gtk_entry_set_width_chars((GtkEntry *) password_entry, 30);
	gtk_layout_put(GTK_LAYOUT(layout), password_entry, 233, 210);
	gtk_widget_set_size_request(password_entry, 250, 50);
  gtk_entry_set_max_length (GTK_ENTRY(password_entry),NAME_LEN);
	gtk_entry_set_visibility(GTK_ENTRY(password_entry),FALSE);
     gtk_entry_set_invisible_char (GTK_ENTRY (password_entry),'*');

/********************* Handling data and callback functions ***************************/
  //g_signal_connect(SignupButton,"clicked",G_CALLBACK(open_dialogSignUp),window3); 
  /*Handling object and set Login button*/
  g_object_set_data(G_OBJECT(LoginButton),"usernameLogin",user_entry);
  g_object_set_data(G_OBJECT(LoginButton),"passwordLogin",password_entry);
  g_signal_connect(GTK_BUTTON(LoginButton),"clicked",G_CALLBACK(login_button),LoginButton);
  char *username  = (char*) gtk_entry_get_text(GTK_ENTRY(user_entry));

  g_signal_connect(GTK_BUTTON(SignupButton),"clicked",G_CALLBACK(signUp_Button),SignupButton);
 
  
  /*Makinga login button close*/
  g_object_set_data(G_OBJECT(LoginButton),"window",window2);   
	gtk_widget_show_all(window2);
  gtk_main();
  return 0;
}


char chatInterface(int argc, char **argv,char *username){
  gtk_init(&argc, &argv);
	//Creating New Window
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);
	gtk_window_set_default_size(GTK_WINDOW(window), 600, 480);
	//gtk_window_set_resizable (GTK_WINDOW(window), FALSE);
	gtk_widget_show(GTK_WIDGET(window));

	//Layout
	layout = gtk_layout_new(NULL, NULL);
	gtk_container_add(GTK_CONTAINER (window), layout);
	gtk_widget_show(layout);

	//Loading Images
	MessageImage = gtk_image_new_from_file ("messageGUI.jpg");
	gtk_layout_put(GTK_LAYOUT(layout), MessageImage, 0,0);
	gtk_widget_show(GTK_WIDGET(MessageImage));
	
	AddFriendImage = gtk_image_new_from_file("addFriend.jpg");
	AddFriendButton = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(AddFriendButton), AddFriendImage);
	gtk_layout_put(GTK_LAYOUT(layout), AddFriendButton, 7, 440);
	gtk_widget_set_size_request(AddFriendButton, 135, 38); 

	SendMessageImage = gtk_image_new_from_file("sendmessage.jpg");
	SendMessageButton = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(SendMessageButton), SendMessageImage);
	gtk_layout_put(GTK_LAYOUT(layout), SendMessageButton, 535, 440);
	gtk_widget_set_size_request(SendMessageButton, 60, 35);
	
	ContactsImage = gtk_image_new_from_file("contacts.jpg");
	ContactsButton = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(ContactsButton), ContactsImage);
	gtk_layout_put(GTK_LAYOUT(layout), ContactsButton, 15, 50);
	gtk_widget_set_size_request(ContactsButton, 120, 38);
 
  gdk_color_parse( "white", &colorWhite);

  GtkWidget *ContactOneButton = gtk_button_new_with_label("bobs");
	gtk_layout_put(GTK_LAYOUT(layout), ContactOneButton, 15, 120);
	gtk_widget_set_size_request(ContactOneButton, 120, 38);
  gtk_widget_modify_bg(GTK_BUTTON(ContactOneButton), GTK_STATE_NORMAL, &colorWhite);
  g_signal_connect(GTK_BUTTON(ContactOneButton),"clicked",G_CALLBACK(first_contact),ContactOneButton);
  
  
  GtkWidget *statusImageOne = gtk_image_new_from_file("active.PNG");
  gtk_container_add(GTK_CONTAINER(ContactOneButton), statusImageOne);
  gtk_widget_set_size_request(statusImageOne, 15, 15);
  gtk_layout_put(GTK_LAYOUT(layout), statusImageOne,105,130);

  //Contact 2 Button
  GtkWidget *ContactTwoButton = gtk_button_new_with_label("sallyv");
	gtk_layout_put(GTK_LAYOUT(layout), ContactTwoButton, 15, 170);
	gtk_widget_set_size_request(ContactTwoButton, 120, 38);
  gtk_widget_modify_bg(GTK_BUTTON(ContactTwoButton), GTK_STATE_NORMAL, &colorWhite);
  g_signal_connect(GTK_BUTTON(ContactTwoButton),"clicked",G_CALLBACK(second_contact),ContactTwoButton);
  
  GtkWidget *statusImageTwo = gtk_image_new_from_file("active.PNG");
  gtk_container_add(GTK_CONTAINER(ContactTwoButton), statusImageTwo);
  gtk_widget_set_size_request(statusImageTwo, 15, 15);
  gtk_layout_put(GTK_LAYOUT(layout), statusImageTwo,105,180);
 
 //Contact 3 Button
  GtkWidget *ContactThirdButton = gtk_button_new_with_label("nicks");
	gtk_layout_put(GTK_LAYOUT(layout), ContactThirdButton, 15, 220);
	gtk_widget_set_size_request(ContactThirdButton, 120, 38);
  gtk_widget_modify_bg(GTK_BUTTON(ContactThirdButton), GTK_STATE_NORMAL, &colorWhite);
  g_signal_connect(GTK_BUTTON(ContactThirdButton),"clicked",G_CALLBACK(third_contact),ContactThirdButton);

  GtkWidget *statusImageThird = gtk_image_new_from_file("active.PNG");
  gtk_container_add(GTK_CONTAINER(ContactThirdButton), statusImageThird);
  gtk_widget_set_size_request(statusImageThird, 15, 15);
  gtk_layout_put(GTK_LAYOUT(layout), statusImageThird,105,230);

	DeleteImage = gtk_image_new_from_file("delete.jpg");
	DeleteButton = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(DeleteButton), DeleteImage);
	gtk_layout_put(GTK_LAYOUT(layout), DeleteButton, 165, 50);
	gtk_widget_set_size_request(DeleteButton, 50, 30);

	BlockImage = gtk_image_new_from_file("block.jpg");
	BlockButton = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(BlockButton), BlockImage);
	gtk_layout_put(GTK_LAYOUT(layout), BlockButton, 535, 40);
	gtk_widget_set_size_request(BlockButton, 50, 45);
 
  message = gtk_text_view_new();
  gtk_layout_put(GTK_LAYOUT(layout), message, 160, 445);
  gtk_widget_set_size_request(message, 360, 30); //width length
  g_object_set_data(G_OBJECT(SendMessageButton),"messageEntered",message);
  
  
   textArea = gtk_text_view_new();
   //GtkWidget* scrollbar= gtk_vscrollbar_new(gtk_text_view_get_vadjustment(GTK_TEXT_VIEW(textArea)));
  GtkWidget *vbox2 = gtk_vbox_new(FALSE,2);
  gtk_layout_put(GTK_LAYOUT(layout), vbox2, 149, 90);
  gtk_widget_set_size_request(vbox2,455,345); //width length  
  gtk_text_view_set_editable(GTK_TEXT_VIEW(textArea),FALSE);
  gtk_text_view_set_cursor_visible(GTK_TEXT_VIEW(textArea),FALSE);
  g_object_set_data(G_OBJECT(SendMessageButton),"textDisplay",textArea);
   //g_object_set_data(G_OBJECT(SendMessageButton),"textDisplay",message);
   
  g_signal_connect(GTK_BUTTON(SendMessageButton),"clicked",G_CALLBACK(send_button),SendMessageButton);
 
  
  GtkWidget *scrolled = gtk_scrolled_window_new(NULL,NULL);
  gtk_container_add(GTK_CONTAINER(scrolled),textArea);
  gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled),GTK_POLICY_AUTOMATIC,GTK_POLICY_ALWAYS);
  gtk_box_pack_start(GTK_BOX(vbox2),scrolled,TRUE,TRUE,1);

  ChessImage = gtk_image_new_from_file("bking.png");
	ChessButton = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(ChessButton), ChessImage);
	gtk_layout_put(GTK_LAYOUT(layout), ChessButton, 50, 370);
	gtk_widget_set_size_request(ChessButton, 50, 50);
  g_signal_connect(GTK_BUTTON(ChessButton),"clicked",G_CALLBACK(chess_button),ChessButton);
  
  
	gtk_widget_show_all(window);
  gtk_main();
  return 0;

}

int main(int argc, char **argv){
	
  	//g_print("done\n");
	int clientSocket = socket(PF_INET, SOCK_STREAM, 0);
	printf("CS: %d\n", clientSocket);
	usernumber = clientSocket;
	printf("UN: %d\n", usernumber);

	struct sockaddr_in serverAddr;

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(6732);
	serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);

	if(connect(clientSocket, (struct sockaddr*) &serverAddr, sizeof(serverAddr)) == -1){
		printf("ERROR 102 = SERVER NOT ONLINE.\n");
		return 0;
	}

	printf("Connection established with server.\n");

	pthread_t thread;
	pthread_create(&thread, NULL, doRecieving, (void *) &clientSocket );
	createLogin(argc, argv);
	
}

