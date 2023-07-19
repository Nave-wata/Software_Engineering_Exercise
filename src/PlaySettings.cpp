/**
 * @file PlaySettings.cpp
 * 
 * @brief PlaySettingsクラスのソースファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-07-18
 */

#include "PlaySettings.hpp"

/**
 * @brief PlaySettingsクラスのコンストラクタ
 */
PlaySettings::PlaySettings()
    : player_num(0)
    , isCreateRoom(false)
    , isJoinRoom(false)
    , player_infos({})
    , my_name("") {}

/**
 * @brief プレイ設定を行う
 */
std::vector<playerInfo> PlaySettings::settings() {
    this->selectPlayerOfNumber();

    return this->player_infos;

    if (this->player_num != 1) {
        this->createOrJoinRoom();

        if (this->isCreateRoom) this->createRoom();
        else if (this->isJoinRoom) this->joinRoom();

        this->inputUserName();
    }

    return this->player_infos;
}

/**
 * @brief プレイヤー人数を選択する
 */
void PlaySettings::selectPlayerOfNumber() {
    SelectPlayerController controller = SelectPlayerController();
    controller.selectPlayer();
    this->player_num = controller.getPlayerOfNumber();
}

/**
 * @brief 部屋作成・参加を選択する
 */
void PlaySettings::createOrJoinRoom() {
    CreateOrJoinRoomController controller = CreateOrJoinRoomController();
    controller.createOrJoin();

    if (controller.getAction() == CREATE_ROOM) {
        this->isCreateRoom = true;
    } else if (controller.getAction() == JOIN_ROOM) {
        this->isJoinRoom = true;
    }
}

/**
 * @brief 部屋を作成する
 */
void PlaySettings::createRoom() {
    CreateRoomController controller = CreateRoomController();

    std::string room_name = controller.inputRoomName();
    std::vector<playerInfo> player_infos = controller.createRoom(room_name);

    this->player_infos = player_infos;
}

/**
 * @brief 部屋に入室する
 */
void PlaySettings::joinRoom() {
    JoinRoomController controller = JoinRoomController();

    RoomInfo room_info = controller.show();
    std::vector<playerInfo> player_infos = controller.joinRoom(room_info);

    this->player_infos = player_infos;
}

/**
 * @brief ユーザー名を入力する
 */
void PlaySettings::inputUserName() {
    UserNameController controller = UserNameController();
    this->my_name = controller.inputUserName();
    controller.setUserName(this->isCreateRoom, this->player_infos, this->my_name);
}