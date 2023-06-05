/**
 * @file PlayBoard.hpp
 * 
 * @brief PlayBoardクラスのヘッダファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-06-05
 */

#pragma once

#include "views/PlayField.hpp"
#include "views/ScoreField.hpp"
#include "views/NextPuyoField.hpp"
#include "views/ChainField.hpp"
#include "views/NuisancePuyoField.hpp"

/**
 * @brief プレイボードクラス
 * 
 * プレイヤー1人あたりに表示されるゲーム画面を表示・管理する
 */
class PlayBoard {
    private:
        /** @brief ぷよを操作するフィールド */
        PlayField playField;

        /** @brief スコアを表示するフィールド */
        ScoreField scoreField;

        /** @brief 次のぷよフィールドを表示するフィールド */
        NextPuyoField nextPuyoField;

        /** @brief 連鎖数を表示するフィールド */
        ChainField chainField;

        /** @brief おじゃまぷよを表示するフィールド */
        NuisancePuyoField nuisancePuyoField;

    public:
        PlayBoard(const int y, const int x);
        ~PlayBoard();
        void showBoard();
};