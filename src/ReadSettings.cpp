/**
 * @file ReadSettings.cpp
 * 
 * @brief ReadSettingsクラスのソースファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-06-23
 */

#include "ReadSettings.hpp"
#include <ncurses.h>
#include <exception>

/**
 * @brief ReadSettingsクラスのコンストラクタ
 * 
 * ファイルを開く
 * 各種設定の初期値を設定する
 */
ReadSettings::ReadSettings() :
    ifs(std::ifstream(this->file_path)), settings({
        KEY_UP,     // 上キー
        KEY_DOWN,   // 下キー
        KEY_LEFT,   // 左キー
        KEY_RIGHT,  // 右キー
        's',        // 左回転キー
        'd',        // 右回転キー
        'p',        // 一時停止キー
        'q',        // 終了キー
        10,         // 落下速度
        3,          // 1度に落下するおじゃまぷよの最大行数
        2.0,        // 全消し後のスコア倍率
        80          // おじゃまぷよレート
    }) {
        ifs.open(this->file_path);
    }

/**
 * @brief ReadSettingsクラスのデストラクタ
 * 
 * ファイルを閉じる
 */
ReadSettings::~ReadSettings() {
    this->ifs.close();
}

/**
 * @brief 設定ファイルを読み込む
 * 
 * @return settings 設定
 */
Settings ReadSettings::read() {
    // ファイル読み込みに失敗したらデフォルトの設定を返す
    if (!this->ifs) {
        return this->settings;
    }

    // ファイル読み込み
    std::string line;
    while (std::getline(this->ifs, line)) {
        // 項目名と値に分割
        std::string itemKey = line.substr(0, line.find("="));
        std::string itemValue = line.substr(line.find("=") + 1);

        // 項目名と一致し，問題のない値であれば設定を更新する
        try {
            if (itemKey == this->keyUp && itemValue.length() == 1) {
                this->settings.key_up = static_cast<int>(*itemValue.c_str());
            }
            else if (itemKey == this->keyDown && itemValue.length() == 1) {
                this->settings.key_down = static_cast<int>(*itemValue.c_str());
            }
            else if (itemKey == this->keyLeft && itemValue.length() == 1) {
                this->settings.key_left = static_cast<int>(*itemValue.c_str());
            }
            else if (itemKey == this->keyRight && itemValue.length() == 1) {
                this->settings.key_right = static_cast<int>(*itemValue.c_str());
            }
            else if (itemKey == this->keyLeftRotate && itemValue.length() == 1) {
                this->settings.key_left_rotate = static_cast<int>(*itemValue.c_str());
            }
            else if (itemKey == this->keyRightRotate && itemValue.length() == 1) {
                this->settings.key_right_rotate = static_cast<int>(*itemValue.c_str());
            }
            else if (itemKey == this->keyPause && itemValue.length() == 1) {
                this->settings.key_pause = static_cast<int>(*itemValue.c_str());
            }
            else if (itemKey == this->keyQuit && itemValue.length() == 1) {
                this->settings.key_quit = static_cast<int>(*itemValue.c_str());
            }
            else if (itemKey == this->gravity) {
                this->settings.gravity = std::stoi(itemValue);
            }
            else if (itemKey == this->nuisancePuyoMaxRow) {
                this->settings.nuisance_puyo_max_row = std::stoi(itemValue);
            }
            else if (itemKey == this->allClearMagnification) {
                this->settings.all_clear_magnification = std::stod(itemValue);
            }
            else if (itemKey == this->nuisancePuyoRate) {
                this->settings.nuisance_puyo_rate = std::stoi(itemValue);
            }
        } catch (std::exception &e) {
            continue;
        }
    }

    return this->settings;
}