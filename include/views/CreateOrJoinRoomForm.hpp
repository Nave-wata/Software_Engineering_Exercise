/**
 * @file CreateOrJoinRoomForm.hpp
 * 
 * @brief 部屋作成・参加フォームのヘッダファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-06-02
 */

#pragma once

#include "views/BaseBox.hpp"

#define CREATE_ROOM 1
#define JOIN_ROOM 2

/**
 * @brief 部屋作成・参加フォームクラス
 * 
 * 部屋の作成・参加を選択するウィンドウを表示する
 */
class CreateOrJoinRoomForm: public BaseBox {
    private:
        /** @brief ウィンドウの行数 */
        const int FORM_BOX_HEIGHT = 12;

        /** @brief ウィンドウの列数 */
        const int FORM_BOX_WIDTH = 40;

        /** @brief 他変数に依存 部屋作成項目の表示位置 x軸 */
        const int CREATE_CENTER_X = -12;

        /** @brief 他変数に依存 部屋入室項目の表示位置 x軸 */
        const int JOIN_CENTER_X = 3;

        /** @brief ボックス内でコンテンツを表示し始める位置 y軸 */
        const int WIN_BASE_Y = 2;

        /** @brief 部屋の操作 */
        int action;

        /** @brief タイトルを表示し始める位置 */
        Position title;

        /** @brief 部屋作成項目を表示し始める位置 */
        Position create;

        /** @brief 部屋入室項目を表示し始める位置 */
        Position join;

    public:
        CreateOrJoinRoomForm();
        ~CreateOrJoinRoomForm();
        void showForm();
        int getAction();

    protected:
        void showContents() override;
        void keyWait() override;
};