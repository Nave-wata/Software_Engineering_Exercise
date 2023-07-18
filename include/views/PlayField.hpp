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

#include <array>

#include "views/BaseBox.hpp"
#include "views/DynamicField.hpp"
#include "views/Puyo.hpp"

/**
 * @brief 座標を表す構造体
 */
typedef struct {
    int y;
    int x;
} coordinate;

/**
 * @brief プレイフィールドを表すクラス
 */
class PlayField: public BaseBox, DynamicField {
    public:
        /** @brief ぷよを管理するセルの行数 */
        static const int CELL_HEIGHT = 10;

        /** @brief ぷよを管理するセルの列数 */
        static const int CELL_WIDTH = 6;

    private:
        /** @brief プレイフィールドの行数 */
        static const int FIELD_BOX_HEIGHT = 12;

        /** @brief プレイフィールドの列数 */
        static const int FIELD_BOX_WIDTH = 14;

        /** @brief 1文字を表示するのに使用する列数 */
        const int ONE_CHARACTER_WIDTH = 2;

        /** @brief フレーム数 ＋ 最後のぷよの右にマスが入らないように */
        const int CELL_CENTER_X = 2 + 1;

        /** @brief プレイフィールド上に存在するセル一覧 */
        std::array<std::array<Puyo, PlayField::CELL_WIDTH>, PlayField::CELL_HEIGHT> puyos;

    public:
        PlayField(const int y, const int x);
        ~PlayField();
        void showField();
        std::array<std::array<PuyoState, PlayField::CELL_WIDTH>, PlayField::CELL_HEIGHT> getStates();
        std::array<std::array<Puyo, PlayField::CELL_WIDTH>, PlayField::CELL_HEIGHT>& referencePuyo();
        void createPuyo(const int y, const int x, const PuyoState puyo);
        inline void movePuyo(const int from_y, const int from_x, const int to_y, const int to_x);
        inline void deletePuyo(const int y, const int x);

    protected:
        /** @brief 使用しない・何もしない */
        void updateField() override {}

        /** @brief 使用しない・何もしない */
        void showContents() override {}

        /** @brief 使用しない・何もしない */
        void keyWait() override {}
};
