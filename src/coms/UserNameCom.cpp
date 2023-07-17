/**
 * @file UserNameCom.cpp
 * 
 * @brief UserNameComクラスのソースファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-07-18
 */

#include "coms/UserNameCom.hpp"

/**
 * @brief ユーザ名を送信する
 * 
 * @param user_name ユーザ名
 * @param sockfd ソケットファイルディスクリプタ
 */
void UserNameCom::sendUserName(const std::string user_name, const int sockfd) {
    TCP tcp = TCP(sockfd);
    tcp._send(user_name);
}

/**
 * @brief ユーザ名を受信する
 * 
 * @param player_infos プレイヤー情報
 * @param sockfd ソケットファイルディスクリプタ
 * @return std::vector<playerInfo> プレイヤー情報
 */
std::vector<playerInfo> UserNameCom::recvUserName(std::vector<playerInfo> &player_infos, const int sockfd) {
    TCP tcp = TCP(sockfd);
    player_infos[0].name = tcp._recv();;
    
    return player_infos;
}