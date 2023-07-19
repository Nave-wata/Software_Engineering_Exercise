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

#include "ReadSettings.hpp"
#include "PlaySettings.hpp"
#include "Playing.hpp"

#include <stdexcept>

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
    atexit(mainDestroy);

    ReadSettings read_settings;
    Settings settings = read_settings.read();

    while (true) {
        Playing playing(settings, 1);
        playing.initScreen();
        
        clear();
        refresh();
    }

    return 0;
}