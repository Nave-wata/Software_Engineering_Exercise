/**
 * @file CreateRoomCom.cpp
 * 
 * @brief CreateRoomComクラスのソースファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-07-07
 */

#include "coms/CreateRoomCom.hpp"
#include "coms/Socket.hpp"
#include "utils/Sleep.hpp"
#include <thread>

UDP CreateRoomCom::udp;
std::vector<playerInfo> CreateRoomCom::player_infos;

/**
 * @brief 選択したプレイ人数分のコネクションを確立する
 * 
 * @param room_name 部屋名
 * @param n 選択したプレイ人数
 */
void CreateRoomCom::recvTcpInfo(const std::string room_name, const int n) {
    std::thread send_room_thread(CreateRoomCom::__sendRoomThread, room_name, n);
    std::thread connect_tcp_thread(CreateRoomCom::__connectTcpThread, room_name, n);
    send_room_thread.join();
    connect_tcp_thread.join();
}

/**
 * @brief 全プレイヤーが相互にコネクションをはってもらう
 * 
 * @return std::vector<playerInfo>
 */
std::vector<playerInfo> CreateRoomCom::sendTcpInfo() {
    for (int i = 0; i < static_cast<int>(CreateRoomCom::player_infos.size()); i++) {
        for (int j = 0; j < static_cast<int>(CreateRoomCom::player_infos.size()); j++) {
            if (i == j) {
                continue;
            }
            CreateRoomCom::player_infos[i].tcp._send(CreateRoomCom::player_infos[j].ip);
        }
    }
    return CreateRoomCom::player_infos;
}

/**
 * @brief 部屋情報をブロードキャストする
 * 
 * @param room_name 部屋名
 * @param player_num 選択したプレイ人数
 */
void CreateRoomCom::__sendRoomThread(const std::string room_name, const int player_num) {
    while (static_cast<int>(CreateRoomCom::player_infos.size()) < player_num) {
        CreateRoomCom::udp.broadcast(room_name);
        Sleep::milliSleep(500);
    }
}

/**
 * @brief 部屋に入室したプレイヤーとコネクションを確立する
 * 
 * @param room_name 部屋名
 * @param player_num 選択したプレイ人数
 */
void CreateRoomCom::__connectTcpThread(const std::string room_name, const int player_num) {
    while (static_cast<int>(player_infos.size()) < player_num) {
        std::string msg, ip;
        UDP _udp = UDP("0.0.0.0", CHECK_ROOM_NAME_PORT);
        _udp._bind();
        _udp._recv(msg, ip);

        if (msg != room_name) {
            continue;
        }

        TCP tcp = TCP(ip, TCP_PORT);
        tcp._bind();
        tcp._listen();
        tcp._accept();

        if (tcp._recv() != room_name) {
            continue;
        }

        playerInfo info = {
            room_name,
            ip,
            tcp
        };
        CreateRoomCom::player_infos.push_back(info);
    }
}