/**
 * @file NextPuyoController.hpp
 * 
 * @brief NextPuyoControllerクラスのヘッダファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-07-18
 */

#pragma once

#include <array>

#include "views/Puyo.hpp"
#include "views/NextPuyoField.hpp"
#include "services/NextPuyoService.hpp"

class NextPuyoController {
    private:
        /** @brief 次のぷよを表示するフィールド */
        NextPuyoField field;

        /** @brief 次のぷよを実際に生成する */
        NextPuyoService service;

        /** @brief 次のぷよ */
        std::array<PuyoState, 2> next_puyos;

    public:
        NextPuyoController(const int y, const int x);
        void show();
        std::array<PuyoState, 2> create();
        std::array<PuyoState, 2> update();
};