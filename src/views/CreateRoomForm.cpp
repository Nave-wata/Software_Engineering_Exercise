/**
 * @file CreateRoomForm.cpp
 * 
 * @brief 部屋作成フォームのソースファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-06-02
 */

#include "views/CreateRoomForm.hpp"

/**
 * @brief コンストラクタ
 * 
 * @param title_msg タイトルメッセージ
 * @param field_msg 入力項目の前に表示するメッセージ
 */
CreateRoomForm::CreateRoomForm(const char *title_msg, const char *field_msg)
    : InputForm(title_msg, field_msg) {};

/**
 * @brief デストラクタ
 */
CreateRoomForm::~CreateRoomForm() {}