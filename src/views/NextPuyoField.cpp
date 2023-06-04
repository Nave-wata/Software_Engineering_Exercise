/**
 * @file NextPuyoField.cpp
 * 
 * @brief NextPuyoFieldクラスのソースファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-06-04
 */

#include "views/NextPuyoField.hpp"

/**
 * @brief コンストラクタ
 * 
 * @param y int フィールドを表示するウィンドウの中央のy座標
 * @param x int フィールドを表示するウィンドウの中央のx座標
 */
NextPuyoField::NextPuyoField(const int y, const int x)
    : DynamicField(y, x) {
        this->puyos[0].setState(PuyoState::NONE);
        this->puyos[0].setWin(newwin(
            1, 1,
            this->FIELD_CENTER_Y - this->FIELD_BOX_HEIGHT / 2 + this->FIELD_MOVE_Y + this->PUYO1_CENTER_Y,
            this->FIELD_CENTER_X - this->FIELD_BOX_WIDTH / 2 + this->FIELD_MOVE_X + this->PUYO_CENTER_X

        ));
        this->puyos[1].setState(PuyoState::NONE);
        this->puyos[1].setWin(newwin(
            1, 1,
            this->FIELD_CENTER_Y - this->FIELD_BOX_HEIGHT / 2 + this->FIELD_MOVE_Y + this->PUYO2_CENTER_Y,
            this->FIELD_CENTER_X - this->FIELD_BOX_WIDTH / 2 + this->FIELD_MOVE_X + this->PUYO_CENTER_X
        ));
    };

/**
 * @brief デストラクタ
 */
NextPuyoField::~NextPuyoField() {};

/**
 * @brief フィールドを表示する
 * 
 * @return void
 */
void NextPuyoField::showField() {
    this->showBox(
        this->FIELD_BOX_HEIGHT,
        this->FIELD_BOX_WIDTH,
        this->FIELD_CENTER_Y - this->FIELD_BOX_HEIGHT / 2 + this->FIELD_MOVE_Y,
        this->FIELD_CENTER_X - this->FIELD_BOX_WIDTH / 2 + this->FIELD_MOVE_X
    );
    wrefresh(this->win);
}

/**
 * @brief フィールドを更新する
 * 
 * @return void
 */
void NextPuyoField::updateField() {
    this->puyos[0].showPuyo();
    this->puyos[1].showPuyo();
}

/**
 * @brief フィールドを更新する
 * 
 * @param puyo1 PuyoState 1つめのぷよ
 * @param puyo2 PuyoState 2つめのぷよ
 * @return void
 */
void NextPuyoField::updateField(const PuyoState puyo1, const PuyoState puyo2) {
    this->createPuyoSet(puyo1, puyo2);
    this->updateField();
}

/**
 * @brief 次のぷよセットを作成する
 * 
 * @param puyo1 PuyoState 1つめのぷよ
 * @param puyo2 PuyoState 2つめのぷよ
 * @return void
 */
void NextPuyoField::createPuyoSet(const PuyoState puyo1, const PuyoState puyo2) {
    this->puyos[0].setState(puyo1);
    this->puyos[1].setState(puyo2);
}