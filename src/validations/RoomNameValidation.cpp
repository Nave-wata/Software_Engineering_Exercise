/**
 * @file RoomNameValidation.cpp
 * 
 * @brief RoomNameValidationクラスのソースファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-07-14
 */

#include "validations/RoomNameValidation.hpp"
#include "exceptions/DuplicateRoomNameException.hpp"
#include "coms/UDP.hpp"

/**
 * @brief 部屋名のバリデーションを行う
 * 
 * @param room_name 部屋名
 */
void RoomNameValidation::validation(const std::string room_name) {
    UDP udp = UDP("0.0.0.0", BROADCAST_PORT);
    std::string msg, ip;
    int count = 0;

    udp._bind();

    /* 1 sec */
    while (count++ < 100) {
        udp._recv(msg, ip, 0, 10 * 1000);
        if (msg == room_name) {
            throw DuplicateRoomNameException("Duplicate room name");
        }
    }
}
