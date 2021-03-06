#define _XOPEN_SOURCE_EXTENDED

#include <stdio.h>
#include <string.h>
#include <locale.h>
#if __FreeBSD__
// why not seperate headers for wide support?!?!? 
#include <ncurses/curses.h>
#endif
#if __linux__
#include <ncursesw/curses.h>
#endif
#include "status_win.h"
#include "utils.h"
#include "menu.h"

int main (int argc, char *agrv[]) {

    setlocale(LC_ALL, "");

    WINDOW *statusWindow;
    WINDOW *qsoDetailsWin;
    WINDOW *extendedWin;
    WINDOW *popupWin;

    initscr();
    noecho();
    cbreak();
    
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

    updateStatusWindowText(statusWindow, 1, 1, "Starting Up...");

    wrefresh(statusWindow);

    acl_menu_init();
    acl_print_menu();


    refresh();

    // Send user into the menu
    acl_process_menu_input();


    acl_menu_clearup();
    endwin();
    return 0;
}
