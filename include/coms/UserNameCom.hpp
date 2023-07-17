/**
 * @file UserNameCom.hpp
 * 
 * @brief UserNameComクラスのヘッダファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-07-18
 */

#pragma once

#include <string>
#include "controllers/CreateRoomController.hpp"

class UserNameCom {
    public:
        void sendUserName(const std::string user_name, const int sockfd);
        std::vector<playerInfo> recvUserName(std::vector<playerInfo> &player_infos, const int sockfd);
};