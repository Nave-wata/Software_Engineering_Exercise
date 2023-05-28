#include <ncurses.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

#include "SelectPlayerMenu.hpp"

int main(int argc, char **argv) {
    initscr();
    cbreak();
    curs_set(0);
    start_color();
    keypad(stdscr, TRUE);
    noecho();
    timeout(-1);
    refresh();

    SelectPlayerMenu selectPlayerMenu = SelectPlayerMenu();
    selectPlayerMenu.showMenu();

    endwin();
    return 0;
}