/**
 * @file BaseBox.cpp
 * 
 * @brief BaseBoxクラスのソースファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-06-02
 */

#include "views/BaseBox.hpp"

/**
 * @brief コンストラクタ
 */
BaseBox::BaseBox() {
    getmaxyx(stdscr, this->y, this->x);
    this->center_y = this->y / 2;
    this->center_x = this->x / 2;
}

/**
 * @brief デストラクタ
 */
BaseBox::~BaseBox() {
    delwin(this->win);
}

/**
 * ボックスを表示する
 * 
 * @param rows 表示するボックスの行数
 * @param cols 表示するボックスの列数
 * @param y 表示するボックスのy座標
 * @param x 表示するボックスのx座標
 * @return void
*/
void BaseBox::showBox(const int rows, const int cols, const int y, const int x) {
    this->win = newwin(rows, cols, y, x);

    getmaxyx(this->win, this->box_y, this->box_x);
    this->box_center_y = this->box_y / 2;
    this->box_center_x = this->box_x / 2;

    box(this->win, 0, 0);
}