/**
 * @file UserNameForm.cpp
 * 
 * @brief UserNameFormクラスのソースファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-06-02
 */

#include "views/UserNameForm.hpp"

/**
 * @brief コンストラクタ
 * 
 * @param title_msg タイトルメッセージ
 * @param field_msg 入力フィールドの前に表示するメッセージ
 */
UserNameForm::UserNameForm(const char *title_msg, const char *field_msg)
    : InputForm(title_msg, field_msg) {};

/**
 * @brief デストラクタ
 */
UserNameForm::~UserNameForm() {}
