cmake_minimum_required(VERSION 3.10)

project(cool_logger C)

set(CURSES_NEED_NCURSES)
set(CURSES_NEED_WIDE TRUE)
find_package(Curses REQUIRED)
add_executable(logger main.c status_win.c utils.c)

target_link_libraries(logger PUBLIC ncursesw)

