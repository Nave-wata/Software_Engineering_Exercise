/**
 * @file PlayField.hpp
 * 
 * @brief PlayFieldクラスのヘッダファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-06-04
 */

#pragma once

#include "views/BaseBox.hpp"
#include "views/DynamicField.hpp"
#include "views/Puyo.hpp"

/**
 * @brief プレイフィールドを表すクラス
 */
class PlayField: public BaseBox, DynamicField {
    private:
        /** @brief プレイフィールドの行数 */
        static const int FIELD_BOX_HEIGHT = 12;

        /** @brief プレイフィールドの列数 */
        static const int FIELD_BOX_WIDTH = 14;

        /** @brief ぷよを管理するセルの行数 */
        static const int CELL_HEIGHT = 10;

        /** @brief ぷよを管理するセルの列数 */
        static const int CELL_WIDTH = 6;

        /** @brief 1文字を表示するのに使用する列数 */
        const int ONE_CHARACTER_WIDTH = 2;

        /** @brief フレーム数 ＋ 最後のぷよの右にマスが入らないように */
        const int CELL_CENTER_X = 2 + 1;

        /** @brief プレイフィールド上に存在するセル一覧 */
        Puyo puyos[CELL_HEIGHT][CELL_WIDTH];

        /** @brief 前回プレイフィールド上に存在したセル一覧 */
        Puyo prev_puyos[CELL_HEIGHT][CELL_WIDTH];

    public:
        PlayField(const int y, const int x);
        ~PlayField();
        void showField();
        void updateField();
        inline int getPuyo(const int y, const int x);
        inline void createPuyo(const int y, const int x, const PuyoState puyo);
        inline void movePuyo(const int from_y, const int from_x, const int to_y, const int to_x);
        inline void deletePuyo(const int y, const int x);

    protected:
        /** @brief 使用しない・何もしない */
        void showContents() override {}

        /** @brief 使用しない・何もしない */
        void keyWait() override {}
};
