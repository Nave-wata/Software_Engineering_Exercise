/**
 * @file RoomNameValidation.hpp
 * 
 * @brief RoomNameValidationクラスのヘッダファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-07-14
 */

#pragma once

#include "coms/UDP.hpp"
#include <vector>

class RoomNameValidation {
    private:
        UDP udp;

    public:
        void validation(const std::string room_name);
    
    private:
        std::vector<std::string> recvRoomNames();
};