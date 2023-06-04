/**
 * @file NuisancePuyoField.cpp
 * 
 * @brief NuisancePuyoFieldクラスのソースファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-06-04
 */

#include "views/NuisancePuyoField.hpp"

/**
 * @brief コンストラクタ
 * 
 * @param y int フィールドを表示するウィンドウの中央のy座標
 * @param x int フィールドを表示するウィンドウの中央のx座標
 */
NuisancePuyoField::NuisancePuyoField(const int y, const int x)
    : DynamicField(y, x), cntNuisancePuyo(0) {
    for (int i = 0; i < this->CELL_WIDTH; i++) {
        this->nuisancePuyos[i].setState(PuyoState::NUISANCE);
        this->nuisancePuyos[i].setWin(newwin(
            1, 1,
            this->FIELD_CENTER_Y - this->FIELD_HEIGHT / 2 + this->FIELD_MOVE_Y,
            this->FIELD_CENTER_X - this->FIELD_WIDTH / 2 + this->FIELD_MOVE_X + (i * this->ONE_CHARACTER_WIDTH)
        ));
    }
}

/**
 * @brief デストラクタ
 */
NuisancePuyoField::~NuisancePuyoField() {}

/**
 * @brief おじゃまぷよフィールドを表示する
 * 
 * @return void
 */
void NuisancePuyoField::showField() {
    this->updateField();
}

/**
 * @brief おじゃまぷよフィールドを更新する
 * 
 * @return void
 */
void NuisancePuyoField::updateField() {
    int i = 0;
    int n1 = 1;
    int n2 = n1 * this->CELL_WIDTH;
    int n3 = n2 * this->CELL_WIDTH;
    int cnt = cntNuisancePuyo;

    while (i < this->CELL_WIDTH) {
        if (cnt / n3 > 0) { 
            nuisancePuyos[i].showPuyo('@');
            cnt -= n3;
        } else if (cnt / n2 > 0) {
            nuisancePuyos[i].showPuyo('0');
            cnt -= n2;
        } else if (cnt / n1 > 0) {
            nuisancePuyos[i].showPuyo('o');
            cnt -= n1;
        } else nuisancePuyos[i].showPuyo(' ');
        i++;
    }
}

/**
 * @brief おじゃまぷよの数を更新する
 * 
 * @param cntNuisancePuyo int 変化させるおじゃまぷよの数 (正・負)
 * @return void
 */
void NuisancePuyoField::updateField(const int cntNuisancePuyo) {
    this->addNuisancePuyo(cntNuisancePuyo);
    this->updateField();
}

/**
 * @brief おじゃまぷよの数を追加する
 * 
 * @param cntNuisancePuyo 増加させるおじゃまぷよの数
 * @return void
 */
void NuisancePuyoField::addNuisancePuyo(const int cntNuisancePuyo) {
    this->cntNuisancePuyo += cntNuisancePuyo;
}

/**
 * @brief おじゃまぷよの数を減少させる
 * 
 * @param cntNuisancePuyo 減少させるおじゃまぷよの数
 * @return void
 */
void NuisancePuyoField::subNuisancePuyo(const int cntNuisancePuyo) {
    this->cntNuisancePuyo -= cntNuisancePuyo;
}
