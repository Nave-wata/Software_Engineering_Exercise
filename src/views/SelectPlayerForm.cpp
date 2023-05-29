#include "views/SelectPlayerForm.hpp"

// コンストラクタ
SelectPlayerForm::SelectPlayerForm() {
    getmaxyx(stdscr, this->y, this->x);
    this->center_y = this->y / 2;
    this->center_x = this->x / 2;
}

// デストラクタ
SelectPlayerForm::~SelectPlayerForm() {}

// プレイ人数選択メニューを表示する
void SelectPlayerForm::showForm() {
    this->showBox();
    this->showContents();
    wrefresh(this->win);
    this->keyWait();
}

// メニューボックスを表示する
void SelectPlayerForm::showBox() {
    int y, x;
    this->win = newwin(
        this->FORM_BOX_HEIGHT, this->FORM_BOX_WIDTH,
        this->center_y - this->FORM_BOX_HEIGHT / 2, this->center_x - this->FORM_BOX_WIDTH / 2
    );

    getmaxyx(this->win, y, x);
    this->box_center_y = y / 2;
    this->box_center_x = x / 2;

    box(this->win, 0, 0);
}

// 選択可能人数を表示する
void SelectPlayerForm::showContents() {
    const int space = 3;
    this->title = {this->WIN_BASE_Y, 2};
    this->play1 = {this->WIN_BASE_Y + space, this->box_center_x - this->NUMBERS_CENTER_X + 1};
    this->play2 = {this->WIN_BASE_Y + space + 1, this->box_center_x - this->NUMBERS_CENTER_X + 1};
    this->play3 = {this->WIN_BASE_Y + space + 2, this->box_center_x - this->NUMBERS_CENTER_X + 1};
    this->play4 = {this->WIN_BASE_Y + space + 3, this->box_center_x - this->NUMBERS_CENTER_X + 1};

    mvwprintw(this->win, this->title.y, this->title.x, "Please select the number of players.");
    mvwprintw(this->win, this->play1.y, this->play1.x, "[ ] 1");
    mvwprintw(this->win, this->play2.y, this->play2.x, "[ ] 2");
    mvwprintw(this->win, this->play3.y, this->play3.x, "[ ] 3");
    mvwprintw(this->win, this->play4.y, this->play4.x, "[ ] 4");
}

// キー入力待ち
void SelectPlayerForm::keyWait() {
    int c = '\0';

    Position cursor = {-1, -1};

    timeout(-1);
    while (c != 'q') {
        c = getch();
        switch (c) {
            case KEY_DOWN:
                if (cursor.y == -1) {
                    cursor = this->play1;
                    cursor.x++;
                    mvwaddch(this->win, cursor.y, cursor.x, '*');
                } else if (cursor.y == this->play4.y) {
                    // 何もしない
                } else {
                    mvwaddch(this->win, cursor.y, cursor.x, ' ');
                    cursor.y++;
                    mvwaddch(this->win, cursor.y, cursor.x, '*');
                }
                break;
            case KEY_UP:
                if (cursor.y == -1) { 
                    cursor = this->play4;
                    cursor.x++;
                    mvwaddch(this->win, cursor.y, cursor.x, '*');
                } else if (cursor.y == this->play1.y) {
                    // 何もしない
                } else {
                    mvwaddch(this->win, cursor.y, cursor.x, ' ');
                    cursor.y--;
                    mvwaddch(this->win, cursor.y, cursor.x, '*');
                }
                break;
            case KEY_ENTER:
                if (cursor.y != -1) {
                    // プレイ人数決定
                }
                break;
        };
        wrefresh(this->win);
    }
}