/**
 * @file Playing.cpp
 * 
 * @brief Playingクラスのソースファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-07-19
 */

#include "Playing.hpp"

/**
 * @brief Playingクラスのコンストラクタ
 * 
 * @param settings ファイルから読み込んだ設定
 * @param player_info プレイヤー情報
 * @param player_num プレイヤー人数
 */
Playing::Playing(const Settings settings, const std::vector<playerInfo> player_info, const int player_num)
    : settings(settings)
    , player_info(player_info)
    , player_num(player_num) {}

void Playing::initScreen() {
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);
    int y = yMax / 2;
    int x = xMax / 2;

    if (player_num == 1) {
        PlayBoard play_board(y, x, settings);
        play_board.show();
    }

    if (player_num == 2) {
        PlayBoard play_board1(y, x - PLAY_BOARD_WIDTH, settings);
        PlayBoard play_board2(y, x + PLAY_BOARD_WIDTH, settings);
        play_board1.show();
    }
}
