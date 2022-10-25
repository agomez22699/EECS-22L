//This is for the Message Area of the GUI

#include <gtk/gtk.h>
#include <gdk/gdkx.h>
#include <stdio.h>
#include <gdk/gdktestutils.h>






//Widgets for Message Screen
GtkWidget	*window;
GtkWidget	*MessageImage;
GtkWidget	*AddFriendImage;
GtkWidget	*SendMessageImage;
GtkWidget 	*AddFriendButton;
GtkWidget	*SendMessageButton;
GtkWidget	*layout;
GtkWidget	*ContactsImage;
GtkWidget	*ContactsButton;
GtkWidget	*DeleteImage;
GtkWidget	*DeleteButton;
GtkWidget	*BlockImage;
GtkWidget	*BlockButton;
GtkWidget	*entry1;
GtkWidget	*view;
GtkTextBuffer	*MessageBuffer;

GtkWidget	*ChessImage;
GtkWidget	*ChessButton;

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

//For Delete Friend GUI
GtkWidget	*window4;
GtkWidget	*DeleteGUI;
GtkWidget	*yesButtonImage;
GtkWidget	*yesButton;
GtkWidget	*noButtonImage;
GtkWidget	*noButton;

//For Block Friend GUI
GtkWidget	*window5;
GtkWidget	*BlockGUI;

//For Friend Request GUI
GtkWidget	*window6;
GtkWidget	*FriendRequestGUI;
GtkWidget	*submitImage;
GtkWidget	*submitButton;
GtkWidget	*friend_entry;

//For Friend Accept 
GtkWidget	*window7;
GtkWidget	*AcceptGUI;

int login_button (GtkButton *LoginButton, GObject *context_object);
int signUp_Button(GtkButton *SignupButton, GObject *context_object);
int add_button(GtkButton *AddFriendButton, GObject *context_object);
int create_button(GtkButton *createButton, GObject *context_object);
int contacts_button(GtkButton *ContactsButton, GObject *context_object);
int submit_button(GtkButton *submitButton, GObject *context_object);
int delete_button(GtkButton *DeleteButton, GObject *context_object);
int yes_button(GtkButton *yesButton, GObject *context_object);
int no_button(GtkButton *noButton, GObject *context_object);
int block_button(GtkButton *BlockButton, GObject *context_object);

char create_friend_acceptGUI(int argc, char **argv);
char create_friend_requestGUI(int argc, char **argv);
char create_block_friendGUI(int argc, char **argv);
char create_delete_friendGUI(int argc, char **argv);
char createNewUser(int argc, char **argv);
char createLogin(int argc, char **argv);
char createMess(int argc, char **argv);

int login_button (GtkButton *LoginButton, GObject *context_object){
	g_print("You clicked login button \n");
	gtk_widget_destroy(GTK_WIDGET(window2));
	createMess(0,0);
	return 1;
}

int signUp_Button(GtkButton *SignupButton, GObject *context_object){
  g_print("Selected the sign up button\n");
  gtk_widget_destroy(GTK_WIDGET(window2));
  createNewUser(0,0);
  return 1;
}

int create_button(GtkButton *createButton, GObject *context_object){
	g_print("Selected the Create button\n");
	gtk_widget_destroy(GTK_WIDGET(window3));
	createMess(0,0);
	return 1;
}

int add_button(GtkButton *AddFriendButton, GObject *context_object){
	g_print("Selected the Add Friend button\n");
	gtk_widget_destroy(GTK_WIDGET(window));
	if (window6 != NULL){
	gtk_widget_destroy(GTK_WIDGET(window6));
	}

	if(window4 != NULL){
	gtk_widget_destroy(GTK_WIDGET(window4));
	}
	if(window5 != NULL){
	gtk_widget_destroy(GTK_WIDGET(window5));
	}
	create_friend_requestGUI(0,0);
	return 1;

}

int contacts_button(GtkButton *ContactsButton, GObject *context_object){
	g_print("Selected the contacts button\n");
	gtk_widget_destroy(GTK_WIDGET(window));
	if (window6 != NULL){
	gtk_widget_destroy(GTK_WIDGET(window6));
		}
	if(window4 != NULL){
	gtk_widget_destroy(GTK_WIDGET(window4));
	}
	if(window5 != NULL){
	gtk_widget_destroy(GTK_WIDGET(window5));
	}
	createMess(0,0);
	return 1;

}

