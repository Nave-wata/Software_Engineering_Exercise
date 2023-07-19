/**
 * @file ReadSettings.hpp
 * 
 * @brief ReadSettingsクラスのヘッダファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-06-23
 */

#pragma once

#include <fstream>
#include <string>

/**
 * @brief 各種設定を保存する構造体
 */
typedef struct {
    /** @brief 上キー */
    int key_up;

    /** @brief 下キー */
    int key_down;

    /** @brief 左キー */
    int key_left;

    /** @brief 右キー */
    int key_right;

    /** @brief 左回転キー */
    int key_left_rotate;

    /** @brief 右回転キー */
    int key_right_rotate;

    /** @brief 一時停止キー */
    int key_pause;

    /** @brief 終了キー */
    int key_quit;

    /** @brief 落下速度 */
    int gravity;

    /** @brief 1度に落下するおじゃまぷよの最大行数 */
    int nuisance_puyo_max_row;

    /** @brief 全消し後のスコア倍率 */
    double all_clear_magnification;

    /** @brief おじゃまぷよレート */
    int nuisance_puyo_rate;
} Settings;

/**
 * @brief 設定ファイルを読み込むクラス
 */
class ReadSettings {
    private:
        /** @brief ファイル */
        std::ifstream ifs;

        /** @brief 各種設定 */
        Settings settings;

        /** @brief ファイルパス */
        const std::string file_path = "./setting.txt";

        /** @brief 上キーの項目名 */
        const std::string keyUp = "KEY_UP";
        
        /** @brief 下キーの項目名 */
        const std::string keyDown = "KEY_DOWN";

        /** @brief 左キーの項目名 */
        const std::string keyLeft = "KEY_LEFT";

        /** @brief 右キーの項目名 */
        const std::string keyRight = "KEY_RIGHT";

        /** @brief 左回転キーの項目名 */
        const std::string keyLeftRotate = "KEY_LEFT_ROTATE";

        /** @brief 右回転キーの項目名 */
        const std::string keyRightRotate = "KEY_RIGHT_ROTATE";

        /** @brief 一時停止キーの項目名 */
        const std::string keyPause = "KEY_PAUSE";

        /** @brief 終了キーの項目名 */
        const std::string keyQuit = "KEY_QUIT";

        /** @brief 落下速度の項目名 */
        const std::string gravity = "GRAVITY";

        /** @brief 1度に落下するおじゃまぷよの最大行数の項目名 */
        const std::string nuisancePuyoMaxRow = "NUISANCE_PUYO_MAX_ROW";

        /** @brief 全消し後のスコア倍率の項目名 */
        const std::string allClearMagnification = "ALL_CLEAR_MAGNIFICATION";

        /** @brief おじゃまぷよレートの項目名 */
        const std::string nuisancePuyoRate = "NUISANCE_PUYO_RATE";

    public:
        ReadSettings();
        ~ReadSettings();
        Settings read();
};