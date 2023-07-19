/**
 * @file PuyoGravityService.cpp
 * 
 * @brief PuyoGravityServiceクラスのソースファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-07-19
 */

#include "services/PuyoGravityService.hpp"
#include "utils/Sleep.hpp"

/**
 * @brief PuyoGravityServiceクラスのコンストラクタ
 * 
 * @param gravity 落下速度
 */
PuyoGravityService::PuyoGravityService(const int time)
    : time(time)
    , tick(10)
    , count(0) {}

bool PuyoGravityService::gravity() {
    if (this->count >= this->time) this->count = 0;

    Sleep::milliSleep(this->tick);
    this->count += this->tick;

    return this->count >= this->time;
}

