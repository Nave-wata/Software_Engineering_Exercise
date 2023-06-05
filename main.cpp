/**
 * @file main.cpp
 * 
 * @brief main関数のソースファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-06-04
 */

#include <ncurses.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

#include "views/SelectPlayerForm.hpp"
#include "views/CreateOrJoinRoomForm.hpp"
#include "views/CreateRoomForm.hpp" 
#include "views/JoinRoomForm.hpp"
#include "views/UserNameForm.hpp"
#include "views/PlayBoard.hpp"

/**
 * @brief main関数
 * 
 * @return int 終了コード
 */
int main() {
    initscr();
    cbreak();
    curs_set(0);
    start_color();
    keypad(stdscr, TRUE);
    noecho();
    timeout(-1);
    refresh();

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    // SelectPlayerForm *selectPlayerForm = new SelectPlayerForm();
    // selectPlayerForm->showForm();
    // delete selectPlayerForm;

    // CreateOrJoinRoomForm *createOrJoinRoomForm = new CreateOrJoinRoomForm();
    // createOrJoinRoomForm->showForm();
    // delete createOrJoinRoomForm;

    // CreateRoomForm *createRoomForm = new CreateRoomForm("Please enter the room name.", "Room name: ");
    // createRoomForm->showForm();
    // delete createRoomForm;

    // JoinRoomForm *joinRoomForm = new JoinRoomForm();
    // joinRoomForm->showForm();
    // delete joinRoomForm;

    // UserNameForm *userNameForm = new UserNameForm("Please enter the user name.", "User name: ");
    // userNameForm->showForm();
    // delete userNameForm;

    PlayBoard playBoard = PlayBoard(yMax / 2, xMax / 2);
    playBoard.showBoard();

    getch();

    endwin();
    return 0;
}