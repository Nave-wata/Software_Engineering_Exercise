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
        PlaySettings play_settings;
        std::vector<playerInfo> player_info = play_settings.settings();
        int player_num = player_info.size();

        if (player_num == 0) player_num = 1;

        clear();
        refresh();

        Playing playing(settings, player_num);
        playing.initScreen();
        
        clear();
        refresh();
    }

    return 0;
}