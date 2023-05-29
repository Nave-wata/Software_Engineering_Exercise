#pragma once

#include <ncurses.h>

typedef struct {
    int y;
    int x;
} Position;

class BaseBox {
    protected:
        int y;
        int x;
        int center_y;
        int center_x;
        int box_y;
        int box_x;
        int box_center_y;
        int box_center_x;
        WINDOW *win;

    public:
        BaseBox();
        virtual ~BaseBox();

    protected:
        void showBox(const int, const int, const int, const int);
        virtual void showContents()=0;
        virtual void keyWait()=0;
};