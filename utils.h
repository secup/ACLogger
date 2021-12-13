#ifndef __UTILS_H__
#define __UTILS_H__
#if __FreeBSD__
#include <ncurses/curses.h>
#else
#include <ncursesw/curses.h>
#endif

void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string);

#endif
