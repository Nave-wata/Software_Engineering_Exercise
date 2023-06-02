/**
 * @file JoinRoomForm.cpp
 * 
 * @brief JoinRoomFormクラスのソースファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-06-02
 */

#include "views/JoinRoomForm.hpp"

/**
 * @brief コンストラクタ
 */
JoinRoomForm::JoinRoomForm() {
    // カラーセットの作成
    init_pair(BG_WHITE, COLOR_BLACK, COLOR_WHITE);

    // ダミーデータを作成
    for (int i = 1; i <= 9; i++) {
        RoomInfo room_info;
        room_info.room_name = new char[256];
        room_info.ip_address = new char[256];
        sprintf(room_info.room_name, "Room %d", i);
        sprintf(room_info.ip_address, "150.89.0.%d", i);
        this->room_infos.push_back(room_info);
    }
}

/**
 * @brief デストラクタ
 */
JoinRoomForm::~JoinRoomForm() {
    delwin(this->box_win);
    delwin(this->field_win);
}

/**
 * @brief 部屋入室フォームを表示する
 * 
 * @return void
 */
void JoinRoomForm::showForm() {
    int y, x;

    // フォームのボックスを表示する
    this->showBox(
        this->FORM_BOX_HEIGHT,
        this->FORM_BOX_WIDTH,
        this->center_y - this->FORM_BOX_HEIGHT / 2,
        this->center_x - this->FORM_BOX_WIDTH / 2
    );
    this->box_win = this->win;
    y = this->box_center_y;
    x = this->box_center_x;

    // 入力フィールドのボックスを表示する
    this->showBox(
        this->FIELD_BOX_HEIGHT,
        this->FIELD_BOX_WIDTH,
        this->center_y - this->FIELD_BOX_HEIGHT / 2 + this->FIELD_SPACE_Y,
        this->center_x - this->FIELD_BOX_WIDTH / 2
    );
    this->field_win = this->win;
    this->box_center_y = y;
    this->box_center_x = x;

    this->showContents();
    wrefresh(this->box_win);
    wrefresh(this->field_win);
    this->keyWait();
}

/**
 * @brief 入出可能な部屋の一覧を表示する
 * 
 * @return void
 */
void JoinRoomForm::showContents() {
    const int space = 3;
    this->title = {this->WIN_BASE_Y, this->WIN_BASE_X};
    this->field = {this->WIN_BASE_Y + space, this->WIN_BASE_X + this->FIELD_CENTER_X};
    this->reload = {this->WIN_BASE_Y + space + this->RELOAD_SPACE_Y, this->box_center_x + this->RELOAD_CENTER_X};

    mvwprintw(this->box_win, this->title.y, this->title.x, "Please select the room name.");
    mvwprintw(this->box_win, this->reload.y, this->reload.x, "reload");

    for (int i = 0; i < this->FIELD_BOX_HEIGHT - this->FIELD_FRAME; i++) {
        mvwprintw(this->field_win, i + 1, 1, this->room_infos[i].room_name);
    }
}

/**
 * @brief キー入力待ち
 * 
 * @return void
 */
