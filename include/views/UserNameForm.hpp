/**
 * @file UserNameForm.hpp
 * 
 * @brief UserNameFormクラスのヘッダファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-06-02
 */

#pragma once

#include "views/InputForm.hpp"

/**
 * @brief ユーザ名入力フォームクラス
 * 
 * ユーザ名入力フォームを表示し，プレイヤーからユーザ名の入力を待ち受ける
 */
class UserNameForm: public InputForm {
    public:
        UserNameForm(const char*, const char*);
        ~UserNameForm();
};