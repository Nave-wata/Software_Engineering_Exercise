/**
 * @file TCP.cpp
 * 
 * @brief TCPクラスのソースファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-07-07
 */

#include "coms/TCP.hpp"
#include <iostream>

/**
 * @brief TCPクラスのコンストラクタ
 * 
 * ソケット通信に必要なものをメンバ変数に格納する
 * 
 * @param ip 通信相手のIPアドレス
 * @param port 通信に使用するポート番号
 */
TCP::TCP(const std::string ip, const int port)
    : Socket(ip, port) {
    this->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    this->addr.sin_family = AF_INET;
    this->addr.sin_addr.s_addr = inet_addr(this->ip.c_str());
    this->addr.sin_port = htons(this->port);
}

/**
 * @brief TCPクラスのデストラクタ
 * 
 * ソケット通信を終了する
 */
TCP::~TCP() {
    close(this->sock);
}

/**
 * @brief メッセージを送信する
 * 
 * @param msg 送信するメッセージ
 */
void TCP::_send(const std::string msg) {
    if (this->sock == -2) {
        send(this->sockfd, msg.c_str(), msg.length(), 0);
    } else {
        send(this->sock, msg.c_str(), msg.length(), 0);
    }
}

/**
 * @brief メッセージを受信する
 * 
 * @return std::string 受信したメッセージ
 */
std::string TCP::_recv() {
    char buf[1024] = {'\0'};

    if (this->sock == -2) {
        recv(this->sockfd, buf, sizeof(buf), 0);
    } else {
        recv(this->sock, buf, sizeof(buf), 0);
    }
    
    return std::string(buf);
}

/**
 * @brief 接続を待ち受ける
 */
void TCP::_listen() {
    listen(this->sockfd, 1);
}

/**
 * @brief 接続を受け入れる
 */
void TCP::_accept() {
    this->sock = accept(this->sockfd, NULL, NULL);
}

/**
 * @brief 接続を行う
 */
int TCP::_connect() {
    return connect(this->sockfd, (struct sockaddr *)&this->addr, sizeof(this->addr));
}