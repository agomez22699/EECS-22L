#include <gtk/gtk.h> 
#include <gdk/gdkx.h>
//#include <stdio.h>
//#include <stdlib.h>

void destroy( GtkWidget *widget, gpointer   data )
{
   gtk_main_quit ();
}

static void login_screen(void){
  
  GtkWidget *window;
  GtkWidget *loginButton;
  GtkWidget *createAccountButton;
  GtkWidget *loginScreen;
  GtkWidget	*layout;  
  GtkWidget	*entry; 
  GtkWidget *username;
  GtkWidget *password;
  GtkWidget *labelUsername;
  const gchar *const appName = "ZOT CHAT";
  GtkWidget *loginButtonImage;
  GtkWidget *signupButtonImage;
  //GtkStyle *style = NULL; 
  
  //Window 
  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  g_signal_connect (window, "destroy",G_CALLBACK (gtk_main_quit),NULL);
  gtk_window_set_default_size(GTK_WINDOW(window), 715, 600);
	gtk_window_set_title (GTK_WINDOW (window), "ZOT CHAT");
  gtk_window_set_position(GTK_WINDOW (window),GTK_WIN_POS_CENTER);
  gtk_widget_show(GTK_WIDGET(window));
 
  
 	//Layout
	layout = gtk_layout_new(NULL, NULL);
	gtk_container_add(GTK_CONTAINER (window), layout);
	gtk_widget_show(layout);
  

	//Loading Images
	loginScreen = gtk_image_new_from_file ("login.JPG");
  gtk_layout_put(GTK_LAYOUT(layout), loginScreen, 0,0);
 
	
  loginButtonImage = gtk_image_new_from_file("loginBut.JPG");
 	loginButton = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(loginButton), loginButtonImage);
	gtk_layout_put(GTK_LAYOUT(layout), loginButton,280,300);
	gtk_widget_set_size_request(loginButton,150,40); 
//g_signal_connect(loginButton,"clicked",gtk_main_quit,NULL);

  signupButtonImage = gtk_image_new_from_file("signup.JPG");
 	createAccountButton = gtk_button_new();
	//could change to create account screen
  gtk_container_add(GTK_CONTAINER(createAccountButton), signupButtonImage);
	gtk_layout_put(GTK_LAYOUT(layout), createAccountButton,280,360);
	gtk_widget_set_size_request(createAccountButton,150,40); 
  //when event is create account then pop up new screen 
  //  g_signal_connect(createAccountButton,"clicked",gtk_main_quit,NULL);


//dont have to put max size
   /*displaying box for username and password*/
  username= gtk_entry_new();
  //labelUsername = gtk_label_new_with_mnemonic ("Username");
  //gtk_label_set_mnemonic_widget (GTK_LABEL (labelUsername), entry);

  gtk_layout_put(GTK_LAYOUT(layout), username,220,150); 
  gtk_widget_set_size_request(username,280,50); /*box width,box height*/
  gtk_entry_append_text (GTK_ENTRY(username), "username");
  //add temp text 
  
  password= gtk_entry_new();
  gtk_layout_put(GTK_LAYOUT(layout),password,220,210); 
  gtk_widget_set_size_request(password,280,50); /*box width,box height*/
  gtk_entry_set_visibility(GTK_ENTRY(password),FALSE);
  //add temp text  
  //g_signal_connect(entry,"activate",G_CALLBACK(button_clicked),entry);

  gtk_widget_show_all(window);
}


int main( int   argc, char *argv[] )
{
    	gtk_init (&argc, &argv);
    	login_screen();
    	gtk_main ();

    	return 0;
}
