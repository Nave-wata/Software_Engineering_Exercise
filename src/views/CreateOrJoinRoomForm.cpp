/**
 * @file CreateOrJoinRoomForm.cpp
 * 
 * @brief 部屋作成・参加選択フォームのソースファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-06-02
 */

#include "views/CreateOrJoinRoomForm.hpp"
#include <string>

/**
 * @brief コンストラクタ
 */
CreateOrJoinRoomForm::CreateOrJoinRoomForm() {}

/**
 * @brief デストラクタ
 */
CreateOrJoinRoomForm::~CreateOrJoinRoomForm() {}

/**
 * @brief 部屋作成・参加選択フォームを表示する
 * 
 * @return void
 */
void CreateOrJoinRoomForm::showForm() {
    this->showBox(
        this->FORM_BOX_HEIGHT,
        this->FORM_BOX_WIDTH,
        this->center_y - this->FORM_BOX_HEIGHT / 2,
        this->center_x - this->FORM_BOX_WIDTH / 2
    );
    this->showContents();
    wrefresh(this->win);
    this->keyWait();
}

/**
 * @brief 部屋の操作を返す
 * 
 * @return int 部屋の操作
 */
int CreateOrJoinRoomForm::getAction() {
    return this->action;
}

/**
 * @brief 選択可能な項目を表示する
 * 
 * @return void
*/
void CreateOrJoinRoomForm::showContents() {
    const int space = 5;
    this->title = {this->WIN_BASE_Y, 2};
    this->create = {this->WIN_BASE_Y + space, this->box_center_x + this->CREATE_CENTER_X};
    this->join = {this->WIN_BASE_Y + space, this->box_center_x + this->JOIN_CENTER_X};

    mvwprintw(this->win, this->title.y, this->title.x, "Choose to create or enter a room.");

    mvwprintw(this->win, this->create.y, this->create.x, "[ ] Create");
    mvwprintw(this->win, this->join.y, this->join.x, "[ ] Join");
}

/**
 * @brief キーの入力処理
 * 
 *  - q: 終了
 *  - 右キー: 選択項目を右に移動
 *  - 左キー: 選択項目を左に移動
 *  - Enter: 選択項目を決定
 * 
 * @return void
 */
void CreateOrJoinRoomForm::keyWait() {
    int c = '\0';

    Position cursor = {-1, -1};

    timeout(-1);
    while (c != 'q') {
        c = getch();
        switch (c) {
            case KEY_RIGHT:
                if (cursor.y == -1) {
                    cursor = this->create;
                    cursor.x++;
                    mvwaddch(this->win, cursor.y, cursor.x, '*');
                } else {
                    mvwaddch(this->win, cursor.y, cursor.x, ' ');
                    cursor = this->join;
                    cursor.x++;
                    mvwaddch(this->win, cursor.y, cursor.x, '*');
                }
                break;
            case KEY_LEFT:
                if (cursor.y == -1) {
                    cursor = this->join;
                    cursor.x++;
                    mvwaddch(this->win, cursor.y, cursor.x, '*');
                } else {
                    mvwaddch(this->win, cursor.y, cursor.x, ' ');
                    cursor = this->create;
                    cursor.x++;
                    mvwaddch(this->win, cursor.y, cursor.x, '*');
                }
                break;
            case '\n':
                if (cursor.y != -1) {
                    if (cursor.x == this->create.x + 1) {
                        this->action = CREATE_ROOM;
                        return;
                    } else if (cursor.x == this->join.x + 1) {
                        this->action = JOIN_ROOM;
                        return;
                    }
                }
                break;
        }
        wrefresh(this->win);
    }
}
