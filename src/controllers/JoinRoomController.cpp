/**
 * @file JoinRoomController.cpp
 * 
 * @brief JoinRoomControllerクラスのソースファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-07-17
 */

#include "controllers/JoinRoomController.hpp"
#include "coms/JoinRoomCom.hpp"
#include "exceptions/CantConnectException.hpp"

RoomInfo JoinRoomController::show() {
    JoinRoomForm form;
    return form.showForm();
}

/**
 * @brief 部屋に入室する
 * 
 * @param room_info 部屋情報
 * @return std::vector<playerInfo> 
 */
std::vector<playerInfo> JoinRoomController::joinRoom(const RoomInfo room_info) {
    JoinRoomCom com = JoinRoomCom(room_info.room_name, room_info.ip_address);
    
    if (!com.join()) {
        throw CantConnectException("部屋に入室できませんでした");
    }

    return com.recvPlayerInfo();
}