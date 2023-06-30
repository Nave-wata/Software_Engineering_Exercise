/**
 * @file CreateOrJoinRoomController.cpp
 * 
 * @brief CreateOrJoinRoomControllerクラスのソースファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-06-30
 */

#include "controllers/CreateOrJoinRoomController.hpp"

/**
 * @brief 部屋作成・参加画面のコントローラークラス
 */
void CreateOrJoinRoomController::createOrJoin() {
    this->form.showForm();
    this->action = this->form.getAction(); 
}

/**
 * @brief 部屋の操作を返す
 * 
 * @return int 部屋作成/入室
 */
int CreateOrJoinRoomController::getAction() {
    return this->action;
}

