/**
 * @file ChainService.hpp
 * 
 * @brief ChainServiceクラスのヘッダファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-07-19
 */

#pragma once

class ChainService {
    private:
        /** @brief 表示中の連鎖数 */
        int show_chain;

    public:
        ChainService();
        bool isUpdate(const int chain);
        int chain(const int chain);
};