#include <ncurses.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

#include "views/SelectPlayerForm.hpp"
#include "views/CreateOrJoinRoomForm.hpp"
#include "views/CreateRoomForm.hpp" 
#include "views/JoinRoomForm.hpp"

int main() {
    initscr();
    cbreak();
    curs_set(0);
    start_color();
    keypad(stdscr, TRUE);
    noecho();
    timeout(-1);
    refresh();

    // SelectPlayerForm *selectPlayerForm = new SelectPlayerForm();
    // selectPlayerForm->showForm();
    // delete selectPlayerForm;

    // CreateOrJoinRoomForm *createOrJoinRoomForm = new CreateOrJoinRoomForm();
    // createOrJoinRoomForm->showForm();
    // delete createOrJoinRoomForm;

    // CreateRoomForm *createRoomForm = new CreateRoomForm();
    // createRoomForm->showForm();
    // delete createRoomForm;

    JoinRoomForm *joinRoomForm = new JoinRoomForm();
    joinRoomForm->showForm();
    delete joinRoomForm;

    endwin();
    return 0;
}