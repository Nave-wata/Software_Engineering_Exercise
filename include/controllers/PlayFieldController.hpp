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
#include "services/PuyoDeleteService.hpp"

/**
 * @brief フィールド上のぷよを操作するクラス
 */
class PlayFieldController {
    private:    
        /** @brief ぷよを作成する位置情報 */
        const coordinate create_puyo_cit;

        /** @brief ぷよフィールド */
        PlayField field;

        /** @brief ぷよを動かすサービス */
        PuyoMoveService puyo_move_service;

        /** @brief ぷよを削除するサービス */
        PuyoDeleteService puyo_delete_service;

        /** @brief 現在操作中のぷよの位置情報 */
        coordinate move_cit1;

        /** @brief 現在操作中のぷよの位置情報 */
        coordinate move_cit2;

    public:
        PlayFieldController(const int y, const int x);
        void show();
        void create(std::array<PuyoState, 2> puyos);
        void move(const int direction);
        void rotation(const int direction);
        std::array<PuyoState, 2> resetPuyo();
        void setPuyos(const std::array<PuyoState, 2> puyos);
        bool isGameOver();
        bool isNext();
        void deletePuyos();

    private:
        bool isCantDown();
        bool isBottom();
};