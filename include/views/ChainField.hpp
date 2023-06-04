/**
 * @file ChainField.hpp
 * 
 * @brief ChainFieldクラスのヘッダファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-06-04
 */

#pragma once

#include "views/DynamicField.hpp"
#include <ncurses.h>

/**
 * @brief 連鎖数を表示するフィールドを表示・更新する
 */
class ChainField : public DynamicField {
    private:
        /** @brief フィールドの行数 */
        const int FIELD_HEIGHT = 2;

        /** @brief フィールドの列数 */
        const int FIELD_WIDTH = 5;

        /** @brief フィールドを縦方向に移動させる */
        const int FIELD_MOVE_Y = 2;

        /** @brief フィールドを横方向に移動させる */
        const int FIELD_MOVE_X = 9;

        /** @brief 連鎖数 */
        int chain;

        /** @brief フィールドのウィンドウ */
        WINDOW* win;

    public:
        ChainField(const int y, const int x);
        ~ChainField();
        void showField() override;
        void updateField() override;
        void updateField(const int chain);
        void setChain(const int chain);
};
