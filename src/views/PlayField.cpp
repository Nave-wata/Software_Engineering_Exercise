/**
 * @file PlayField.cpp
 * 
 * @brief PlayFieldクラスのソースファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-06-04
 */

#include "views/PlayField.hpp"

/**
 * @brief コンストラクタ
 * 
 * @param y int フィールドのy座標
 * @param x int フィールドのx座標
 */
PlayField::PlayField(const int y, const int x): DynamicField(y, x) {
    // フィールドのセルを初期化する
    for (int i = 0; i < this->CELL_HEIGHT; i++) {
        for (int j = 0; j < this->CELL_WIDTH; j++) {
            this->puyos[i][j].setState(PuyoState::NONE);
            this->puyos[i][j].setWin(newwin(
                1, 1,
                this->center_y - (this->CELL_HEIGHT / 2) + i,
                this->center_x - (this->CELL_WIDTH / 2) + (j * this->ONE_CHARACTER_WIDTH) - this->CELL_CENTER_X
            ));
        }
    }
}

/**
 * @brief デストラクタ
 */
PlayField::~PlayField() {
    for (int i = 0; i < this->CELL_HEIGHT; i++) {
        for (int j = 0; j < this->CELL_WIDTH; j++) {
            delwin(this->puyos[i][j].getWin());
        }
    }
}

/**
 * @brief フィールドを表示する
 * 
 * @return void
 */
void PlayField::showField() {
    this->showBox(
        this->FIELD_BOX_HEIGHT,
        this->FIELD_BOX_WIDTH - 1,
        this->FIELD_CENTER_Y - (this->FIELD_BOX_HEIGHT) / 2,
        this->FIELD_CENTER_X - (this->FIELD_BOX_WIDTH) / 2
    );
    wrefresh(this->win);
}

/**
 * @brief フィールドの指定したセルのぷよを取得する
 * 
 * @return std::array<std::array<Puyo, CELL_HEIGHT>, CELL_WIDTH> ぷよの状態
 */
std::array<std::array<PuyoState, PlayField::CELL_WIDTH>, PlayField::CELL_HEIGHT> PlayField::getStates() {
    std::array<std::array<PuyoState, PlayField::CELL_WIDTH>, PlayField::CELL_HEIGHT> puyoStates;

    for (int i = 0; i < static_cast<int>(this->puyos.size()); i++) {
        for (int j = 0; j < static_cast<int>(this->puyos[i].size()); j++) {
            puyoStates[i][j] = this->puyos[i][j].getState();
        }
    }

    return puyoStates;
}

/**
 * @brief フィールドの指定したセルのぷよを取得する
 * 
 * @return std::array<std::array<Puyo, CELL_HEIGHT>, CELL_WIDTH> ぷよの状態
 */
std::array<std::array<Puyo, PlayField::CELL_WIDTH>, PlayField::CELL_HEIGHT>& PlayField::referencePuyo() {
    return this->puyos;
}

/**
 * @brief フィールドの指定したセルにぷよを作成する
 * 
 * @param y int ぷよのy座標
 * @param x int ぷよのx座標
 * @param color int ぷよの色
 * @return void
 */
void PlayField::createPuyo(const int y, const int x, const PuyoState color) {
    this->puyos[y][x].setState(color);
    this->puyos[y][x].showPuyo();
}

/**
 * @brief フィールドの指定したセルのぷよを移動する
 * 
 * @param from_y int 移動先のy座標
 * @param from_x int 移動元のx座標
 * @param to_y int 移動先のy座標
 * @param to_x int 移動先のx座標
 * @return void
 */
void PlayField::movePuyo(const int from_y, const int from_x, const int to_y, const int to_x) {
    this->createPuyo(to_x, to_y, this->puyos[from_y][from_x].getState());
    this->deletePuyo(from_x, from_y);
}

/**
 * @brief フィールドの指定したセルのぷよを削除する
 * 
 * @param y int ぷよのy座標
 * @param x int ぷよのx座標
 * @return void
 */
void PlayField::deletePuyo(const int y, const int x) {
    this->puyos[y][x].setState(PuyoState::NONE);
}