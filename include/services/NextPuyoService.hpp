/**
 * @file NextPuyoService.hpp
 * 
 * @brief NextPuyoServiceクラスのヘッダファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-07-18
 */

#pragma once

#include <array>
#include <random>

#include "views/Puyo.hpp"

class NextPuyoService {
    public:
        std::array<PuyoState, 2> create();
};