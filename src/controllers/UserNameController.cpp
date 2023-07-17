/**
 * @file UserNameController.cpp
 * 
 * @brief UserNameControllerクラスのソースファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-07-18
 */

#include "controllers/UserNameController.hpp"

/**
 * @brief UserNameControllerクラスのコンストラクタ
 */
UserNameController::UserNameController()
    : form("Please enter your name.", "User name: ") {}

/**
 * @brief 入力されたユーザ名を取得する
 */
std::string UserNameController::inputUserName() {
    return this->form.showForm();
}

/**
 * @brief ユーザ名を設定する
 * 
 * @param host ホストかどうか
 * @param player_infos プレイヤー情報
 * @param user_name ユーザ名 
 * @param player_infos プレイヤー情報
 */
void UserNameController::setUserName(
    const bool host, 
    std::vector<playerInfo> &player_infos, 
    const std::string user_name
) {
    if (host) {
        this->com.sendUserName(user_name, player_infos[0].sockfd);
        this->com.recvUserName(player_infos, player_infos[0].sockfd);
    } else {
        this->com.recvUserName(player_infos, player_infos[0].sockfd);
        this->com.sendUserName(user_name, player_infos[0].sockfd);
    }
}
