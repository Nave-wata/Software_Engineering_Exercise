/**
 * @file JoinRoomController.hpp
 * 
 * @brief JoinRoomControllerクラスのヘッダファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-07-14
 */

#pragma once

#include "coms/CreateRoomCom.hpp"
#include "views/JoinRoomForm.hpp"

class JoinRoomController {
    public:
        RoomInfo show();
        std::vector<playerInfo> joinRoom(const RoomInfo room_info);
        // std::vector<playerInfo> joinRoom(const RoomInfo room_info, const int player_num);
};