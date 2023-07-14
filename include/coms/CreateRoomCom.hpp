/**
 * @file CreateRoomCom.hpp
 * 
 * @brief CreateRoomComクラスのヘッダファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-06-30
 */

#pragma once

#include <string>
#include <vector>
#include "coms/UDP.hpp"
#include "coms/TCP.hpp"

typedef struct {
    std::string room_name;
    std::string ip;
    TCP tcp;
} playerInfo;

/**
 * @brief CreateRoomComクラス
 * 
 * 通信するプレイヤーを集める部屋の作成を行う
 */
class CreateRoomCom {
    private:
        static UDP udp;
        static std::vector<playerInfo> player_infos;

    public:
        void recvTcpInfo(const std::string room_name, const int n);
        std::vector<playerInfo> sendTcpInfo();

    private:
        static void __sendRoomThread(const std::string room_name, const int player_num);
        static void __connectTcpThread(const std::string room_name, const int player_num);
};