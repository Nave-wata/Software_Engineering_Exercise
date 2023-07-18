/**
 * @file PlayFieldController.hpp
 * 
 * @brief PlayFieldControllerクラスのヘッダファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-07-18
 */

#pragma once

#include "views/PlayField.hpp"
#include "services/PuyoMoveService.hpp"

/**
 * @brief フィールド上のぷよを操作するクラス
 */
class PlayFieldController {
    private:
        PlayField field;
        
        PuyoMoveService puyo_move_service;

        const coordinate create_puyo_cit;

        coordinate move_cit1;
        coordinate move_cit2;

    public:
        PlayFieldController(const int y, const int x);
        void show();
        void create(std::array<PuyoState, 2> puyos);
        void move(const int direction);
        void rotation(const int direction);
        std::array<PuyoState, 2> resetPuyo();
        void setPuyos(const std::array<PuyoState, 2> puyos);
};