int submit_button(GtkButton *submitButton, GObject *context_object){
	g_print("Selected the Submit button\n");
	gtk_widget_destroy(GTK_WIDGET(window6));
	createMess(0,0);
	return 1;

}

int delete_button(GtkButton *DeleteButton, GObject *context_object){
	g_print("Selected the Delete button\n");
	gtk_widget_destroy(GTK_WIDGET(window));
	create_delete_friendGUI(0,0);
	return 1;

}

int yes_button(GtkButton *yesButton, GObject *context_object){
	g_print("Selected the Yes button\n");
	if(window5 != NULL){
	gtk_widget_destroy(GTK_WIDGET(window5));
	}
	gtk_widget_destroy(GTK_WIDGET(window4));
	createMess(0,0);
	return 1;

}

int no_button(GtkButton *noButton, GObject *context_object){
	g_print("Selected the No button\n");
	if(window5 != NULL){
	gtk_widget_destroy(GTK_WIDGET(window5));
	}
	gtk_widget_destroy(GTK_WIDGET(window4));
	createMess(0,0);
	return 1;

}

int block_button(GtkButton *BlockButton, GObject *context_object){
	g_print("Selected the Block button\n");
	gtk_widget_destroy(GTK_WIDGET(window));
	create_block_friendGUI(0,0);
	return 1;

}

int chess_button(GtkButton *ChessButton, GObject *context_object){
	g_print("Selected the Chess button\n");
	return 1;
}




char create_friend_acceptGUI(int argc, char **argv){

	gtk_init(&argc, &argv);
	
	//Creating New Window
	window7 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	g_signal_connect (window7, "destroy", G_CALLBACK (gtk_main_quit), NULL);
	gtk_window_set_default_size(GTK_WINDOW(window7), 723, 578);
	gtk_widget_show(GTK_WIDGET(window7));

	//Layout
	layout = gtk_layout_new(NULL, NULL);
	gtk_container_add(GTK_CONTAINER (window7), layout);
	gtk_widget_show(layout);

	//Loading Images
	AcceptGUI = gtk_image_new_from_file ("accept_friend.png");
	gtk_layout_put(GTK_LAYOUT(layout), AcceptGUI, 0,0);
	gtk_widget_show(GTK_WIDGET(AcceptGUI));

	AddFriendImage = gtk_image_new_from_file("addFriend.jpg");
	AddFriendButton = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(AddFriendButton), AddFriendImage);
	gtk_layout_put(GTK_LAYOUT(layout), AddFriendButton, 7, 505);
	gtk_widget_set_size_request(AddFriendButton, 160, 50);

	ContactsImage = gtk_image_new_from_file("contacts.jpg");
	ContactsButton = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(ContactsButton), ContactsImage);
	gtk_layout_put(GTK_LAYOUT(layout), ContactsButton, 15, 60);
	gtk_widget_set_size_request(ContactsButton, 140, 38);

	SendMessageImage = gtk_image_new_from_file("sendmessage.jpg");
	SendMessageButton = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(SendMessageButton), SendMessageImage);
	gtk_layout_put(GTK_LAYOUT(layout), SendMessageButton, 615, 505);
	gtk_widget_set_size_request(SendMessageButton, 80, 53);

	yesButtonImage = gtk_image_new_from_file("yesButton.png");
	yesButton = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(yesButton), yesButtonImage);
	gtk_layout_put(GTK_LAYOUT(layout), yesButton, 250, 280);
	gtk_widget_set_size_request(yesButton, 135, 38);

	noButtonImage = gtk_image_new_from_file("noButton.png");
	noButton = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(noButton), noButtonImage);
	gtk_layout_put(GTK_LAYOUT(layout), noButton, 500, 280);
	gtk_widget_set_size_request(noButton, 135, 38);


	gtk_widget_show_all(window7);

	gtk_main();
  	return 0;

}

