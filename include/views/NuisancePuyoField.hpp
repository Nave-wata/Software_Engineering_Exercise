/**
 * @file NuisancePuyoField.hpp
 * 
 * @brief NuisancePuyoFieldクラスのヘッダファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-06-04
 */

#pragma once

#include "views/DynamicField.hpp"
#include "views/Puyo.hpp"
#include <ncurses.h>

/**
 * @brief おじゃまぷよを表示するフィールドを表示・更新する
 */
class NuisancePuyoField : public DynamicField {
    private:
        /** @brief フィールドの行数 */
        const int FIELD_HEIGHT = 1;

        /** @brief フィールドの列数 */
        const int FIELD_WIDTH = 14;

        /** @brief おじゃまぷよの表示個数 */
        static const int CELL_WIDTH = 6;

        /** @brief フィールドを縦方向に移動させる */
        const int FIELD_MOVE_Y = -7;

        /** @brief フィールドを横方向に移動させる */
        const int FIELD_MOVE_X = 1;

        /** @brief 1ぷよを描写するのに使用する文字数 */
        const int ONE_CHARACTER_WIDTH = 2;

        /** @brief おじゃまぷよの数 */
        int cntNuisancePuyo;

        Puyo nuisancePuyos[CELL_WIDTH];

    public:
        NuisancePuyoField(const int y, const int x);
        ~NuisancePuyoField();
        void showField() override;
        void updateField() override;
        void updateField(const int cntNuisancePuyo);
        void addNuisancePuyo(const int cntNuisancePuyo);
        void subNuisancePuyo(const int cntNuisancePuyo);
};