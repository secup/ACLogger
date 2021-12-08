#ifndef __UTILS_H__
#define __UTILS_H__
#include <ncurses/curses.h>

void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string);

void updateStatusWindowText(WINDOW *win, int startx, int starty, char *string);

#endif
