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

/**
 * @brief PlayFieldControllerクラスのコンストラクタ
 * 
 * @param y フィールドの高さ
 * @param x フィールドの幅
 */
PlayFieldController::PlayFieldController(const int y, const int x)
    : field(y, x)
    , create_puyo_cit({0, 3})
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
