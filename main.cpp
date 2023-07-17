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

#include "controllers/CreateRoomController.hpp"
#include "controllers/JoinRoomController.hpp"
#include <iostream>
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

int main(int argc, char* argv[]) {
    char c = argv[0][0];
    c++;

    if (argc == 1) {
        mainInit();

        CreateRoomController createRoomController;
        std::string room_name = createRoomController.inputRoomName();
        std::vector<playerInfo> player_infos = createRoomController.createRoom(room_name, 1);

        mainDestroy();

        for (auto player_info : player_infos) {
            std::cout << player_info.room_name << std::endl;
            std::cout << player_info.ip << std::endl;
        }

    } else {
        mainInit();

        JoinRoomController joinRoomController;
        RoomInfo room_info = joinRoomController.show();
        std::vector<playerInfo> player_infos = joinRoomController.joinRoom(room_info, 1);

        mainDestroy();

        for (auto player_info : player_infos) {
            std::cout << player_info.room_name << std::endl;
            std::cout << player_info.ip << std::endl;
        }
    }

    return 0;
}