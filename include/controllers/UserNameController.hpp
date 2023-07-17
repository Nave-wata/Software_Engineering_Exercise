/**
 * @file UserNameController.hpp
 * 
 * @brief UserNameControllerクラスのヘッダファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-07-18
 */

#pragma once

#include <string>

#include "views/UserNameForm.hpp"
#include "coms/UserNameCom.hpp"
#include "controllers/CreateRoomController.hpp"

class UserNameController {
    private:
        /** @brief UserNameForm のインスタンス */
        UserNameForm form;

        /** @brief UserNameCom のインスタンス */
        UserNameCom com;

        /** @brief ユーザ名 */
        std::string user_name;

    public:
        UserNameController();
        std::string inputUserName();
        void setUserName(const bool host, std::vector<playerInfo> &player_infos, const std::string user_name);
};