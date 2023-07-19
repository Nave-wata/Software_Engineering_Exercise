/**
 * @file SelectPlayerController.cpp
 * 
 * @brief SelectPlayerControllerクラスのソースファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-06-27
 */

#include "controllers/SelectPlayerController.hpp"
#include <ncurses.h>
#include <iostream>

/**
 * @brief プレイ人数の入力を受け付け，画面サイズを検証する
 */
void SelectPlayerController::selectPlayer() {
    // プレイ人数の入力フィールド画面を表示するサイズがあるか検証
    this->validation();

    return;

    select_player_form.showForm();
    this->player_num = select_player_form.getPlayerOfNumber();

    // 選択されたプレイ人数分の画面があるか検証
    this->validation();
}

/**
 * @brief 入力されたプレイ人数を返す
 * 
 * @return int 入力されたプレイ人数
 */
int SelectPlayerController::getPlayerOfNumber() {
    return this->player_num;
}

/**
 * @brief 画面サイズを検証する
 */
void SelectPlayerController::validation() {
    try {
        screen_size_validation.validation(this->player_num);
    } catch (std::exception &e) {
        endwin();
        std::cerr << e.what() << std::endl;
        exit(1);
    }
}
