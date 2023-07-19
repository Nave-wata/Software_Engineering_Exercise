/**
 * @file ScoreService.cpp
 * 
 * @brief ScoreServiceクラスのソースファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-07-19
 */

#include "services/ScoreService.hpp"

/**
 * @brief ScoreServiceクラスのコンストラクタ
 * 
 * @param all_clear_magnification 全消し後のスコア倍率
 */
ScoreService::ScoreService(const int all_clear_magnification)
    : deleted_puyos({})
    , chain(0)
    , all_clear_magnification(all_clear_magnification) {}

/**
 * @brief スコアを計算する
 * 
 * @param deleted_puyos 消えたぷよの座標
 * @param chain 現在の連鎖数
 * @param isAllClear 全消しされたかどうか
 * @return int スコア
 */
int ScoreService::calculation(
    const std::vector<std::vector<puyoInfo>> deleted_puyos,
    const int chain,
    const bool isAllClear
) {
    this->deleted_puyos = deleted_puyos;
    this->chain = chain;

    int score = 
        10 * 
        this->calcDeletedPuyo() * 
        (
            this->calcChain() + 
            this->calcMoreDeletedPuyo() + 
            this->calcDeletedPuyoColor()
        );

    if (isAllClear) {
        score *= this->all_clear_magnification;
    }

    return score;
}

/**
 * @brief 消えたぷよの数を計算する
 * 
 * @return int 消えたぷよの数
 */
int ScoreService::calcDeletedPuyo() {
    int deleted_puyo_num = 0;
    for (const auto& v: this->deleted_puyos) {
        deleted_puyo_num += v.size();
    }
    return deleted_puyo_num;
}

/**
 * @brief 連鎖から求めたスコア計算に用いる要素を計算する
 * 
 * 連鎖数の2倍
 * 
 * @return int 連鎖から求めたスコア計算に用いる要素
 */
int ScoreService::calcChain() {
    return this->chain * 2;
}

/**
 * @brief 消えたぷよの数から求めたスコア計算にもちいる要素を計算する
 * 
 * 同時に消えるのに必要な数より多く消した数
 * 
 * @return int 消えたぷよの数から求めたスコア計算に用いる要素
 */
int ScoreService::calcMoreDeletedPuyo() {
    return this->calcDeletedPuyo() - 4;
}

/**
 * @brief 消えたぷよの色から求めたスコア計算に用いる要素を計算する
 * 
 * 同時に消した色の数 - 1
 * 
 * @return int 消えたぷよの色から求めたスコア計算に用いる要素
 */
int ScoreService::calcDeletedPuyoColor() {
    // RED, BLUE, GREEN
    std::array<bool, 3> color_set = {false, false, false};

    for (const auto& vs: this->deleted_puyos) {
        for (const auto& v: vs) {
            if (v.state == PuyoState::RED) {
                color_set[0] = true;
            } else if (v.state == PuyoState::BLUE) {
                color_set[1] = true;
            } else if (v.state == PuyoState::GREEN) {
                color_set[2] = true;
            }
        }
    }

    int color_num = 0;
    for (const auto& v: color_set) {
        if (v) {
            color_num++;
        }
    }

    return color_num - 1;
}