void JoinRoomForm::keyWait() {
    const int init = -1;
    const int reload = -2; 
    const int default_color = 0;
    int c = '\0';
    int i = 0;
    std::vector<RoomInfo> show_room_infos;

     // {1 ~ 4, _} カーソル範囲，{-1, _} 初期値，{-2, _} リロード
    Position cursor = {init, init};
    Position prev_cursor = {init, init};

    this->selectFieldRoom(show_room_infos);
    // キー入力処理
    timeout(-1);
    while ((c = getch()) != 'q') {
        switch (c) {
            case KEY_DOWN:
                if (cursor.y == reload) break;
                if (cursor.y == init) cursorInit(cursor, i); 
                else if (cursor.y == this->FIELD_BOX_HEIGHT - this->FIELD_FRAME && i < (int) this->room_infos.size() - 1) {
                    i++;
                    show_room_infos.push_back(this->room_infos[i]);
                    show_room_infos.erase(show_room_infos.begin());
                } else {
                    if (cursor.y < this->FIELD_BOX_HEIGHT - this->FIELD_FRAME) cursor.y++;
                    if (i < (int) this->room_infos.size() - 1) i++;
                }
                this->updateField(cursor.y, show_room_infos);
                break;
            case KEY_UP:
                if (cursor.y == reload) break;
                if (cursor.y == init) {
                    cursor = {this->FIELD_BOX_HEIGHT - this->FIELD_FRAME, 1};
                    i = this->FIELD_BOX_HEIGHT - this->FIELD_FRAME - 1;
                } else if (cursor.y == 1 && i > 0) {
                    i--;
                    show_room_infos.insert(show_room_infos.begin(), this->room_infos[i]);
                    show_room_infos.pop_back();
                } else {
                    if (cursor.y > 1) cursor.y--;
                    if (i > 0) i--;
                }
                this->updateField(cursor.y, show_room_infos);
                break;
            case '\t':
                if (cursor.y == init) cursorInit(cursor, i);
                else if (cursor.y == reload) {
                    cursor = prev_cursor;
                    this->changeCursorReload(default_color);
                } else {
                    prev_cursor = cursor;
                    cursor = {-2, 1};
                    this->changeCursorReload(BG_WHITE);
                }
                this->updateField(cursor.y, show_room_infos);
                break;
            case '\n':
                if (cursor.y == init);
                else if (cursor.y == reload) {
                    cursorInit(cursor, i);
                    this->changeCursorReload(default_color);
                    this->selectFieldRoom(show_room_infos);
                    this->updateField(cursor.y, show_room_infos);
                } else {
                    // 部屋入室
                    return;
                }
        }
    }
}

/**
 * @brief カーソルの位置を選択可能な部屋の一番上になるよう初期化する
 * 
 * @param cursor 初期化したいカーソル
 * @param i 選択可能な部屋のインデックス
 * @return void
 */
void JoinRoomForm::cursorInit(Position &cursor, int &i) {
    cursor = {1, 1};
    i = 0;
}

/**
 * @brief リロードの文字を更新する
 * 
 * @param color 更新する色
 * @return void
 */
void JoinRoomForm::changeCursorReload(const int color) {
    wattrset(this->box_win, COLOR_PAIR(color));
    mvwprintw(this->box_win, this->reload.y, this->reload.x, "reload");
    wrefresh(this->box_win);
}

/**
 * @brief 選択可能な部屋一覧からフィールドに表示する部屋を選択する
 * 
 * 選択可能な部屋一覧の先頭から，
 * 4つまでをフィールドに表示する部屋一覧として選択する
 * 
 * @param show_room_infos フィールドに表示する部屋一覧
 * @return void
 */
void JoinRoomForm::selectFieldRoom(std::vector<RoomInfo> &show_room_infos) {
    show_room_infos.clear();
    for (int j = 0; j < (int)this->room_infos.size() && j < this->FIELD_BOX_HEIGHT - this->FIELD_FRAME; j++) {
        show_room_infos.push_back(this->room_infos[j]);
    }
}

/**
 * @brief フィールドに表示する部屋一覧を更新する
 * 
 * @param cursor_y カーソルの現在地
 * @param show_room_infos フィールドに表示する部屋一覧
 * @return void
 */
void JoinRoomForm::updateField(const int cursor_y, const std::vector<RoomInfo> show_room_infos) {
    for (int i = 0; i < this->FIELD_BOX_HEIGHT - this->FIELD_FRAME; i++) {
        if (i + 1 == cursor_y) wattrset(this->field_win, COLOR_PAIR(BG_WHITE));
        else wattrset(this->field_win, COLOR_PAIR(0));
        mvwprintw(this->field_win, i + 1, 1, show_room_infos[i].room_name);
    }
    wrefresh(this->field_win);
}
