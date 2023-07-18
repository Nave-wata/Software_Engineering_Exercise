/**
 * @file ChainController.hpp
 * 
 * @brief ChainControllerクラスのヘッダファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-07-19
 */

#pragma once

#include "views/ChainField.hpp"
#include "services/ChainService.hpp"

class ChainController {
    private:
        /** @brief 連鎖数を表示するフィールド */
        ChainField field;

        /** @brief 連鎖数を計算するサービス */
        ChainService service;

    public:
        ChainController(const int y, const int x);
        void show();
        int update(const int chain);
};