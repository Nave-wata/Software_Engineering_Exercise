/**
 * @file ScoreField.hpp
 * 
 * @brief ScoreFieldクラスのヘッダファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-06-04
 */

#pragma once

#include "views/DynamicField.hpp"
#include <ncurses.h>

/**
 * @brief スコアフィールドクラス
 * 
 * プレイヤー1人あたりに表示されるスコアを表示・更新する
 */
class ScoreField: DynamicField {
    private:
        /** @brief スコアフィールドの行数 */
        const int FIELD_BOX_HEIGHT = 3;

        /** @brief スコアフィールドの列数 */
        const int FIELD_BOX_WIDTH = 13;

        /** @brief スコアをぷよフィールドの下に表示されるようにする */
        const int SCORE_CENTER_Y = 7;

        /** @brief スコアの桁数 */
        const int SCORE_LENGTH = 11;

        /** @brief スコア */
        int score;

        /** @brief フィールドを表示するウィンドウ */
        WINDOW *win;

    public:
        ScoreField(const int y, const int x);
        ~ScoreField();
        void showField();
        void updateField() override;
        void updateField(const int score);
        inline int getScore();
        inline void setScore(const int score);

    private:
        inline const char* toCharScore();
};
