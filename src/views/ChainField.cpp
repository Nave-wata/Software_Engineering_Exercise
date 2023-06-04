/**
 * @file ChainField.cpp
 * 
 * @brief ChainFieldクラスのソースファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-06-04
 */

#include "views/ChainField.hpp"

/**
 * @brief コンストラクタ
 */
ChainField::ChainField(const int y, const int x): DynamicField(y, x), chain(0) {}

/**
 * @brief デストラクタ
 */
ChainField::~ChainField() {
    delwin(this->win);
}

/**
 * @brief フィールドを表示する
 * 
 * @return void
 */
void ChainField::showField() {
    this->win = newwin(
        this->FIELD_HEIGHT,
        this->FIELD_WIDTH,
        this->FIELD_CENTER_Y - this->FIELD_HEIGHT / 2 + this->FIELD_MOVE_Y,
        this->FIELD_CENTER_X - this->FIELD_WIDTH / 2 + this->FIELD_MOVE_X
    );
    this->updateField();
}

/**
 * @brief 連鎖数フィールドを現在の連鎖数で更新する
 * 
 * @return void
 */
void ChainField::updateField() {
    mvwprintw(this->win, 0, 0, "Chain");
    mvwprintw(this->win, 1, 0, "%d", this->chain);
    wrefresh(this->win);
}

/**
 * @brief 連鎖数を更新し，連鎖数フィールドに表示する
 * 
 * @param chain
 * @return void 
 */
void ChainField::updateField(const int chain) {
    this->setChain(chain);
    this->updateField();
}

/**
 * @brief 連鎖数を設定する
 * 
 * @param chain int 連鎖数
 * @return void
 */
void ChainField::setChain(const int chain) {
    this->chain = chain;
}