/**
 * @file ChainController.cpp
 * 
 * @brief ChainControllerクラスのソースファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-07-19
 */

#include "controllers/ChainController.hpp"
#include <iostream>

/**
 * @brief コンストラクタ
 * 
 * @param y 表示するy座標
 * @param x 表示するx座標
 */
ChainController::ChainController(const int y, const int x)
    : field(y, x) {}

/**
 * @brief 連鎖数を表示する
 */
void ChainController::show() {
    this->field.showField();
}

/**
 * @brief 連鎖数を更新する
 * 
 * @param chain 現在の連鎖数
 * @return int 
 */
int ChainController::update(const int chain) {
    if (this->service.isUpdate(chain)) {
        int show_chain = this->service.chain(chain);
        this->field.updateField(show_chain);
        return show_chain;
    }
    return chain;
}