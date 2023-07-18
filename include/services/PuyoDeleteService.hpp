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

class PuyoDeleteService {
    private:
        /** @brief 探索中のぷよ */
        std::vector<coordinate> deleted_puyos;

    public:
        std::vector<std::vector<coordinate>> deletePuyos(
            std::array<std::array<PuyoState, PlayField::CELL_WIDTH>, PlayField::CELL_HEIGHT> puyo_states
        );
        std::vector<coordinate> deletePuyo(
            std::array<std::array<PuyoState, PlayField::CELL_WIDTH>, PlayField::CELL_HEIGHT> puyo_states,
            const int y,
            const int x
        );
};