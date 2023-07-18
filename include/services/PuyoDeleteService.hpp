/**
 * @file PuyoDeleteService.hpp
 * 
 * @brief PuyoDeleteServiceクラスのヘッダファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-07-18
 */

#pragma once

#include "views/PlayField.hpp"
#include <vector>

typedef struct {
    coordinate cit;
    PuyoState state;
} puyoInfo;

class PuyoDeleteService {
    private:
        /** @brief 探索中のぷよ */
        std::vector<puyoInfo> deleted_puyos;

    public:
        std::vector<std::vector<puyoInfo>> deletePuyos(
            std::array<std::array<PuyoState, PlayField::CELL_WIDTH>, PlayField::CELL_HEIGHT> puyo_states
        );
        std::vector<puyoInfo> deletePuyo(
            std::array<std::array<PuyoState, PlayField::CELL_WIDTH>, PlayField::CELL_HEIGHT> puyo_states,
            const int y,
            const int x
        );
};