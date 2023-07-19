/**
 * @file NextPuyoController.cpp
 * 
 * @brief NextPuyoControllerクラスのソースファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-07-18
 */

#include "controllers/NextPuyoController.hpp"

/**
 * @brief 次のぷよフィールド
 * 
 * @param y int フィールドを表示するウィンドウの中央のy座標
 * @param x int フィールドを表示するウィンドウの中央のx座標
 */
NextPuyoController::NextPuyoController(const int y, const int x)
    : field(y, x) {}

/**
 * @brief 次のぷよをセットする
 */
void NextPuyoController::show() {
    this->field.showField();
}

/**
 * @brief 次のぷよを生成する
 */
std::array<PuyoState, 2> NextPuyoController::create() {
    this->next_puyos = this->service.create();
    this->field.updateField(this->next_puyos[0], this->next_puyos[1]);
    return this->next_puyos;
}

/**
 * @brief 次のぷよを生成し，フィールドにセットする
 * 
 * @return std::array<PuyoState, 2> 
 */
std::array<PuyoState, 2> NextPuyoController::update() {
    std::array<PuyoState, 2> res = this->next_puyos;
    this->next_puyos = this->service.create();
    this->field.updateField(this->next_puyos[0], this->next_puyos[1]);
    return res;
}
