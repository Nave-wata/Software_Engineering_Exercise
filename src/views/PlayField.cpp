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
    // ぷよのカラーセットを作成する
    init_pair(static_cast<int>(PuyoState::RED), COLOR_RED, COLOR_BLACK);
    init_pair(static_cast<int>(PuyoState::BLUE), COLOR_BLUE, COLOR_BLACK);
    init_pair(static_cast<int>(PuyoState::GREEN), COLOR_GREEN, COLOR_BLACK);

    // フィールドのセルを初期化する
    for (int i = 0; i < this->CELL_HEIGHT; i++) {
        for (int j = 0; j < this->CELL_WIDTH; j++) {
            this->prev_puyos[i][j].setState(PuyoState::NONE);
            this->prev_puyos[i][j].setWin(nullptr);
            this->puyos[i][j].setState(PuyoState::NONE);
            this->puyos[i][j].setWin(newwin(
                1, 1,
                this->center_y - (this->CELL_HEIGHT / 2) + i,
                this->center_x - (this->CELL_WIDTH / 2) + (j * this->ONE_CHARACTER_WIDTH) - this->CELL_CENTER_X
            ));
        }
    }

    /** ダミーデータ */
    // this->createPuyo(3, 2, PuyoState::RED);
    // this->createPuyo(4, 2, PuyoState::GREEN);
    // this->createPuyo(this->CELL_HEIGHT - 1, 0, PuyoState::GREEN);
    // this->createPuyo(this->CELL_HEIGHT - 2, 0, PuyoState::GREEN);
    // this->createPuyo(this->CELL_HEIGHT - 3, 0, PuyoState::GREEN);
    // this->createPuyo(this->CELL_HEIGHT - 1, 1, PuyoState::RED);
    // this->createPuyo(this->CELL_HEIGHT - 2, 1, PuyoState::RED);
    // this->createPuyo(this->CELL_HEIGHT - 3, 1, PuyoState::RED);
    // this->createPuyo(this->CELL_HEIGHT - 4, 1, PuyoState::GREEN);
    // this->createPuyo(this->CELL_HEIGHT - 1, 2, PuyoState::BLUE);
    // this->createPuyo(this->CELL_HEIGHT - 2, 2, PuyoState::BLUE);
    // this->createPuyo(this->CELL_HEIGHT - 3, 2, PuyoState::BLUE);
    // this->createPuyo(this->CELL_HEIGHT - 4, 2, PuyoState::RED);
    // this->createPuyo(this->CELL_HEIGHT - 1, 3, PuyoState::GREEN);
    // this->createPuyo(this->CELL_HEIGHT - 2, 3, PuyoState::GREEN);
    // this->createPuyo(this->CELL_HEIGHT - 3, 3, PuyoState::GREEN);
    // this->createPuyo(this->CELL_HEIGHT - 4, 3, PuyoState::BLUE);
    // this->createPuyo(this->CELL_HEIGHT - 1, 4, PuyoState::RED);
    // this->createPuyo(this->CELL_HEIGHT - 2, 4, PuyoState::RED);
    // this->createPuyo(this->CELL_HEIGHT - 3, 4, PuyoState::RED);
    // this->createPuyo(this->CELL_HEIGHT - 4, 4, PuyoState::GREEN);
    /** */
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
 * @brief フィールドを更新する
 * 
 * @return void
 */
void PlayField::updateField() {
    // 前回から変化した部分だけ更新する
    for (int i = 0; i < this->CELL_HEIGHT; i++) {
        for (int j = 0; j < this->CELL_WIDTH; j++) {
            if (this->puyos[i][j].getState() != prev_puyos[i][j].getState()) {
                this->puyos[i][j].showPuyo();
            }
        }
    }

    // 次回のために今回の状態を保存する
    for (int i = 0; i < this->CELL_HEIGHT; i++) 
        for (int j = 0; j < this->CELL_WIDTH; j++)
            this->puyos[i][j].setState(this->prev_puyos[i][j].getState());
}

/**
 * @brief フィールドの指定したセルのぷよを取得する
 * 
 * @param x int ぷよのx座標
 * @param y int ぷよのy座標
 * @return int ぷよの状態
 */
int PlayField::getPuyo(const int x, const int y) {
    return static_cast<int>(this->puyos[y][x].getState());
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