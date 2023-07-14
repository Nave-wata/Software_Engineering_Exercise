/**
 * @file TCP.hpp
 * 
 * @brief TCPクラスのヘッダファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-07-07
 */

#pragma once

#include "coms/Socket.hpp"
#include <string>

/**
 * @brief TCP通信を行うクラス
 */
class TCP: public Socket {
    private:
        int sock = -2;

    public:
        TCP(const std::string, const int port=50000);
        ~TCP();
        void _send(const std::string msg);
        std::string _recv();
        void _listen();
        void _accept();
        int _connect();
};