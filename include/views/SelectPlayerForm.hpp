/**
 * @file SelectPlayerForm.hpp
 * 
 * @brief SelectPlayerFormクラスのヘッダファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-06-02
 */

#pragma once

#include "views/BaseBox.hpp"

/**
 * @brief プレイ人数選択フォームを表示するクラス
 * 
 * プレイ人数を選択するフォームを表示し，プレイヤーからの選択を待ち受ける
 */
class SelectPlayerForm: public BaseBox {
    private:
        /** @brief フォームウィンドウの行数 */
        const int FORM_BOX_HEIGHT = 12;

        /** @brief フォームウィンドウの列数 */
        const int FORM_BOX_WIDTH = 40;

        /** @brief 人数の選択項目を中央に表示するための調整用 x軸 */
        const int NUMBERS_CENTER_X = 3;

        /** @brief コンテンツを表示し始める位置 y軸 */
        const int WIN_BASE_Y = 2;

        /** @brief タイトルを表示し始める位置 */
        Position title;

        /** @brief 1人の選択項目を表示し始める位置 */
        Position play1;

        /** @brief 2人の選択項目を表示し始める位置 */
        Position play2;

        /** @brief 3人の選択項目を表示し始める位置 */
        Position play3;

        /** @brief 4人の選択項目を表示し始める位置 */
        Position play4;

    public:
        SelectPlayerForm();
        ~SelectPlayerForm();
        void showForm();

    protected:
        void showContents() override;
        void keyWait() override;
};