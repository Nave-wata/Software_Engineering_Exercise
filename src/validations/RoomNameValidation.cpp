/**
 * @file RoomNameValidation.cpp
 * 
 * @brief RoomNameValidationクラスのソースファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-07-14
 */

#include <time.h>

#include "validations/RoomNameValidation.hpp"
#include "exceptions/DuplicateRoomNameException.hpp"

/**
 * @brief 部屋名のバリデーションを行う
 * 
 * @param room_name 部屋名
 */
void RoomNameValidation::validation(const std::string room_name) {
    std::vector<std::string> room_names = this->recvRoomNames();

    for (int i = 0; i < static_cast<int>(room_names.size()); i++) {
        if (room_names[i] == room_name) {
            throw DuplicateRoomNameException("Duplicate room name");
        }
    }
}

/**
 * @brief UDPで送られてきた部屋名を受け取る
 * 
 * @return std::vector<std::string> 部屋名のリスト
 */
std::vector<std::string> RoomNameValidation::recvRoomNames() {
    std::vector<std::string> room_names;
    std::string msg, ip;
    clock_t start = clock();
    clock_t end = clock();

    while ((double)(end - start) / CLOCKS_PER_SEC < 1.0) {
        this->udp._recv(msg, ip);
        room_names.push_back(msg);
        end = clock();
    }

    return room_names;
}