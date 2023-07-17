/**
 * @file CantConnectException.hpp
 * 
 * @brief CantConnectExceptionクラスのヘッダファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-07-17
 */

#pragma once

#include <stdexcept>

class CantConnectException: std::runtime_error {
    public:
        CantConnectException(const std::string& message);
};