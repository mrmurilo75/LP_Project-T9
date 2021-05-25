#include "util.h"
#include "Dictionary.h"
#include "String.h"
#include <gtk/gtk.h>
#include <ctype.h>
#include <string.h>

GtkWidget *window,
	*vbox,
	*grid,
	*fullTxt,
	*curWord,
	*buttons[12];
	/*
	*btn1,
	*btn2,
	*btn3,
	*btn4,
	*btn5,
	*btn6,
	*btn7,
	*btn8,
	*btn9,
	*btnCycle,
	*btn0,
	*btnSend;
	*/

gchar *buttonLabels[12] = { 
	" 1\n ~", " 2\nabc", " 3\ndef", 
	" 4\nghi", " 5\njkl", "  6\nmno", 
	"  7\npqrs", " 8\ntuv", "  9\nwxyz", 
	" *\nclr", " 0\ncycl", " #\ndel" 
	};

String fullTxtStr,
	curWordStr;

Dictionary dictionary;

void buttonClick(GtkWidget *widget, gpointer data);
// create a button_cliked callback that compare the label and calls the respective funtion


int main(int argc, char* argv[]) {

	String fname = new_String( 18, "lusiadas_clean.txt");
	FILE* dictFile = fopen((char*)fname->value, "r");
	dictionary = Dictionary_fillFromFile(dictFile);

	gtk_init(&argc, & argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Project T9");
	gtk_window_set_default_size(GTK_WINDOW(window), 1, 1);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_container_set_border_width(GTK_CONTAINER(window), 5);

	vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 1);

	fullTxt = gtk_label_new((gchar*) "full txt place holder");
	curWord = gtk_label_new((gchar*) "placeholder");

	grid = gtk_grid_new();
	gtk_grid_set_row_spacing(GTK_GRID(grid), 2);
	gtk_grid_set_column_spacing(GTK_GRID(grid), 2);

	for(int line = 0, pos = 0; line < 4; line++)
		for(int col = 0; col < 3; col++) {
			buttons[pos] = gtk_button_new_with_label(buttonLabels[pos]);
			g_signal_connect(G_OBJECT(buttons[pos]), "clicked", G_CALLBACK(buttonClick), buttons[pos]); 
			gtk_grid_attach(GTK_GRID(grid), buttons[pos], col, line, 1, 1);
			pos++;
		}

	gtk_container_add(GTK_CONTAINER(window), vbox);
	gtk_box_pack_start(GTK_BOX(vbox), fullTxt, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox), curWord, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox), grid, TRUE, TRUE, 0);



	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

	gtk_widget_show_all(window);

	gtk_main();

	return 0;
}

void numpad_clicked(int i);

void asterisk_clicked();

void hashtag_clicked();

void buttonClick(GtkWidget *widget, gpointer data) {
	const char *label = gtk_button_get_label(data);

	int i;
	for(i = 0; i < 9 
		&& ( 
			!isdigit(label[i]) 
			&& label[i] != '#' 
			&& label[i] != '*' 
		); i++);

	const char val = label[i];

	g_print("button %c\n", val);

	if(val >= '0' && val <= '9')
		numpad_clicked(i);
	else if (val == '*')
		asterisk_clicked();
	else
		hashtag_clicked();

	return;
}

void numpad_clicked(int i) {
	
}
void asterisk_clicked() {}
void hashtag_clicked() {}



