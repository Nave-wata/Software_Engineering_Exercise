/**
 * @file main.cpp
 * 
 * @brief メイン関数
 * 
 * @author Nave-wata
 * 
 * @date 2023-06-23
 */

#include <ncurses.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <iostream>

#include "controllers/CreateOrJoinRoomController.hpp"
#include <iostream>

void mainInit() {
    initscr();
    cbreak();
    curs_set(0);
    start_color();
    keypad(stdscr, TRUE);
    noecho();
    timeout(-1);
    refresh();
}

void mainDestroy() {
    endwin();
}

int main() {
    mainInit();

    CreateOrJoinRoomController controller;
    controller.createOrJoin();

    mainDestroy();

    std::cout << controller.getAction() << std::endl;
    return 0;
}