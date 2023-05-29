#include "views/BaseBox.hpp"

// コンストラクタ
BaseBox::BaseBox() {
    getmaxyx(stdscr, this->y, this->x);
    this->center_y = this->y / 2;
    this->center_x = this->x / 2;
}

// デストラクタ
BaseBox::~BaseBox() {}

// メニューボックスを表示する
void BaseBox::showBox(const int rows, const int cols, const int y, const int x) {
    this->win = newwin(rows, cols, y, x);

    getmaxyx(this->win, this->box_y, this->box_x);
    this->box_center_y = this->box_y / 2;
    this->box_center_x = this->box_x / 2;

    box(this->win, 0, 0);
}