/**
 * @file PuyoDeleteService.cpp
 * 
 * @brief PuyoDeleteServiceクラスのソースファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-07-18
 */

#include "services/PuyoDeleteService.hpp"

/**
 * @brief すべてのセルを開始とした探索を行う
 * 
 * @param puyo_states フィールド上のぷよ状態
 * @return std::vector<std::vector<coordinate>> 
 */
std::vector<std::vector<puyoInfo>> PuyoDeleteService::deletePuyos(
    std::array<std::array<PuyoState, PlayField::CELL_WIDTH>, PlayField::CELL_HEIGHT> puyo_states
) {
    std::vector<std::vector<puyoInfo>> res;

    for (int y = 0; y < PlayField::CELL_HEIGHT; y++) {
        for (int x = 0; x < PlayField::CELL_WIDTH; x++) {
            if (puyo_states[y][x] != PuyoState::NONE) {
                this->deleted_puyos.clear();
                std::vector<puyoInfo> puyo_info = this->deletePuyo(puyo_states, y, x);

                if (puyo_info.size() >= 4) {
                    res.push_back(puyo_info);
                }
            }
        }
    }

    return res;
}

/**
 * @brief 隣接している同じ状態のぷよを探索する
 * 
 * @param puyo_states フィールド上のぷよ
 * @param y 検証するぷよのy座標
 * @param x 検証するぷよのx座標
 * 
 * @return std::vector<coordinate> 探索したぷよの座標
 */
std::vector<puyoInfo> PuyoDeleteService::deletePuyo(
    std::array<std::array<PuyoState, PlayField::CELL_WIDTH>, PlayField::CELL_HEIGHT> &puyo_states,
    const int y,
    const int x
) {
    PuyoState current_puyo_state = puyo_states[y][x];
    puyoInfo puyo_info = {{y, x}, current_puyo_state};

    this->deleted_puyos.push_back(puyo_info);
    puyo_states[y][x] = PuyoState::NONE;

    if (
        0 <= y - 1 &&
        current_puyo_state != PuyoState::NONE && 
        current_puyo_state == puyo_states[y - 1][x]
    ) {
        deletePuyo(puyo_states, y - 1, x);
    }

    if (
        y + 1 < PlayField::CELL_HEIGHT &&
        current_puyo_state != PuyoState::NONE && 
        current_puyo_state == puyo_states[y + 1][x]
    ) {
        deletePuyo(puyo_states, y + 1, x);
    }

    if (
        0 <= x - 1 &&
        current_puyo_state != PuyoState::NONE && 
        current_puyo_state == puyo_states[y][x - 1]
    ) {
        deletePuyo(puyo_states, y, x - 1);
    }

    if (
        x + 1 < PlayField::CELL_WIDTH &&
        current_puyo_state != PuyoState::NONE && 
        current_puyo_state == puyo_states[y][x + 1]
    ) {
        deletePuyo(puyo_states, y, x + 1);
    }

    return this->deleted_puyos;
}

/**
 * @brief フィールド上にぷよが存在しないかどうかを判定する
 * 
 * @param puyo_states すべてのぷよの状態
 * @return bool
 */
bool PuyoDeleteService::isAllClear(
    std::array<std::array<PuyoState, PlayField::CELL_WIDTH>, PlayField::CELL_HEIGHT> puyo_states
) {
    for (int y = 0; y < PlayField::CELL_HEIGHT; y++) {
        for (int x = 0; x < PlayField::CELL_WIDTH; x++) {
            if (puyo_states[y][x] != PuyoState::NONE) {
                return false;
            }
        }
    }
    return true;
}