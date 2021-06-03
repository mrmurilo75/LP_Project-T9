#include "util.h"
#include "Dictionary.h"
#include <ctype.h>
#include <string.h>
#include <gtk/gtk.h>

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

LinkedListMap llmCycle;

byte isCycling;

FILE *fullTxtFile, *dictionaryFile;

void buttonClick(GtkWidget *widget, gpointer data);
// create a button_cliked callback that compare the label and calls the respective funtion

void initialize() {
//	String fname = new_String( 13, "lus_test2.txt");
//	String fname = new_String( 12, "lus_test.txt");
//	String fname = new_String( 18, "lusiadas_clean.txt");
	String fname = new_String( 14, "dictionary.txt");
	dictionaryFile = fopen(fname->value, "r");
	if(dictionaryFile == NULL)
		fprintf(stderr, "Failed to open dictionary file\n");
	else
		dictionary = Dictionary_fillFromFile(dictionaryFile);

	printf("Dicitionary filled\n");


	fullTxtFile = fopen("fullTxt.txt", "r");
	if(fullTxtFile != NULL) {
		fullTxtStr = String_readTextFile(fullTxtFile);
		fullTxtFile = freopen(NULL, "a", fullTxtFile);
	}
	if(fullTxtFile == NULL) {
		fullTxtFile = fopen("fullTxt.txt", "w");
		fullTxtStr = new_StringWithBuffer( 0, (char *) calloc(256, sizeof(char)), 256 );
	}

//	fullTxtStr = new_StringWithBuffer( 0, (char *) calloc(256, sizeof(char)), 256 );

	curWordStr = new_StringWithBuffer( 0, (char *) calloc(64, sizeof(char)), 64 );

	isCycling = 0; // false
	llmCycle = NULL;
}

int main(int argc, char* argv[]) {

	initialize();

	printf("Finished initialization\n");

	gtk_init(&argc, NULL);

	printf("GTK initialized\n");

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Project T9");
	gtk_window_set_default_size(GTK_WINDOW(window), 1, 1);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_container_set_border_width(GTK_CONTAINER(window), 5);

	vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 1);

	fullTxt = gtk_label_new( fullTxtStr->value );
	curWord = gtk_label_new((char*) "<Current typing>");

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

	printf("Finished GTK setup\n");

	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

	gtk_widget_show_all(window);

	gtk_main();

	return 0;
}

void numpad_clicked(int i);

void cycle();

void sendTxt();

void clear();

void del();

void buttonClick(GtkWidget *widget, gpointer data) {
	printf("in button_click()\n");
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

	switch(val) {
		case '0':
			cycle();
			return;
		case '1':
			sendTxt();
			return;
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			numpad_clicked(val-'0');
			return;
		case '*':
			clear();
			return;
		case '#':
			del();
			return;
		default:
			return;
	}

	return;
}

void numpad_clicked(int i) {
	printf("in numpad_clicked()\n");
	if(isCycling)
		sendTxt();

	//char *val = malloc(sizeof(char)*2);
	//val[0] = '0' + i;
	//val[1] = '\0';
	//String end = new_String(1, val);
	char val = '0' + i;
	//printf("curWord = %s\n", curWordStr->value );
	curWordStr = String_appendChar(curWordStr, val);

	gtk_label_set_text( (GtkLabel *) curWord, curWordStr->value );
	//printf("curWord = %s\n", curWordStr->value );
	printf("out of numpad_clicked()\n");
	return;
}

void cycle() {
	printf("in cycle()\n");
		printf("here\n");

	StringT9 curWordStrT9;

	if(!isCycling) {
		isCycling = 1; // true

		curWordStrT9 = String_toStringT9(curWordStr);
		llmCycle = Dictionary_find(dictionary, curWordStrT9);
		printf("dict= %p\tcWS= %p\tcWST9= %p\tllmC= %p\n", dictionary, curWordStr, curWordStrT9, llmCycle);
	}

	if(llmCycle == NULL) {
		isCycling = 0;
		return;
	}

	curWordStr = (String) LinkedListMap_next(llmCycle);
	//printf("dict= %p\tcWS= %p\tcWST9= %p\tllmC= %p\n", dictionary, curWordStr, curWordStrT9, llmCycle);

	if(curWordStr != NULL)
		gtk_label_set_text( (GtkLabel *) curWord, curWordStr->value );
	else
		clear();
	//printf("curWord = %s\n", curWordStr->value );

	printf("out of cycle()\n");
	return;
}

void sendTxt() {
	printf("in sendTxt()\n");

	if(!isCycling) {
		cycle();
		if(!isCycling) {
			clear();
			return;
		}
	}

	fullTxtStr = String_appendChar(fullTxtStr, ' ');
	fullTxtStr = String_append(fullTxtStr, curWordStr);

	fprintf(fullTxtFile, " %s", curWordStr->value);

	gtk_label_set_text( (GtkLabel *) fullTxt, fullTxtStr->value );
	//printf("fullTxt = %s\n", fullTxtStr->value );

	clear();

	printf("out of sendTxt()\n");
	return;
}

void clear() {
	printf("in clear()\n");
	isCycling = 0; // false

	curWordStr = new_StringWithBuffer( 0, (char *) calloc(64, sizeof(char)), 64 );

	gtk_label_set_text( (GtkLabel *) curWord, curWordStr->value );
	//printf("curWord = %s\n", curWordStr->value );
	printf("out of clear()\n");
	return;
}

void del() {
	printf("in del()\n");
	if(isCycling) {
		clear();

		printf("out of del()\n");
		return;
	}

	String_del(curWordStr, 1);

	gtk_label_set_text( (GtkLabel *) curWord, curWordStr->value );
	//printf("curWord = %s\n", curWordStr->value );

	printf("out of del()\n");
	return;
}