char create_friend_requestGUI(int argc, char **argv){

	gtk_init(&argc, &argv);


	//Creating New Window
	window6 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	g_signal_connect (window6, "destroy", G_CALLBACK (gtk_main_quit), NULL);
	gtk_window_set_default_size(GTK_WINDOW(window6), 723, 578);
	gtk_widget_show(GTK_WIDGET(window6));

	//Layout
	layout = gtk_layout_new(NULL, NULL);
	gtk_container_add(GTK_CONTAINER (window6), layout);
	gtk_widget_show(layout);

	//Loading Images
	FriendRequestGUI = gtk_image_new_from_file ("friendGUI.png");
	gtk_layout_put(GTK_LAYOUT(layout), FriendRequestGUI, 0,0);
	gtk_widget_show(GTK_WIDGET(FriendRequestGUI));

	AddFriendImage = gtk_image_new_from_file("addFriend.jpg");
	AddFriendButton = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(AddFriendButton), AddFriendImage);
	gtk_layout_put(GTK_LAYOUT(layout), AddFriendButton, 7, 525);
	gtk_widget_set_size_request(AddFriendButton, 160, 50);

	ContactsImage = gtk_image_new_from_file("contacts.jpg");
	ContactsButton = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(ContactsButton), ContactsImage);
	gtk_layout_put(GTK_LAYOUT(layout), ContactsButton, 15, 60);
	gtk_widget_set_size_request(ContactsButton, 140, 38);

	SendMessageImage = gtk_image_new_from_file("sendmessage.jpg");
	SendMessageButton = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(SendMessageButton), SendMessageImage);
	gtk_layout_put(GTK_LAYOUT(layout), SendMessageButton, 640, 525);
	gtk_widget_set_size_request(SendMessageButton, 80, 53);

	friend_entry = gtk_entry_new();
	gtk_entry_set_width_chars((GtkEntry *) friend_entry, 30);
	gtk_layout_put(GTK_LAYOUT(layout), friend_entry, 320, 198);
	gtk_widget_set_size_request(friend_entry, 250, 50);

	submitImage = gtk_image_new_from_file("submitButton.png");
	submitButton = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(submitButton), submitImage);
	gtk_layout_put(GTK_LAYOUT(layout), submitButton, 370, 275);
	gtk_widget_set_size_request(submitButton, 170, 50);

	g_signal_connect(GTK_BUTTON(ContactsButton),"clicked",G_CALLBACK(contacts_button),ContactsButton);
	g_signal_connect(GTK_BUTTON(AddFriendButton),"clicked",G_CALLBACK(add_button),AddFriendButton);
	g_signal_connect(GTK_BUTTON(submitButton),"clicked",G_CALLBACK(submit_button),submitButton);


	gtk_widget_show_all(window6);

	gtk_main();
  	return 0;

}

char create_block_friendGUI(int argc, char **argv){

	gtk_init(&argc, &argv);


	//Creating New Window
	window5 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	g_signal_connect (window5, "destroy", G_CALLBACK (gtk_main_quit), NULL);
	gtk_window_set_default_size(GTK_WINDOW(window5), 723, 578);
	gtk_widget_show(GTK_WIDGET(window5));

	//Layout
	layout = gtk_layout_new(NULL, NULL);
	gtk_container_add(GTK_CONTAINER (window5), layout);
	gtk_widget_show(layout);

	//Loading Images
	BlockGUI = gtk_image_new_from_file ("BlockGUI.png");
	gtk_layout_put(GTK_LAYOUT(layout), BlockGUI, 0,0);
	gtk_widget_show(GTK_WIDGET(BlockGUI));

	AddFriendImage = gtk_image_new_from_file("addFriend.jpg");
	AddFriendButton = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(AddFriendButton), AddFriendImage);
	gtk_layout_put(GTK_LAYOUT(layout), AddFriendButton, 7, 525);
	gtk_widget_set_size_request(AddFriendButton, 160, 50);

	ContactsImage = gtk_image_new_from_file("contacts.jpg");
	ContactsButton = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(ContactsButton), ContactsImage);
	gtk_layout_put(GTK_LAYOUT(layout), ContactsButton, 15, 60);
	gtk_widget_set_size_request(ContactsButton, 140, 38);

	SendMessageImage = gtk_image_new_from_file("sendmessage.jpg");
	SendMessageButton = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(SendMessageButton), SendMessageImage);
	gtk_layout_put(GTK_LAYOUT(layout), SendMessageButton, 640, 525);
	gtk_widget_set_size_request(SendMessageButton, 80, 53);

	yesButtonImage = gtk_image_new_from_file("yesButton.png");
	yesButton = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(yesButton), yesButtonImage);
	gtk_layout_put(GTK_LAYOUT(layout), yesButton, 250, 280);
	gtk_widget_set_size_request(yesButton, 135, 38);

	noButtonImage = gtk_image_new_from_file("noButton.png");
	noButton = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(noButton), noButtonImage);
	gtk_layout_put(GTK_LAYOUT(layout), noButton, 500, 280);
	gtk_widget_set_size_request(noButton, 135, 38);

	g_signal_connect(GTK_BUTTON(AddFriendButton),"clicked",G_CALLBACK(add_button),AddFriendButton);
	g_signal_connect(GTK_BUTTON(ContactsButton),"clicked",G_CALLBACK(contacts_button),ContactsButton);
	g_signal_connect(GTK_BUTTON(yesButton),"clicked",G_CALLBACK(yes_button),yesButton);
	g_signal_connect(GTK_BUTTON(noButton),"clicked",G_CALLBACK(no_button),noButton);


	gtk_widget_show_all(window5);

	gtk_main();
  	return 0;

}

