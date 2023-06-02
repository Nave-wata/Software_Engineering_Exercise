/**
 * @file DynamicField.cpp
 * 
 * @brief DynamicFieldクラスのソースファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-06-02
 */

#include "views/DynamicField.hpp"

/**
 * @brief コンストラクタ
 * 
 * @param y 表示するフィールド位置の中央値のy座標
 * @param x 表示するフィールド位置の中央値のx座標
 */
DynamicField::DynamicField(const int y, const int x)
    : FIELD_CENTER_Y(y), FIELD_CENTER_X(x) {}

/**
 * @brief デストラクタ
 */
DynamicField::~DynamicField() {}