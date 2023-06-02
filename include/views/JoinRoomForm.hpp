/**
 * @file JoinRoomForm.hpp
 * 
 * @brief JoinRoomFormクラスのヘッダファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-06-02
 */

#pragma once

#include "views/BaseBox.hpp"
#include <vector>

/**
 * @brief 部屋情報を格納する構造体
 * 
 * @param room_name 部屋名
 * @param ip_address IPアドレス
 */
typedef struct {
    char* room_name;
    char* ip_address;
} RoomInfo;

/**
 * @brief 文字のカラーセット
 */
enum colors {
    BG_WHITE = 1
};

/**
 * @brief 部屋入室フォームクラス
 * 
 * 入室可能な部屋一覧を表示し，プレイヤーからの選択を待ち受ける
 */
class JoinRoomForm: public BaseBox {
    private:
        /** @brief フォームウィンドウの行数 */
        const int FORM_BOX_HEIGHT = 12;

        /** @brief フォームウィンドウの列数 */
        const int FORM_BOX_WIDTH = 40;

        /** @brief 入力フィールドの行数 */
        const int FIELD_BOX_HEIGHT = 6;

        /** @brief 入力フィールドの列数 */
        const int FIELD_BOX_WIDTH = 30;

        /** @brief 入力フィールドを表示する際の調整用 y軸 */
        const int FIELD_SPACE_Y = 1;

        /** @brief 入力フィールドのフレーム数 */
        const int FIELD_FRAME = 2;

        /** @brief 入力フィールドを表示し始める位置調整用 x軸 */
        const int FIELD_CENTER_X = 2;

        /** @brief "reload" 文字（ボタン）を表示し始める位置調整用 y軸 */
        const int RELOAD_SPACE_Y = 5;

        /** @brief "reload" 文字（ボタン）を表示し始める位置調整用 x軸 */
        const int RELOAD_CENTER_X = -3;

        /** @brief ボックス内でコンテンツを表示し始める位置 y軸 */
        const int WIN_BASE_Y = 2;

        /** @brief ボックス内でコンテンツを表示し始める位置 x軸 */
        const int WIN_BASE_X = 2;

        /** @brief 選択可能な部屋一覧 */
        std::vector<RoomInfo> room_infos;

        /** @brief フォームウィンドウ */
        WINDOW *box_win;

        /** @brief 入力フィールドのウィンドウ */
        WINDOW *field_win;

        /** @brief タイトルを表示し始める位置 */
        Position title;

        /** @brief 部屋一覧を表示し始める位置 */
        Position field;

        /** @brief "reload" 文字（ボタン）を表示し始める位置 */
        Position reload;

    public:
        JoinRoomForm();
        ~JoinRoomForm();
        void showForm();

    protected:
        void showContents() override;
        void keyWait() override;

    private:
        inline void cursorInit(Position&, int&);
        inline void changeCursorReload(const int);
        inline void selectFieldRoom(std::vector<RoomInfo>&);
        inline void updateField(const int, const std::vector<RoomInfo>);
};