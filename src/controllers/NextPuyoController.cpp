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
 * @brief 次のぷよを生成し，フィールドにセットする
 * 
 * @return std::array<PuyoState, 2> 
 */
std::array<PuyoState, 2> NextPuyoController::update() {
    std::array<PuyoState, 2> next_puyo = this->service.update();
    this->field.updateField(next_puyo[0], next_puyo[1]);
    return next_puyo;
}
