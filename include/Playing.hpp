/**
 * @file Playing.hpp
 * 
 * @brief Playingクラスのヘッダファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-07-19
 */

#pragma once

#include "ReadSettings.hpp"
#include "PlayBoard.hpp"

class Playing {
    private:
        /** @brief プレイボードに利用する列数 */
        const int PLAY_BOARD_WIDTH = 26;

        /** @brief 設定ファイルから読み込んだ各設定 */
        const Settings settings;

        /** @brief プレイ人数 */
        const int player_num;

    public:
        Playing(const Settings settings, const int player_num);
        void initScreen();
};