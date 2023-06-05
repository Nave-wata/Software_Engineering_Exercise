/**
 * @file PlayBoard.cpp
 * 
 * @brief PlayBoardクラスのソースファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-06-05
 */

#include "views/PlayBoard.hpp"

/**
 * @brief コンストラクタ
 * 
 * @param y int フィールドを表示するウィンドウの中央のy座標
 * @param x int フィールドを表示するウィンドウの中央のx座標
 */
PlayBoard::PlayBoard(const int y, const int x):
    playField(PlayField(y, x)),
    scoreField(ScoreField(y, x)),
    nextPuyoField(NextPuyoField(y, x)),
    chainField(ChainField(y, x)) ,
    nuisancePuyoField(NuisancePuyoField(y, x)) {}

/**
 * @brief デストラクタ
 */
PlayBoard::~PlayBoard() {};

/**
 * @brief プレイボードを表示する
 * 
 * @return void
 */
void PlayBoard::showBoard() {
    this->playField.showField();
    this->playField.updateField();

    this->scoreField.showField();

    this->nextPuyoField.showField();
    this->nextPuyoField.updateField(PuyoState::GREEN, PuyoState::BLUE);

    this->chainField.showField();

    this->nuisancePuyoField.showField();
}