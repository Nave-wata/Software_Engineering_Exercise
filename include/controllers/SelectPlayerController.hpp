/**
 * @file SelectPlayerController.hpp
 * 
 * @brief SelectPlayerControllerクラスのヘッダファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-06-27
 */

#pragma once

#include "views/SelectPlayerForm.hpp"
#include "validations/ScreenSizeValidation.hpp"

/**
 * @brief プレイヤー選択画面のフォームクラス
 */
class SelectPlayerController {
    private:
        /** @brief 画面サイズのバリデーションクラス */
        ScreenSizeValidation screen_size_validation;

        /** @brief プレイヤー選択画面のフォームクラス */
        SelectPlayerForm select_player_form;

        /** @brief プレイヤー人数 */
        int player_num = 0;

    public:
        void selectPlayer();
        int getPlayerOfNumber();
        void validation();
};