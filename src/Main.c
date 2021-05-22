#include <gtk/gtk.h>

GtkWidget *window,
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
	"1", "2", "3", 
	"4", "5", "6", 
	"7", "8", "9", 
	"C", "0", "S" 
	}; 


int main(int argc, char* argv[]) {

	gtk_init(&argc, & argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Project T9");
	gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_container_set_border_width(GTK_CONTAINER(window), 5);

	grid = gtk_grid_new();
	gtk_grid_set_row_spacing(GTK_GRID(grid), 2);
	gtk_grid_set_column_spacing(GTK_GRID(grid), 2);

	for(int line = 0, pos = 0; line < 4; line++)
		for(int col = 0; col < 3; col++) {
			buttons[pos] = gtk_button_new_with_label(buttonLabels[pos]);
			gtk_grid_attach(GTK_GRID(grid), buttons[pos], col, line, 1, 1);
			pos++;
		}

	gtk_container_add(GTK_CONTAINER(window), grid);

	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

	gtk_widget_show_all(window);

	gtk_main();

	return 0;
}

