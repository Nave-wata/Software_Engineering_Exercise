/**
 * @file PlayFieldController.cpp
 * 
 * @brief PlayFieldControllerクラスのソースファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-07-18
 */

#include "controllers/PlayFieldController.hpp"
#include "utils/Sleep.hpp"

/**
 * @brief PlayFieldControllerクラスのコンストラクタ
 * 
 * @param y フィールドの高さ
 * @param x フィールドの幅
 */
PlayFieldController::PlayFieldController(const int y, const int x)
    : create_puyo_cit({0, 3})
    , field(y, x)
    , move_cit1(create_puyo_cit)
    , move_cit2({create_puyo_cit.y + 1, create_puyo_cit.x}) {}

void PlayFieldController::show() {
    this->field.showField();
}

/**
 * @brief フィールド上にぷよを生成する
 * 
 * @param puyos 生成するぷよの種類
 */
void PlayFieldController::create(std::array<PuyoState, 2> puyos) {
    this->field.createPuyo(this->create_puyo_cit.y, this->create_puyo_cit.x, puyos[0]);
    this->field.createPuyo(this->create_puyo_cit.y + 1, this->create_puyo_cit.x, puyos[1]);
    this->move_cit1 = this->create_puyo_cit;
    this->move_cit2 = {this->create_puyo_cit.y + 1, this->create_puyo_cit.x};
}

/**
 * @brief ぷよを移動させる
 * 
 * @param direction 移動方向
 */
void PlayFieldController::move(const int direction) {
    std::array<PuyoState, 2> puyos = this->resetPuyo();
    this->puyo_move_service.move(
        this->move_cit1,
        this->move_cit2,
        this->field.getStates(),
        direction
    );
    this->setPuyos(puyos);
}

/**
 * @brief ぷよを回転させる
 * 
 * @param direction 回転方向
 */
void PlayFieldController::rotation(const int direction) {
    std::array<PuyoState, 2> puyos = this->resetPuyo();
    this->puyo_move_service.rotation(
        this->move_cit1,
        this->move_cit2,
        this->field.getStates(),
        direction
    );
    this->setPuyos(puyos);
}

/**
 * @brief ぷよを削除する
 * 
 * @return std::array<PuyoState, 2> 削除したぷよの状態
 */
std::array<PuyoState, 2> PlayFieldController::resetPuyo() {
    std::array<PuyoState, 2> puyos;
    puyos[0] = this->field.referencePuyo()[this->move_cit1.y][this->move_cit1.x].getState();
    puyos[1] = this->field.referencePuyo()[this->move_cit2.y][this->move_cit2.x].getState();
    this->field.referencePuyo()[this->move_cit1.y][this->move_cit1.x].setState(PuyoState::NONE);
    this->field.referencePuyo()[this->move_cit2.y][this->move_cit2.x].setState(PuyoState::NONE);
    this->field.referencePuyo()[this->move_cit1.y][this->move_cit1.x].showPuyo();
    this->field.referencePuyo()[this->move_cit2.y][this->move_cit2.x].showPuyo();
    return puyos;
}

/**
 * @brief ぷよをセットする
 * 
 * @param puyos セットするぷよの状態
 */
void PlayFieldController::setPuyos(const std::array<PuyoState, 2> puyos) {
    this->field.referencePuyo()[this->move_cit1.y][this->move_cit1.x].setState(puyos[0]);
    this->field.referencePuyo()[this->move_cit2.y][this->move_cit2.x].setState(puyos[1]);
    this->field.referencePuyo()[this->move_cit1.y][this->move_cit1.x].showPuyo();
    this->field.referencePuyo()[this->move_cit2.y][this->move_cit2.x].showPuyo();
}

/**
 * @brief ゲームオーバーを判定する
 * 
 * @return bool
 */
bool PlayFieldController::isGameOver() {
    std::array<std::array<PuyoState, PlayField::CELL_WIDTH>, PlayField::CELL_HEIGHT> puyo_states = this->field.getStates();
    return puyo_states[this->create_puyo_cit.y][this->create_puyo_cit.x] != PuyoState::NONE
        || puyo_states[this->create_puyo_cit.y + 1][this->create_puyo_cit.x] != PuyoState::NONE;
}

/**
 * @brief 次のぷよを生成するかを判定する
 * 
 * @return bool
 */
bool PlayFieldController::isNext() {
    if (this->isCantDown() || this->isBottom()) {
        return true;
    }
    return false;
}

/**
 * @brief ぷよを削除する
 */
std::vector<std::vector<coordinate>> PlayFieldController::deletePuyos() {
    std::vector<std::vector<coordinate>> deleted_puyos = this->puyo_delete_service.deletePuyos(this->field.getStates());

    for (auto deleted_puyo : deleted_puyos) {
        if (deleted_puyo.size() < 3) {
            continue;
        }

        for (auto coordinate : deleted_puyo) {
            this->field.referencePuyo()[coordinate.y][coordinate.x].setState(PuyoState::NONE);
            this->field.referencePuyo()[coordinate.y][coordinate.x].showPuyo();
        }
    }

    return deleted_puyos;
}

/**
 * @brief ぷよを落下させる
 */
void PlayFieldController::dropPuyos() {
    for (int y = PlayField::CELL_HEIGHT - 1; 0 <= y; y--) {
        for (int x = PlayField::CELL_WIDTH - 1; 0 <= x; x--) {
            coordinate current_coordinate = {y, x};
            PuyoState state = this->field.referencePuyo()[current_coordinate.y][current_coordinate.x].getState();

            this->field.referencePuyo()[current_coordinate.y][current_coordinate.x].setState(PuyoState::NONE);
            this->field.referencePuyo()[current_coordinate.y][current_coordinate.x].showPuyo();

            this->puyo_move_service.drop(
                current_coordinate,
                this->field.getStates()
            );

            this->field.referencePuyo()[current_coordinate.y][current_coordinate.x].setState(state);
            this->field.referencePuyo()[current_coordinate.y][current_coordinate.x].showPuyo();
        }
    }
}

/**
 * @brief ぷよが落下可能かを判定する
 * 
 * @return bool
 */
bool PlayFieldController::isCantDown() {
    return !this->puyo_move_service.canMove(
        this->move_cit1,
        this->move_cit2,
        this->field.getStates(),
        DOWN
    );
}

/**
 * @brief ぷよがフィールドの底に到達したかを判定する
 * 
 * @return bool
 */
bool PlayFieldController::isBottom() {
    return this->move_cit1.y == PlayField::CELL_HEIGHT - 1 
        || this->move_cit2.y == PlayField::CELL_HEIGHT - 1;
}
