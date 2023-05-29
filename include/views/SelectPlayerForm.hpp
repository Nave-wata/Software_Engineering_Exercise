#pragma once

#include <ncurses.h>

typedef struct {
    int y;
    int x;
} Position;

class SelectPlayerForm {
    private:
        const int FORM_BOX_HEIGHT = 12;
        const int FORM_BOX_WIDTH = 40;
        const int NUMBERS_CENTER_X = 3;
        const int SUBMIT_CENTER_X = 3;
        const int WIN_BASE_Y = 2;
        int y;
        int x;
        int center_y;
        int center_x;
        int box_center_y;
        int box_center_x;
        WINDOW *win;
        Position title;
        Position play1;
        Position play2;
        Position play3;
        Position play4;

    public:
        SelectPlayerForm();
        ~SelectPlayerForm();
        void showForm();

    private:
        void showBox();
        void showContents();
        void keyWait();
};