/**
 * @file SearchRoomCom.hpp
 * 
 * @brief SearchRoomComクラスのヘッダファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-07-14
 */

#pragma once

#include "coms/UDP.hpp"
#include <vector>

typedef struct {
    std::string room_name;
    std::string ip;
} roomInfo;

class SearchRoomCom {
    public:
        SearchRoomCom();
        std::vector<roomInfo> recvRoomInfo();
};