/**
 * @file ScreenSizeException.cpp
 * 
 * @brief ScreenSizeExceptionクラスのソースファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-06-30
 */

#include "exceptions/ScreenSizeException.hpp"

/**
 * @brief ScreenSizeExceptionクラスのコンストラクタ
 * 
 * @param msg string エラーメッセージ
 */
ScreenSizeException::ScreenSizeException(const std::string& msg)
    : runtime_error(msg) {}
