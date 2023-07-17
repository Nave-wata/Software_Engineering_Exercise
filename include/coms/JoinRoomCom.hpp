/**
 * @file JoinRoomCom.hpp
 * 
 * @brief JoinRoomComクラスのヘッダファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-07-16
 */

#pragma once

#include <string>
#include <vector>

#include "coms/CreateRoomCom.hpp"

class JoinRoomCom {
    private:
        /** @brief 入出する部屋名 */
        const std::string room_name;

        /** @brief 通信先IPアドレス */
        const std::string ip;

        /** @brief 同じ部屋内のプレイヤーデータ */
        std::vector<playerInfo> player_infos;

    public:
        JoinRoomCom(const std::string room_name, const std::string ip);
        bool join();
        std::vector<playerInfo> recvPlayerInfo();
        // std::vector<playerInfo> recvPlayerInfo(const int player_num);
};