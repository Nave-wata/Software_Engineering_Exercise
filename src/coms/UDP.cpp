/**
 * @file UDP.cpp
 * 
 * @brief UDPクラスのソースファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-07-06
 */

#include "coms/UDP.hpp"

/**
 * @brief UDPクラスのコンストラクタ
 * 
 * ソケット通信に必要なものをメンバ変数に格納する
 * 
 * @param ip 通信相手のIPアドレス
 * @param port 通信に使用するポート番号
 */
UDP::UDP(const std::string ip, const int port)
    : Socket(ip, port) {
    this->sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    this->addr.sin_family = AF_INET;
    if (this->ip == this->RECV_ALL) {
        this->addr.sin_addr.s_addr = INADDR_ANY;
    } else {
        this->addr.sin_addr.s_addr = inet_addr(this->ip.c_str());
    }
    this->addr.sin_port = htons(this->port);
}

/**
 * @brief UDP通信を受け付ける
 * 
 * @param msg 受信したメッセージ
 * @param ip 送信元のIPアドレス
 */
void UDP::_recv(std::string& msg, std::string& ip) {
    char buf[1024] = {'\0'};
    struct sockaddr_in from_addr;
    socklen_t from_len = sizeof(from_addr);
    recvfrom(this->sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&from_addr, &from_len);
    
    msg = buf;
    ip = inet_ntoa(from_addr.sin_addr);
}

/**
 * @brief UDP通信を受け付ける
 * 
 * @param msg 受信したメッセージ
 */
void UDP::_recv(std::string &msg) {
    std::string ip;
    this->_recv(msg, ip);
}

/**
 * @brief UDP通信を行う
 * 
 * @param msg 送信するメッセージ
 * @param ip 送信先のIPアドレス
 */
void UDP::_send(const std::string msg) {
    sendto(this->sockfd, msg.c_str(), msg.length(), 0, (struct sockaddr *)&this->addr, sizeof(this->addr));
}

/**
 * @brief ブロードキャストを行う
 * 
 * @param msg ブロードキャストするメッセージ
 */
void UDP::broadcast(const std::string msg) {
    int broadcast = 1;
    setsockopt(this->sockfd, SOL_SOCKET, SO_BROADCAST, (char *)&broadcast, sizeof(broadcast));
    sendto(this->sockfd, msg.c_str(), msg.length(), 0, (struct sockaddr *)&this->addr, sizeof(this->addr));
}
