/**
 * @file PuyoGravityService.hpp
 * 
 * @brief PuyoGravityServiceクラスのヘッダファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-07-19
 */

#pragma once

class PuyoGravityService {
    private:
        /** @brief 落下速度 */
        const int time;

        const int tick;

        int count;

    public:
        PuyoGravityService(const int time);
        bool gravity();
};