#if __FreeBSD__
#include <ncurses/curses.h>
#include <ncurses/menu.h>
#else
#include <ncursesw/curses.h>
#endif

#include <stdio.h>

void acl_menu_init(void);
void acl_print_menu(void);
void acl_process_menu_input(void);
void acl_menu_clearup(void);
