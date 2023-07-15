/**
 * @file SearchRoomCom.cpp
 * 
 * @brief SearchRoomComクラスのソースファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-07-14
 */

#include "coms/SearchRoomCom.hpp"
#include <iostream>
#include <algorithm>

/**
 * @brief コンストラクタ
 */
SearchRoomCom::SearchRoomCom() {}

/**
 * @brief UDPで送られてきた部屋情報を受け取る
 * 
 * @return std::vector<roomInfo> 
 */
std::vector<roomInfo> SearchRoomCom::recvRoomInfo() {
    std::vector<roomInfo> room_infos;
    std::string msg, ip;
    int count = 0;
    UDP udp = UDP("0.0.0.0");
    udp._bind();

    /* 1 sec */
    while (count++ < 100) {
        udp._recv(msg, ip, 0, 10 * 1000);
        roomInfo room_info = {msg, ip};
        bool is_continue = false;

        for (const auto &v: room_infos) {
            if (v.room_name == msg && v.ip == ip) {
                is_continue = true;
                break;
            }
        }

        if (msg == "" || ip == "") continue;
        if (is_continue) continue;
        room_infos.push_back(room_info);
    }

    return room_infos;
}