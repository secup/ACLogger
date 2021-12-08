#include <string.h>
#include "utils.h"


void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string)
{	int length, x, y, maxwidth, maxlength;
	float temp;

	if(win == NULL)
		win = stdscr;
	getyx(win, y, x);
	if(startx != 0)
		x = startx;
	if(starty != 0)
		y = starty;
	if(width == 0) {
        getmaxyx(win, maxlength, maxwidth);
		width = maxwidth;
    }

	length = strlen(string);
	temp = (width - length)/ 2;
	x = startx + (int)temp;
	mvwprintw(win, y, x, "%s", string);
	refresh();
}

void updateStatusWindowText(WINDOW *win, int startx, int starty, char *string) {
    if (!win) { return; }

    int width, length;

    // Get window length and erase that line.
    getmaxyx(win, length, width);

    mvwaddstr(win, starty, startx, string); 
    
    wrefresh(win);

}