char create_delete_friendGUI(int argc, char **argv){

	gtk_init(&argc, &argv);


	//Creating New Window
	window4 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	g_signal_connect (window4, "destroy", G_CALLBACK (gtk_main_quit), NULL);
	gtk_window_set_default_size(GTK_WINDOW(window4), 723, 580);
	gtk_widget_show(GTK_WIDGET(window4));

	//Layout
	layout = gtk_layout_new(NULL, NULL);
	gtk_container_add(GTK_CONTAINER (window4), layout);
	gtk_widget_show(layout);

	//Loading Images
	DeleteGUI = gtk_image_new_from_file ("DeleteGUI.png");
	gtk_layout_put(GTK_LAYOUT(layout), DeleteGUI, 0,0);
	gtk_widget_show(GTK_WIDGET(DeleteGUI));

	//Buttons
	AddFriendImage = gtk_image_new_from_file("addFriend.jpg");
	AddFriendButton = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(AddFriendButton), AddFriendImage);
	gtk_layout_put(GTK_LAYOUT(layout), AddFriendButton, 7, 525);
	gtk_widget_set_size_request(AddFriendButton, 160, 50);

	ContactsImage = gtk_image_new_from_file("contacts.jpg");
	ContactsButton = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(ContactsButton), ContactsImage);
	gtk_layout_put(GTK_LAYOUT(layout), ContactsButton, 15, 60);
	gtk_widget_set_size_request(ContactsButton, 140, 38);

	SendMessageImage = gtk_image_new_from_file("sendmessage.jpg");
	SendMessageButton = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(SendMessageButton), SendMessageImage);
	gtk_layout_put(GTK_LAYOUT(layout), SendMessageButton, 640, 525);
	gtk_widget_set_size_request(SendMessageButton, 80, 53);

	yesButtonImage = gtk_image_new_from_file("yesButton.png");
	yesButton = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(yesButton), yesButtonImage);
	gtk_layout_put(GTK_LAYOUT(layout), yesButton, 250, 280);
	gtk_widget_set_size_request(yesButton, 135, 38);

	noButtonImage = gtk_image_new_from_file("noButton.png");
	noButton = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(noButton), noButtonImage);
	gtk_layout_put(GTK_LAYOUT(layout), noButton, 500, 280);
	gtk_widget_set_size_request(noButton, 135, 38);

	g_signal_connect(GTK_BUTTON(AddFriendButton),"clicked",G_CALLBACK(add_button),AddFriendButton);
	g_signal_connect(GTK_BUTTON(ContactsButton),"clicked",G_CALLBACK(contacts_button),ContactsButton);
	g_signal_connect(GTK_BUTTON(yesButton),"clicked",G_CALLBACK(yes_button),yesButton);
	g_signal_connect(GTK_BUTTON(noButton),"clicked",G_CALLBACK(no_button),noButton);




	gtk_widget_show_all(window4);

	gtk_main();
  	return 0;


}
char createNewUser(int argc, char **argv){

	gtk_init(&argc, &argv);


	//Creating New Window
	window3 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	g_signal_connect (window3, "destroy", G_CALLBACK (gtk_main_quit), NULL);
	gtk_window_set_default_size(GTK_WINDOW(window3), 720, 580);
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

	lname_entry = gtk_entry_new();
	gtk_entry_set_width_chars((GtkEntry *) lname_entry, 30);
	gtk_layout_put(GTK_LAYOUT(layout), lname_entry, 389, 180);
	gtk_widget_set_size_request(lname_entry, 250, 50);

	new_user_entry = gtk_entry_new();
	gtk_entry_set_width_chars((GtkEntry *) new_user_entry, 30);
	gtk_layout_put(GTK_LAYOUT(layout), new_user_entry, 389, 240);
	gtk_widget_set_size_request(new_user_entry, 250, 50);

	new_pass_entry = gtk_entry_new();
	gtk_entry_set_width_chars((GtkEntry *) new_pass_entry, 30);
	gtk_layout_put(GTK_LAYOUT(layout), new_pass_entry, 389, 300);
	gtk_widget_set_size_request(new_pass_entry, 250, 50);

	//Buttons
	createButtonImage = gtk_image_new_from_file("create.jpg");
	createButton = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(createButton), createButtonImage);
	gtk_layout_put(GTK_LAYOUT(layout), createButton, 290, 500);
	gtk_widget_set_size_request(createButton, 135, 38);

	//Events
	g_signal_connect(GTK_BUTTON(createButton),"clicked",G_CALLBACK(create_button),createButton);


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

	password_entry = gtk_entry_new();
	gtk_entry_set_width_chars((GtkEntry *) password_entry, 30);
	gtk_layout_put(GTK_LAYOUT(layout), password_entry, 233, 210);
	gtk_widget_set_size_request(password_entry, 250, 50);

	//Events
	g_signal_connect(GTK_BUTTON(LoginButton),"clicked",G_CALLBACK(login_button),LoginButton);
	g_signal_connect(GTK_BUTTON(SignupButton),"clicked",G_CALLBACK(signUp_Button),SignupButton);

	gtk_widget_show_all(window2);

	gtk_main();
  	return 0;

}



