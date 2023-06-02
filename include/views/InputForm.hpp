#pragma once

#include "views/BaseBox.hpp"

class InputForm: public BaseBox {
    private:
        const char *title_msg;
        const char *field_msg;

    protected:
        const int FORM_BOX_HEIGHT = 12;
        const int FORM_BOX_WIDTH = 40;
        const int FIELD_BOX_HEIGHT = 3;
        const int FIELD_BOX_WIDTH = 20;
        const int TITLE_CENTER_X = 4;
        const int FIELD_CENTER_X = 2;
        const int WIN_BASE_Y = 2;
        const int WIN_BASE_X = 2;
        WINDOW *box_win;
        WINDOW *field_win;
        Position title;
        Position field;

    public:
        InputForm(const char*, const char*);
        virtual ~InputForm();
        void showForm();
    
    protected:
        void showContents() override;
        void keyWait() override;
};