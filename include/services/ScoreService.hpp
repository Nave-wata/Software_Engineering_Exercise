/**
 * @file ScoreService.hpp
 * 
 * @brief ScoreServiceクラスのヘッダファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-07-19
 */

#pragma once

#include "services/PuyoDeleteService.hpp"
#include <vector>

class ScoreService {
    private:
        /** @brief 消えたぷよの情報 */
        std::vector<std::vector<puyoInfo>> deleted_puyos;

        /** @brief 連鎖数 */
        int chain;

    public:
        ScoreService();
        int calculation(
            const std::vector<std::vector<puyoInfo>> deleted_puyos,
            const int chain
        );

    private:
        int calcDeletedPuyo();
        int calcChain();
        int calcMoreDeletedPuyo();
        int calcDeletedPuyoColor();
};