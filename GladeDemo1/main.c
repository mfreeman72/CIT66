#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include <math.h>
#include <ctype.h>

// From YouTube video Linux Gtk Glade Programming Part 1 - https://www.youtube.com/watch?v=g-KDOH_uqPk

GtkWidget   *window;
GtkWidget   *fixed1;
GtkWidget   *button1;
GtkWidget   *label1;
GtkBuilder  *builder;

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv); // init Gtk

    // Establish contact with xml code used to adjust widget settings

    builder = gtk_builder_new_from_file ("part1.glade"); // Loads the Glade XML file from the Glade Gtk GUI builder application

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window")); // Makes the connection to the application window

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL); // Causes the closed window to quit the program instead of just closing the window

    gtk_builder_connect_signals(builder, NULL); // Builds table of all callback functions to all GUI elements in your XML

    fixed1 = GTK_WIDGET(gtk_builder_get_object(builder, "fixed1")); // Connects to the pointer for the GUI fixed container
    button1 = GTK_WIDGET(gtk_builder_get_object(builder, "button1")); // Connects to the pointer for the GUI button
    label1 = GTK_WIDGET(gtk_builder_get_object(builder, "label1")); // Connects to the pointer for the GUI label

    gtk_widget_show(window); // Cause the window to appear

    gtk_main(); // This will sit there and watch for events

    return EXIT_SUCCESS; // Exit when window closes
}

void	on_button1_clicked (GtkButton *b) {
	gtk_label_set_text (GTK_LABEL(label1), (const gchar* ) "Hello World");
	}
