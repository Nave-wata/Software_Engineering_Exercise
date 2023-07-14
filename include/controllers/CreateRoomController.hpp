/**
 * @file CreateRoomController.hpp
 * 
 * @brief CreateRoomControllerクラスのヘッダファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-06-30
 */

#pragma once

#include "views/CreateRoomForm.hpp"
#include "coms/CreateRoomCom.hpp"
#include "validations/RoomNameValidation.hpp"

class CreateRoomController {
    private:
        CreateRoomForm form;
        CreateRoomCom com;
        RoomNameValidation roomNameValidation;

    public:
        CreateRoomController();
        std::string inputRoomName();
        std::vector<playerInfo> createRoom(const std::string room_name, const int n);
        void validation(const std::string room_name);
};