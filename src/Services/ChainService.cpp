/**
 * @file ChainService.cpp
 * 
 * @brief ChainServiceクラスのソースファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-07-19
 */

#include "services/ChainService.hpp"

#include <algorithm>

/**
 * @brief コンストラクタ
 */
ChainService::ChainService()
    : show_chain(0) {}

/**
 * @brief 連鎖数を更新するか
 * 
 * @param chain 現在の連鎖数
 * @return bool
 */
bool ChainService::isUpdate(const int chain) {
    return this->show_chain < chain;
}

/**
 * @brief 表示中の連鎖数と現在の連鎖数で大きい方を返す
 * 
 * @param chain 現在の連鎖数
 * @return int 
 */
int ChainService::chain(const int chain) {
    this->show_chain = std::max(this->show_chain, chain);
    return this->show_chain;
}