/**
 * @file CreateRoomForm.hpp
 * 
 * @brief 部屋作成フォームのヘッダファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-06-02
 */

#pragma once

#include "views/InputForm.hpp"

/**
 * @brief 部屋作成フォームクラス
 * 
 * 部屋名を入力するウィンドウを表示するクラス
 */
class CreateRoomForm: public InputForm {
    public:
        CreateRoomForm(const char*, const char*);
        ~CreateRoomForm();
};