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
 * @param all_clear_magnification 全消し時の倍率
 */
ScoreController::ScoreController(const int y, const int x, const int all_clear_magnification)
    : field(y, x)
    , service(all_clear_magnification) {}

/**
 * @brief スコアを表示する
 */
void ScoreController::show() {
    this->field.showField();
}

/**
 * @brief スコアを更新する 
 * 
 * @param deleted_puyos 削除されたぷよ
 * @param chain 現在の連鎖数
 * @param isAllClear 全消しされたかどうか
 * @return int 加算するスコア
 */
int ScoreController::update(
    std::vector<std::vector<puyoInfo>> deleted_puyos, 
    const int chain, 
    const bool isAllClear
) {
    int score = this->service.calculation(deleted_puyos, chain, isAllClear);
    this->field.updateField(score);
    return score;
}