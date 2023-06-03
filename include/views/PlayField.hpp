/**
 * @file PlayField.hpp
 * 
 * @brief PlayFieldクラスのヘッダファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-06-03
 */

#pragma once

#include "views/BaseBox.hpp"
#include "views/DynamicField.hpp"

/**
 * @brief 該当セルにおけるぷよの状態
 */
enum class PuyoState {
    NONE,
    RED,
    BLUE,
    GREEN,
};

/**
 * @brief 1つのぷよを表すことが可能なセルの構造体
 * 
 * プレイフィールドに複数のセルが存在し，
 * それぞれのセルにでぷよの位置・状態を管理する
 * 
 * @param puyo ぷよの状態
 * @param win ぷよを表示するためのウィンドウ
 */
typedef struct {
    PuyoState puyo;
    WINDOW* win;
} cell;

class PlayField: public BaseBox, DynamicField {
    public:
        /** @brief フィールド上に存在するぷよの状態(なにもない) */
        const PuyoState NONE = PuyoState::NONE;

        /** @brief フィールド上に存在するぷよの状態(赤) */
        const PuyoState RED = PuyoState::RED;

        /** @brief フィールド上に存在するぷよの状態(青) */
        const PuyoState BLUE = PuyoState::BLUE;

        /** @brief フィールド上に存在するぷよの状態(緑) */
        const PuyoState GREEN = PuyoState::GREEN;

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
        cell cells[CELL_HEIGHT][CELL_WIDTH];

        /** @brief 前回プレイフィールド上に存在したセル一覧 */
        cell prev_cells[CELL_HEIGHT][CELL_WIDTH];

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
