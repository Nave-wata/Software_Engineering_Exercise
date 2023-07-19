/**
 * @file ScoreController.hpp
 * 
 * @brief ScoreControllerクラスのヘッダファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-07-19
 */

#pragma once

#include "views/ScoreField.hpp"
#include "services/ScoreService.hpp"
#include "services/PuyoDeleteService.hpp"

class ScoreController {
    private:
        /** @brief スコアを表示するフィールド */
        ScoreField field;

        /** @brief スコアを計算するサービス */
        ScoreService service;

    public:
        ScoreController(const int y, const int x);
        void show();
        int update(std::vector<std::vector<puyoInfo>> deleted_puyos, const int chan);
};