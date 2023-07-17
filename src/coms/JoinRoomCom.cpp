/**
 * @file JoinRoomCom.cpp
 * 
 * @brief JoinRoomComクラスのソースファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-07-16
 */

#include "coms/JoinRoomCom.hpp"
#include "coms/UDP.hpp"
#include "coms/TCP.hpp"

/**
 * @brief JoinRoomComクラスのコンストラクタ
 * 
 * @param room_name 入出する部屋名
 * @param ip 通信先IPアドレス
 */
JoinRoomCom::JoinRoomCom(const std::string room_name, const std::string ip)
    : room_name(room_name), ip(ip) {}

/**
 * @brief 部屋に入室する
 * 
 * @return bool
 */
bool JoinRoomCom::join() {
    UDP udp = UDP(this->ip, CHECK_ROOM_NAME_PORT);
    TCP tcp = TCP(this->ip, TCP_PORT);

    udp._send(this->room_name);

    if (tcp._connect()) {
        playerInfo player_info = {
            this->room_name,
            this->ip,
            "",
            tcp.getSockfd()};
        this->player_infos.push_back(player_info);
        return true;
    }

    return false;
}

/**
 * @brief 部屋に入室したプレイヤーの情報を受け取る
 * 
 * @return std::vector<playerInfo> 
 */
std::vector<playerInfo> JoinRoomCom::recvPlayerInfo() {
    return this->player_infos;

    // TCP host_tcp = TCP(this->player_infos[0].sockfd);

    // for (int i = 0; i < player_num; i++) {
    //     std::string recv_data = host_tcp._recv();
    //     std::string type = recv_data.substr(0, 1);
    //     std::string ip = recv_data.substr(1);

    //     TCP tcp = TCP(ip, TCP_PORT);

    //     if (type == "s") {
    //         tcp._connect();

    //         this->player_infos.push_back({this->room_name, ip, tcp.getSockfd()});
    //     } else if (type == "r") {
    //         tcp._bind();
    //         tcp._listen();
    //         int sockfd = tcp._accept();

    //         this->player_infos.push_back({this->room_name, ip, sockfd});
    //     }
    // }
    
    // return this->player_infos;
}