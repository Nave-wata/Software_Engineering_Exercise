#include "views/CreateRoomForm.hpp"
#include <string.h>
#include <iostream>

// コンストラクタ
CreateRoomForm::CreateRoomForm() {}

// デストラクタ
CreateRoomForm::~CreateRoomForm() {
    delwin(this->box_win);
    delwin(this->field_win);
}

// 部屋作成フォームを表示する
void CreateRoomForm::showForm() {
    // フォームのボックスを表示する
    this->showBox(
        this->FORM_BOX_HEIGHT,
        this->FORM_BOX_WIDTH,
        this->center_y - this->FORM_BOX_HEIGHT / 2,
        this->center_x - this->FORM_BOX_WIDTH / 2
    );
    this->box_win = this->win;

    // 入力フィールドのボックスを表示する
    this->showBox(
        this->FIELD_BOX_HEIGHT,
        this->FIELD_BOX_WIDTH,
        this->center_y - this->FIELD_BOX_HEIGHT / 2,
        this->center_x - this->FIELD_BOX_WIDTH / 4
    );
    this->field_win = this->win;

    this->showContents();
    wrefresh(this->box_win);
    wrefresh(this->field_win);
    this->keyWait();
}

// 部屋作成フォームの内容を表示する
void CreateRoomForm::showContents() {
    const int space = 4;
    this->title = {this->WIN_BASE_Y, this->WIN_BASE_X};
    this->field = {this->WIN_BASE_Y + space, this->WIN_BASE_X + this->FIELD_CENTER_X};

    mvwprintw(this->box_win, this->title.y, this->title.x, "Please enter the room name.");
    mvwprintw(this->box_win, this->field.y, this->field.x, "Room name: ");

}

// キー入力待ち
void CreateRoomForm::keyWait() {
    int c = '\0';
    char str[256] = {"\0"};
    int i = 0;

    // カーソルを入力フィールドに移動する
    wmove(this->field_win, 1, 1);
    wrefresh(this->field_win);

    curs_set(2);    // カーソルを表示する
    echo();         // 入力文字を表示する
    nocbreak();     // エンターキーを押すまで入力を保持する
    timeout(-1);    // キー入力待ち時間を無制限にする

    while (1) {
        c = wgetch(this->field_win);
        if (c == '\n') {
            if (this->FIELD_BOX_WIDTH - 2 >= i && str[0] != '\0' && str[0] != '\n') break;
            // 入力文字の初期化
            i = 0;
            memset(str, '\0', sizeof(str));

            // 入力フィールドをクリアする
            werase(this->field_win);
            box(this->field_win, 0, 0);
            
            // カーソルを入力フィールドに移動する
            wmove(this->field_win, 1, 1);
            wrefresh(this->field_win);
        } else str[i++] = c;
    }

    curs_set(0);    // カーソルを非表示にする
    noecho();       // 入力文字を非表示にする
    cbreak();       // キーを押すと即座に入力を処理する
}
