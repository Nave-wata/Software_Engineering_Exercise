/**
 * @file CantConnectException.cpp
 * 
 * @brief CantConnectExceptionクラスのソースファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-07-17
 */

#include "exceptions/CantConnectException.hpp"

/**
 * @brief CantConnectExceptionクラスのコンストラクタ
 * 
 * @param message エラーメッセージ
 */
CantConnectException::CantConnectException(const std::string& message)
    : std::runtime_error(message) {}