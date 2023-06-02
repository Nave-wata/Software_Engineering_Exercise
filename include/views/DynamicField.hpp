/**
 * @file DynamicField.hpp
 * 
 * @brief DynamicFieldクラスのヘッダファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-06-02
 */

#pragma once

/**
 * @brief DynamicFieldクラス
 * 
 * 表示するフィールドの位置が事前にわからない場合や，
 * コンテンツが動的に変化する際に使用する実質インターフェース
 */
class DynamicField {
    protected:
        /** 
         * @brief 表示するフィールド位置の中央値 y軸
         * 
         * コンストラクタで初期化
         */
        const int FIELD_CENTER_Y;

        /** 
         * @brief 表示するフィールド位置の中央値 x軸 
         * 
         * コンストラクタで初期化
         */
        const int FIELD_CENTER_X;

    public:
        DynamicField(const int, const int);
        virtual ~DynamicField();
        virtual void showField()=0;
        virtual void updateField()=0;
};