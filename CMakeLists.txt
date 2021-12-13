cmake_minimum_required(VERSION 3.10)

project(cool_logger C)

if (${CMAKE_SYSTEM_NAME} MATCHES "FreeBSD")
	message("FreeBSD Detected! Doing some different includes (WIDE Support is activated by default), I hope you installed ncurses into /usr/local")
	include_directories("/usr/local/include")
	link_directories("/usr/local/lib")
else()
	# Other standard OS with ncursesw folder
set(CURSES_NEED_NCURSES)
set(CURSES_NEED_WIDE TRUE)

endif()
find_package(Curses REQUIRED)
add_executable(logger main.c status_win.c utils.c menu.c)

target_link_libraries(logger PUBLIC ncursesw)

