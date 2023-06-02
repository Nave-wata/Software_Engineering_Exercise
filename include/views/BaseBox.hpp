/**
 * @file BaseBox.hpp
 * 
 * @brief BaseBoxクラスのヘッダファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-06-02
 */

#pragma once

#include <ncurses.h>

/**
 * @brief 位置情報を表す構造体
 * 
 * @param y y座標
 * @param x x座標
 */
typedef struct {
    int y;
    int x;
} Position;

/**
 * @brief BaseBoxクラス
 * 
 * ウィンドウにボックスを表示させるための基底クラス
 */
class BaseBox {
    protected:
        /** @brief ウィンドウの最大行数 */
        int y;

        /** @brief ウィンドウの最大列数 */
        int x;

        /** @brief ウィンドウの中心のy座標 */
        int center_y;

        /** @brief ウィンドウの中心のx座標 */
        int center_x;

        /** @brief ボックスの最大行数 */
        int box_y;

        /** @brief ボックスの最大列数 */
        int box_x;

        /** @brief ボックスの中心のy座標 */
        int box_center_y;

        /** @brief ボックスの中心のx座標 */
        int box_center_x;

        /** @brief ボックスのウィンドウ */
        WINDOW *win;


    public:
        BaseBox();
        virtual ~BaseBox();


    protected:
        void showBox(const int rows, const int cols, const int y, const int x);
        virtual void showContents()=0;
        virtual void keyWait()=0;
};