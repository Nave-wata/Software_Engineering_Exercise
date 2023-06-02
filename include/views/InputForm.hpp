/**
 * @file InputForm.hpp
 * 
 * @brief InputFormクラスのヘッダファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-06-02
 */

#pragma once

#include "views/BaseBox.hpp"

/**
 * @brief InputFormクラス
 * 
 * 1つのウィンドウ上に入力フォームを表示させるためのクラス
 */
class InputForm: public BaseBox {
    private:
        /** @brief タイトルメッセージ */
        const char *title_msg;

        /** @brief 入力項目の前に表示するメッセージ */
        const char *field_msg;

    protected:
        /** @brief フォームウィンドウの行数 */
        const int FORM_BOX_HEIGHT = 12;

        /** @brief フォームウィンドウの列数 */
        const int FORM_BOX_WIDTH = 40;

        /** @brief 入力フィールドの行数 */
        const int FIELD_BOX_HEIGHT = 3;

        /** @brief 入力フィールドの列数・入力フィールドの文字数上限 + 2 */
        const int FIELD_BOX_WIDTH = 20;

        /** @brief タイトルを表示し始める位置 x軸 */
        const int TITLE_CENTER_X = 4;

        /** @brief 入力フィールドを表示し始める位置 x軸 */
        const int FIELD_CENTER_X = 2;

        /** @brief ボックス内でコンテンツを表示し始める位置 y軸 */
        const int WIN_BASE_Y = 2;

        /** @brief ボックス内でコンテンツを表示し始める位置 x軸 */
        const int WIN_BASE_X = 2;

        /** @brief ボックスのウィンドウ */
        WINDOW *box_win;

        /** @brief 入力フィールドのウィンドウ */
        WINDOW *field_win;

        /** @brief タイトルを表示し始める位置 */
        Position title;

        /** @brief 入力フィールドの前に表示するメッセージを表示し始める位置 */
        Position field;

    public:
        InputForm(const char*, const char*);
        virtual ~InputForm();
        void showForm();
    
    protected:
        void showContents() override;
        void keyWait() override;
};