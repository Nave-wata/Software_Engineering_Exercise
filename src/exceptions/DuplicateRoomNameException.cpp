/**
 * @file DuplicateRoomNameException.cpp
 * 
 * @brief DuplicateRoomNameExceptionクラスのソースファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-07-14
 */

#include "exceptions/DuplicateRoomNameException.hpp"

/**
 * @brief DuplicateRoomNameExceptionクラスのコンストラクタ
 * 
 * @param msg エラーメッセージ
 */
DuplicateRoomNameException::DuplicateRoomNameException(const std::string& msg)
    : runtime_error(msg) {}