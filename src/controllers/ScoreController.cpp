/**
 * @file ScoreController.cpp
 * 
 * @brief ScoreControllerクラスのソースファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-07-19
 */

#include "controllers/ScoreController.hpp"

/**
 * @brief ScoreControllerクラスのコンストラクタ
 * 
 * @param y 表示する位置の中央のy座標
 * @param x 表示する位置の中央のx座標
 */
ScoreController::ScoreController(const int y, const int x)
    : field(y, x), service() {}

/**
 * @brief スコアを表示する
 */
void ScoreController::show() {
    this->field.showField();
}

int ScoreController::update(std::vector<std::vector<puyoInfo>> deleted_puyos, const int chain) {
    int score = this->service.calculation(deleted_puyos, chain);
    this->field.updateField(score);
    return score;
}