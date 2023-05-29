#include "views/CreateOrJoinRoomForm.hpp"
#include <string>

// 部屋作成・参加メニューを表示する
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

// 選択可能なメニューを表示する
void CreateOrJoinRoomForm::showContents() {
    const int space = 5;
    this->title = {this->WIN_BASE_Y, 2};
    this->create = {this->WIN_BASE_Y + space, this->box_center_x + this->CREATE_CENTER_X};
    this->join = {this->WIN_BASE_Y + space, this->box_center_x + this->JOIN_CENTER_X};

    mvwprintw(this->win, this->title.y, this->title.x, "Choose whether you want to create ");
    mvwprintw(this->win, this->title.y + 1, this->title.x, "or join a room");

    mvwprintw(this->win, this->create.y, this->create.x, "[ ] Create");
    mvwprintw(this->win, this->join.y, this->join.x, "[ ] Join");
}

// キー入力待ち
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
                        // 部屋の作成
                        return;
                    } else if (cursor.x == this->join.x + 1) {
                        // 部屋の参加
                        return;
                    }
                }
                break;
        }
        wrefresh(this->win);
    }
}
