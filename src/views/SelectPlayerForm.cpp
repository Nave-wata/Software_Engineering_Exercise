/**
 * @file SelectPlayerForm.cpp
 * 
 * @brief SelectPlayerFormクラスのソースファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-06-02
 */

#include "views/SelectPlayerForm.hpp"

/**
 * @brief コンストラクタ
 */
SelectPlayerForm::SelectPlayerForm() {}

/**
 * @brief デストラクタ
 */
SelectPlayerForm::~SelectPlayerForm() {}

/**
 * @brief プレイ人数選択フォームを表示する
 * 
 * @return void
 */
void SelectPlayerForm::showForm() {
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
 * @brief フォームのコンテンツを表示する
 * 
 * @return void
 */
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

/**
 * @brief プレイヤーからのキー入力を待ち受ける
 * 
 * @return void
 */
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
            case '\n':
                if (cursor.y != -1) {
                    if (cursor.y == this->play1.y) {
                        // 1人プレイ
                        return;
                    } else if (cursor.y == this->play2.y) {
                        // 2人プレイ
                        return;
                    } else if (cursor.y == this->play3.y) {
                        // 3人プレイ
                        return;
                    } else if (cursor.y == this->play4.y) {
                        // 4人プレイ
                        return;
                    }
                }
                break;
        };
        wrefresh(this->win);
    }
}
