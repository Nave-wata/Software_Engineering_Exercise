/**
 * @file PuyoMoveService.hpp
 * 
 * @brief PuyoMoveServiceクラスのヘッダファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-07-18
 */

#pragma once

#include "views/PlayField.hpp"

enum Direction {
    UP=0,
    DOWN,
    LEFT,
    RIGHT,
    LEFT_ROTATE,
    RIGHT_ROTATE
};

/**
 * @brief プレイフィールドのぷよを動かすサービスクラス
 * 
 */
class PuyoMoveService {
    public:
        bool canMove(
            const coordinate cit, 
            std::array<std::array<PuyoState, PlayField::CELL_WIDTH>, PlayField::CELL_HEIGHT> puyo_states,
            const int direction
        );
        bool canMove(
            const coordinate cit1, 
            const coordinate cit2,
            std::array<std::array<PuyoState, PlayField::CELL_WIDTH>, PlayField::CELL_HEIGHT> puyo_states,
            const int direction
        );
        coordinate canRotate(
            const coordinate cit1, 
            const coordinate cit2,
            std::array<std::array<PuyoState, PlayField::CELL_WIDTH>, PlayField::CELL_HEIGHT> puyo_states,
            const int direction
        );
        void drop(
            coordinate &cit, 
            std::array<std::array<PuyoState, PlayField::CELL_WIDTH>, PlayField::CELL_HEIGHT> puyo_states
        );
        void move(
            coordinate &cit1, 
            coordinate &cit2, 
            std::array<std::array<PuyoState, PlayField::CELL_WIDTH>, PlayField::CELL_HEIGHT> puyo_states,
            const int direction
        );
        void rotation(
            coordinate &cit1, 
            coordinate &cit2, 
            std::array<std::array<PuyoState, PlayField::CELL_WIDTH>, PlayField::CELL_HEIGHT> puyo_states,
            const int direction
        );
    private:
        std::array<PuyoState, 2> resetPuyo(
            const coordinate cit1, 
            const coordinate cit2, 
            std::array<std::array<Puyo, PlayField::CELL_WIDTH>, PlayField::CELL_HEIGHT> field_puyos
        );
        void setPuyos(
            coordinate cit1, 
            coordinate cit2, 
            std::array<std::array<Puyo, PlayField::CELL_WIDTH>, PlayField::CELL_HEIGHT> field_puyos,
            const std::array<PuyoState, 2> puyo_states
        );
};