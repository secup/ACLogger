#include "status_win.h"

WINDOW* create_status_window() {

    WINDOW *statusWindow;
    statusWindow = newwin(3, COLS-2, LINES-4, 1);
    if (!statusWindow) {
        fprintf(stderr, "Hmmm, could not create the status window, this is not recoverable!\n");

    }
    box(statusWindow,0 ,0);

    return statusWindow;
}

void updateStatusWindowText(WINDOW *win, int startx, int starty, char *string) {
    if (!win) { return; }

    int width, length;

    // Get window length and erase that line.
    getmaxyx(win, length, width);

    mvwaddstr(win, starty, startx, string); 
    
    wrefresh(win);

}
