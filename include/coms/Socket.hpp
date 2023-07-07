/**
 * @file Socket.hpp
 * 
 * @brief Socketクラスのヘッダファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-06-30
 */

#pragma once

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>

/**
 * @brief ソケット通信を行うクラス
 */
class Socket {
    protected:
        /** @brief 通信に用いるソケット */
        int sockfd = -2;

        /** @brief 接続先情報 */
        struct sockaddr_in addr;

        /** @brief 通信相手のIPアドレス */
        const std::string ip;

        /** @brief 通信に用いるポート番号 */
        const int port;

    public:
        Socket(const std::string ip, const int port);
        virtual ~Socket();
        void _bind();
};