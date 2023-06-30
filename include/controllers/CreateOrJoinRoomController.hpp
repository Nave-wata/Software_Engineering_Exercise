/**
 * @file CreateOrJoinRoomController.hpp
 * 
 * @brief CreateOrJoinRoomControllerクラスのヘッダファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-06-30
 */

#pragma once

#include "views/CreateOrJoinRoomForm.hpp"

/**
 * @brief 部屋作成・参加画面のコントローラークラス
 */
class CreateOrJoinRoomController {
    private:
        /** @brief 部屋作成・参加画面のフォーム */
        CreateOrJoinRoomForm form;

        /** @brief 部屋の操作 */
        int action;

        
    public:
        void createOrJoin();
        int getAction();
};