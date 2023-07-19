/**
 * @file PlayBoard.hpp
 * 
 * @brief PlayBoardクラスのヘッダファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-07-19
 */

#pragma once

#include "ReadSettings.hpp"
#include "Playing.hpp"
#include "controllers/ChainController.hpp"
#include "controllers/NextPuyoController.hpp"
#include "controllers/PlayFieldController.hpp"
#include "controllers/ScoreController.hpp"

class PlayBoard {
    private:
        /** @brief ChainControllerクラスのコントローラ */
        ChainController chain_controller;

        /** @brief NextPuyoControllerクラスのコントローラ */
        NextPuyoController next_puyo_controller;

        /** @brief PlayFieldControllerクラスのコントローラ */
        PlayFieldController play_field_controller;

        /** @brief ScoreControllerクラスのコントローラ */
        ScoreController score_controller;

        /** @brief ファイルから読み込んだ各設定 */
        const Settings settings;

        /** @brief 1リプレイかどうか */
        const bool single;

        std::array<PuyoState, 2> next_puyos;

        int score;

    public:
        PlayBoard(const int y, const int x, const Settings settings, const bool single=true);
        void show();
};