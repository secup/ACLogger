#define _XOPEN_SOURCE_EXTENDED

#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ncursesw/curses.h>
#include "status_win.h"
#include "utils.h"

int main (int argc, char *agrv[]) {

    setlocale(LC_ALL, "");

    WINDOW *statusWindow;

    initscr();
    noecho();
    
    int hasColor = has_colors();

    if (!hasColor) {
        fprintf(stderr, "Sorry OM, your terminal seems a bit too old and lacks colors\n");
        endwin();
        return 0;
    }

    start_color();

    init_pair(1, COLOR_WHITE, COLOR_BLUE);

    wbkgd(stdscr, COLOR_PAIR(1));
    box(stdscr,0 ,0);
    refresh();

    print_in_middle(NULL, 0, 0, 0, "COOL LOGGER");

    // Deal with status window
    statusWindow = create_status_window();
    print_in_middle(statusWindow, 0, 0, 0,"Status Bar");
    wrefresh(statusWindow);

    getch();

    endwin();
    return 0;
}
