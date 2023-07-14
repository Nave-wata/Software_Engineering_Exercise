/**
 * @file DuplicateRoomNameException.hpp
 * 
 * @brief DuplicateRoomNameExceptionクラスのヘッダファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-07-14
 */

#pragma once

#include <stdexcept>
#include <string>

class DuplicateRoomNameException: public std::runtime_error {
    public:
        DuplicateRoomNameException(const std::string& msg);
};