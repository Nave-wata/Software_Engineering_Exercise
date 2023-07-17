/**
 * @file PlaySettings.hpp
 * 
 * @brief PlaySettingsクラスのヘッダファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-07-18
 */

#pragma once

#include "controllers/CreateOrJoinRoomController.hpp"
#include "controllers/CreateRoomController.hpp"
#include "controllers/JoinRoomController.hpp"
#include "controllers/SelectPlayerController.hpp"
#include "controllers/UserNameController.hpp"

class PlaySettings {
    private:
        /** @brief プレイ人数 */
        int player_num;

        /** @brief 部屋作成を選択したか */
        bool isCreateRoom;

        /** @brief 部屋入室を選択したか */
        bool isJoinRoom;

        /** @brief 通信相手の情報 */
        std::vector<playerInfo> player_infos;

        /** @brief ユーザー名 */
        std::string my_name;

    public:
        PlaySettings();
        std::vector<playerInfo> settings();
    
    private:
        void selectPlayerOfNumber();
        void createOrJoinRoom();
        void createRoom();
        void joinRoom();
        void inputUserName();
};
