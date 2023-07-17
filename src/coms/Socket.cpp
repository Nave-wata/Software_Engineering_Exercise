/**
 * @file Socket.cpp
 * 
 * @brief Socketクラスのソースファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-06-30
 */

#include "coms/Socket.hpp"

/**
 * @brief Socketクラスのコンストラクタ
 * 
 * ソケット通信に必要なものをメンバ変数に格納する
 * 
 * @param ip 通信相手のIPアドレス
 * @param port 通信に用いるポート番号
 */
Socket::Socket(const std::string ip, const int port)
    : ip(ip), port(port) {}

/**
 * @brief ポート番号を指定してソケット通信を開始する
 */
void Socket::_bind() {
    bind(this->sockfd, (struct sockaddr *)&this->addr, sizeof(this->addr));
}

/**
 * @brief ソケット通信に用いるソケットを取得する
 * 
 * @return ソケット通信に用いるソケット
 */
int Socket::getSockfd() {
    return this->sockfd;
}
