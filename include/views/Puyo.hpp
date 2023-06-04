/**
 * @file Puyo.hpp
 * 
 * @brief Puyoクラスのヘッダファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-06-04
 */

#pragma once

#include <ncurses.h>

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
 * @brief 1つのぷよを表すクラス
 * 
 * プレイフィールドに複数のセルが存在し，
 * それぞれのセルにでぷよの位置・状態を管理する
 */
class Puyo {
    private:
        /** @brief ぷよの状態 */
        PuyoState state;

        /** @brief ぷよを表示するウィンドウ */
        WINDOW *win;

    public:
        Puyo();
        ~Puyo();
        PuyoState getState();
        void setState(const PuyoState state);
        WINDOW* getWin();
        void setWin(WINDOW* win);
        void showPuyo();
};