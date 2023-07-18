/**
 * @file NextPuyoService.cpp
 * 
 * @brief NextPuyoServiceクラスのソースファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-07-18
 */

#include "services/NextPuyoService.hpp"

/**
 * @brief 次のぷよをセットする
 * 
 * @return std::array<PuyoState, 2> 次のぷよ
 */
std::array<PuyoState, 2> NextPuyoService::create() {
    std::array<PuyoState, 2> nextPuyo;
    std::random_device random;
    std::mt19937 mt(random());
    std::uniform_int_distribution<> rand(1, 3);

    nextPuyo[0] = static_cast<PuyoState>(rand(mt));
    nextPuyo[1] = static_cast<PuyoState>(rand(mt));

    return nextPuyo;
}