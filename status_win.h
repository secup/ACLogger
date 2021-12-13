#ifndef __STATUS_WIN_H__
#define __STATUS_WIN_H__

#include <stdio.h>
#include <locale.h>
#include <ncurses/curses.h>

WINDOW* create_status_window(void);
void updateStatusWindowText(WINDOW *win, int startx, int starty, char *string); 

#endif