char createMess(int argc, char **argv){

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

	ChessImage = gtk_image_new_from_file("bking.png");
	ChessButton = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(ChessButton), ChessImage);
	gtk_layout_put(GTK_LAYOUT(layout), ChessButton, 50, 380);
	gtk_widget_set_size_request(ChessButton, 50, 50);

	//Text box entry
	entry1 = gtk_entry_new();
	gtk_entry_set_width_chars((GtkEntry *) entry1, 85);
	gtk_layout_put(GTK_LAYOUT(layout), entry1, 160, 445);
	gtk_widget_set_size_request(entry1, 360, 30);

	//Message Box Entry
	view = gtk_text_view_new ();
	MessageBuffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (view));
	gtk_text_buffer_set_text (MessageBuffer, "Hello", -1);
	gtk_text_view_set_editable(GTK_TEXT_VIEW(view),FALSE);
	gtk_text_view_set_cursor_visible(GTK_TEXT_VIEW(view),FALSE);
	gtk_layout_put(GTK_LAYOUT(layout), view, 155, 90);

	//Events
	g_signal_connect(GTK_BUTTON(AddFriendButton),"clicked",G_CALLBACK(add_button),AddFriendButton);
	g_signal_connect(GTK_BUTTON(ContactsButton),"clicked",G_CALLBACK(contacts_button),ContactsButton);
	g_signal_connect(GTK_BUTTON(DeleteButton),"clicked",G_CALLBACK(delete_button),DeleteButton);
	g_signal_connect(GTK_BUTTON(BlockButton),"clicked",G_CALLBACK(block_button),BlockButton);
	g_signal_connect(GTK_BUTTON(ChessButton),"clicked",G_CALLBACK(chess_button),ChessButton);



	gtk_widget_show_all(window);

	gtk_main();
  	return 0;


}


int main(int argc, char *argv[]){

	gtk_init(&argc, &argv);

	createLogin(argc, argv);

	gtk_main();
	
	return 0;

}

