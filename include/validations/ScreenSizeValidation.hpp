/**
 * @file ScreenSizeValidation.hpp
 * 
 * @brief ScreenSizeValidationクラスのヘッダファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-06-30
 */

#pragma once

class ScreenSizeValidation {
    private:
        /** @brief ゲームプレイに必要な最小画面行数 */
        const int MIN_SCREEN_COLS = 50;

        /** @brief ゲームプレイに必要な最小画面列数 */
        const int MIN_SCREEN_ROWS = 20;

        /** @brief プレイ人数増加に伴う必要画面の増加行数 */
        const int ADD_SCREEN_COLS = 25;

        /** @brief 画面の列数 */
        int screen_cols;

        /** @brief 画面の行数 */
        int screen_rows;

    public:
        ScreenSizeValidation();
        void validation(const int n);
};