/**
 * @file PuyoMoveService.cpp
 * 
 * @brief PuyoMoveServiceクラスのソースファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-07-18
 */

#include "services/PuyoMoveService.hpp"

/**
 * @brief ぷよを動かせるかどうかを判定する
 * 
 * @param cit 検証するぷよの座標
 * @param field_puyos フィールド上のぷよ
 * @param direction 移動方向
 * @return bool
 */
bool PuyoMoveService::canMove(
    const coordinate cit, 
    std::array<std::array<PuyoState, PlayField::CELL_WIDTH>, PlayField::CELL_HEIGHT> puyo_states,
    const int direction
) {
    switch (direction) {
        case UP:
            if (
                0 <= cit.y - 1 &&
                puyo_states[cit.y - 1][cit.x] == PuyoState::NONE
            ) {
                return true;
            }
            return false;
        case DOWN:
            if (
                PlayField::CELL_HEIGHT > cit.y + 1 &&
                puyo_states[cit.y + 1][cit.x] == PuyoState::NONE
            ) {
                return true;
            }
            return false;
        case LEFT:
            if (
                0 <= cit.x - 1 &&
                puyo_states[cit.y][cit.x - 1] == PuyoState::NONE
            ) {
                return true;
            }
            return false;
        case RIGHT:
            if (
                PlayField::CELL_WIDTH > cit.x + 1 &&
                puyo_states[cit.y][cit.x + 1] == PuyoState::NONE
            ) {
                return true;
            }
            return false;
    }
    return false;
}

/**
 * @brief ぷよを動かせるかどうかを判定する
 * 
 * @param cit1 1つめの座標
 * @param cit2 2つめの座標
 * @param puyo_states すべてのぷよの状態
 * @param direction 移動したい方向
 * @return bool 移動可否
 */
bool PuyoMoveService::canMove(
    const coordinate cit1, 
    const coordinate cit2,
    std::array<std::array<PuyoState, PlayField::CELL_WIDTH>, PlayField::CELL_HEIGHT> puyo_states,
    const int direction
) {
    switch (direction) {
        case DOWN:
            if (cit1.y + 1 == cit2.y && cit1.x == cit2.x) {
                // @1
                // @2
                return this->canMove(cit2, puyo_states, direction);
            } else if (cit2.y + 1 == cit1.y && cit1.x == cit2.x) {
                // @2
                // @1
                return this->canMove(cit1, puyo_states, direction);
            } else {
                return this->canMove(cit1, puyo_states, direction) && this->canMove(cit2, puyo_states, direction);
            }
            return false;
        case LEFT:
            if (cit1.y == cit2.y && cit1.x + 1 == cit2.x) {
                // @1 @2
                return this->canMove(cit1, puyo_states, direction);
            } else if (cit1.y == cit2.y && cit1.x == cit2.x + 1) {
                // @2 @1 
                return this->canMove(cit2, puyo_states, direction);
            } else {
                return this->canMove(cit1, puyo_states, direction) && this->canMove(cit2, puyo_states, direction);
            }
            return false;
        case RIGHT:
            if (cit1.y == cit2.y && cit1.x + 1 == cit2.x) {
                // @1 @2
                return this->canMove(cit2, puyo_states, direction);
            } else if (cit1.y == cit2.y && cit1.x == cit2.x + 1) {
                // @2 @1 
                return this->canMove(cit1, puyo_states, direction);
            } else {
                return this->canMove(cit1, puyo_states, direction) && this->canMove(cit2, puyo_states, direction);
            }
            return false;
    }
    return false;
}

/**
 * @brief ぷよを回転できるかどうかを判定する
 * 
 * @param cit1 1つめの座標
 * @param cit2 2つめの座標
 * @param puyo_states すべてのぷよの状態
 * @param direction 回転したい方向
 * @return coordinate 回転後の座標
 */
