/**
 * @file CreateRoomController.cpp
 * 
 * @brief CreateRoomControllerクラスのソースファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-07-14
 */

#include "controllers/CreateRoomController.hpp"
#include <vector>

/**
 * @brief CreateRoomControllerクラスのコンストラクタ
 */
CreateRoomController::CreateRoomController()
    : form("Create room name", "Room name") {}

/**
 * @brief 入力された部屋名を取得する
 * 
 * @return std::string 入力された部屋名
 */
std::string CreateRoomController::inputRoomName() {
    return this->form.showForm();
}

/**
 * @brief 部屋を作成する
 * 
 * @param room_name 部屋名
 * @param n プレイヤー数
 */
std::vector<playerInfo> CreateRoomController::createRoom(const std::string room_name, const int n) {
    this->com.recvTcpInfo(room_name, n);
    std::vector<playerInfo> player_infos = this->com.sendTcpInfo();
    return player_infos;
}

/**
 * @brief 部屋名のバリデーションを行う
 * 
 * @param room_name 部屋名
 */
void CreateRoomController::validation(const std::string room_name) {
    this->roomNameValidation.validation(room_name);
}

