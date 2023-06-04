/**
 * @file Puyo.cpp
 * 
 * @brief Puyoクラスのソースファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-06-04
 */

#include "views/Puyo.hpp"

/**
 * @brief コンストラクタ
 */
Puyo::Puyo() {
    // ぷよのカラーセットを作成する
    init_pair(static_cast<int>(PuyoState::RED), COLOR_RED, COLOR_BLACK);
    init_pair(static_cast<int>(PuyoState::BLUE), COLOR_BLUE, COLOR_BLACK);
    init_pair(static_cast<int>(PuyoState::GREEN), COLOR_GREEN, COLOR_BLACK);
    init_pair(static_cast<int>(PuyoState::NUISANCE), COLOR_WHITE, COLOR_BLACK);
}

/**
 * @brief デストラクタ
 */
Puyo::~Puyo() {
    delwin(win);
}

/**
 * @brief ぷよの状態を取得する
 * 
 * @return PuyoState ぷよの状態
 */
PuyoState Puyo::getState() {
    return this->state;
}

/**
 * @brief ぷよの状態を設定する
 * 
 * @param state PuyoState ぷよの状態
 */
void Puyo::setState(const PuyoState state) {
    this->state = state;
}

/**
 * @brief ぷよを表示するウィンドウを取得する
 * 
 * @return WINDOW* 
 */
WINDOW* Puyo::getWin() {
    return this->win;
}

/**
 * @brief ぷよを表示するウィンドウを設定する
 * 
 * @param win 
 * @return void
 */
void Puyo::setWin(WINDOW* win) {
    this->win = win;
}

/**
 * @brief ぷよを表示する
 * 
 * @param c char ぷよを表示するときの文字
 * @return void
 */
void Puyo::showPuyo(char c) {
    if (this->state == PuyoState::NONE) waddch(this->win, COLOR_PAIR(PuyoState::NONE)|' ');
    else if (this->state == PuyoState::RED) waddch(this->win, COLOR_PAIR(PuyoState::RED)|c);
    else if (this->state == PuyoState::BLUE) waddch(this->win, COLOR_PAIR(PuyoState::BLUE)|c);
    else if (this->state == PuyoState::GREEN) waddch(this->win, COLOR_PAIR(PuyoState::GREEN)|c);
    else if (this->state == PuyoState::NUISANCE) waddch(this->win, COLOR_PAIR(PuyoState::NUISANCE)|c);
    wrefresh(this->win);
}