#include <ncurses.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

#include "views/SelectPlayerForm.hpp"

int main(int argc, char **argv) {
    initscr();
    cbreak();
    curs_set(0);
    start_color();
    keypad(stdscr, TRUE);
    noecho();
    timeout(-1);
    refresh();

    SelectPlayerForm selectPlayerForm = SelectPlayerForm();
    selectPlayerForm.showForm();

    endwin();
    return 0;
}