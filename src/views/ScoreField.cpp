/**
 * @file ScoreField.cpp
 * 
 * @brief ScoreFieldクラスのソースファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-06-04
 */

#include "views/ScoreField.hpp"
#include <string>

/**
 * @brief コンストラクタ
 * 
 * @param y int スコアを表示するウィンドウの中央のy座標
 * @param x int スコアを表示するウィンドウの中央のx座標
 */
ScoreField::ScoreField(const int y, const int x): DynamicField(y, x) , score(0) {
    this->win = newwin(
        this->FIELD_BOX_HEIGHT,
        this->FIELD_BOX_WIDTH,
        this->FIELD_CENTER_Y - this->FIELD_BOX_HEIGHT / 2 + this->SCORE_CENTER_Y,
        this->FIELD_CENTER_X - this->FIELD_BOX_WIDTH / 2
    );
};

/**
 * @brief デストラクタ
 */
ScoreField::~ScoreField() {};

/**
 * @brief スコアフィールドを表示する
 * 
 * @return void
 */
void ScoreField::showField() {
    mvwprintw(this->win, 0, 0, this->toCharScore());
    wrefresh(this->win);
}

/**
 * @brief スコアフィールドを更新する
 * 
 * @return void
 */
void ScoreField::updateField() {
    mvwprintw(this->win, 0, 0, this->toCharScore());
    wrefresh(this->win);
}

/**
 * @brief スコアをchar型に変換する
 * 
 * @return char*
 */
inline const char* ScoreField::toCharScore() {
    std::string score = std::to_string(this->score);
    score = std::string(this->SCORE_LENGTH - static_cast<int>(score.size()), '0') + score;
    return score.c_str();
}

/**
 * @brief スコアを取得する
 * 
 * @return int スコア
 */
int ScoreField::getScore() {
    return this->score;
}

/**
 * @brief スコアを設定する
 * 
 * @param score int スコア
 * @return void
 */
void ScoreField::setScore(const int score) {
    this->score = score;
}