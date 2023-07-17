/**
 * @file ScreenSizeValidation.cpp
 * 
 * @brief ScreenSizeValidationクラスのソースファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-06-30
 */

#include "validations/ScreenSizeValidation.hpp"
#include "exceptions/ScreenSizeException.hpp"
#include <ncurses.h>
#include <iostream>

/**
 * @brief ScreenSizeValidationクラスのコンストラクタ
 * 
 * 画面のサイズをメンバ変数に格納する
 */
ScreenSizeValidation::ScreenSizeValidation() {
    getmaxyx(stdscr, this->screen_rows, this->screen_cols);
}

/**
 * @brief 画面サイズの検証
 * 
 * 画面サイズが小さい場合は例外を投げる
 * 
 * @param n int プレイヤーの人数
 */
void ScreenSizeValidation::validation(const int n) {
    int need_screen_cols = this->MIN_SCREEN_COLS + (this->ADD_SCREEN_COLS * (n - 1));
    int need_screen_rows = this->MIN_SCREEN_ROWS;

    if (this->screen_cols < need_screen_cols || this->screen_rows < need_screen_rows) {
        std::cerr << "Exception: " << std::endl;
        throw ScreenSizeException("画面サイズが小さすぎます");
    }
}

