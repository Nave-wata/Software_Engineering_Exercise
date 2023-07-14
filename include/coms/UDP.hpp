/**
 * @file UDP.hpp
 * 
 * @brief UDPクラスのヘッダファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-07-06
 */

#pragma once

#include "coms/Socket.hpp"
#include <string>

class UDP: public Socket {
    public:
        const std::string RECV_ALL = "RECV_ALL";

    public:
        UDP(const std::string ip="255.255.255.255", const int port=50000);
        void _send(const std::string msg);
        void _recv(std::string& msg, std::string& ip);
        void _recv(std::string& msg);
        void broadcast(const std::string msg);
};