coordinate PuyoMoveService::canRotate(
    const coordinate cit1, 
    const coordinate cit2,
    std::array<std::array<PuyoState, PlayField::CELL_WIDTH>, PlayField::CELL_HEIGHT> puyo_states,
    const int direction
) {
    if (cit1.y == cit2.y && cit1.x == cit2.x + 1) {
        // @2 @1
        switch (direction) {
            case LEFT_ROTATE:
                if (canMove(cit1, puyo_states, DOWN)) {
                    return {cit1.y + 1, cit1.x};
                }
                return {-1, -1};
            case RIGHT_ROTATE:
                if (canMove(cit1, puyo_states, UP)) {
                    return {cit1.y - 1, cit1.x};
                }
                return {-1, -1};
        }
    } else if (cit1.y == cit2.y && cit1.x == cit2.x - 1) {
        // @1 @2
        switch (direction) {
            case LEFT_ROTATE:
                if (canMove(cit1, puyo_states, UP)) {
                    return {cit1.y - 1, cit1.x};
                }
                return {-1, -1};
            case RIGHT_ROTATE:
                if (canMove(cit1, puyo_states, DOWN)) {
                    return {cit1.y + 1, cit1.x};
                }
                return {-1, -1};
        }
    } else if (cit1.y == cit2.y - 1 && cit1.x == cit2.x) {
        // @1
        // @2
        switch (direction) {
            case LEFT_ROTATE:
                if (canMove(cit1, puyo_states, RIGHT)) {
                    return {cit1.y, cit1.x + 1};
                }
                return {-1, -1};
            case RIGHT_ROTATE:
                if (canMove(cit1, puyo_states, LEFT)) {
                    return {cit1.y, cit1.x - 1};
                }
                return {-1, -1};
        }
    } else if (cit1.y == cit2.y + 1 && cit1.x == cit2.x) {
        // @2
        // @1
        switch (direction) {
            case LEFT_ROTATE:
                if (canMove(cit1, puyo_states, LEFT)) {
                    return {cit1.y, cit1.x - 1};
                }
                return {-1, -1};
            case RIGHT_ROTATE:
                if (canMove(cit1, puyo_states, RIGHT)) {
                    return {cit1.y, cit1.x + 1};
                }
                return {-1, -1};
        }
    }
    return {-1, -1};
}

/**
 * @brief ぷよを移動させる
 * 
 * 移動できるかを判定し，移動後の座標を返す
 * 
 * @param cit1 1つめの座標
 * @param cit2 2つめの座標
 * @param puyo_states すべてのぷよの状態
 * @param direction 移動したい方向
 */
void PuyoMoveService::move(
    coordinate &cit1, 
    coordinate &cit2, 
    std::array<std::array<PuyoState, PlayField::CELL_WIDTH>, PlayField::CELL_HEIGHT> puyo_states,
    const int direction
) {
    switch (direction) {
        case UP:
            while (canMove(cit1, cit2, puyo_states, DOWN)) {
                cit1.y++;
                cit2.y++;
            }
            return;
        case DOWN:
            if (canMove(cit1, cit2, puyo_states, DOWN)) {
                cit1.y++;
                cit2.y++;
            }
            return;
        case LEFT:
            if (canMove(cit1, cit2, puyo_states, LEFT)) {
                cit1.x--;
                cit2.x--;
            }
            return;
        case RIGHT:
            if (canMove(cit1, cit2, puyo_states, RIGHT)) {
                cit1.x++;
                cit2.x++;
            }
            return;
    }
}

/**
 * @brief ぷよを回転させられるかどうかを判定する
 * 
 * @param cit1 検証するぷよの座標1
 * @param cit2 検証するぷよの座標2
 * @param field_puyos フィールド上のぷよ
 * @param direction 回転方向
 * @return bool
 */
void PuyoMoveService::rotation(
    coordinate &cit1, 
    coordinate &cit2, 
    std::array<std::array<PuyoState, PlayField::CELL_WIDTH>, PlayField::CELL_HEIGHT> puyo_states,
    const int direction
) {
    coordinate cit;
    switch (direction) {
        case LEFT_ROTATE:
            cit = canRotate(cit1, cit2, puyo_states, LEFT_ROTATE);
            if (cit.x != -1 && cit.y != -1) {
                cit2 = cit;
            }
            return;
        case RIGHT_ROTATE:
            cit = canRotate(cit1, cit2, puyo_states, RIGHT_ROTATE);
            if (cit.x != -1 && cit.y != -1) {
                cit2 = cit;
            }
            return;
    }
}
