/**
 * @file ScreenSizeException.hpp
 * 
 * @brief ScreenSizeExceptionクラスのヘッダファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-06-30
 */

#pragma once

#include <stdexcept>
#include <string>

/**
 * @brief 画面サイズが不正な場合の例外クラス
 */
class ScreenSizeException: public std::runtime_error {
    public:
        ScreenSizeException(const std::string& msg);
};